
#include "TouchKeyCTC.h"
#include "IcoreTKDebug.h"




/*******************************通信参数*************************************/
#define WriteDeviceAddress 0xa0
#define ReadDviceAddress 0xa1
#define  Data_ADDR    0X00
#define   C_SlaveAddr    0x28
#define   C_FrameHeader  0x55AA
/***************************************************************************/


///*******************************通信引脚P10 P11*******************************/
#define   Port_I2CSCL   P10                               //通信SCL口，连接到仿真器SCK
#define   Port_I2CSDA   P11                               //通信SDA口， 连接到仿真器SDA
#define   Port_I2CSDA_SETIN    P1IO &= 0XFD;P1PU |= 0x02; //将通信SDA口设置为输入，并开启该端口上拉电阻
#define   Port_I2CSDA_SETOUT   P1IO |= 0X02;              //将通信SDA端口配置为输出
#define   Port_I2CSCL_SETOUT   P1IO |= 0X01;               //将通信SCL端口配置为输出
/***************************************************************************/



/*******************************通信时序************************************/
#if TK_DEBUG_ENABLE

/*************变量定义*****************/
unsigned char r1ms_tkFrame;

/*************函数声明*****************/
void TK_FrameSender(unsigned int *tkData1, unsigned int *tkData2, unsigned char DataSize);

/*************函数定义*****************/
void I2C_Wait_uSec(unsigned char  num)
{
	while (num--);
}


/***************************************************************************/
void I2C_Start()
{
	Port_I2CSDA = 1;
	Port_I2CSCL = 1;
	I2C_Wait_uSec(20);
	Port_I2CSDA = 0;
	I2C_Wait_uSec(200);
	Port_I2CSCL = 0;
}

/***************************************************************************/
void I2C_Stop()
{
	Port_I2CSCL = 0;
	I2C_Wait_uSec(200);
	Port_I2CSDA = 0;
	I2C_Wait_uSec(200);
	Port_I2CSCL = 1;
	I2C_Wait_uSec(200);
	Port_I2CSDA = 1;
}

/***************************************************************************/
//void I2C_Ack()
//{
//	Port_I2CSDA = 0;
//	I2C_Wait_uSec(200);
//	Port_I2CSCL = 1;
//	I2C_Wait_uSec(200);
//	Port_I2CSCL = 0;
//	I2C_Wait_uSec(200);
//	Port_I2CSDA = 1;
//}

/***************************************************************************/
//void I2C_NoAck()
//{
//	Port_I2CSDA = 1;
//	I2C_Wait_uSec(200);
//	Port_I2CSCL = 1;
//	I2C_Wait_uSec(200);
//	Port_I2CSCL = 0;
//}

/***************************************************************************/
bit TestAck()
{
	bit ErrorBit;
	Port_I2CSDA_SETIN;
	I2C_Wait_uSec(20);
	Port_I2CSCL = 1;
	I2C_Wait_uSec(20);
	ErrorBit = Port_I2CSDA;
	Port_I2CSCL = 0;
	Port_I2CSDA_SETOUT;

	return(ErrorBit);
}

/***************************************************************************/
void Write_Byte(unsigned char input)
{
	unsigned char temp;
	for (temp = 8;temp > 0;temp--)
	{
		Port_I2CSDA = (bit)(input & 0x80);
		I2C_Wait_uSec(10);
		Port_I2CSCL = 1;
		I2C_Wait_uSec(10);
		Port_I2CSCL = 0;
		input = input << 1;
	}
	I2C_Wait_uSec(10);
	TestAck();
}





void   Frame_SendStart(PackHeader _packHeader)
{
	unsigned char _checkSum = 0;
	unsigned char _i;
	unsigned char *_bufPoint;

	_bufPoint = (unsigned char *)&_packHeader;
	I2C_Start();
	for (_i = 0;_i < sizeof(_packHeader);_i++, _bufPoint++)
	{
		Write_Byte(*_bufPoint);
	}
}


unsigned char Frame_SendData(PackStrcut _packStrcut)
{
	unsigned char _checkSum = 0;
	unsigned char _i;
	unsigned char *_bufPoint;

	_bufPoint = (unsigned char *)&_packStrcut;
	for (_i = 0;_i < sizeof(_packStrcut);_i++, _bufPoint++)
	{
		Write_Byte(*_bufPoint);
		_checkSum += *_bufPoint;
	}
	return _checkSum;
}


/*******************************************************************************
* 函数名:TK_FrameSender
* 功  能 : 数据发送
 * 返回值：无
 * 参  数：无
 ******************************************************************************/


void TK_FrameSender(unsigned int *tkData1, unsigned int *tkData2, unsigned char DataSize)
{
	PackHeader packHeader;
	PackStrcut packStrcut;//
	unsigned char checksum = 0;
	unsigned char i;
	Port_I2CSDA_SETOUT                //将通信SDA端口配置为输出
		Port_I2CSCL_SETOUT                //将通信SCL端口配置为输出        //P10 P11输出作为通信引脚
		packHeader.Slave_Addr = C_SlaveAddr;
	packHeader.Frame_Header = C_FrameHeader;
	packHeader.length = sizeof(packStrcut) * DataSize + 2;        //长度=数据长度(1)+按键数据(6*X)+校验码(1)
	checksum = (unsigned char)(packHeader.length);   //校验码为除从机地址和0X55AA外的所有数据之和
	Frame_SendStart(packHeader);
	for (i = 0;i < DataSize;i++)
	{
		packStrcut.debug_baseLine = *(tkData1 + i);
		packStrcut.debug_rawData = *(tkData2 + i);
		packStrcut.debug_noiseData = abs(*(tkData1 + i) - *(tkData2 + i));  //

		checksum += Frame_SendData(packStrcut);

	}
	Write_Byte(checksum);//发送校验和
	I2C_Stop();

}


#endif
