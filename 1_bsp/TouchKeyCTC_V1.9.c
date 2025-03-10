
/****************************************Copyright (c)*************************
**--------------文件信息-------------------------------------------------------
**文   件   名: TouchKeyCTC_V1.0.c
**描        述: 触摸处理总文件
**使 用 说 明 : 此文件下函数无须用户修改,用户需要调用的文件都在该文件内
**-----------------------------------------------------------------------------
******************************************************************************/
#include "TouchKeyCTC.h"
unsigned long int code Tk_TotalChannel = ((unsigned long int)(T_K0_7) + ((unsigned long int)(T_K8_15) << 8) + ((unsigned long int)(T_K16_23) << 16) + \
	((unsigned long int)(T_K24_30) << 24));

//============各个按键灵敏度设置===================================================================
const unsigned int code C_FingerThreshold[] =
{
	TK0_FINGER_THRESHOLD,
	TK1_FINGER_THRESHOLD,
	TK2_FINGER_THRESHOLD,
	TK3_FINGER_THRESHOLD,
	TK4_FINGER_THRESHOLD,
	TK5_FINGER_THRESHOLD,
	TK6_FINGER_THRESHOLD,
	TK7_FINGER_THRESHOLD,
	TK8_FINGER_THRESHOLD,
	TK9_FINGER_THRESHOLD,
	TK10_FINGER_THRESHOLD,
	TK11_FINGER_THRESHOLD,
	TK12_FINGER_THRESHOLD,
	TK13_FINGER_THRESHOLD,
	TK14_FINGER_THRESHOLD,
	TK15_FINGER_THRESHOLD,
	TK16_FINGER_THRESHOLD,
	TK17_FINGER_THRESHOLD,
	TK18_FINGER_THRESHOLD,
	TK19_FINGER_THRESHOLD,
	TK20_FINGER_THRESHOLD,
	TK21_FINGER_THRESHOLD,
	TK22_FINGER_THRESHOLD,
	TK23_FINGER_THRESHOLD,
	TK24_FINGER_THRESHOLD,
	TK25_FINGER_THRESHOLD,
	TK26_FINGER_THRESHOLD,
	TK27_FINGER_THRESHOLD,
	TK28_FINGER_THRESHOLD,
	TK29_FINGER_THRESHOLD,
	TK30_FINGER_THRESHOLD,
};


//==============================================================
//		         触摸变量设置
//==============================================================
unsigned long data  Tktmrcount = 0;
unsigned long data  AllTouchKeyFlag;                    //按键状态 BIT0代表按键1，以此类推
unsigned char data	CurrentChannelCnt = 0;
unsigned char data  tkFreqGrade = 0;
unsigned char xdata tkstablecnt = 0;
unsigned char xdata F_TKtmrBOver = 0;
unsigned int  data  Provisional_Val;
unsigned long xdata  s_hwTkLongLockFlag;
unsigned int  xdata  tkSensorDataBuff[TkTotalNum];
unsigned int  xdata  tkBaseLine[TkTotalNum];
unsigned char xdata	 CurrentChannel[TkTotalNum];
unsigned int  xdata  tkFilterCapData[TkTotalNum];
unsigned char xdata  tkReleaseCnt[TkTotalNum];
unsigned char xdata  tkPressCnt[TkTotalNum];
unsigned char xdata	 tkRestCnt[TkTotalNum];
int           xdata  tkDifference[TkTotalNum];
unsigned char xdata  tkNoiseBiggerFlag[TkTotalNum];
unsigned int  xdata  tkCapData[TkTotalNum][3];
unsigned char xdata  tkBaseSteadyCnt[TkTotalNum];

//--------------高可靠性---------------------------------
unsigned char xdata tkLowFingerDataCnt[TkTotalNum];
unsigned char xdata tkMulCnt;
//-------------------------------------------------------
bit  F_tkDetectFinsh;
bit  F_tkbMultipleKey;
bit  F_tkBaseNeedUpdata;

tk_user_cfg_t data S_tTkUserCfgStruct;


void DelayTk_us(unsigned int delay);
void TouchKeyPullResDis();
void TouchKeySetToLow(void);
void TouchScanChannel(void);
void TouchScanChannelIniti(void);
void TouchKeyRestart(void);
void TouchKeyScan(void);

extern void TouchKey_Service(void);
extern void tkFilterDataDeal_First();
extern void tkFilterDataDeal_Double();
extern void TK_GetDataRenovate();
extern void TK_BaseLineMultiUpdata();

/*********************************************************
函  数：DelayTk_us
描  述:	延时函数
输入值: delay
输出值: 无
返回值: 无
**********************************************************/
void DelayTk_us(unsigned int delay)
{
	while (delay)
	{
		delay--;
	}
}

/*********************************************************
函  数：GetCurrFingerValue
描  述: 返回通道触摸阈值
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
unsigned int   GetCurrFingerValue(unsigned char i)
{
	unsigned int volatile Fth;
	Fth = C_FingerThreshold[CurrentChannel[i]];
	Fth = Fth * S_tTkUserCfgStruct.tkFigerPressRate / 10;
	return Fth;
}




/*********************************************************
函  数：GetTkReliabilityStatus
描  述:	获取触摸判断模式是否为CS强干扰模式
输入值: 无
输出值: 无
返回值: 无
**********************************************************/

unsigned char GetTkReliabilityStatus()
{
	return(C_CSFunctionEn);
}


/************************************************************************
函  数：TouchKeyRestart
描  述: 获取按键抑制确认次数
输入值: 无
输出值: 无
返回值: 返回噪声抑制次数

/************************************************************************/

unsigned char GettkRestrainNum(void)
{
	return ((S_tTkUserCfgStruct.DebounceTimes / C_tkPressRestrianrRatio) + 1);
}

/*********************************************************
函  数：GetTKNoiseThreshold
描  述:	获取抑制噪声数据
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
int GetTKNoiseThreshold(unsigned char i)
{
	int SetFingerNoisetmp;
	SetFingerNoisetmp = GetCurrFingerValue(i);                          //当前阈值
	SetFingerNoisetmp = SetFingerNoisetmp * C_tkRestrainNoiseVal / 10;  //抑制噪声为触摸阈值的70%
	return SetFingerNoisetmp;
}


#if (C_HighReliabilityMode == 1)
unsigned char xdata dTK_NoiseNum_Cnt, dTK_NoiseRet_Cnt;
//-----------------------------------------------------------------//
//函数名称： void TouchHighMoiseChk(void)
//函数功能： 高噪声和大电压波动检测
//输入参数： 无
//输出参数： 无
//返 回 值： 无
//-----------------------------------------------------------------//

void  TouchHighMoiseChk()
{
	unsigned char Tk_Cnt;
	unsigned int fth;
	int differ;
	dTK_NoiseNum_Cnt = 0;
	for (Tk_Cnt = 0; Tk_Cnt < S_tTkUserCfgStruct.CurrentChannelMax; Tk_Cnt++)
	{
		fth = C_FingerThreshold[CurrentChannel[Tk_Cnt]];
		differ = (int)tkBaseLine[Tk_Cnt] - (int)tkSensorDataBuff[Tk_Cnt];
		if (C_MULTI_KEY_NOISE_NUM != 0)   //多个按键噪声判断功能
		{
			if (differ >= 0)
			{
				if (differ >= (((int)fth) * C_MULTI_KEY_NOISE_RATE / 10))//多按键标志判断
				{
					dTK_NoiseNum_Cnt++;
				}
			}
		}
	}

	//2:2  3:2  4:3  5:3 6:4 7:4 8:5
	if (dTK_NoiseNum_Cnt > (C_MULTI_KEY_NOISE_NUM + 1))   //如果多个按键差值大于40%的阈值，则认为有噪声，需要进行环境更新
	{
		dTK_NoiseNum_Cnt = 0;
		dTK_NoiseRet_Cnt++;
		if (dTK_NoiseRet_Cnt >= C_MULTI_KEY_NOISE_RST_CNT)
		{
			dTK_NoiseRet_Cnt = 0;
			AllTouchKeyFlag = 0;
			F_tkBaseNeedUpdata = 1;           //需要更新环境值
		}
	}
	else
	{
		dTK_NoiseRet_Cnt = 0;
	}
}

#endif


/*********************************************************
函  数：TouchScanChannelIniti
描  述:	 扫描所有触摸按键，依次选择触摸通道
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void TouchScanChannelIniti(void)
{
	//------------------------
	unsigned char  	i;
	unsigned char  	Ctk_Channel_SelCnt = 0;
	unsigned long int	CurrentResponseKey;

	//------------------------
	CurrentResponseKey = Tk_TotalChannel;
	for (i = 0;i < 31;i++)
	{
		CurrentResponseKey = CurrentResponseKey >> 1;
		if (CY)
		{
			CurrentChannel[Ctk_Channel_SelCnt] = i;
			Ctk_Channel_SelCnt++;
			if (Ctk_Channel_SelCnt >= S_tTkUserCfgStruct.CurrentChannelMax) break;
		}
	}
}

/*********************************************************
函  数：TK_Cfg_Init
描  述:	触摸按键用户参数设置初始化
输入值: 无
输出值: 无
返回值: 无
**********************************************************/

void TK_Cfg_Init()
{
	S_tTkUserCfgStruct.CurrentChannelMax = TkTotalNum;
	S_tTkUserCfgStruct.DebounceTimes = C_ConfirmFilterCount;
	S_tTkUserCfgStruct.BaseNoise = C_SetNoiseThreshold;
	S_tTkUserCfgStruct.MaximumKeyHoldTime = C_tkContiTouchTime;
	S_tTkUserCfgStruct.OneKeyActive = C_SlideKeyFunc;
	S_tTkUserCfgStruct.PoweronStable = C_tkPoweronStableCycleNum;
	S_tTkUserCfgStruct.CsFunStatus = C_CSFunctionEn;
	S_tTkUserCfgStruct.OneTkUpdataTmr = C_tkOneseSyncUpdateVal;
	S_tTkUserCfgStruct.AllTkUpdataTmr = C_tkAllSyncUpdateVal;
	S_tTkUserCfgStruct.AutoFrequence = C_AutoFrequenceGet;
	S_tTkUserCfgStruct.WaveAbnormal = C_tkWaveAbnormalCount;
	S_tTkUserCfgStruct.ResponseMaxNum = C_tkResponseMaxNum;
	S_tTkUserCfgStruct.tkHighDelicasymode = C_tkHighDelicasy;
	S_tTkUserCfgStruct.tkOneNoiseMultiNum = C_tkOneNoiseMultiNum;
	S_tTkUserCfgStruct.tkFigerLeftRate = C_TKFigerLeftRate;
	S_tTkUserCfgStruct.tkFigerPressRate = C_TKFigerPressRate;
	S_tTkUserCfgStruct.tkUpNoiseUpdateVal = C_tkUpNoiseUpdateVal;
}



/*********************************************************
函  数：GetBaselineUpdateThreshold
描  述:	获取基值变化速率
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
int  GetBaselineUpdateThreshold(void)
{
	unsigned int tkBaseLineUpdateSpeed;
	tkBaseLineUpdateSpeed = S_tTkUserCfgStruct.BaseNoise;
	tkBaseLineUpdateSpeed = tkBaseLineUpdateSpeed * S_tTkUserCfgStruct.tkOneNoiseMultiNum;         //16倍数
	return tkBaseLineUpdateSpeed;
}





/*********************************************************
函  数：tkAutoFrequenceModeSet
描  述:	自动跳频模式设定
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void tkAutoFrequenceModeSet()
{
	if (S_tTkUserCfgStruct.AutoFrequence)
	{
		TKCR |= 0X04 | 0X02;
		//TKINT |= 0x80;                                            //自动跳频每次初值0X40开始跳频
#if(Header_File==0)
		TKOSCCR = 0XC0;                                            //选择独立时钟源
#else
		TKCHSEL |= 0X80;
#endif
	}

#if(Header_File==0)

#else
	if (S_tTkUserCfgStruct.tkHighDelicasymode) TKCHSEL |= 0X20;       //高灵敏度模式
#endif
}



/*********************************************************
函  数：PortCx_Output_Low
描  述:	将CX电容放电
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void PortCx_Output_Low()
{
	P0PU &= 0X7F;
#if(Header_File==0)
	P0OD &= 0X7F;
#endif
	P0IO |= 0x80;
	P0 &= 0X7F;        //输出0
}
/*********************************************************
函  数：PortCx_floating
描  述:	将CX电容端口配置为输入态
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void PortCx_floating()
{
	P0PU &= 0X7F;
#if(Header_File==0)
	P0OD &= 0X7F;
#endif
	P0IO &= 0X7F;       //浮空输入

}

/*********************************************************
函  数：TouchKeyResgInit
描  述:	触摸按键功能寄存器初始化
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void TouchKeyResgInit()
{
	TKCR &= ~0X08;		            //关闭触摸模块功能
	DelayTk_us(50);
	PortCx_Output_Low();
	DelayTk_us(50);
	PortCx_floating();              //将P07端口设置为CX口
	TKOSCCR = 0;                        	   //关闭跳频
	TKINT = 0x01 | 0x02 | 0x10;	 	   //TMR使能 TMR中断使能 触摸中断使能
	IE1 |= 0x10;                      //打开触摸中断    2个中断都要打开
	TKCR = 0XE0;            	      //，数字+模拟滤波，7*TCK滤波
	TKCHSEL = 0;
	tkAutoFrequenceModeSet();         //设定是否使能自动跳频模式和高灵敏度模式
	TouchScanChannel();	             //配置触摸通道
	DelayTk_us(20);
	TKCR |= 0x08;                   //使能触摸模块
}

/*********************************************************
函  数：TouchKeySetToLow
描  述:	将TK端口电荷清0
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
//void TouchKeySetToLow()
//{
//	PortCx_Output_Low();  	      					       // 0 0 0 输出态 0，检测完之后，将CS电容口电荷清0
//	DelayTk_us(20);
//	PortCx_floating();
//	DelayTk_us(10);
//
//}

/*********************************************************
函  数：TouchScanChannel
描  述:	获取触摸端口
输入值: 无
输出值: 无
返回值: 无
/**********************************************************/
void TouchScanChannel(void)
{
	unsigned char TKCHSELBUFF;
	//	TouchKeySetToLow();         						 //相应的touch key作为输出0，放掉残留电荷

	TKCHSELBUFF = TKCHSEL;
	TKCHSELBUFF &= 0XE0;
	TKCHSELBUFF |= CurrentChannel[CurrentChannelCnt];
	TKCHSEL = TKCHSELBUFF;

}



/*********************************************************
函  数：TouchKeyRestart
描  述:	触摸时钟选择同时启动触摸检测
输入值: 无
输出值: 无
返回值: 无
/**********************************************************/
void TouchKeyRestart(void)
{
	//Fsys = 16M，且Fctc < 8M ,至少需要3分频
	TouchScanChannel();                    //选择需要检测的触摸按键


	TKCR &= 0XFE;

	CTCCR = CTC_VREF | CTC_CounterMode;	   // 时钟输入:  /计数模式/CTC参考电压0.4VDD

	switch (tkFreqGrade)
	{
		case 0:
			CTCCR |= CTC_CLKDIV5;	       // 时钟输入:系统时钟\5
			break;
		case 1:
			CTCCR |= CTC_CLKDIV7;	       // 时钟输入:系统时钟\7
			break;
		case 2:
			CTCCR |= CTC_CLKDIV9;	       // 时钟输入:系统时钟\9
			break;
		default:
			break;

	}
	TKCR |= 0X01;						   //启动检测
}



/*********************************************************
函  数：TouchKeyChkTmrOverChk
描  述:	触摸按键检测溢出判断
输入值: 无
输出值: 无
返回值: 无
**********************************************************/

void TouchKeyChkTmrOverChk()
{
	//---------------------按键检测时间溢出判断------------
	if (Tktmrcount < S_tTkUserCfgStruct.WaveAbnormal)	// KeyWAve_Abnormal_Count=5000
	{
		Tktmrcount++;
	}
	else
	{
		Tktmrcount = 0;
		TouchKeyInit();
	}
}




/*********************************************************
函  数：TouchKeyOneScan
描  述:	触摸按键总判断，环境判断总函数
输入值: 无
输出值: 无
返回值: 无
**********************************************************/

void  TouchKeyOneScan()
{
	unsigned char i;
	if (tkstablecnt < (S_tTkUserCfgStruct.PoweronStable + 20))
	{
		tkstablecnt++;
		if (tkstablecnt > S_tTkUserCfgStruct.PoweronStable) 					// 前S_tTkUserCfgStruct.PoweronStable次为无效，等待系统稳定。
		{
			tkFilterDataDeal_First();                                             //数据优化并处理
			for (i = 0;i < S_tTkUserCfgStruct.CurrentChannelMax;i++)
			{
				if (tkBaseLine[i] == 0)
				{
					tkBaseLine[i] = tkSensorDataBuff[i];
				}
				else
				{
					tkBaseLine[i] -= tkBaseLine[i] >> 1;
					tkBaseLine[i] += tkSensorDataBuff[i] >> 1;
					tkFilterCapData[i] = tkSensorDataBuff[i];
				}
			}
		}
		TouchKeyRestart();	                                               // 设置扫描频率，启动触摸检测
		return;
	}

	tkFilterDataDeal_First();                                                    //数据优化并处理
#if (C_HighReliabilityMode == 1)
	TouchHighMoiseChk();
#endif
	tkFilterDataDeal_Double();
	TouchKeyRestart();	                                                   //设置扫描频率，启动触摸检测


	if (F_tkBaseNeedUpdata == 0)						                       //检测是否需要更新baseline
	{
		TK_GetDataRenovate();    					                       //触摸按键按下松开，噪声等判断
	}
	else
	{
		TK_BaseLineMultiUpdata();		                                   //基线复位处理
	}

}

/*********************************************************
函  数：TouchKeyScan
描  述:	触摸检测
输入值: 无
输出值: 无
返回值: 无
**********************************************************/
void TouchKeyScan(void)
{
	TouchKeyChkTmrOverChk();
	if (F_tkDetectFinsh)             //所有按键一个周期检测结束
	{
		F_tkDetectFinsh = 0;
		TouchKeyOneScan();          //启动触摸判断和下一个周期检测
	}
}


//=============================================================
//	InterruptTouch		扫描中断
//=============================================================
void InterruptTouch(void) interrupt 10
{
	if (TKINT & 0x40)	              //触摸检测完成  实际测试：16M 中断处理时间20us
	{
		TKINT &= ~0x40;
		Provisional_Val = TKDRH;
		Provisional_Val = Provisional_Val << 8;
		Provisional_Val += TKDRL;			// 	采集到的触摸值
		TouchKey_Service();
	}
	else                          //触摸溢出则重新扫描
	{
		if (TKINT & 0x08)
		{
			TKINT &= ~0x08;
			TouchKeyRestart();
		}
	}
}
