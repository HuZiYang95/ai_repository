/*
--------------------Touch库软件免责声明--------------------------------
本产品中提供的软件之著作权归软件作者所有。用户可以自由选择是否使用本产品提供的软件。
如果用户选择使用本产品中所提供的软件版本，即表明用户信任该软件作者，
对任何原因在使用本产品中提供的软件时可能对用户自己或他人造成的任何形式的损失和伤害不承担责任。
*/


//*************************************************************************************************
//  Copyright (c) 	无锡中微爱芯电子有限公司
//	文件名称	:
//	作者		:
//	模块功能	:  触控键配置文件
// 	版本		:
// 	更改记录	:
//	注意事项	:  用户配置文件，用户可修改
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__



#define Header_File    0 //范围0~4; 0:AIP8F3264; 1:AIP8F3216; 2:AIP8F3208  3:AIP8F3216E
//----------------------------------------------------
#if(Header_File==0)
#include "bsp_sfr.h"
#elif(Header_File==1)
#include "AiP8F3216_Config.h"
#elif(Header_File==2)
#include "AiP8F3208_Config.h"
#elif(Header_File==3)
#include "AiP8F3216E_Config.h"

#endif




//------------------------------------------------------------------------
//-------1:打开当前I/O 的Touch功能，0:关闭当前I/O 的Touch功能
//-------如果P_TK0设置为1则该引脚为TK口，设置为0则为普通IO口。
//------------------------------------------------------------------------
#define P_TK0				0
#define P_TK1				0
#define P_TK2				0
#define P_TK3				0
#define P_TK4				0
#define P_TK5				0
#define P_TK6				0
#define P_TK7				0
#define P_TK8				1
#define P_TK9				1
#define P_TK10				0
#define P_TK11				0
#define P_TK12				0
#define P_TK13				0
#define P_TK14				0
#define P_TK15				0
#define P_TK16				0
#define P_TK17				0
#define P_TK18				0
#define P_TK19				0
#define P_TK20				0
#define P_TK21				0
#define P_TK22				0
#define P_TK23				0
#define P_TK24			    0
#define P_TK25				0
#define P_TK26				0
#define P_TK27				0
#define P_TK28				0
#define P_TK29				0
#define P_TK30				0

//-------按键门槛设定------------------------------------------------------------------------------
//---TKx_FINGER_THRESHOLD 为Touch I/O 的触摸感应阈值，x值：0~30
//---如TK3_FINGER_THRESHOLD对应P_TK3的阈值 ，初次调节设定60。 实际设置不得低于140。
//------------------------------------------------------------------------------------------------
#define TK0_FINGER_THRESHOLD			60
#define TK1_FINGER_THRESHOLD			60
#define TK2_FINGER_THRESHOLD		    60
#define TK3_FINGER_THRESHOLD			60
#define TK4_FINGER_THRESHOLD			60
#define TK5_FINGER_THRESHOLD			60
#define TK6_FINGER_THRESHOLD			60
#define TK7_FINGER_THRESHOLD			60
#define TK8_FINGER_THRESHOLD			200
#define TK9_FINGER_THRESHOLD			200
#define TK10_FINGER_THRESHOLD			60
#define TK11_FINGER_THRESHOLD			60
#define TK12_FINGER_THRESHOLD			60
#define TK13_FINGER_THRESHOLD			60
#define TK14_FINGER_THRESHOLD			60
#define TK15_FINGER_THRESHOLD			60
#define TK16_FINGER_THRESHOLD			80
#define TK17_FINGER_THRESHOLD			80
#define TK18_FINGER_THRESHOLD			80
#define TK19_FINGER_THRESHOLD			80
#define TK20_FINGER_THRESHOLD			80
#define TK21_FINGER_THRESHOLD			80
#define TK22_FINGER_THRESHOLD			80
#define TK23_FINGER_THRESHOLD			80
#define TK24_FINGER_THRESHOLD			60
#define TK25_FINGER_THRESHOLD			60
#define TK26_FINGER_THRESHOLD			60
#define TK27_FINGER_THRESHOLD			60
#define TK28_FINGER_THRESHOLD			60
#define TK29_FINGER_THRESHOLD			60
#define TK30_FINGER_THRESHOLD			60




//==========================================================================
//--------常规触摸参数设置
//==========================================================================
//触摸引脚电阻 建议1K
//Cx引脚外接电容默认使用10nF

//按键类型
#define   C_SlideKeyFunc   	       1    //0:表示单键，1:表示组合双键

//按键同时按下最大个数,超过该值则触摸输出0
#define   C_tkResponseMaxNum       2    //范围2~31,默认设置为2。一般不做修改。

//按键按下消抖次数
#define   C_ConfirmFilterCount     10	//范围5~20，消抖次数越大，可靠性越高，同时反应越慢

//环境噪声值
#define   C_SetNoiseThreshold      40   //范围40~100，建议小于1/2阈值。触摸观察软件中最大噪声值+16

//硬件跳频使能
#define   C_AutoFrequenceGet       1    // 0：关闭  1：使能。一般默认1,不做修改







/*-------------------------------------------------------
--------------以下数据通常情况下不用修改
-------------------------------------------------------*/

//内部比较器参考电压设定，在下列值中选取
//CTC_0P4VDD  => 0.4VDD
//CTC_0P5VDD  => 0.5VDD
//CTC_0P6VDD  => 0.6VDD
//CTC_0P7VDD  => 0.7VDD
#define   CTC_VREF   CTC_0P4VDD              //参考电压越高，灵敏度越好，但相应的可靠性也会稍微变差。
#define   C_tkHighDelicasy          0        //硬件高灵敏度模式  只有AiP8F3216(E)/3208芯片支持，1:使能 0:关闭
#define   C_TKFigerPressRate 		7		 //手指按下阈值比例，按键按下阈值= 触摸差值*C_TKFigerPressRate/10。范围:6-7.默认7
#define   C_TKFigerLeftRate         7        //手指松开阈值比例，按键松开阈值= 按下阈值*C_TKFigerLeftRate/10。范围6-9，默认7
#define   C_tkAllSyncUpdateVal      5        //所有按键大更新消抖次数,设置范围 2-10，默认5
#define   C_tkUpNoiseUpdateVal      40        //大于正噪声按键更新消抖次数，设置范围:10的倍数，默认：40
#define   C_tkOneseSyncUpdateVal    200       //大于负噪声按键更新消抖次数，设置范围:100-250,默认：200
#define   C_CSFunctionEn            1         //CS注入电流实验   1:使能,0:关闭 默认1
#define   C_tkOneNoiseMultiNum      8         //单个按键噪声累加倍数  设置范围：4-16  默认8
#define   C_tkPressRestrianrRatio   3         //多个按键响应抑制比例 ，设置范围 2-3。仅高可靠性模式下有效。
#define   C_tkRestrainNoiseVal      7         //噪声抑制区间，设置范围5-10，默认7。仅高可靠性模式下有效。
#define	  C_tkContiTouchTime		5000	  //按键有效的最长输出时间,设置范围0~50000，默认5000，输出时间= 5000*单位每轮扫描时间（如10ms）=50S
											  //设置为0，则输出一直有效。
#define   C_tkPoweronStableCycleNum  20       //上电触摸稳定次数，设置范围：20-50。
#define   C_tkWaveAbnormalCount      50000    //触摸硬件异常超出时间，超出该值则模块自动重启，输出清0，范围：100-50000。


//-----高可靠性模式(默认设置)----------------------
#define   C_HighReliabilityMode      1        			//高可靠性模式:多按键噪声检测功能，1：使能  0：关闭(以下参数无需设置)，默认：1
#define   C_MULTI_KEY_NOISE_NUM      ((TkTotalNum)/2)     //多按键噪声判断总数，范围：2-按键总数，一般设置为：1/2按键总数，等于0时无多按键噪声判断。
#define   C_MULTI_KEY_NOISE_RATE     5        		    //多按键噪声比例：多按键手指噪声= 触摸差值*C_MULTI_KEY_NOISE_RATE/10。范围: 2-5，一般设置为：5
#define   C_MULTI_KEY_NOISE_RST_CNT  (C_ConfirmFilterCount/2+1)   //多按键计数复位次数：范围：2-C_ConfirmFilterCout，一般设置C_ConfirmFilterCount/2+1。

//Touch Initial Value Setting

#define T_K0_7    		(P_TK0+(P_TK1<<1)+(P_TK2<<2)+(P_TK3<<3)+(P_TK4<<4)+(P_TK5<<5)+(P_TK6<<6)+(P_TK7<<7))
#define T_K8_15    		(P_TK8+(P_TK9<<1)+(P_TK10<<2)+(P_TK11<<3)+(P_TK12<<4)+(P_TK13<<5)+(P_TK14<<6)+(P_TK15<<7))
#define T_K16_23        (P_TK16+(P_TK17<<1)+(P_TK18<<2)+(P_TK19<<3)+(P_TK20<<4)+(P_TK21<<5)+(P_TK22<<6)+(P_TK23<<7))
#define T_K24_30   		(P_TK24+(P_TK25<<1)+(P_TK26<<2)+(P_TK27<<3)+(P_TK28<<4)+(P_TK29<<5)+(P_TK30<<6))

#define TkTotalNum     P_TK0+P_TK1+P_TK2+P_TK3+P_TK4+P_TK5+P_TK6+P_TK7+\
                       P_TK8+P_TK9+P_TK10+P_TK11+P_TK12+P_TK13+P_TK14+P_TK15+\
					   P_TK16+P_TK17+P_TK18+P_TK19+P_TK20+P_TK21+P_TK22+P_TK23+\
					   P_TK24+P_TK25+P_TK26+P_TK27+P_TK28+P_TK29+P_TK30



typedef struct
{
	unsigned char       CurrentChannelMax;           //使能触摸最大按键个数
	unsigned char 		DebounceTimes;               // 去抖次数
	unsigned char 		BaseNoise;                   //噪声值
	unsigned int 		MaximumKeyHoldTime;          //按键触摸最长时间
	unsigned char 		OneKeyActive;                //单键使能
	unsigned char 		PoweronStable;               //上电稳定次数
	unsigned char       CsFunStatus;                 //CS是否使能
	unsigned char    	OneTkUpdataTmr;              //单按键异常次数
	unsigned char       AllTkUpdataTmr;              //所有按键更新消抖次数
	unsigned char    	AutoFrequence;               //自动跳频
	unsigned int        WaveAbnormal;                //触摸IC模块检测溢出时间
	unsigned char       ResponseMaxNum;              //按键同时按下最大个数
	unsigned char       tkHighDelicasymode;          //高灵敏度模式
	unsigned char       tkOneNoiseMultiNum;          //更新噪声倍数
	unsigned char       tkFigerLeftRate;             //手指松开比例
	unsigned char       tkFigerPressRate;            //手指按下差值比例
	unsigned char       tkUpNoiseUpdateVal;
}tk_user_cfg_t;

extern tk_user_cfg_t data S_tTkUserCfgStruct;


//-------------------------------------------------------------
//Touch Global Variable

extern unsigned long data AllTouchKeyFlag;	   //scan key variable
//Touch function
extern void TouchKeyInit(void);
extern void TouchKeyScan(void);

//------------------------------------------------
#endif
