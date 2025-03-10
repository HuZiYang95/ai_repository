
#ifndef _REL_SENDER_
#define _REL_SENDER_
#include <math.h>
//--------------------------------
#define   TK_DEBUG_ENABLE   0
//--------------------------------
typedef struct _PackHeader
{
	unsigned char  Slave_Addr;       //从机地址
	unsigned int   Frame_Header;     //数据帧头
	unsigned char   length;		     //数据长度  去除数据头的总长度

}PackHeader;


typedef struct _PackStrcut
{
	unsigned int  debug_baseLine;					//基准值
	unsigned int  debug_rawData;					//滤波后的值

	unsigned int  debug_noiseData;				 	//噪声值

}PackStrcut;



extern unsigned int  xdata  tkSensorDataBuff[];		//当前触摸扫描值缓存，用于后期触摸整合计算
extern unsigned int  xdata  tkBaseLine[];			//环境值，整数部分
extern unsigned char r1ms_tkFrame;

extern void TK_FrameSender(unsigned int *tkData1, unsigned int *tkData2, unsigned char DataSize);

#endif
