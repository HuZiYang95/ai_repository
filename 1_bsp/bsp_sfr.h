/******************************************************************************
 * @file     AiP8F3264_Config.h
 * @author   guyonghe
 * @version  V1.0
 * @date     2023-9-5
 * @brief    Config  File for AiP8F3264
 * @note
 * Copyright (C) 2023 Wuxi I-CORE Electronics Co.,Ltd. All rights reserved.
*******************************************************************************
  * @par 修改日志:
  * <table>
  * <tr><th>Date   <th>Version <th>Author  <th>Description
  * <tr><td>2023/06/28<td>1.0  <td>guyonghe <td>创建初始版本
  * </table>
******************************************************************************/

#ifndef		_AiP8F3264_Config_H
#define		_AiP8F3264_Config_H

#include  <intrins.h>


//===================IRAM=============================================================

sfr       P0 = 0x80;                  //端口P0数据寄存器
sbit   P07 = P0 ^ 7;
sbit   P06 = P0 ^ 6;
sbit   P05 = P0 ^ 5;
sbit   P04 = P0 ^ 4;
sbit   P03 = P0 ^ 3;
sbit   P02 = P0 ^ 2;
sbit   P01 = P0 ^ 1;
sbit   P00 = P0 ^ 0;

sfr       SP = 0x81;                  //堆栈指针寄存器

sfr       DPL = 0x82;                  //数据指针低8位寄存器

sfr       DPH = 0x83;                  //数据指针高8位寄存器

sfr       DPL1 = 0x82;                  //数据指针低8位寄存器1

sfr       DPH1 = 0x83;                  //数据指针高8位寄存器1

sfr       LVICR = 0x86;                  //LVD控制寄存器

sfr       PCON = 0x87;                  //电源管理控制寄存器

sfr       P4 = 0x88;                  //端口P4数据寄存器
sbit   P47 = P4 ^ 7;
sbit   P46 = P4 ^ 6;
sbit   P45 = P4 ^ 5;
sbit   P44 = P4 ^ 4;
sbit   P43 = P4 ^ 3;
sbit   P42 = P4 ^ 2;
sbit   P41 = P4 ^ 1;
sbit   P40 = P4 ^ 0;


sfr       WDTDR = 0x8A;                  //WDT溢出寄存器,可写不可读
sfr       WDTCNT = 0x8A;                  //WDT计数寄存器,可读不可写

sfr       WTDR = 0x8B;                  //WT数据寄存器,可写不可读
sfr       WTCNT = 0x8B;                  //WT计数寄存器,可读不可写

sfr       EIFLAG2 = 0x8C;                  //外部中断标志5寄存器

sfr       FRECR = 0x8E;                  //预分频控制寄存器

sfr       FRECNT = 0x8F;                  //WDT预分频计数器

sfr       P1 = 0x90;                  //端口P1数据寄存器
sbit   P17 = P1 ^ 7;
sbit   P16 = P1 ^ 6;
sbit   P15 = P1 ^ 5;
sbit   P14 = P1 ^ 4;
sbit   P13 = P1 ^ 3;
sbit   P12 = P1 ^ 2;
sbit   P11 = P1 ^ 1;
sbit   P10 = P1 ^ 0;

sfr       DPS = 0x91;                  //数据指针选择寄存器

sfr       WDTCR = 0x92;                  //WDT控制寄存器

sfr       WTCR = 0x93;                  //WT控制寄存器

sfr       P0IO = 0x95;                  //端口P0方向控制寄存器

sfr       P1IO = 0x96;                  //端口P1方向控制寄存器

sfr       P2IO = 0x97;                  //端口P2方向控制寄存器

sfr       P5 = 0x98;                  //端口P5数据寄存器
sbit   P57 = P5 ^ 7;
sbit   P56 = P5 ^ 6;
sbit   P55 = P5 ^ 5;
sbit   P54 = P5 ^ 4;
sbit   P53 = P5 ^ 3;
sbit   P52 = P5 ^ 2;
sbit   P51 = P5 ^ 1;
sbit   P50 = P5 ^ 0;

sfr       T0CR1 = 0x99;                  //定时器T0控制寄存器1

sfr       T0CR2 = 0x9A;                  //定时器T0控制寄存器2

sfr       T0DR1L = 0x9B;                  //定时器T0周期寄存器低8位

sfr       T0DR1H = 0x9C;                  //定时器T0周期寄存器高8位

sfr       T0DR2L = 0x9D;                  //定时器T0占空比寄存器低8位

sfr       T0DR2H = 0x9E;                  //定时器T0占空比寄存器高8位

sfr       P3IO = 0x9F;                  //端口P3方向控制寄存器

sfr       P2 = 0xA0;                  //端口P2数据寄存器
sbit   P27 = P2 ^ 7;
sbit   P26 = P2 ^ 6;
sbit   P25 = P2 ^ 5;
sbit   P24 = P2 ^ 4;
sbit   P23 = P2 ^ 3;
sbit   P22 = P2 ^ 2;
sbit   P21 = P2 ^ 1;
sbit   P20 = P2 ^ 0;

sfr       T1CR1 = 0xA1;                  //定时器T1控制寄存器1

sfr       T1CR2 = 0xA2;                  //定时器T1控制寄存器2

sfr       T1DR1L = 0xA3;                  //定时器T1周期寄存器低8位

sfr       T1DR1H = 0xA4;                  //定时器T1周期寄存器高8位

sfr       T1DR2L = 0xA5;                  //定时器T1占空比寄存器低8位

sfr       T1DR2H = 0xA6;                  //定时器T1占空比寄存器高8位

sfr       P4IO = 0xA7;                  //端口P4方向控制寄存器

sfr       IE0 = 0xA8;                  //中断控制寄存器0
sbit   EA = IE0 ^ 7;                 //全局中断使能
sbit   INT5E = IE0 ^ 5;                 //外部中断5使能
sbit   INT4E = IE0 ^ 4;                 //外部中断4使能
sbit   INT3E = IE0 ^ 3;                 //外部中断3使能
sbit   INT2E = IE0 ^ 2;                 //外部中断2使能
sbit   INT1E = IE0 ^ 1;                 //外部中断1使能
sbit   INT0E = IE0 ^ 0;                 //外部中断0使能

sfr       IE1 = 0XA9;                  //中断控制寄存器1

sfr       IE2 = 0XAA;                  //中断控制寄存器1

sfr       ADCCRL = 0xAB;                  //AD控制寄存器低字节

sfr       ADCCRH = 0xAC;                  //AD控制寄存器高字节

sfr       ADCDRL = 0xAD;                  //AD转换结果寄存器低字节

sfr       ADCDRH = 0xAE;                  //AD转换结果寄存器高字节

sfr       P5IO = 0xAF;                  //端口P5方向控制寄存器

sfr       P3 = 0xB0;                  //端口P2数据寄存器
sbit   P37 = P3 ^ 7;
sbit   P36 = P3 ^ 6;
sbit   P35 = P3 ^ 5;
sbit   P34 = P3 ^ 4;
sbit   P33 = P3 ^ 3;
sbit   P32 = P3 ^ 2;
sbit   P31 = P3 ^ 1;
sbit   P30 = P3 ^ 0;

sfr       T2CR1 = 0xB1;                  //定时器T2控制寄存器1

sfr       T2CR2 = 0xB2;                  //定时器T2控制寄存器2

sfr       T2DR1L = 0xB3;                  //定时器T1周期寄存器低8位

sfr       T2DR1H = 0xB4;                  //定时器T1周期寄存器高8位

sfr       T2DR2L = 0xB5;                  //定时器T1占空比寄存器低8位

sfr       T2DR2H = 0xB6;                  //定时器T1占空比寄存器高8位

sfr       EIFLAG1 = 0xB7;                  //外部中断标志4寄存器

sfr       IP0 = 0xB8;                  //中断优先级控制寄存器
sbit   IP0_5 = IP0 ^ 5;
sbit   IP0_4 = IP0 ^ 4;
sbit   IP0_3 = IP0 ^ 3;
sbit   IP0_2 = IP0 ^ 2;
sbit   IP0_1 = IP0 ^ 1;
sbit   IP0_0 = IP0 ^ 0;
sfr       UART0CR1 = 0xB9;                  //UART0控制寄存器1

sfr       UART0CR2 = 0xBA;                  //UART0控制寄存器2

sfr       UART0CR3 = 0xBB;                  //UART0控制寄存器3

sfr       UART0DR = 0xBC;                  //UART0数据寄存器

sfr       UART0SR = 0xBD;                  //UART0状态寄存器

sfr       UART0BRR1 = 0xBE;                  //UART0波特率控制寄存器1

sfr       UART0BRR2 = 0xBF;                  //UART0波特率控制寄存器2

sfr       EIFLAG0 = 0xC0;                  //外部中断标志0寄存器
sbit   IEX3 = EIFLAG0 ^ 3;
sbit   IEX2 = EIFLAG0 ^ 2;
sbit   IEX1 = EIFLAG0 ^ 1;
sbit   IEX0 = EIFLAG0 ^ 0;

sfr       UART1CR1 = 0xC1;                  //UART1控制寄存器1

sfr       UART1CR2 = 0xC2;                  //UART1控制寄存器2

sfr       UART1CR3 = 0xC3;                  //UART1控制寄存器

sfr       UART1SR = 0xC4;                  //UART1状态寄存器

sfr       UART1DR = 0xC5;                  //UART1数据寄存器

sfr       UART1BRR1 = 0xC6;                  //UART1波特率控制寄存器1

sfr       UART1BRR2 = 0xC7;                  //UART1波特率控制寄存器2

sfr       OSCCR = 0XC8;                  //系统时钟控制寄存器
sbit   LXTE = OSCCR ^ 7;
sbit   LIRCE = OSCCR ^ 6;
sbit   HXTE = OSCCR ^ 5;
sbit   HIRCE = OSCCR ^ 4;
sbit   DIVEN = OSCCR ^ 2;
sbit   DIVS_1 = OSCCR ^ 1;
sbit   DIVS_0 = OSCCR ^ 0;

sfr       UART2CR1 = 0xC9;                  //UART2控制寄存器1

sfr       UART2CR2 = 0xCA;                  //UART2控制寄存器2

sfr       UART2CR3 = 0xCB;                  //UART2控制寄存器3


sfr       UART2DR = 0xCC;                  //UART2数据寄存器

sfr       UART2SR = 0xCD;                  //UART2状态寄存器

sfr       UART2BRR1 = 0xCE;                  //UART2波特率控制寄存器1

sfr       UART2BRR2 = 0xCF;                  //UART2波特率控制寄存器2

sfr       PSW = 0xD0;                  //程序状态寄存器
sbit   CY = PSW ^ 7;
sbit   AC = PSW ^ 6;
sbit   F0 = PSW ^ 5;
sbit   RS_1 = PSW ^ 4;
sbit   RS_0 = PSW ^ 3;
sbit   OV = PSW ^ 2;
sbit   F1 = PSW ^ 1;
sbit   P = PSW ^ 0;

sfr       I2CSR1 = 0xD1;                  //I2C状态寄存器1

sfr       I2CSR2 = 0xD2;                  //I2C状态寄存器2

sfr       I2CDR = 0xD3;                  //I2C控制寄存器

sfr       I2CADDR = 0xD4;                  //I2C从机地址寄存器

sfr       I2CCCRL = 0xD5;                  //I2C时钟控制寄存器低字节

sfr       I2CCCRH = 0xD6;                  //I2C时钟控制寄存器高字节

sfr       I2CSDHR = 0xD7;                  //I2C SDA保持时间寄存器

sfr       LVRCR = 0xD8;                  //LVR控制寄存器
sbit   LVR_EN = LVRCR ^ 7;
sbit   LVR_SEL_3 = LVRCR ^ 3;
sbit   LVR_SEL_2 = LVRCR ^ 2;
sbit   LVR_SEL_1 = LVRCR ^ 1;
sbit   LVR_SEL_0 = LVRCR ^ 0;
sfr       I2CCR1 = 0xD9;                  //I2C控制寄存器

sfr       SPICR1 = 0xDA;                  //SPI控制寄存器1

sfr       SPICR2 = 0xDB;                  //SPI控制寄存器2

sfr       SPISR = 0xDC;                  //SPI状态寄存器

sfr       SPIDR = 0xDD;                  //SPI数据寄存器

sfr       FSCR1 = 0xDE;                  //页保护控制寄存器

sfr       KEYCODE = 0xDF;                  //钥密寄存器

sfr       ACC = 0xE0;                  //累加器A

sfr       MDAL0 = 0xE1;                  //乘法寄存器A低16位低字节

sfr       MDAL1 = 0xE2;                  //乘法寄存器A低16位高字节

sfr       MDBL0 = 0xE3;                  //乘法寄存器B低16位低字节

sfr       MDBL1 = 0xE4;                  //乘法寄存器B低16位高字节

sfr       MDCL0 = 0xE5;                  //乘法寄存器C低16位低字节

sfr       MDCL1 = 0xE6;                  //乘法寄存器B低16位高字节

sfr       MDUC = 0xE7;                  //MDU控制寄存器

sfr       RSTFR = 0xE8;                  //复位标志寄存器
sbit   PORF = RSTFR ^ 7;
sbit   EXTRF = RSTFR ^ 6;
sbit   WDTRF = RSTFR ^ 5;
sbit   LVRF = RSTFR ^ 4;

sfr       MDAH0 = 0xE9;                  //乘法寄存器A高16位低字节

sfr       MDAH1 = 0xEA;                  //乘法寄存器A高16位高字节

sfr       MDBH0 = 0xEB;                  //乘法寄存器B高16位低字节

sfr       MDBH1 = 0xEC;                  //乘法寄存器B高16位高字节

sfr       MDCH0 = 0xED;                  //乘法寄存器B高16位低字节

sfr       MDCH1 = 0xEE;                  //乘法寄存器C高16位高字节

sfr       OPACR = 0xEF;                  //OPA控制寄存器

sfr       B = 0xF0;                  //累加器B

sfr       SYSCR = 0XF4;                  //唤醒时钟控制寄存器

sfr       CKCR = 0XF5;                  //系统时钟源控制寄存器

sfr       OSCCR1 = 0XF6;                  //系统时钟控制寄存器1

sfr       OSCTS = 0XF7;                  //外部晶振稳定时间检测寄存器

sfr       IP1 = 0xF8;                  //中断优先级控制寄存器1
sbit   IP1_5 = IP1 ^ 5;
sbit   IP1_4 = IP1 ^ 4;
sbit   IP1_3 = IP1 ^ 3;
sbit   IP1_2 = IP1 ^ 2;
sbit   IP1_1 = IP1 ^ 1;
sbit   IP1_0 = IP1 ^ 0;
sfr       CRCIN = 0xF9;                  //CRC校验数据输入寄存器

sfr       CRCDL = 0xFA;                  //CRC校验结果低字节寄存器

sfr       CRCDH = 0xFB;                  //CRC校验结果高字节寄存器

sfr       FSCR = 0xFC;                  //自编程控制寄存器

sfr       FSDR = 0xFD;                  //自编程数据寄存器

sfr       FSALR = 0xFE;                  //自编程低位地址寄存器

sfr       FSAHR = 0xFF;                  //自编程高位地址寄存器



//===================XRAM=============================================================

#define   P0PU           *((unsigned char xdata *)(0x40E1))          //端口上拉控制寄存器

#define   P1PU           *((unsigned char xdata *)(0x40E2))          //端口上拉控制寄存器

#define   P2PU           *((unsigned char xdata *)(0x40E3))          //端口上拉控制寄存器

#define   P3PU           *((unsigned char xdata *)(0x40E4))          //端口上拉控制寄存器

#define   P4PU           *((unsigned char xdata *)(0x40E5))          //端口上拉控制寄存器

#define   P5PU           *((unsigned char xdata *)(0x40E6))          //端口上拉控制寄存器

#define   P0OD           *((unsigned char xdata *)(0x40E9))          //端口开漏控制寄存器

#define   P1OD           *((unsigned char xdata *)(0x40EA))          //端口开漏控制寄存器

#define   P2OD           *((unsigned char xdata *)(0x40EB))          //端口开漏控制寄存器

#define   P3OD           *((unsigned char xdata *)(0x40EC))          //端口开漏控制寄存器

#define   P4OD           *((unsigned char xdata *)(0x40ED))          //端口开漏控制寄存器

#define   P5OD           *((unsigned char xdata *)(0x40EE))          //端口开漏控制寄存器

#define   P0DB           *((unsigned char xdata *)(0x40F1))          //P0数字滤波控制寄存器

#define   P1DB           *((unsigned char xdata *)(0x40F2))          //P1数字滤波控制寄存器

#define   P2DB           *((unsigned char xdata *)(0x40F3))          //P2数字滤波控制寄存器

#define   P4DB           *((unsigned char xdata *)(0x40F4))          //P4数字滤波控制寄存器

#define   EIPOL0         *((unsigned char xdata *)(0x4118))          //外部中断触发控制寄存器0

#define   EIPOL1         *((unsigned char xdata *)(0x4119))          //外部中断触发控制寄存器1

#define   EINT4SEL       *((unsigned char xdata *)(0x411A))          //外部中断4输入端口选择寄存器

#define   EINT5SEL       *((unsigned char xdata *)(0x411B))          //外部中断5输入端口选择寄存器

#define   TKCR           *((unsigned char xdata *)(0x4130))          //触摸按键控制寄存器

#define   TKCHSEL        *((unsigned char xdata *)(0x4131))          //触摸按键通道选择寄存器

#define   TKOSCCR        *((unsigned char xdata *)(0x4132))          //触摸独立振荡控制寄存器

#define   CTCCR          *((unsigned char xdata *)(0x4133))          //CTC模式控制寄存器

#define   TKINT          *((unsigned char xdata *)(0x4134))          //触摸中断控制寄存器

#define   TKTMRL         *((unsigned char xdata *)(0x4135))          //TKTMR低字节寄存器

#define   TKTMRH         *((unsigned char xdata *)(0x4136))          //TKTMR高字节寄存器

#define   TKDRL          *((unsigned char xdata *)(0x4137))          //TKDR低字节寄存器

#define   TKDRH          *((unsigned char xdata *)(0x4138))          //TKDR高字节寄存器

#define   TMRPLDL        *((unsigned char xdata *)(0x4139))          //TKTMR_PLOAD低字节寄存器

#define   TMRPLDH        *((unsigned char xdata *)(0x413A))          //TKTMR_PLOAD高字节寄存器

#define   LCDCRL         *((unsigned char xdata *)(0x413B))          //LCD控制寄存器低字节

#define   LCDCRH         *((unsigned char xdata *)(0x413C))          //LCD控制寄存器高字节

#define   FRASEL         *((unsigned char xdata *)(0x413D))          //LCD帧频选择寄存器

#define   LEDCR          *((unsigned char xdata *)(0x413E))          //LED控制寄存器

#define   DISCOM         *((unsigned char xdata *)(0x413F))          //LED扫描宽度选择寄存器

#define   LEDDZ          *((unsigned char xdata *)(0x4140))          //LED死区宽度寄存器

#define   BIGDRIVE       *((unsigned char xdata *)(0x4141))          //端口大驱动控制寄存器

#define   ADAN0          *((unsigned char xdata *)(0x4150))          //AD模拟输入端口使能控制寄存器0

#define   ADAN1          *((unsigned char xdata *)(0x4151))          //AD模拟输入端口使能控制寄存器1

#define   ADAN2          *((unsigned char xdata *)(0x4152))          //AD模拟输入端口使能控制寄存器2

#define   ADAN3          *((unsigned char xdata *)(0x4153))          //AD模拟输入端口使能控制寄存器3

#define   ADAN4          *((unsigned char xdata *)(0x4154))          //AD模拟输入端口使能控制寄存器4

#define   SEGCR0         *((unsigned char xdata *)(0x4155))          //SEG口使能控制寄存器0

#define   SEGCR1         *((unsigned char xdata *)(0x4156))          //SEG口使能控制寄存器1

#define   SEGCR2         *((unsigned char xdata *)(0x4157))          //SEG口使能控制寄存器2

#define   SEGCR3         *((unsigned char xdata *)(0x4158))          //SEG口使能控制寄存器3

#define   COMCR          *((unsigned char xdata *)(0x4159))          //COM口使能控制寄存器

#define   LCMCR0         *((unsigned char xdata *)(0x415A))          //映射端口控制寄存器0

#define   LCMCR1         *((unsigned char xdata *)(0x415B))          //映射端口控制寄存器1

#define   LCMCR2         *((unsigned char xdata *)(0x415C))          //映射端口控制寄存器2


#define   T5PWMOE        *((unsigned char xdata *)(0x41E2))          //定时器通道输出使能寄存器

#define   T5DCR1         *((unsigned char xdata *)(0x41E3))          //定时器死区控制寄存器1

#define   T5DCR2         *((unsigned char xdata *)(0x41E4))          //定时器死区控制寄存器2

#define   T5DR0L         *((unsigned char xdata *)(0x41E6))          //定时器周期寄存器低8位

#define   T5DR0H         *((unsigned char xdata *)(0x41E7))          //定时器周期寄存器高8位

#define   T5DR1L         *((unsigned char xdata *)(0x41E9))          //定时器通道1占空比寄存器低8位

#define   T5DR1H         *((unsigned char xdata *)(0x41EA))          //定时器通道1占空比寄存器高8位

#define   T5DR2L         *((unsigned char xdata *)(0x41EB))          //定时器通道2占空比寄存器低8位

#define   T5DR2H         *((unsigned char xdata *)(0x41EC))          //定时器通道2占空比寄存器高8位

#define   T5DR3L         *((unsigned char xdata *)(0x41ED))          //定时器通道3占空比寄存器低8位

#define   T5DR3H         *((unsigned char xdata *)(0x41EE))          //定时器通道3占空比寄存器高8位

#define   T5CR1          *((unsigned char xdata *)(0x41EF))          //定时器控制寄存器1

#define   T5DR4L         *((unsigned char xdata *)(0x41F1))          //定时器通道4占空比寄存器低8位

#define   T5DR4H         *((unsigned char xdata *)(0x41F2))          //定时器通道4占空比寄存器高8位

#define   T5DR5L         *((unsigned char xdata *)(0x41F3))          //定时器通道5占空比寄存器低8位

#define   T5DR5H         *((unsigned char xdata *)(0x41F4))          //定时器通道5占空比寄存器高8位

#define   T5DR6L         *((unsigned char xdata *)(0x41F5))          //定时器通道6占空比寄存器低8位

#define   T5DR6H         *((unsigned char xdata *)(0x41F6))          //定时器通道6占空比寄存器高8位

#define   T5CR2          *((unsigned char xdata *)(0x41F7))          //定时器控制寄存器2

#define   LED_COM0RAM0   *((unsigned char xdata *)(0X0800))

#define   LED_COM0RAM1   *((unsigned char xdata *)(0X0801))

#define   LCD_RAM0       *((unsigned char xdata *)(0X0800))

#define   LCD_RAM1       *((unsigned char xdata *)(0X0801))

#define   LCD_RAM2       *((unsigned char xdata *)(0X0802))

#define   LCD_RAM3       *((unsigned char xdata *)(0X0803))

#define   LCD_RAM4       *((unsigned char xdata *)(0X0804))

#define   LCD_RAM5       *((unsigned char xdata *)(0X0805))

#define   LCD_RAM6       *((unsigned char xdata *)(0X0806))

#define   LCD_RAM7       *((unsigned char xdata *)(0X0807))

#define   LCD_RAM8       *((unsigned char xdata *)(0X0808))

#define   LCD_RAM9       *((unsigned char xdata *)(0X0809))

#define   LCD_RAM10      *((unsigned char xdata *)(0X080A))

#define   LCD_RAM11      *((unsigned char xdata *)(0X080B))

#define   LCD_RAM12      *((unsigned char xdata *)(0X080C))

#define   LCD_RAM13      *((unsigned char xdata *)(0X080D))

#define   LCD_RAM14      *((unsigned char xdata *)(0X080E))

#define   LCD_RAM15      *((unsigned char xdata *)(0X080F))

#define   LCD_RAM16      *((unsigned char xdata *)(0X0810))

#define   LCD_RAM17      *((unsigned char xdata *)(0X0811))

#define   LCD_RAM18      *((unsigned char xdata *)(0X0812))

#define   LCD_RAM19      *((unsigned char xdata *)(0X0813))

#define   LCD_RAM20      *((unsigned char xdata *)(0X0814))

#define   LCD_RAM21      *((unsigned char xdata *)(0X0815))

#define   LCD_RAM22      *((unsigned char xdata *)(0X0816))

#define   LCD_RAM23      *((unsigned char xdata *)(0X0817))

#define   LCD_RAM24      *((unsigned char xdata *)(0X0818))

#define   LCD_RAM25      *((unsigned char xdata *)(0X0819))

#define   LCD_RAM26      *((unsigned char xdata *)(0X081A))

#define   LCD_RAM27      *((unsigned char xdata *)(0X081B))


//===================其他=============================================================
#define   NOP()            _nop_()




#define   SystemKeyCode       	 KEYCODE=0x3C;KEYCODE=0x02;KEYCODE=0xA0;
#define   FSCRKeyCode         	 KEYCODE=0x3C;KEYCODE=0x02;KEYCODE=0xA1;   //关闭FSCR写保护
#define   KeyCodeOff          	 KEYCODE=0x00;

//===================IRAM=============================================================

//LVD控制寄存器 LVICR
#define   LVDEN							0x80		//LVD使能
#define   LVDF							0x10		//LVD状态标志
#define   LVDSEL_2P0V 					0x00		//LVD电压2.0V
#define   LVDSEL_2P1V 					0x01		//LVD电压2.1V
#define   LVDSEL_2P2V 					0x02		//LVD电压2.2V
#define   LVDSEL_2P32V					0x03		//LVD电压2.32V
#define   LVDSEL_2P44V					0x04		//LVD电压2.44V
#define   LVDSEL_2P59V					0x05		//LVD电压2.59V
#define   LVDSEL_2P75V					0x06		//LVD电压2.75V
#define   LVDSEL_2P93V					0x07		//LVD电压2.93V
#define   LVDSEL_3P14V					0x08		//LVD电压3.14V
#define   LVDSEL_3P38V					0x09		//LVD电压3.38V
#define   LVDSEL_3P67V					0x0A		//LVD电压3.67V
#define   LVDSEL_4P0V 					0x0B		//LVD电压4.0V
#define   LVDSEL_4P4V 					0x0C		//LVD电压4.4V


//电源管理控制寄存器 PCON
#define   IDLE_Enable					0x01		//IDLE模式使能
#define   STOP_Enable					0x02		//STOP模式使能

//时钟控制寄存器 CKCON
#define   CPU_1T					  	0x00		//CPU运行周期1T
#define   CPU_2T					  	0x10		//CPU运行周期2T
#define   CPU_3T					  	0x20		//CPU运行周期3T
#define   CPU_4T					  	0x30		//CPU运行周期4T
#define   CPU_5T					  	0x40		//CPU运行周期5T
#define   CPU_6T					  	0x50		//CPU运行周期6T
#define   CPU_7T					  	0x60		//CPU运行周期7T
#define   CPU_8T					  	0x70		//CPU运行周期8T

//外部中断标志5寄存器 EIFLAG2
#define   EINT51IF						0x02
#define   EINT52IF						0x04
#define   EINT53IF						0x08
#define   EINT54IF						0x10
#define   EINT55IF						0x20
#define   EINT56IF						0x40
#define   EINT57IF						0x80

//预分频控制寄存器 FRECR
#define   WDT_BIT2CYCLE                	0X00        //溢出周期
#define   WDT_BIT4CYCLE                	0X01
#define   WDT_BIT8CYCLE                	0X02
#define   WDT_BIT16CYCLE               	0X03
#define   WDT_BIT32CYCLE               	0X04
#define   WDT_BIT64CYCLE               	0X05
#define   WDT_BIT128CYCLE              	0X06
#define   WDT_BIT256CYCLE              	0X07
#define   WDT_CNTCLR                   	0X08        //写入1 预分频计数器清0
#define   WDT_CLK_FX512                	0X00        //预分频器时钟选择
#define   WDT_CLK_FX256                	0X20
#define   WDT_CLK_FX128                	0X40
#define   WDT_CLK_FXLIRC               	0X60

//WDT控制寄存器 WDTCR

#define   WDTIFR                        0X01       	//WDT中断标志位
#define   WDTCLK_OSC                    0X00        //预分频器提供WDTCNT驱动时钟
#define   WDTCLK_LIRC_256               0X02        //LIRC/256作为WDTCNT驱动时钟
#define   WDTCLR                        0X20       	//WDT计数器清0
#define   WDTRSON_TMR                   0X00       	//WDT工作模式定时器模式
#define   WDTRSON_RST                   0X40       	//WDT复位打开
#define   WDTEN                         0X80       	//WDT使能

//WT控制寄存器 WTCR
#define   WTCLK_LXT                     0x00      	//WT时钟为LXT
#define   WTCLK_FX256                   0x01      	//WT时钟为fx/256
#define   WTCLK_FX512                   0x02      	//WT时钟为fx/512
#define   WTCLK_LIRC                    0x03      	//WT时钟为LIRC
#define   WTIN_DIV128                   0x00      	//WT中断间隔fwck/128
#define   WTIN_DIV8192                  0x04      	//WT中断间隔fwck/8192
#define   WTIN_DIV16384                 0x08      	//WT中断间隔fwck/16384
#define   WTIN_DIV16384_WTDR1           0x0C      	//WT中断间隔fwck/(16384*(WTDR + 1))
#define   WTIFR                         0x10      	//WT计数溢出
#define   WTCLR                         0x20      	//WT计数器清0
#define   WTEN                          0x80      	//WT使能

//端口P0方向控制寄存器 P0IO
#define   P07IO_Out  					0x80      	//P07口I/O方向输出
#define   P06IO_Out						0x40      	//P06口I/O方向输出
#define   P05IO_Out						0x20      	//P05口I/O方向输出
#define   P04IO_Out			  			0x10      	//P04口I/O方向输出
#define   P03IO_Out			  			0x08      	//P03口I/O方向输出
#define   P02IO_Out			  			0x04      	//P02口I/O方向输出
#define   P01IO_Out						0x02      	//P01口I/O方向输出
#define   P00IO_Out						0x01      	//P00口I/O方向输出
#define   P07IO_In  					0x00      	//P07口I/O方向输入
#define   P06IO_In						0x00      	//P06口I/O方向输入
#define   P05IO_In						0x00      	//P05口I/O方向输入
#define   P04IO_In			  			0x00      	//P04口I/O方向输入
#define   P03IO_In			  			0x00      	//P03口I/O方向输入
#define   P02IO_In			  			0x00      	//P02口I/O方向输入
#define   P01IO_In						0x00      	//P01口I/O方向输入
#define   P00IO_In						0x00      	//P00口I/O方向输入

//端口P1方向控制寄存器 P1IO
#define   P17IO_Out  					0x80      	//P17口I/O方向输出
#define   P16IO_Out						0x40      	//P16口I/O方向输出
#define   P15IO_Out						0x20      	//P15口I/O方向输出
#define   P14IO_Out			  			0x10        //P14口I/O方向输出
#define   P13IO_Out			  			0x08        //P13口I/O方向输出
#define   P12IO_Out			  			0x04        //P12口I/O方向输出
#define   P11IO_Out						0x02        //P11口I/O方向输出
#define   P10IO_Out						0x01        //P10口I/O方向输出
#define   P17IO_In  					0x00      	//P17口I/O方向输入
#define   P16IO_In						0x00      	//P16口I/O方向输入
#define   P15IO_In						0x00      	//P15口I/O方向输入
#define   P14IO_In			  			0x00        //P14口I/O方向输入
#define   P13IO_In			  			0x00        //P13口I/O方向输入
#define   P12IO_In			  			0x00        //P12口I/O方向输入
#define   P11IO_In						0x00        //P11口I/O方向输入
#define   P10IO_In						0x00        //P10口I/O方向输入

//端口P2方向控制寄存器 P2IO
#define   P27IO_Out  					0x80      	//P27口I/O方向输出
#define   P26IO_Out						0x40      	//P26口I/O方向输出
#define   P25IO_Out						0x20      	//P25口I/O方向输出
#define   P24IO_Out			  			0x10        //P24口I/O方向输出
#define   P23IO_Out			  			0x08        //P23口I/O方向输出
#define   P22IO_Out			  			0x04        //P22口I/O方向输出
#define   P21IO_Out						0x02        //P21口I/O方向输出
#define   P20IO_Out						0x01        //P20口I/O方向输出
#define   P27IO_In  					0x00      	//P27口I/O方向输入
#define   P26IO_In						0x00      	//P26口I/O方向输入
#define   P25IO_In						0x00      	//P25口I/O方向输入
#define   P24IO_In			  			0x00        //P24口I/O方向输入
#define   P23IO_In			  			0x00        //P23口I/O方向输入
#define   P22IO_In			  			0x00        //P22口I/O方向输入
#define   P21IO_In						0x00        //P21口I/O方向输入
#define   P20IO_In						0x00        //P20口I/O方向输入

//端口P3方向控制寄存器 P3IO
#define   P37IO_Out  					0x80      	//P37口I/O方向输出
#define   P36IO_Out						0x40      	//P36口I/O方向输出
#define   P35IO_Out						0x20      	//P35口I/O方向输出
#define   P34IO_Out			  			0x10        //P34口I/O方向输出
#define   P33IO_Out			  			0x08        //P33口I/O方向输出
#define   P32IO_Out			  			0x04        //P32口I/O方向输出
#define   P31IO_Out						0x02        //P31口I/O方向输出
#define   P30IO_Out						0x01        //P30口I/O方向输出
#define   P37IO_In  					0x00      	//P37口I/O方向输入
#define   P36IO_In						0x00      	//P36口I/O方向输入
#define   P35IO_In						0x00      	//P35口I/O方向输入
#define   P34IO_In			  			0x00        //P34口I/O方向输入
#define   P33IO_In			  			0x00        //P33口I/O方向输入
#define   P32IO_In			  			0x00        //P32口I/O方向输入
#define   P31IO_In						0x00        //P31口I/O方向输入
#define   P30IO_In						0x00        //P30口I/O方向输入

//定时器T0控制寄存器1 T0CR1
#define   T0_TCCLR                      0x01        //清除定时器
#define   T0OK                          0x02        //T0捕捉完成标示
#define   T0CF                          0x04        //T0定时器发生匹配中断
#define   T0_TIMER_MODE                 0x00        //T0定时器/计数器模式
#define   T0_CAPTURE_MODE               0x10        //T0捕捉模式
#define   T0_PWM_ONESHOT_MODE           0x20        //T0PWM单脉冲模式
#define   T0_PWM_REPEAT_MODE            0x30        //T0PWM多脉冲模式
#define   T0_PWMEN                      0x40        //T0PWM使能
#define   T0EN                          0x80        //T0使能

//定时器T0控制寄存器2 T0CR2
#define   T0OE_PWMEN                    0X01        //T0 PWM输出使能
#define   T0_CLKDIV1                    0X00        //T0时钟分频
#define   T0_CLKDIV2                    0X20
#define   T0_CLKDIV4                    0X40
#define   T0_CLKDIV8                    0X60
#define   T0_CLKDIV64                   0X80
#define   T0_CLKDIV512                  0XA0
#define   T0_CLKDIV2048                 0XC0
#define   T0_CLKEC0                     0XE0      	//外部时钟TCn
#define   T0_Period      			    0x00		//捕捉模式选择：测量输入信号周期
#define   T0_H_Level  				    0x08		//测量输入信号高电平
#define   T0_L_Level 					0x10      	//测量输入信号低电平
#define   T0PWME_Enable                 0x04      	//PWM输出波形不进行反相处理（默认输出低电平）
#define   T0PWME_Disable                0x00      	//PWM输出波形经过反相后输出
#define   T0CES_Faling                  0x02      	//外部时钟计数边沿选择:上升沿定时器/计数器计数值改变
#define   T0CES_Rising                  0x00      	//外部时钟计数边沿选择:下降沿定时器/计数器计数值改变


//定时器T1控制寄存器1 T1CR1
#define   T1_TCCLR                      0X01       	//清除定时器
#define   T1OK                          0X02       	//T1捕捉完成标示
#define   T1CF                          0X04       	//T1定时器发生匹配中断
#define   T1_TIMER_MODE                 0x00       	//T1定时器/计数器模式
#define   T1_CAPTURE_MODE               0x10       	//T1捕捉模式
#define   T1_PWM_ONESHOT_MODE           0x20       	//T1PWM单脉冲模式
#define   T1_PWM_REPEAT_MODE            0x30       	//T1PWM多脉冲模式
#define   T1_PWMEN                      0X40       	//T1PWM使能
#define   T1EN                          0X80       	//T1使能

//定时器T1控制寄存器2 T1CR2
#define   T1OE_PWMEN                    0X01       	//T1 PWM输出使能
#define   T1_CLKDIV1                    0X00       	//T1时钟分频
#define   T1_CLKDIV2                    0X20
#define   T1_CLKDIV4                    0X40
#define   T1_CLKDIV8                    0X60
#define   T1_CLKDIV64                   0X80
#define   T1_CLKDIV512                  0XA0
#define   T1_CLKDIV2048                 0XC0
#define   T1_CLKEC0                     0XE0        //T1时钟外部输入
#define   T1_Period      			    0x00		//捕捉模式选择：测量输入信号周期
#define   T1_H_Level  				    0x08		//测量输入信号高电平
#define   T1_L_Level 					0x10      	//测量输入信号低电平
#define   T1PWME_Enable                 0x04        //PWM输出波形不进行反相处理（默认输出低电平）
#define   T1PWME_Disable                0x00        //PWM输出波形经过反相后输出
#define   T1CES_Faling                  0x02      	//外部时钟计数边沿选择:上升沿定时器/计数器计数值改变
#define   T1CES_Rising                  0x00      	//外部时钟计数边沿选择:下降沿定时器/计数器计数值改变

//端口P4方向控制寄存器 P4IO
#define   P47IO_Out  					0x80       	//P47口I/O方向输出
#define   P46IO_Out						0x40       	//P46口I/O方向输出
#define   P45IO_Out						0x20       	//P45口I/O方向输出
#define   P44IO_Out			  			0x10       	//P44口I/O方向输出
#define   P43IO_Out			  			0x08       	//P43口I/O方向输出
#define   P42IO_Out			  			0x04       	//P42口I/O方向输出
#define   P41IO_Out						0x02       	//P41口I/O方向输出
#define   P40IO_Out						0x01       	//P40口I/O方向输出
#define   P47IO_In  					0x00       	//P47口I/O方向输入
#define   P46IO_In						0x00       	//P46口I/O方向输入
#define   P45IO_In						0x00       	//P45口I/O方向输入
#define   P44IO_In			  			0x00       	//P44口I/O方向输入
#define   P43IO_In			  			0x00       	//P43口I/O方向输入
#define   P42IO_In			  			0x00       	//P42口I/O方向输入
#define   P41IO_In						0x00       	//P41口I/O方向输入
#define   P40IO_In						0x00       	//P40口I/O方向输入

//中断控制寄存器0 IE0
#define   INT0E_Enable                  0x01      	//外部中断0使能
#define   INT1E_Enable                  0x02      	//外部中断1使能
#define   INT2E_Enable                  0x04      	//外部中断2使能
#define   INT3E_Enable                  0x08      	//外部中断3使能
#define   INT4E_Enable                  0x10      	//外部中断4使能
#define   INT5E_Enable                  0x20      	//外部中断5使能
#define   EA_Enable                     0x80      	//全局中断使能

//中断控制寄存器1 IE1
#define   LVDINT_Enable                 0x02        //LVD中断使能控制
#define   I2CINT_Enable                 0x04        //I2C中断使能控制
#define   UARTINT_Enable                0x08        //UART中断使能控制
#define   CCTINT_Enable                 0x10        //触摸中断使能控制
#define   TMR0INT_Enable                0x20        //TMR0中断使能控制
#define   TMR1INT_Enable                0x40        //TMR1中断使能控制
#define   TMR2INT_Enable                0x80        //TMR2中断使能控制

//中断控制寄存器2 IE2
#define   TMR5INT_Enable                0X01        //TMR5中断使能控制
#define   INT15INT_Enable               0X02        //归类1(ADC SPI)中断使能控制
#define   INT16INT_Enable               0X04        //归类2(WT WDT)中断使能控制
#define   INT17INT_Enable               0X08        //归类3(LED COM MDU)中断使能控制

//AD控制寄存器低字节 ADCCRL
#define   STBY                          0X80      	//AD模块使能控制位
#define   ADST                          0X40	  	//AD转换开始控制位
#define   REFSEL_VREF                   0X20	  	//AD基准电压选择:内部VREF模块提供参考电压
#define   REFSEL_VDD                    0X00	  	//AD基准电压选择:内部参考电压VDD
#define   ADSEL_AN0                     0X00      	//AD模拟输入通道选择位
#define   ADSEL_AN1                     0X01
#define   ADSEL_AN2                     0X02
#define   ADSEL_AN3                     0X03
#define   ADSEL_AN4                     0X04
#define   ADSEL_AN5                     0X05
#define   ADSEL_AN6                     0X06
#define   ADSEL_AN7                     0X07
#define   ADSEL_AN8                     0X08
#define   ADSEL_AN9                     0X09
#define   ADSEL_AN10                    0X0A
#define   ADSEL_AN11                    0X0B
#define   ADSEL_AN12                    0X0C
#define   ADSEL_AN13                    0X0D
#define   ADSEL_AN14                    0X0E
#define   ADSEL_AN15                    0X0F
#define   ADSEL_AN16                    0X10
#define   ADSEL_AN17                    0X11
#define   ADSEL_AN18                    0X12
#define   ADSEL_AN19                    0X13
#define   ADSEL_AN20                    0X14
#define   ADSEL_AN21                    0X15
#define   ADSEL_AN22                    0X16
#define   ADSEL_AN23                    0X17
#define   ADSEL_AN24                    0X18
#define   ADSEL_AN25                    0X19
#define   ADSEL_AN26                    0X1A
#define   ADSEL_AN27                    0X1B
#define   ADSEL_AN28                    0X1C
#define   ADSEL_VDD_Div4                0X1D

//AD控制寄存器高字节 ADCCRH
#define   ADCIFR                        0X80        //AD中断标志位
#define   ADFLAG                        0X40        //A/D转换操作状态
#define   ADCVREFSL_5V                 	0X00        //AD内部VREF选择位
#define   ADCVREFSL_4V                  0X10
#define   ADCVREFSL_3V                  0X20
#define   ADCVREFSL_2V                  0X30
#define   ADC_LSB                       0X04        //AD转换结果保存格式:右对齐
#define   ADC_MSB			            0X00		//左对齐
#define   ADCKSELFX_DIV1                0X00        //AD转换时钟选择控制位fsys
#define   ADCKSELFX_DIV2                0X01        //fsys/2
#define   ADCKSELFX_DIV4                0X02        //fsys/4
#define   ADCKSELFX_DIV8                0X03        //fsys/8

//端口P5方向控制寄存器 P5IO
#define   P55IO_Out			  			0x10        //P55口I/O方向输出
#define   P54IO_Out			  			0x10        //P54口I/O方向输出
#define   P53IO_Out			  			0x08        //P53口I/O方向输出
#define   P52IO_Out			  			0x04        //P52口I/O方向输出
#define   P51IO_Out						0x02        //P51口I/O方向输出
#define   P50IO_Out						0x01        //P50口I/O方向输出
#define   P55IO_In			  			0x00        //P55口I/O方向输入
#define   P54IO_In			  			0x00        //P54口I/O方向输入
#define   P53IO_In			  			0x00        //P53口I/O方向输入
#define   P52IO_In			  			0x00        //P52口I/O方向输入
#define   P51IO_In						0x00        //P51口I/O方向输入
#define   P50IO_In						0x00        //P50口I/O方向输入


//定时器T2控制寄存器1 T2CR1
#define   T2_TCCLR                      0X01       	//清除定时器
#define   T2OK                          0X02       	//T2捕捉完成标示
#define   T2CF                          0X04       	//T2定时器发生匹配中断
#define   T2_TIMER_MODE                 0x00       	//T2定时器/计数器模式
#define   T2_CAPTURE_MODE               0x10       	//T2捕捉模式
#define   T2_PWM_ONESHOT_MODE           0x20       	//T2PWM单脉冲模式
#define   T2_PWM_REPEAT_MODE            0x30       	//T2PWM多脉冲模式
#define   T2_PWMEN                      0X40       	//T2PWM使能
#define   T2EN                          0X80       	//T2使能

//定时器T2控制寄存器2 T2CR2
#define   T2OE_PWMEN                    0X01        //T2_PWM输出使能
#define   T2_CLKDIV1                    0X00        //T2时钟分频
#define   T2_CLKDIV2                    0X20
#define   T2_CLKDIV4                    0X40
#define   T2_CLKDIV8                    0X60
#define   T2_CLKDIV64                   0X80
#define   T2_CLKDIV512                  0XA0
#define   T2_CLKDIV2048                 0XC0
#define   T2_CLKEC0                     0XE0
#define   T2_Period      			    0x00		//捕捉模式选择：测量输入信号周期
#define   T2_H_Level  				    0x08		//测量输入信号高电平
#define   T2_L_Level 					0x10      	//测量输入信号低电平
#define   T2PWME_Enable                 0x04        //PWM输出波形不进行反相处理（默认输出低电平）
#define   T2PWME_Disable                0x00        //PWM输出波形经过反相后输出
#define   T2CES_Faling                  0x02      	//外部时钟计数边沿选择:上升沿定时器/计数器计数值改变
#define   T2CES_Rising                  0x00      	//外部时钟计数边沿选择:下降沿定时器/计数器计数值改变

//外部中断标志4寄存器 EIFLAG1
#define   EINT40IF						0x01		//外部中断40标志位
#define   EINT41IF						0x02        //外部中断41标志位
#define   EINT42IF						0x04        //外部中断42标志位
#define   EINT43IF						0x08        //外部中断43标志位
#define   EINT44IF						0x10        //外部中断44标志位
#define   EINT45IF						0x20		//外部中断45标志位
#define   EINT46IF						0x40        //外部中断46标志位
#define   EINT47IF						0x80        //外部中断47标志位

//UART0控制寄存器1 UART0CR1
#define   UART0_PCEN                   	0X20        //奇偶校验控制使能
#define   UART0_PS                     	0X10        //奇偶校验选择
#define   UART0_M_9BIT                 	0X08        //选择帧数据长度9 bit
#define   UART0_M_8BIT                 	0X00        //选择帧数据长度8 bit
#define   UART0_RWU                    	0X04        //静默模式使能
#define   UART0_RWUF                   	0X02        //接收唤醒标志
#define   UART0_PIEN                   	0X01        //校验中断使能

//UART0控制寄存器2 UART0CR2
#define   UART0_EN						0x02		//UART模块使能
#define   UART0_RX_EN					0x04		//接收使能
#define   UART0_TX_EN					0x08		//发送使能
#define   UART0_WAKEIE					0x10		//UART在STOP模式唤醒中断使能
#define   UART0_RIEN					0x20		//接收中断使能
#define   UART0_TCIEN					0x40		//发送完成中断使能
#define   UART0_TIEN					0x80		//发送中断使能

//UART0控制寄存器 UART0CR3
#define   UART0_R8				    	0x01		//接收数据位8
#define   UART0_T8  			    	0x02		//发送数据位8
#define   UART0_STOP_2BIT  				0x04		//2个停止位
#define   UART0_STOP_1BIT  				0x00		//1个停止位
#define   UART0_ADDR3			    	0x80		//UART从机地址
#define   UART0_ADDR2  			    	0x40
#define   UART0_ADDR1  			    	0x20
#define   UART0_ADDR0  			    	0x10

//UART0状态寄存器 UART0SR
#define   UART0_PE_ERR					0x01        //奇偶检验错误
#define   UART0_FE_ERR					0x02        //帧错误
#define   UART0_OVR_ERR					0x04        //溢出错误
#define   UART0_RST						0x08        //UART软件复位
#define   UART0_WAKE					0x10        //UART唤醒中断标志位
#define   UART0_RX_NE					0x20        //接收数据寄存器非空
#define   UART0_TC_OVER					0x40        //发送完成
#define   UART0_TXE_NUL					0x80        //发送数据寄存器空

//外部中断标志0寄存器 EIFLAG0
#define   EINT0IF                   	0X01        //外部中断0中断标志位
#define   EINT1IF                   	0X02        //外部中断1中断标志位
#define   EINT2IF                   	0X04        //外部中断2中断标志位
#define   EINT3IF                   	0X08        //外部中断3中断标志位

//UART1控制寄存器1 UART1CR1
#define   UART1_PCEN                   	0X20        //奇偶校验控制使能
#define   UART1_PS                     	0X10        //奇偶校验选择
#define   UART1_M_9BIT                 	0X08        //选择帧数据长度9 bit
#define   UART1_M_8BIT                 	0X00        //选择帧数据长度8 bit
#define   UART1_RWU                    	0X04        //静默模式使能
#define   UART1_RWUF                   	0X02        //接收唤醒标志
#define   UART1_PIEN                   	0X01        //校验中断使能

//UART1控制寄存器2 UART1CR2
#define   UART1_EN						0x02		//UART模块使能
#define   UART1_RX_EN					0x04		//接收使能
#define   UART1_TX_EN					0x08		//发送使能
#define   UART1_WAKEIE					0x10		//UART在STOP模式唤醒中断使能
#define   UART1_RIEN					0x20		//接收中断使能
#define   UART1_TCIEN					0x40		//发送完成中断使能
#define   UART1_TIEN					0x80		//发送中断使能

//UART1控制寄存器 UART1CR3
#define   UART1_R8				    	0x01		//接收数据位8
#define   UART1_T8  			    	0x02		//发送数据位8
#define   UART1_STOP_2BIT  				0x04		//2个停止位
#define   UART1_STOP_1BIT  				0x00		//1个停止位
#define   UART1_ADDR3			    	0x80		//UART从机地址
#define   UART1_ADDR2  			    	0x40
#define   UART1_ADDR1  			    	0x20
#define   UART1_ADDR0  			    	0x10

//UART1状态寄存器 UART1SR
#define   UART1_PE_ERR					0x01        //奇偶检验错误
#define   UART1_FE_ERR					0x02        //帧错误
#define   UART1_OVR_ERR					0x04        //溢出错误
#define   UART1_RST						0x08        //UART软件复位
#define   UART1_WAKE					0x10        //UART唤醒中断标志位
#define   UART1_RX_NE					0x20        //接收数据寄存器非空
#define   UART1_TC_OVER					0x40        //发送完成
#define   UART1_TXE_NUL					0x80        //发送数据寄存器空

//系统时钟控制寄存器 OSCCR
#define   SYSCLK_DIV2					0x00     	//系统时钟分频
#define   SYSCLK_DIV4					0x01
#define   SYSCLK_DIV8					0x02
#define   SYSCLK_DIV16					0x03
#define   SYSCLK_DIVDIS					0x00		//不分频
#define   SYSCLK_DIVEN					0x04		//使能系统分频
#define   SYSCLK_HIRCEN					0x10		//HIRC使能
#define   SYSCLK_HXTEN					0x20		//HXTE使能
#define   SYSCLK_LIRCEN					0x40		//LIRC使能
#define   SYSCLK_LXTEN					0x80		//LXT使能

//UART2控制寄存器1 UART2CR1
#define   UART2_PCEN                   	0X20        //奇偶校验控制使能
#define   UART2_PS                     	0X10        //奇偶校验选择
#define   UART2_M_9BIT                 	0X08        //选择帧数据长度9 bit
#define   UART2_M_8BIT                 	0X00        //选择帧数据长度8 bit
#define   UART2_RWU                    	0X04        //静默模式使能
#define   UART2_RWUF                   	0X02        //接收唤醒标志
#define   UART2_PIEN                   	0X01        //校验中断使能

//UART2控制寄存器2 UART2CR2
#define   UART2_EN						0x02		//UART模块使能
#define   UART2_RX_EN					0x04		//接收使能
#define   UART2_TX_EN					0x08		//发送使能
#define   UART2_WAKEIE					0x10		//UART在STOP模式唤醒中断使能
#define   UART2_RIEN					0x20		//接收中断使能
#define   UART2_TCIEN					0x40		//发送完成中断使能
#define   UART2_TIEN					0x80		//发送中断使能

//UART2控制寄存器3 UART2CR3
#define   UART2_R8						0x01		//接收数据位8
#define   UART2_T8  					0x02		//发送数据位8
#define   UART2_STOP_2BIT  				0x04		//2个停止位
#define   UART2_STOP_1BIT  				0x00		//1个停止位
#define   UART2_ADDR3			    	0x80		//UART从机地址
#define   UART2_ADDR2  			    	0x40
#define   UART2_ADDR1  			    	0x20
#define   UART2_ADDR0  			    	0x10

//UART2状态寄存器 UART2SR
#define   UART2_PE_ERR					0x01		//奇偶检验错误
#define   UART2_FE_ERR					0x02		//帧错误
#define   UART2_OVR_ERR					0x04		//溢出错误
#define   UART2_RST						0x08		//UART软件复位
#define   UART2_WAKE					0x10		//UART唤醒中断标志位
#define   UART2_RX_NE					0x20		//接收数据寄存器非空
#define   UART2_TC_OVER					0x40		//发送完成
#define   UART2_TXE_NUL					0x80		//发送数据寄存器空

//程序状态寄存器 PSW
#define   PSW_P							0x01        //奇偶标志
#define   PSW_F1						0x02        //用户可定义标志
#define   PSW_OV						0x04        //溢出标志
#define   PSW_RS0						0x00        //寄存器0：0x00-0x07
#define   PSW_RS1						0x08        //寄存器0：0x08-0x0F
#define   PSW_RS2		  				0x10        //寄存器0：0x10-0x17
#define   PSW_RS3						0x18        //寄存器0：0x18-0x1F
#define   PSW_F0		  				0x20        //通用用户可定义标志
#define   PSW_AC						0x40        //辅助进位标志
#define   PSW_CY						0x80        //进位标志

//I2C状态寄存器1 I2CSR1
#define   GCALL							0x80        //主控模式：该位代表是否从从机接收ACK信号
#define   BTF							0x40        //字节发送结束标志位
#define   STOPF							0x20        //STOP条件检测标志位
#define   ADDR							0x10        //地址已被发送(主模式)/地址匹配(从模式)
#define   ARLO							0x08        //仲裁失败（主模式）
#define   BUSBUSY						0x04        //总线忙标志位
#define   TRA							0x02        //发送器/接收器状态标志位
#define   RXACK							0x01        //显示ACK信号状态

//I2C状态寄存器2 I2CSR2
#define   I2CTXE						0x80       	//数据寄存器为空(发送时)
#define   I2CRXNE						0x40       	//数据寄存器非空(接收时)
#define   STARTF						0x08       	//起始条件检测标志位
#define   I2CIFR						0x04       	//I2C中断标志位
#define   I2COVR						0x02       	//溢出错误标志位
#define   NO_ACK						0x01       	//未接收到应答信号标志位

//LVR控制寄存器 LVRCR
#define   LVRSEL_1P9V 					0x00		//LVR1.9V
#define   LVRSEL_2P0V 					0x01		//LVR2.0V
#define   LVRSEL_2P1V 					0x02		//LVR2.1V
#define   LVRSEL_2P2V 					0x03		//LVR2.2V
#define   LVRSEL_2P32V					0x04		//LVR2.32V
#define   LVRSEL_2P44V					0x05		//LVR2.44V
#define   LVRSEL_2P59V					0x06		//LVR2.59V
#define   LVRSEL_2P75V					0x07		//LVR2.75V
#define   LVRSEL_2P93V					0x08		//LVR2.93V
#define   LVRSEL_3P14V					0x09		//LVR3.14V
#define   LVRSEL_3P38V					0x0A		//LVR3.38V
#define   LVRSEL_3P67V					0x0B		//LVR3.67V
#define   LVRSEL_4P0V 					0x0C		//LVR4.0V
#define   LVRSEL_4P4V 					0x0D		//LVR4.4V
#define   LVREN							0x80		//LVR使能

//I2C控制寄存器 I2CCR1
#define   I2CRST  						0x80       	//软件复位
#define   I2CEN   						0x40       	//I2C使能控制位
#define   TXDLYENB   					0x20       	//使能I2CSDHR 寄存器
#define   IICIE   			  			0x10       	//中断使能位
#define   ACKEN   			  			0x08       	//应答使能
#define   MODE    			  			0x04       	//I2C 操作模式选择控制位
#define   STOP    						0x02       	//发送STOP信号控制位
#define   START   						0x01       	//发送START信号控制位

//SPI控制寄存器1 SPICR1
#define   SPIEN							0x80        //SPI使能控制位
#define   DIR_MSB                       0x40        //SPI数据帧格式：先发送高字节
#define   DIR_LSB                       0x00        //SPI数据帧格式：先发送低字节
#define   MSTR 							0x20        //SPI主从模式选择
#define   CPOL_HIGH                     0x10        //SPI管脚空闲状态SCK保持1
#define   CPOL_LOW                      0x00        //SPI管脚空闲状态SCK保持0
#define   CPHA_1EDGE                    0x00        //SCK周期的第一个沿采集数据
#define   CPHA_2EDGE                    0x08        //SCK周期的第二个沿采集数据
#define   SPIBR_DIV4 					0x00        //SPI工作时钟选择
#define   SPIBR_DIV16 					0x01
#define   SPIBR_DIV64 					0x02
#define   SPIBR_DIV128 					0x03
#define   SPIBR_DIV2 					0x04
#define   SPIBR_DIV8 					0x05
#define   SPIBR_DIV32 					0x06

//SPI控制寄存器2 SPICR2
#define   SPITXIE 						0x80       	//发送缓冲空中断使能
#define   SPIRXIE 						0x40       	//接收缓冲非空中断使能
#define   SPIERRIE						0x20       	//错误中断使能
#define   SPIBUSY 			  			0x10       	//总线忙标志
#define   SPIMODF 			  			0x08       	//模式错误标志

//SPI状态寄存器 SPISR
#define   SPIIFR 						0x80       	//SPI中断标志位
#define   SPIOVR    					0x40       	//溢出标志位
#define   SS_HIGH						0x20       	//NSS引脚状态标志
#define   FXCH   			  			0x08       	//SPI端口控制位
#define   SSENA  			  			0x04       	//NSS引脚控制位
#define   SPITXE    					0x02       	//发送缓冲区空标志
#define   SPIRXNE   					0x01       	//接收缓冲区空标志

//页保护控制寄存器 FSCR1
#define   FLASH0 						0x00       	//无页保护
#define   FLASH1    			  		0x01       	//地址 0x0000~0x07FF 保护
#define   FLASH2    			  		0x02       	//地址 0x0000~0x0BFF 保护
#define   FLASH3    			  		0x03       	//地址 0x0000~0x0FFF 保护
#define   FLASH4    			  		0x04       	//地址 0x0000~0x13FF 保护
#define   FLASH5    			  		0x05       	//地址 0x0000~0x17FF 保护
#define   FLASH6    			  		0x06       	//地址 0x0000~0x1BFF 保护
#define   FLASH7    			  		0x07       	//地址 0x0000~0x1FFF 保护
#define   FLASH8    			  		0x08       	//地址 0x0000~0x23FF 保护
#define   FLASH9    			  		0x09       	//地址 0x0000~0x27FF 保护
#define   FLASH10   			  		0x0A       	//地址 0x0000~0x2BFF 保护
#define   FLASH11   			  		0x0B       	//地址 0x0000~0x2FFF 保护
#define   FLASH12   			  		0x0C       	//地址 0x0000~0x33FF 保护
#define   FLASH13   			  		0x0D       	//地址 0x0000~0x37FF 保护
#define   FLASH14   			  		0x0E       	//地址 0x0000~0x3BFF 保护
#define   FLASH15   			  		0x0F       	//地址 0x0000~0x3FFF 保护
#define   FLASH16   			  		0x10       	//地址 0x0000~0x43FF 保护
#define   FLASH17   			  		0x11       	//地址 0x0000~0x47FF 保护
#define   FLASH18   			  		0x12       	//地址 0x0000~0x4BFF 保护
#define   FLASH19   			  		0x13       	//地址 0x0000~0x4FFF 保护
#define   FLASH20   			  		0x14       	//地址 0x0000~0x53FF 保护
#define   FLASH21   			  		0x15       	//地址 0x0000~0x57FF 保护
#define   FLASH22   			  		0x16       	//地址 0x0000~0x5BFF 保护
#define   FLASH23   			  		0x17       	//地址 0x0000~0x5FFF 保护
#define   FLASH24   			  		0x18       	//地址 0x0000~0x63FF 保护
#define   FLASH25   			  		0x19       	//地址 0x0000~0x67FF 保护
#define   FLASH26   			  		0x1A       	//地址 0x0000~0x6BFF 保护
#define   FLASH27   			  		0x1B       	//地址 0x0000~0x6FFF 保护
#define   FLASH28   			  		0x1C       	//地址 0x0000~0x73FF 保护
#define   FLASH29   			  		0x1D       	//地址 0x0000~0x77FF 保护
#define   FLASH30   			  		0x1E       	//地址 0x0000~0x7BFF 保护
#define   FLASH31   			  		0x1F       	//地址 0x0000~0x7FFF 保护
#define   FLASH32   			  		0x20       	//地址 0x0000~0x83FF 保护
#define   FLASH33   			  		0x21       	//地址 0x0000~0x87FF 保护
#define   FLASH34   			  		0x22       	//地址 0x0000~0x8BFF 保护
#define   FLASH35   			  		0x23       	//地址 0x0000~0x8FFF 保护
#define   FLASH36   			  		0x24       	//地址 0x0000~0x93FF 保护
#define   FLASH37   			  		0x25       	//地址 0x0000~0x97FF 保护
#define   FLASH38   			  		0x26       	//地址 0x0000~0x9BFF 保护
#define   FLASH39   			  		0x27       	//地址 0x0000~0x9FFF 保护
#define   FLASH40   			  		0x28       	//地址 0x0000~0xA3FF 保护
#define   FLASH41   			  		0x29       	//地址 0x0000~0xA7FF 保护
#define   FLASH42   			  		0x2A       	//地址 0x0000~0xABFF 保护
#define   FLASH43   			  		0x2B       	//地址 0x0000~0xAFFF 保护
#define   FLASH44   			  		0x2C       	//地址 0x0000~0xB3FF 保护
#define   FLASH45   			  		0x2D       	//地址 0x0000~0xB7FF 保护
#define   FLASH46   			  		0x2E       	//地址 0x0000~0xBBFF 保护
#define   FLASH47   			  		0x2F       	//地址 0x0000~0xBFFF 保护
#define   FLASH48   			  		0x30       	//地址 0x0000~0xC3FF 保护
#define   FLASH49   			  		0x31       	//地址 0x0000~0xC7FF 保护
#define   FLASH50   			  		0x32       	//地址 0x0000~0xCBFF 保护
#define   FLASH51   			  		0x33       	//地址 0x0000~0xCFFF 保护
#define   FLASH52   			  		0x34       	//地址 0x0000~0xD3FF 保护
#define   FLASH53   			  		0x35       	//地址 0x0000~0xD7FF 保护
#define   FLASH54   			  		0x36       	//地址 0x0000~0xDBFF 保护
#define   FLASH55   			  		0x37       	//地址 0x0000~0xDFFF 保护
#define   FLASH56   			  		0x38       	//地址 0x0000~0xE3FF 保护
#define   FLASH57   			  		0x39       	//地址 0x0000~0xE7FF 保护
#define   FLASH58   			  		0x3A       	//地址 0x0000~0xEBFF 保护
#define   FLASH59   			  		0x3B       	//地址 0x0000~0xEFFF 保护
#define   FLASH60   			  		0x3C       	//地址 0x0000~0xF3FF 保护
#define   FLASH61   			  		0x3D       	//地址 0x0000~0xF7FF 保护
#define   FLASH62   			  		0x3E       	//地址 0x0000~0xFBFF 保护
#define   FLASH63   			  		0x3F       	//地址 0x0000~0xFFFF 保护

//控制寄存器 MDUC
#define   MUL_UNSIGN 					0x00       	//乘法运算模式（无符号）
#define   MUL_SIGN 						0x08       	//乘法运算模式（带符号）
#define   MUL_ADD_UNSIGN 				0x40       	//乘加运算模式（无符号）
#define   MUL_ADD_SIGN 					0x48       	//乘加运算模式（带符号）
#define   DIV_UNSIGN 					0x80       	//除法运算模式（无符号）
#define   DIV_SIGN 						0xC0       	//除法运算模式（带符号）
#define   MDUIF   			  			0x10       	//MDU中断标志位
#define   MACOF    			  			0x04       	//乘加运算结果（累加值）的上溢标志
#define   MACSF    						0x02       	//乘加结果（累加值）的符号标志
#define   DIVST   						0x01       	//开始除法运算/ 正在除法运算

//复位标志寄存器 RSTFR
#define   RSTPORF 						0x80        //上电复位标志位
#define   RSTEXTRF						0x40        //外部复位标志位
#define   RSTWDTRF						0x20        //看门狗复位标志位
#define   RSTLVRF 			    		0x10        //低压复位标志位

//OPA控制寄存器 OPACR
#define   OPAOUT						0x80		//校准模式运放输出状态位:正端电压高于负端电压
#define   COS_DISABLE					0x00		//模块关闭
#define   COS_CMP 						0x10		//使能CMP功能，P44，P45为模拟口P43为数字口
#define   COS_OPA 						0x20		//使能OPA功能，P44，P45，P43均为模拟功能

//唤醒时钟控制寄存器 SYSCR
#define   WKTIME_2 						0x00        //STOP模式唤醒时间选择位Twakeup=（128+2）* Tsys
#define   WKTIME_4 			    		0x01        //Twakeup=（128+4）* Tsys
#define   WKTIME_8 						0x02        //Twakeup=（128+8）* Tsys
#define   WKTIME_16 	  	    		0x03        //Twakeup=（128+16）* Tsys
#define   WKTIME_32 	  	    		0x04        //Twakeup=（128+32）* Tsys
#define   WKTIME_64 	  	    		0x05        //Twakeup=（128+64）* Tsys
#define   WKTIME_128 					0x06        //Twakeup=（128+128）* Tsys
#define   WKTIME_256 					0x07        //Twakeup=（128+256）* Tsys
#define   WKTIME_512 		    		0x08        //Twakeup=（128+512）* Tsys
#define   WKTIME_1024 	        		0x09        //Twakeup=（128+1024）* Tsys
#define   WKTIME_2048 		    		0x0A        //Twakeup=（128+2048）* Tsys
#define   WKTIME_4096 	        		0x0B        //Twakeup=（128+4096）* Tsys
#define   WKTIME_8192 	        		0x0C        //Twakeup=（128+8192）* Tsys
#define   WKTIME_16384	        		0x0D        //Twakeup=（128+16384）* Tsys
#define   WKTIME_32768		    		0x0E        //Twakeup=（128+32768）* Tsys
#define   WKTIME_65536		    		0x0F        //Twakeup=（128+65536）* Tsys

//系统时钟源控制寄存器 CKCR
#define   CPUCLK_HIRC					0x00		//选择HIRC作为主时钟
#define   CPUCLK_HXT					0x01		//选择HXT作为主时钟
#define   CPUCLK_LIRC					0x02		//选择LIRC作为主时钟
#define   CPUCLK_LXT					0x03		//选择LXT作为主时钟
#define   HIRCF							0x10		//HIRC作为系统时钟标志位
#define   HXTF							0x20		//HXTF作为系统时钟标志位
#define   LIRCF							0x40		//LIRC作为系统时钟标志位
#define   LXTF							0x80		//LXT作为系统时钟标志位

//系统时钟控制寄存器1 OSCCR1
#define   HXT_STBF                      0x01     	//HXT振荡稳定标志位
#define   LXT_STBF                      0x02     	//外部LXT振荡稳定表示
#define   LXT_QUICKUP                   0x08     	//外部LXT振荡使能
#define   PAD_SEL                       0x80     	//外部振荡端口复用使能控制位

//外部晶振稳定时间检测寄存器 OSCTS
#define   OSCTS0  						0x00       	//振荡稳定时间选择2^8/fx
#define   OSCTS1						0x01       	//2^9/fx
#define   OSCTS2			    		0x02       	//2^10/fx
#define   OSCTS3			  			0x03       	//2^11/fx
#define   OSCTS4			  			0x04       	//2^12/fx
#define   OSCTS5			  			0x05       	//2^13/fx
#define   OSCTS6						0x06       	//2^14/fx
#define   OSCTS7						0x07       	//2^15/fx
#define   OSCTS8						0x08       	//2^16/fx
#define   OSCTS9						0x09       	//2^17/fx
#define   OSCTS10						0x0A       	//2^18/fx

//自编程控制寄存器 FSCR
#define   EE_EN							0x20       	//EEPROM使能位
#define   EE_WR			  				0x10       	//EE写控制位
#define   EE_RD			  				0x08       	//EE读控制位
#define   EE_ER			  				0x04       	//EE擦控制位
#define   INS_ER_EH						0x02       	//自编程页擦除使能
#define   INS_WR_EH						0x01       	//自编程单字节写使能

//===================XRAM=============================================================
//端口上拉控制寄存器 P0PU
#define   P07PU_Enable  				0x80       	//P07上拉电阻使能
#define   P06PU_Enable					0x40       	//P06上拉电阻使能
#define   P05PU_Enable					0x20       	//P05上拉电阻使能
#define   P04PU_Enable			  		0x10       	//P04上拉电阻使能
#define   P03PU_Enable			  		0x08       	//P03上拉电阻使能
#define   P02PU_Enable			  		0x04       	//P02上拉电阻使能
#define   P01PU_Enable					0x02       	//P01上拉电阻使能
#define   P00PU_Enable					0x01       	//P00上拉电阻使能

//端口上拉控制寄存器 P1PU
#define   P17PU_Enable  				0x80       	//P17上拉电阻使能
#define   P16PU_Enable					0x40       	//P16上拉电阻使能
#define   P15PU_Enable					0x20       	//P15上拉电阻使能
#define   P14PU_Enable			  		0x10       	//P14上拉电阻使能
#define   P13PU_Enable			  		0x08       	//P13上拉电阻使能
#define   P12PU_Enable			  		0x04       	//P12上拉电阻使能
#define   P11PU_Enable					0x02       	//P11上拉电阻使能
#define   P10PU_Enable					0x01       	//P10上拉电阻使能

//端口上拉控制寄存器 P2PU
#define   P27PU_Enable  				0x80       	//P27上拉电阻使能
#define   P26PU_Enable					0x40       	//P26上拉电阻使能
#define   P25PU_Enable					0x20       	//P25上拉电阻使能
#define   P24PU_Enable			  		0x10       	//P24上拉电阻使能
#define   P23PU_Enable			  		0x08       	//P23上拉电阻使能
#define   P22PU_Enable			  		0x04       	//P22上拉电阻使能
#define   P21PU_Enable					0x02       	//P21上拉电阻使能
#define   P20PU_Enable					0x01       	//P20上拉电阻使能

//端口上拉控制寄存器 P3PU
#define   P37PU_Enable  				0x80       	//P37上拉电阻使能
#define   P36PU_Enable					0x40       	//P36上拉电阻使能
#define   P35PU_Enable					0x20       	//P35上拉电阻使能
#define   P34PU_Enable			  		0x10       	//P34上拉电阻使能
#define   P33PU_Enable			  		0x08       	//P33上拉电阻使能
#define   P32PU_Enable			  		0x04       	//P32上拉电阻使能
#define   P31PU_Enable					0x02       	//P31上拉电阻使能
#define   P30PU_Enable					0x01       	//P30上拉电阻使能

//端口上拉控制寄存器 P4PU
#define   P47PU_Enable  				0x80       	//P47上拉电阻使能
#define   P46PU_Enable					0x40       	//P46上拉电阻使能
#define   P45PU_Enable					0x20       	//P45上拉电阻使能
#define   P44PU_Enable			  		0x10       	//P44上拉电阻使能
#define   P43PU_Enable			  		0x08       	//P43上拉电阻使能
#define   P42PU_Enable			  		0x04       	//P42上拉电阻使能
#define   P41PU_Enable					0x02       	//P41上拉电阻使能
#define   P40PU_Enable					0x01       	//P40上拉电阻使能

//端口上拉控制寄存器 P5PU
#define   P55PU_Enable					0x20       	//P55上拉电阻使能
#define   P54PU_Enable			  		0x10       	//P54上拉电阻使能
#define   P53PU_Enable			  		0x08       	//P53上拉电阻使能
#define   P52PU_Enable			  		0x04       	//P52上拉电阻使能
#define   P51PU_Enable					0x02       	//P51上拉电阻使能
#define   P50PU_Enable					0x01       	//P50上拉电阻使能

//漏极开路输出控制寄存器 P0OD
#define   P07OD_Enable  				0x80       	//P07漏极开路输出使能
#define   P06OD_Enable					0x40       	//P06漏极开路输出使能
#define   P05OD_Enable					0x20       	//P05漏极开路输出使能
#define   P04OD_Enable			  		0x10       	//P04漏极开路输出使能
#define   P03OD_Enable			  		0x08       	//P03漏极开路输出使能
#define   P02OD_Enable			  		0x04       	//P02漏极开路输出使能
#define   P01OD_Enable					0x02       	//P01漏极开路输出使能
#define   P00OD_Enable					0x01       	//P00漏极开路输出使能

//漏极开路输出控制寄存器 P1OD
#define   P17OD_Enable  				0x80       	//P17漏极开路输出使能
#define   P16OD_Enable					0x40       	//P16漏极开路输出使能
#define   P15OD_Enable					0x20       	//P15漏极开路输出使能
#define   P14OD_Enable			  		0x10       	//P14漏极开路输出使能
#define   P13OD_Enable			  		0x08       	//P13漏极开路输出使能
#define   P12OD_Enable			  		0x04       	//P12漏极开路输出使能
#define   P11OD_Enable					0x02       	//P11漏极开路输出使能
#define   P10OD_Enable					0x01       	//P10漏极开路输出使能

//漏极开路输出控制寄存器 P2OD
#define   P27OD_Enable  				0x80       	//P27漏极开路输出使能
#define   P26OD_Enable					0x40       	//P26漏极开路输出使能
#define   P25OD_Enable					0x20       	//P25漏极开路输出使能
#define   P24OD_Enable			  		0x10       	//P24漏极开路输出使能
#define   P23OD_Enable			  		0x08       	//P23漏极开路输出使能
#define   P22OD_Enable			  		0x04       	//P22漏极开路输出使能
#define   P21OD_Enable					0x02       	//P21漏极开路输出使能
#define   P20OD_Enable					0x01       	//P20漏极开路输出使能

//漏极开路输出控制寄存器 P3OD
#define   P37OD_Enable  				0x80       	//P37漏极开路输出使能
#define   P36OD_Enable					0x40       	//P36漏极开路输出使能
#define   P35OD_Enable					0x20       	//P35漏极开路输出使能
#define   P34OD_Enable			  		0x10       	//P34漏极开路输出使能
#define   P33OD_Enable			  		0x08       	//P33漏极开路输出使能
#define   P32OD_Enable			  		0x04       	//P32漏极开路输出使能
#define   P31OD_Enable					0x02       	//P31漏极开路输出使能
#define   P30OD_Enable					0x01       	//P30漏极开路输出使能

//漏极开路输出控制寄存器 P4OD
#define   P47OD_Enable  				0x80       	//P47漏极开路输出使能
#define   P46OD_Enable					0x40       	//P46漏极开路输出使能
#define   P45OD_Enable					0x20       	//P45漏极开路输出使能
#define   P44OD_Enable			  		0x10       	//P44漏极开路输出使能
#define   P43OD_Enable			  		0x08       	//P43漏极开路输出使能
#define   P42OD_Enable			  		0x04       	//P42漏极开路输出使能
#define   P41OD_Enable					0x02       	//P41漏极开路输出使能
#define   P40OD_Enable					0x01       	//P40漏极开路输出使能

//漏极开路输出控制寄存器 P5OD
#define   P55OD_Enable					0x20       	//P55漏极开路输出使能
#define   P54OD_Enable			  		0x10       	//P54漏极开路输出使能
#define   P53OD_Enable			  		0x08       	//P53漏极开路输出使能
#define   P52OD_Enable			  		0x04       	//P52漏极开路输出使能
#define   P51OD_Enable					0x02       	//P51漏极开路输出使能
#define   P50OD_Enable					0x01       	//P50漏极开路输出使能

//消抖控制寄存器 P0DB
#define   P07DB_Enable  				0x80       	//P07消抖使能
#define   P06DB_Enable					0x40       	//P06消抖使能
#define   P05DB_Enable					0x20       	//P05消抖使能
#define   P04DB_Enable			  		0x10       	//P04消抖使能
#define   P03DB_Enable			  		0x08       	//P03消抖使能
#define   P02DB_Enable			  		0x04       	//P02消抖使能
#define   P01DB_Enable					0x02       	//P01消抖使能
#define   P00DB_Enable					0x01       	//P00消抖使能

//消抖控制寄存器 P1DB
#define   P17DB_Enable  				0x80       	//P17消抖使能
#define   P16DB_Enable					0x40       	//P16消抖使能
#define   P15DB_Enable					0x20       	//P15消抖使能
#define   P14DB_Enable			  		0x10       	//P14消抖使能

//消抖控制寄存器 P2DB
#define   P23DB_Enable			  		0x08       	//P23消抖使能
#define   P22DB_Enable			  		0x04       	//P22消抖使能
#define   P21DB_Enable					0x02       	//P21消抖使能
#define   P20DB_Enable					0x01       	//P20消抖使能

//消抖控制寄存器 P4DB
#define   P45DB_Enable					0x20       	//P45消抖使能
#define   P44DB_Enable			  		0x10       	//P44消抖使能
#define   P43DB_Enable			  		0x08       	//P43消抖使能
#define   P42DB_Enable			  		0x04       	//P42消抖使能
#define   P41DB_Enable					0x02       	//P41消抖使能
#define   P40DB_Enable					0x01       	//P40消抖使能

//外部中断触发控制寄存器0 EIPOL0
#define   EIPOL03_TRIG_NO  				0x00       	//外部中断3任何边沿不产生中断
#define   EIPOL03_TRIG_RISING   		0x40       	//外部中断3上升沿触发
#define   EIPOL03_TRIG_FALLING			0x80       	//外部中断3下降沿触发
#define   EIPOL03_TRIG_DOUBLE   		0xC0       	//外部中断3双边沿触发
#define   EIPOL02_TRIG_NO  				0x00       	//外部中断2任何边沿不产生中断
#define   EIPOL02_TRIG_RISING   		0x10       	//外部中断2上升沿触发
#define   EIPOL02_TRIG_FALLING			0x20       	//外部中断2下降沿触发
#define   EIPOL02_TRIG_DOUBLE   		0x30       	//外部中断2双边沿触发
#define   EIPOL01_TRIG_NO  				0x00       	//外部中断1任何边沿不产生中断
#define   EIPOL01_TRIG_RISING   		0x04       	//外部中断1上升沿触发
#define   EIPOL01_TRIG_FALLING			0x08       	//外部中断1下降沿触发
#define   EIPOL01_TRIG_DOUBLE   		0x0C       	//外部中断1双边沿触发
#define   EIPOL00_TRIG_NO  				0x00       	//外部中断0任何边沿不产生中断
#define   EIPOL00_TRIG_RISING   		0x01       	//外部中断0上升沿触发
#define   EIPOL00_TRIG_FALLING			0x02       	//外部中断0下降沿触发
#define   EIPOL00_TRIG_DOUBLE   		0x03       	//外部中断0双边沿触发

//外部中断触发控制寄存器1 EIPOL1
#define   EIPOL05_TRIG_NO  				0x00       	//外部中断5任何边沿不产生中断
#define   EIPOL05_TRIG_RISING   		0x04       	//外部中断5上升沿触发
#define   EIPOL05_TRIG_FALLING			0x08       	//外部中断5下降沿触发
#define   EIPOL05_TRIG_DOUBLE   		0x0C       	//外部中断5双边沿触发
#define   EIPOL04_TRIG_NO  				0x00       	//外部中断4任何边沿不产生中断
#define   EIPOL04_TRIG_RISING   		0x01       	//外部中断4上升沿触发
#define   EIPOL04_TRIG_FALLING			0x02       	//外部中断4下降沿触发
#define   EIPOL04_TRIG_DOUBLE   		0x03       	//外部中断4双边沿触发

//外部中断4输入端口选择寄存器 EINT4SEL
#define   EINT47_Enable  				0x80        //使能外部中断47
#define   EINT46_Enable					0x40        //使能外部中断46
#define   EINT45_Enable					0x20        //使能外部中断45
#define   EINT44_Enable			  		0x10        //使能外部中断44
#define   EINT43_Enable			  		0x08        //使能外部中断43
#define   EINT42_Enable			  		0x04        //使能外部中断42
#define   EINT41_Enable					0x02        //使能外部中断41
#define   EINT40_Enable					0x01        //使能外部中断40

//外部中断5输入端口选择寄存器 EINT5SEL
#define   EINT57_Enable  				0x80        //使能外部中断57
#define   EINT56_Enable					0x40        //使能外部中断56
#define   EINT55_Enable					0x20        //使能外部中断55
#define   EINT54_Enable			  		0x10        //使能外部中断54
#define   EINT53_Enable			  		0x08        //使能外部中断53
#define   EINT52_Enable			  		0x04        //使能外部中断52
#define   EINT51_Enable					0x02        //使能外部中断51
#define   EINT50_Enable					0x01        //使能外部中断50

//触摸按键控制寄存器 TKCR
#define   DIG_FIL_NO				    0X00        //CTC转换结束信号滤波时间:不滤波
#define   DIG_FIL_1TKCLK				0X20        //1×TKCLK
#define   DIG_FIL_2TKCLK				0X40        //2×TKCLK
#define   DIG_FIL_3TKCLK				0X60        //3×TKCLK
#define   DIG_FIL_4TKCLK                0X80        //4×TKCLK
#define   DIG_FIL_5TKCLK                0XA0        //5×TKCLK
#define   DIG_FIL_6TKCLK                0XC0        //6×TKCLK
#define   DIG_FIL_7TKCLK                0XE0        //7×TKCLK
#define   FILT_SEL                      0x10        //模拟滤波
#define   TKEN                          0x08        //触摸模块使能
#define   TPEN                          0x04        //触摸独立振荡使能跳频
#define   TP_AUTO                       0x02        //硬件自动跳频
#define   TKST                         	0x01     	//开始触摸检测

#define   TP_EN                         0X04        //触摸独立振荡器使能
#define   DIGFILCLK_0                   0X00
#define   DIGFILCLK_1                   0X20
#define   DIGFILCLK_2                   0X40
#define   DIGFILCLK_3                   0X60
#define   DIGFILCLK_4                   0X80
#define   DIGFILCLK_5                   0XA0
#define   DIGFILCLK_6                   0XC0
#define   DIGFILCLK_7                   0XE0

//触摸按键通道选择寄存器 TKCHSEL
#define   TKSEL_TK0 					0x00		//触摸按键通道选择TK0
#define   TKSEL_TK1 					0x01		//触摸按键通道选择TK1
#define   TKSEL_TK2 					0x02		//触摸按键通道选择TK2
#define   TKSEL_TK3 					0x03		//触摸按键通道选择TK3
#define   TKSEL_TK4 					0x04		//触摸按键通道选择TK4
#define   TKSEL_TK5 					0x05		//触摸按键通道选择TK5
#define   TKSEL_TK6 					0x06		//触摸按键通道选择TK6
#define   TKSEL_TK7 					0x07		//触摸按键通道选择TK7
#define   TKSEL_TK8 					0x08		//触摸按键通道选择TK8
#define   TKSEL_TK9 					0x09		//触摸按键通道选择TK9
#define   TKSEL_TK10					0x0A		//触摸按键通道选择TK10
#define   TKSEL_TK11					0x0B		//触摸按键通道选择TK11
#define   TKSEL_TK12					0x0C		//触摸按键通道选择TK12
#define   TKSEL_TK13					0x0D		//触摸按键通道选择TK13
#define   TKSEL_TK14					0x0E		//触摸按键通道选择TK14
#define   TKSEL_TK15					0x0F		//触摸按键通道选择TK15
#define   TKSEL_TK16					0x10		//触摸按键通道选择TK16
#define   TKSEL_TK17					0x11		//触摸按键通道选择TK17
#define   TKSEL_TK18					0x12		//触摸按键通道选择TK18
#define   TKSEL_TK19					0x13		//触摸按键通道选择TK19
#define   TKSEL_TK20					0x14		//触摸按键通道选择TK20
#define   TKSEL_TK21					0x15		//触摸按键通道选择TK21
#define   TKSEL_TK22					0x16		//触摸按键通道选择TK22
#define   TKSEL_TK23					0x17		//触摸按键通道选择TK23
#define   TKSEL_TK24					0x18		//触摸按键通道选择TK24
#define   TKSEL_TK25					0x19		//触摸按键通道选择TK25
#define   TKSEL_TK26					0x1A		//触摸按键通道选择TK26
#define   TKSEL_TK27					0x1B		//触摸按键通道选择TK27
#define   TKSEL_TK28					0x1C		//触摸按键通道选择TK28
#define   TKSEL_TK29					0x1D		//触摸按键通道选择TK29
#define   TKSEL_TK30					0x1E		//触摸按键通道选择TK30

//触摸独立振荡控制寄存器 TKOSCCR
#define   TKOSC_SEL                     0X80        //启用独立振荡源作为触摸检测
#define   TKOSC_ADJ_N32                 0x00        //触摸独立振荡器TKOSC频率微调-32%
#define   TKOSC_ADJ_N31P5               0x01        //触摸独立振荡器TKOSC频率微调-31.5%
#define   TKOSC_ADJ_N31P                0x02        //触摸独立振荡器TKOSC频率微调-31%
#define   TKOSC_ADJ_N30P5               0x03        //触摸独立振荡器TKOSC频率微调-30.5%
#define   TKOSC_ADJ_N30P                0x04        //触摸独立振荡器TKOSC频率微调-30%
#define   TKOSC_ADJ_N29P5               0x05        //触摸独立振荡器TKOSC频率微调-29.5%
#define   TKOSC_ADJ_N29P                0x06        //触摸独立振荡器TKOSC频率微调-29%
#define   TKOSC_ADJ_N28P5               0x07        //触摸独立振荡器TKOSC频率微调-28.5%
#define   TKOSC_ADJ_N28P                0x08        //触摸独立振荡器TKOSC频率微调-28%
#define   TKOSC_ADJ_N27P5               0x09        //触摸独立振荡器TKOSC频率微调-27.5%
#define   TKOSC_ADJ_N27P                0x0A        //触摸独立振荡器TKOSC频率微调-27%
#define   TKOSC_ADJ_N26P5               0x0B        //触摸独立振荡器TKOSC频率微调-26.5%
#define   TKOSC_ADJ_N26P                0x0C        //触摸独立振荡器TKOSC频率微调-26%
#define   TKOSC_ADJ_N25P5               0x0D        //触摸独立振荡器TKOSC频率微调-25.5%
#define   TKOSC_ADJ_N25P                0x0E        //触摸独立振荡器TKOSC频率微调-25%
#define   TKOSC_ADJ_N24P5               0x0F        //触摸独立振荡器TKOSC频率微调-24.5%
#define   TKOSC_ADJ_N24P                0x10        //触摸独立振荡器TKOSC频率微调-24%
#define   TKOSC_ADJ_N23P5               0x11        //触摸独立振荡器TKOSC频率微调-23.5%
#define   TKOSC_ADJ_N23P                0x12        //触摸独立振荡器TKOSC频率微调-23%
#define   TKOSC_ADJ_N22P5               0x13        //触摸独立振荡器TKOSC频率微调-22.5%
#define   TKOSC_ADJ_N22P                0x14        //触摸独立振荡器TKOSC频率微调-22%
#define   TKOSC_ADJ_N21P5               0x15        //触摸独立振荡器TKOSC频率微调-21.5%
#define   TKOSC_ADJ_N21P                0x16        //触摸独立振荡器TKOSC频率微调-21%
#define   TKOSC_ADJ_N20P5               0x17        //触摸独立振荡器TKOSC频率微调-20.5%
#define   TKOSC_ADJ_N20P                0x18        //触摸独立振荡器TKOSC频率微调-20%
#define   TKOSC_ADJ_N19P5               0x19        //触摸独立振荡器TKOSC频率微调-19.5%
#define   TKOSC_ADJ_N19P                0x1A        //触摸独立振荡器TKOSC频率微调-19%
#define   TKOSC_ADJ_N18P5               0x1B        //触摸独立振荡器TKOSC频率微调-18.5%
#define   TKOSC_ADJ_N18P                0x1C        //触摸独立振荡器TKOSC频率微调-18%
#define   TKOSC_ADJ_N17P5               0x1D        //触摸独立振荡器TKOSC频率微调-17.5%
#define   TKOSC_ADJ_N17P                0x1E        //触摸独立振荡器TKOSC频率微调-17%
#define   TKOSC_ADJ_N16P5               0x1F        //触摸独立振荡器TKOSC频率微调-16.5%
#define   TKOSC_ADJ_N16P                0x20        //触摸独立振荡器TKOSC频率微调-16%
#define   TKOSC_ADJ_N15P5               0x21        //触摸独立振荡器TKOSC频率微调-15.5%
#define   TKOSC_ADJ_N15P                0x22        //触摸独立振荡器TKOSC频率微调-15%
#define   TKOSC_ADJ_N14P5               0x23        //触摸独立振荡器TKOSC频率微调-14.5%
#define   TKOSC_ADJ_N14P                0x24        //触摸独立振荡器TKOSC频率微调-14%
#define   TKOSC_ADJ_N13P5               0x25        //触摸独立振荡器TKOSC频率微调-13.5%
#define   TKOSC_ADJ_N13P                0x26        //触摸独立振荡器TKOSC频率微调-13%
#define   TKOSC_ADJ_N12P5               0x27        //触摸独立振荡器TKOSC频率微调-12.5%
#define   TKOSC_ADJ_N12P                0x28        //触摸独立振荡器TKOSC频率微调-12%
#define   TKOSC_ADJ_N11P5               0x29        //触摸独立振荡器TKOSC频率微调-11.5%
#define   TKOSC_ADJ_N11P                0x2A        //触摸独立振荡器TKOSC频率微调-11%
#define   TKOSC_ADJ_N10P5               0x2B        //触摸独立振荡器TKOSC频率微调-10.5%
#define   TKOSC_ADJ_N10                 0x2C        //触摸独立振荡器TKOSC频率微调-10%
#define   TKOSC_ADJ_N9P5                0x2D        //触摸独立振荡器TKOSC频率微调-9.5%
#define   TKOSC_ADJ_N9P                 0x2E        //触摸独立振荡器TKOSC频率微调-9%
#define   TKOSC_ADJ_N8P5                0x2F        //触摸独立振荡器TKOSC频率微调-8.5%
#define   TKOSC_ADJ_N8P                 0x30        //触摸独立振荡器TKOSC频率微调-8%
#define   TKOSC_ADJ_N7P5                0x31        //触摸独立振荡器TKOSC频率微调-7.5%
#define   TKOSC_ADJ_N7P                 0x32        //触摸独立振荡器TKOSC频率微调-7%
#define   TKOSC_ADJ_N6P5                0x33        //触摸独立振荡器TKOSC频率微调-6.5%
#define   TKOSC_ADJ_N6P                 0x34        //触摸独立振荡器TKOSC频率微调-6%
#define   TKOSC_ADJ_N5P5                0x35        //触摸独立振荡器TKOSC频率微调-5.5%
#define   TKOSC_ADJ_N5P                 0x36        //触摸独立振荡器TKOSC频率微调-5%
#define   TKOSC_ADJ_N4P5                0x37        //触摸独立振荡器TKOSC频率微调-4.5%
#define   TKOSC_ADJ_N4P                 0x38        //触摸独立振荡器TKOSC频率微调-4%
#define   TKOSC_ADJ_N3P5                0x39        //触摸独立振荡器TKOSC频率微调-3.5%
#define   TKOSC_ADJ_N3P                 0x3A        //触摸独立振荡器TKOSC频率微调-3%
#define   TKOSC_ADJ_N2P5                0x3B        //触摸独立振荡器TKOSC频率微调-2.5%
#define   TKOSC_ADJ_N2P                 0x3C        //触摸独立振荡器TKOSC频率微调-2%
#define   TKOSC_ADJ_N1P5                0x3D        //触摸独立振荡器TKOSC频率微调-1.5%
#define   TKOSC_ADJ_N1P                 0x3E        //触摸独立振荡器TKOSC频率微调-1%
#define   TKOSC_ADJ_N0P5                0x3F        //触摸独立振荡器TKOSC频率微调-0.5%
#define   TKOSC_ADJ_0P                  0x40        //触摸独立振荡器TKOSC频率微调0%
#define   TKOSC_ADJ_0P5                 0x41        //触摸独立振荡器TKOSC频率微调0.5%
#define   TKOSC_ADJ_1P                  0x42        //触摸独立振荡器TKOSC频率微调1%
#define   TKOSC_ADJ_1P5                 0x43        //触摸独立振荡器TKOSC频率微调1.5%
#define   TKOSC_ADJ_2P                  0x44        //触摸独立振荡器TKOSC频率微调2%
#define   TKOSC_ADJ_2P5                 0x45        //触摸独立振荡器TKOSC频率微调2.5%
#define   TKOSC_ADJ_3P                  0x46        //触摸独立振荡器TKOSC频率微调3%
#define   TKOSC_ADJ_3P5                 0x47        //触摸独立振荡器TKOSC频率微调3.5%
#define   TKOSC_ADJ_4P                  0x48        //触摸独立振荡器TKOSC频率微调4%
#define   TKOSC_ADJ_4P5                 0x49        //触摸独立振荡器TKOSC频率微调4.5%
#define   TKOSC_ADJ_5P                  0x4A        //触摸独立振荡器TKOSC频率微调5%
#define   TKOSC_ADJ_5P5                 0x4B        //触摸独立振荡器TKOSC频率微调5.5%
#define   TKOSC_ADJ_6P                  0x4C        //触摸独立振荡器TKOSC频率微调6%
#define   TKOSC_ADJ_6P5                 0x4D        //触摸独立振荡器TKOSC频率微调6.5%
#define   TKOSC_ADJ_7P                  0x4E        //触摸独立振荡器TKOSC频率微调7%
#define   TKOSC_ADJ_7P5                 0x4F        //触摸独立振荡器TKOSC频率微调7.5%
#define   TKOSC_ADJ_8P                  0x50        //触摸独立振荡器TKOSC频率微调8%
#define   TKOSC_ADJ_8P5                 0x51        //触摸独立振荡器TKOSC频率微调8.5%
#define   TKOSC_ADJ_9P                  0x52        //触摸独立振荡器TKOSC频率微调9%
#define   TKOSC_ADJ_9P5                 0x53        //触摸独立振荡器TKOSC频率微调9.5%
#define   TKOSC_ADJ_10P                 0x54        //触摸独立振荡器TKOSC频率微调10%
#define   TKOSC_ADJ_10P5                0x55        //触摸独立振荡器TKOSC频率微调10.5%
#define   TKOSC_ADJ_11P                 0x56        //触摸独立振荡器TKOSC频率微调11%
#define   TKOSC_ADJ_11P5                0x57        //触摸独立振荡器TKOSC频率微调11.5%
#define   TKOSC_ADJ_12P                 0x58        //触摸独立振荡器TKOSC频率微调12%
#define   TKOSC_ADJ_12P5                0x59        //触摸独立振荡器TKOSC频率微调12.5%
#define   TKOSC_ADJ_13P                 0x5A        //触摸独立振荡器TKOSC频率微调13%
#define   TKOSC_ADJ_13P5                0x5B        //触摸独立振荡器TKOSC频率微调13.5%
#define   TKOSC_ADJ_14P                 0x5C        //触摸独立振荡器TKOSC频率微调14%
#define   TKOSC_ADJ_14P5                0x5D        //触摸独立振荡器TKOSC频率微调14.5%
#define   TKOSC_ADJ_15P                 0x5E        //触摸独立振荡器TKOSC频率微调15%
#define   TKOSC_ADJ_15P5                0x5F        //触摸独立振荡器TKOSC频率微调15.5%
#define   TKOSC_ADJ_16P                 0x60        //触摸独立振荡器TKOSC频率微调16%
#define   TKOSC_ADJ_16P5                0x61        //触摸独立振荡器TKOSC频率微调16.5%
#define   TKOSC_ADJ_17P                 0x62        //触摸独立振荡器TKOSC频率微调17%
#define   TKOSC_ADJ_17P5                0x63        //触摸独立振荡器TKOSC频率微调17.5%
#define   TKOSC_ADJ_18P                 0x64        //触摸独立振荡器TKOSC频率微调18%
#define   TKOSC_ADJ_18P5                0x65        //触摸独立振荡器TKOSC频率微调18.5%
#define   TKOSC_ADJ_19P                 0x66        //触摸独立振荡器TKOSC频率微调19%
#define   TKOSC_ADJ_19P5                0x67        //触摸独立振荡器TKOSC频率微调19.5%
#define   TKOSC_ADJ_20P                 0x68        //触摸独立振荡器TKOSC频率微调20%
#define   TKOSC_ADJ_20P5                0x69        //触摸独立振荡器TKOSC频率微调20.5%
#define   TKOSC_ADJ_21P                 0x6A        //触摸独立振荡器TKOSC频率微调21%
#define   TKOSC_ADJ_21P5                0x6B        //触摸独立振荡器TKOSC频率微调21.5%
#define   TKOSC_ADJ_22P                 0x6C        //触摸独立振荡器TKOSC频率微调22%
#define   TKOSC_ADJ_22P5                0x6D        //触摸独立振荡器TKOSC频率微调22.5%
#define   TKOSC_ADJ_23P                 0x6E        //触摸独立振荡器TKOSC频率微调23%
#define   TKOSC_ADJ_23P5                0x6F        //触摸独立振荡器TKOSC频率微调23.5%
#define   TKOSC_ADJ_24P                 0x70        //触摸独立振荡器TKOSC频率微调24%
#define   TKOSC_ADJ_24P5                0x71        //触摸独立振荡器TKOSC频率微调24.5%
#define   TKOSC_ADJ_25P                 0x72        //触摸独立振荡器TKOSC频率微调25%
#define   TKOSC_ADJ_25P5                0x73        //触摸独立振荡器TKOSC频率微调25.5%
#define   TKOSC_ADJ_26P                 0x74        //触摸独立振荡器TKOSC频率微调26%
#define   TKOSC_ADJ_26P5                0x75        //触摸独立振荡器TKOSC频率微调26.5%
#define   TKOSC_ADJ_27P                 0x76        //触摸独立振荡器TKOSC频率微调27%
#define   TKOSC_ADJ_27P5                0x77        //触摸独立振荡器TKOSC频率微调27.5%
#define   TKOSC_ADJ_28P                 0x78        //触摸独立振荡器TKOSC频率微调28%
#define   TKOSC_ADJ_28P5                0x79        //触摸独立振荡器TKOSC频率微调28.5%
#define   TKOSC_ADJ_29P                 0x7A        //触摸独立振荡器TKOSC频率微调29%
#define   TKOSC_ADJ_29P5                0x7B        //触摸独立振荡器TKOSC频率微调29.5%
#define   TKOSC_ADJ_30P                 0x7C        //触摸独立振荡器TKOSC频率微调30%
#define   TKOSC_ADJ_30P5                0x7D        //触摸独立振荡器TKOSC频率微调30.5%
#define   TKOSC_ADJ_31P                 0x7E        //触摸独立振荡器TKOSC频率微调31%
#define   TKOSC_ADJ_31P5                0x7F        //触摸独立振荡器TKOSC频率微调31.5%

//CTC模式控制寄存器 CTCCR
#define   CTC_DUTY     				    0x80        //CTC模式工作状态指示：电容充电时间计数
#define   CTCK_SEL_ftk 					0x00        //CTC模式时钟频率选择ftk
#define   CTCK_SEL_ftk_2				0x10        //CTC模式时钟频率选择ftk/2
#define   CTCK_SEL_ftk_3				0x20        //CTC模式时钟频率选择ftk/3
#define   CTCK_SEL_ftk_4                0x30        //CTC模式时钟频率选择ftk/4
#define   CTCK_SEL_ftk_5                0x40        //CTC模式时钟频率选择ftk/5
#define   CTCK_SEL_ftk_7                0x50        //CTC模式时钟频率选择ftk/7
#define   CTCK_SEL_ftk_8                0x60        //CTC模式时钟频率选择ftk/8
#define   CTCK_SEL_ftk_9                0x70        //CTC模式时钟频率选择ftk/9
#define   CTC_CNT      				    0x08        //CTC计数器模式
#define   CX_INTER     					0x04        //CTC充电电容选择:内置充电电容
#define   CTC_RSEL_0P4VDD				0x00        //CTC模式比较器参考电压选择0.4VDD
#define   CTC_RSEL_0P5VDD				0x01        //CTC模式比较器参考电压选择0.5VDD
#define   CTC_RSEL_0P6VDD				0x02        //CTC模式比较器参考电压选择0.6VDD
#define   CTC_RSEL_0P7VDD				0x03        //CTC模式比较器参考电压选择0.7VDD

#define   CTC_0P4VDD                    0X00              //CTC模式比较器参考电压
#define   CTC_0P5VDD                    0X01
#define   CTC_0P6VDD                    0X02
#define   CTC_0P7VDD                    0X03
#define   CTC_TmrMode                   0x00
#define   CTC_CounterMode               0x08              //CTC计数器模式选择
#define   CTC_CLKDIV1                   0x00              //触摸时钟分频
#define   CTC_CLKDIV2                   0x10
#define   CTC_CLKDIV3                   0x20
#define   CTC_CLKDIV4                   0x30
#define   CTC_CLKDIV5                   0x40
#define   CTC_CLKDIV7                   0x50
#define   CTC_CLKDIV8                   0x60
#define   CTC_CLKDIV9                   0x70

//触摸中断控制寄存器 TKINT
#define   AUTP_LOAD  					0x80		//自动跳频每次初值从0x40开始
#define   TOUCHF     					0x40		//触摸扫描结束产生中断
#define   TOUCHIE    					0x10		//触摸中断使能
#define   TKTMROVF   					0x08		//TKTMR溢出中断标志
#define   TKTMRPLD_EN					0x04		//TKTMR_PLOAD寄存器预加载使能
#define   TKTMRIE    					0x02		//TKTMR中断使能
#define   TKTMREN    					0x01		//TKTMR使能

#define   TKTMR_EN                      0x01        //TKTMR使能
#define   TKTMR_PLOAD_EN                0x04         //TKTMR预加载使能

//LCD控制寄存器低字节 LCDCRL
#define   DBS_0  						0x00		//1/4Duty，1/3Bias (4COM × 28SEG) COM口：COM0~3 SEG口：SEG0~27，COM4~7作为SEG24~27使用
#define   DBS_1  						0x20		//1/5Duty，1/3Bias (5COM × 27SEG) COM口：COM0~4 SEG口：SEG0~26，COM5~7作为SEG24~26使用
#define   DBS_2  						0x40		//1/6Duty，1/3Bias (6COM × 26SEG) COM口：COM0~5 SEG口：SEG0~25，COM6~7作为SEG24~25使用
#define   DBS_3  						0x60		//1/8Duty，1/4Bias (8COM × 24SEG) COM口：COM0~7 SEG口：SEG0~23
#define   DBS_4  						0x80		//1/6Duty，1/4Bias (6COM × 26SEG) COM口：COM0~5 SEG口：SEG0~25，COM6~7作为SEG24~25使用
#define   DBS_5  						0xE0		//1/4Duty，1/3Bias (4COM × 28SEG) COM口：COM0~3 SEG口：SEG0~27，COM4~7作为SEG24~27使用
#define   LCDR_1M5     					0x10		//LCD偏置电阻选择辅助位（仅在LCDMD位为00或10时有效）LCD偏置电阻总为1.5M
#define   LCDR_900K     				0x00		//LCD偏置电阻总为900K
#define   LCCR_0    					0x00		//充电时间控制位 约为1/8 LCD COM周期
#define   LCCR_1    					0x04		//约为1/16 LCD COM周期
#define   LCCR_2    					0x08		//约为1/32 LCD COM周期
#define   LCCR_3    					0x0C		//约为1/64 LCD COM周期
#define   LCDMD_0   					0x00		//偏置电阻选择900k/1.5M
#define   LCDMD_1						0x01		//偏置电阻选择60k
#define   LCDMD_2    					0x02		//快速充电模式，偏置电阻自动在60K和900k/1.5M之间切换

//LCD控制寄存器高字节 LCDCRH
#define   LCDON							0x80		//LCD模块使能
#define   LCDPC_IO						0x40		//LCD端口功能配置位 所有LCD端口为普通I/O
#define   LCDPC_LCD						0x00		//所有LCD端口可配置为LCD功能
#define   LCTEN							0x20		//开启LCD对比度控制
#define   CLKSEL_LXT					0x10		//LCD工作时钟选择控制位 LCD工作时钟选择LXT
#define   CLKSEL_LIRC					0x00		//LCD工作时钟选择LIRC
#define   VLCD_0P531VDD               	0x00        //LCD对比度控制位VLCD=0.531VDD
#define   VLCD_0P563VDD               	0x01        //LCD对比度控制位VLCD=0.563VDD
#define   VLCD_0P594VDD               	0x02        //LCD对比度控制位VLCD=0.594VDD
#define   VLCD_0P625VDD               	0x03        //LCD对比度控制位VLCD=0.625VDD
#define   VLCD_0P656VDD               	0x04        //LCD对比度控制位VLCD=0.656VDD
#define   VLCD_0P688VDD               	0x05        //LCD对比度控制位VLCD=0.688VDD
#define   VLCD_0P719VDD               	0x06        //LCD对比度控制位VLCD=0.719VDD
#define   VLCD_0P750VDD               	0x07        //LCD对比度控制位VLCD=0.750VDD
#define   VLCD_0P781VDD               	0x08        //LCD对比度控制位VLCD=0.781VDD
#define   VLCD_0P813VDD               	0x09        //LCD对比度控制位VLCD=0.813VDD
#define   VLCD_0P844VDD               	0x0A        //LCD对比度控制位VLCD=0.844VDD
#define   VLCD_0P875VDD               	0x0B        //LCD对比度控制位VLCD=0.875VDD
#define   VLCD_0P906VDD               	0x0C        //LCD对比度控制位VLCD=0.906VDD
#define   VLCD_0P938VDD               	0x0D        //LCD对比度控制位VLCD=0.938VDD
#define   VLCD_0P969VDD               	0x0E        //LCD对比度控制位VLCD=0.969VDD
#define   VLCD_1P000VDD               	0x0F        //LCD对比度控制位VLCD=1.000VDD

//LCD帧频选择寄存器 FRASEL
#define   LCDFRA_0               		0x00        //fLCD=fLXT LCD帧频选择64Hz，fLCD=fLIRC LCD帧频选择32Hz
#define   LCDFRA_1               		0x01        //fLCD=fLXT LCD帧频选择85.3Hz，fLCD=fLIRC LCD帧频选择42.7Hz
#define   LCDFRA_2               		0x02        //fLCD=fLXT LCD帧频选择128Hz ，fLCD=fLIRC LCD帧频选择64Hz
#define   LCDFRA_3               		0x03        //fLCD=fLXT LCD帧频选择256Hz，fLCD=fLIRC LCD帧频选择128Hz

//LED控制寄存器 LEDCR
#define   LEDON  						0x80        //LED驱动器使能
#define   LEDMD							0x40        //LEDIF=1时，LED扫描停止，需要将LEDON置“1”开始下一帧扫描
#define   MODE_2						0x20        //模式2（带可调光的LED显示）
#define   MODE_1						0x00        //模式1（不可调光的LED显示）
#define   LEDIF			  				0x10        //LED帧中断标志位  硬件置“1”，表示已经完成一帧的LED扫描
#define   COMIF			  				0x08        //LED_COM中断标志 硬件置“1”，表示已经完成一个COM的扫描
#define   MODSW			  				0x01        //LED共享端口设置为IO

//端口大驱动控制寄存器 BIGDRIVE
#define   GIB_P00_Enable				0x01		//P00大驱动控制使能
#define   GIB_P01_Enable				0x02		//P01大驱动控制使能
#define   GIB_P02_Enable				0x04		//P02大驱动控制使能
#define   GIB_P03_Enable				0x08		//P03大驱动控制使能
#define   GIB_P04_Enable				0x10		//P04大驱动控制使能
#define   GIB_P05_Enable				0x20		//P05大驱动控制使能
#define   GIB_P06_Enable				0x40		//P06大驱动控制使能

//AD模拟输入端口使能控制寄存器0 ADAN0
#define   AD22_Enable					0x01		//AD口模式选择:作为AD22
#define   AD23_Enable					0x02		//AD口模式选择:作为AD23
#define   AD24_Enable					0x04		//AD口模式选择:作为AD24
#define   AD25_Enable					0x08		//AD口模式选择:作为AD25
#define   AD26_Enable					0x10		//AD口模式选择:作为AD26
#define   AD27_Enable					0x20		//AD口模式选择:作为AD27
#define   AD28_Enable					0x40		//AD口模式选择:作为AD28

//AD模拟输入端口使能控制寄存器1 ADAN1
#define   AD10_Enable					0x10		//AD口模式选择:作为AD10
#define   AD11_Enable					0x20		//AD口模式选择:作为AD11
#define   AD12_Enable					0x40		//AD口模式选择:作为AD12
#define   AD13_Enable					0x80		//AD口模式选择:作为AD13

//AD模拟输入端口使能控制寄存器2 ADAN2
#define   AD14_Enable					0x01		//AD口模式选择:作为AD14
#define   AD15_Enable					0x02		//AD口模式选择:作为AD15
#define   AD16_Enable					0x04		//AD口模式选择:作为AD16
#define   AD17_Enable					0x08		//AD口模式选择:作为AD17
#define   AD18_Enable					0x10		//AD口模式选择:作为AD18
#define   AD19_Enable					0x20		//AD口模式选择:作为AD19
#define   AD20_Enable					0x40		//AD口模式选择:作为AD20
#define   AD21_Enable					0x80		//AD口模式选择:作为AD21

//AD模拟输入端口使能控制寄存器3 ADAN3
#define   AD9_Enable					0x10		//AD口模式选择:作为AD9
#define   AD8_Enable					0x20		//AD口模式选择:作为AD8
#define   AD7_Enable					0x40		//AD口模式选择:作为AD7
#define   AD6_Enable					0x80		//AD口模式选择:作为AD6

//AD模拟输入端口使能控制寄存器4 ADAN4
#define   AD0_Enable					0x20       	//AD口模式选择:作为AD0
#define   AD1_Enable			  		0x10       	//AD口模式选择:作为AD1
#define   AD2_Enable			  		0x08       	//AD口模式选择:作为AD2
#define   AD3_Enable			  		0x04       	//AD口模式选择:作为AD3
#define   AD4_Enable					0x02       	//AD口模式选择:作为AD4
#define   AD5_Enable					0x01       	//AD口模式选择:作为AD5

//SEG口使能控制寄存器0 SEGCR0
#define   SEG16_Enable					0x01		//P00作为SEG16
#define   SEG17_Enable					0x02		//P01作为SEG17
#define   SEG18_Enable					0x04		//P02作为SEG18
#define   SEG19_Enable					0x08		//P03作为SEG19
#define   SEG20_Enable					0x10		//P04作为SEG20
#define   SEG21_Enable					0x20		//P05作为SEG21
#define   SEG22_Enable					0x40		//P06作为SEG22
#define   SEG23_Enable					0x80		//P07作为SEG23
#define   P00IO_Enable  				0x00      	//P00作为I/O
#define   P01IO_Enable					0x00      	//P01作为I/O
#define   P02IO_Enable					0x00      	//P02作为I/O
#define   P03IO_Enable		  			0x00      	//P03作为I/O
#define   P04IO_Enable		  			0x00      	//P04作为I/O
#define   P05IO_Enable		  			0x00      	//P05作为I/O
#define   P06IO_Enable					0x00      	//P06作为I/O
#define   P07IO_Enable					0x00      	//P07作为I/O

//SEG口使能控制寄存器1 SEGCR1
#define   SEG0_Enable					0x01		//P10作为SEG0
#define   SEG1_Enable					0x02		//P11作为SEG1
#define   SEG2_Enable					0x04		//P12作为SEG2
#define   SEG3_Enable					0x08		//P13作为SEG3
#define   SEG4_Enable					0x10		//P14作为SEG4
#define   SEG5_Enable					0x20		//P15作为SEG5
#define   SEG6_Enable					0x40		//P16作为SEG6
#define   SEG7_Enable					0x80		//P17作为SEG7
#define   P10IO_Enable  				0x00      	//P10作为I/O
#define   P11IO_Enable					0x00      	//P11作为I/O
#define   P12IO_Enable					0x00      	//P12作为I/O
#define   P13IO_Enable		  			0x00      	//P13作为I/O
#define   P14IO_Enable		  			0x00      	//P14作为I/O
#define   P15IO_Enable		  			0x00      	//P15作为I/O
#define   P16IO_Enable					0x00      	//P16作为I/O
#define   P17IO_Enable					0x00      	//P17作为I/O

//SEG口使能控制寄存器2 SEGCR2
#define   SEG8_Enable					0x01		//P20作为SEG8
#define   SEG9_Enable					0x02		//P21作为SEG9
#define   SEG10_Enable					0x04		//P22作为SEG10
#define   SEG11_Enable					0x08		//P23作为SEG11
#define   SEG12_Enable					0x10		//P24作为SEG12
#define   SEG13_Enable					0x20		//P25作为SEG13
#define   SEG14_Enable					0x40		//P26作为SEG14
#define   SEG15_Enable					0x80		//P27作为SEG15
#define   P20IO_Enable  				0x00      	//P20作为I/O
#define   P21IO_Enable					0x00      	//P21作为I/O
#define   P22IO_Enable					0x00      	//P22作为I/O
#define   P23IO_Enable		  			0x00      	//P23作为I/O
#define   P24IO_Enable		  			0x00      	//P24作为I/O
#define   P25IO_Enable		  			0x00      	//P25作为I/O
#define   P26IO_Enable					0x00      	//P26作为I/O
#define   P27IO_Enable					0x00      	//P27作为I/O

//SEG口使能控制寄存器3 SEGCR3
#define   SCKCR_P12						0x01		//SPI模块SCK引脚配置位 SCK映射到P12
#define   SCKCR_P24						0x00		//SCK映射到P24(默认)
#define   SEG24_Enable					0x10		//P34作为SEG24
#define   SEG25_Enable					0x20		//P35作为SEG25
#define   SEG26_Enable					0x40		//P36作为SEG26
#define   SEG27_Enable					0x80		//P37作为SEG27
#define   P34IO_Enable		  			0x00      	//P34作为I/O
#define   P35IO_Enable		  			0x00      	//P35作为I/O
#define   P36IO_Enable					0x00      	//P36作为I/O
#define   P37IO_Enable					0x00      	//P37作为I/O

//COM口使能控制寄存器 COMCR
#define   COM0_Enable					0x01		//P30作为COM0使能
#define   COM1_Enable					0x02		//P31作为COM1使能
#define   COM2_Enable					0x04		//P32作为COM2使能
#define   COM3_Enable					0x08		//P33作为COM3使能
#define   COM4_Enable					0x10		//P34作为COM4使能
#define   COM5_Enable					0x20		//P35作为COM5使能
#define   COM6_Enable					0x40		//P36作为COM6使能
#define   COM7_Enable					0x80		//P37作为COM7使能

//映射端口控制寄存器0 LCMCR0
#define   SCLCR_P20  					0x40        //SCL映射到P20
#define   SCLCR_P41  					0x00        //SCL映射到P41
#define   SCLCR_P26  					0x80        //SCL映射到P26
#define   SCLCR_P45  					0xC0        //SCL映射到P45
#define   SDACR_P21					    0x10        //SDA映射到P21
#define   SDACR_P40					    0x00        //SDA映射到P40
#define   SDACR_P27					    0x20        //SDA映射到P27
#define   SDACR_P44					    0x30        //SDA映射到P44
#define   PWM0CR_P51 					0x00        //PWM0映射到P51
#define   PWM0CR_P22 					0x08        //PWM0映射到P22
#define   PWM1CR_P52 					0x00        //PWM1映射到P52
#define   PWM1CR_P23 					0x04        //PWM1映射到P23
#define   PWM1CR_P53 					0x00        //PWM2映射到P53
#define   PWM1CR_P24 					0x02        //PWM2映射到P24
#define   TC0CR_P25  					0x00        //TC0映射到P25
#define   TC0CR_P51  					0x01        //TC0映射到P51

//映射端口控制寄存器1 LCMCR1
#define   TC1CR_P26  					0x00      	//TC1映射到P26
#define   TC1CR_P52						0x80      	//TC1映射到P52
#define   TC1CR_P27  					0x00      	//TC2映射到P27
#define   TC1CR_P53						0x40      	//TC2映射到P53
#define   RX1CR_P26  					0x00      	//RX1映射到P26
#define   RX1CR_P45						0x20      	//RX1映射到P45
#define   TX1CR_P27  					0x00      	//TX1映射到P27
#define   TX1CR_P44	  			    	0x10      	//TX1映射到P44
#define   RX2CR_P00  					0x00      	//RX2映射到P00
#define   RX2CR_P41	  			    	0x08      	//RX2映射到P41
#define   TX2CR_P01  					0x00      	//TX2映射到P01
#define   TX2CR_P40	  			    	0x04      	//TX2映射到P40
#define   TX0CR_P21  					0x00      	//TX0映射到P21
#define   TX0CR_P17	  			    	0x02      	//TX0映射到P17
#define   PWMFCR_P05  			    	0x00      	//PWMF映射到P05
#define   PWMFCR_P40					0x01      	//PWMF映射到P40

//映射端口控制寄存器2 LCMCR2
#define   PWMECR_P04  					0x00        //PWME映射到P04
#define   PWMECR_P41					0x80        //PWME映射到P41
#define   PWMDCR_P03  					0x00        //PWMD映射到P03
#define   PWMDCR_P42		  			0x40        //PWMD映射到P42
#define   PWMCCR_P02  					0x00        //PWMC映射到P02
#define   PWMCCR_P43					0x20        //PWMC映射到P43
#define   PWMBCR_P01  					0x00        //PWMB映射到P01
#define   PWMBCR_P44	  				0x10        //PWMB映射到P44
#define   PWMACR_P00  					0x00        //PWMA映射到P00
#define   PWMACR_P45	  				0x08        //PWMA映射到P45
#define   MOSI_P22  					0x00      	//SPI模块MOSI映射到P22
#define   MOSI_P10	  			    	0x04      	//SPI模块MOSI映射到P10
#define   MISO_P23  					0x00      	//SPI模块MISO映射到P23
#define   MISO_P11	  			    	0x02      	//SPI模块MISO映射到P11
#define   SS_P25  						0x00      	//SPI模块SS映射到P25
#define   SS_P13	  			    	0x01      	//SPI模块SS映射到P13

//定时器通道输出使能寄存器 T5PWMOE
#define   PWMOE1_Enable					0x01		//通道1PWM使能
#define   PWMOE2_Enable					0x02		//通道2PWM使能
#define   PWMOE3_Enable					0x04		//通道3PWM使能
#define   PWMOE4_Enable					0x08		//通道4PWM使能
#define   PWMOE5_Enable					0x10		//通道5PWM使能
#define   PWMOE6_Enable					0x20		//通道6PWM使能

//定时器死区控制寄存器1 T5DCR1
#define   P6MS_Enable  			    	0x80       	//通道6与通道5组成互补输出
#define   P4MS_Enable					0x40       	//通道4与通道3组成互补输出
#define   C56DS_FALLING					0x00       	//通道56输出主波形下降沿插入死区
#define   C56DS_RISING					0x20       	//通道56输出主波形上升沿插入死区
#define   C56DE_Enable			  		0x10       	//通道56输出死区控制使能位
#define   C34DS_FALLING 				0x00       	//通道34输出主波形下降沿插入死区
#define   C34DS_RISING					0x08       	//通道34输出主波形上升沿插入死区
#define   C34DE_Enable			  		0x04       	//通道34输出死区控制使能位
#define   C12DS_FALLING 				0x00       	//通道12输出主波形下降沿插入死区
#define   C12DS_RISING					0x02       	//通道12输出主波形上升沿插入死区
#define   C12DE_Enable					0x01       	//通道12输出死区控制使能位

//定时器死区控制寄存器2 T5DCR2
#define   P2MS_Enable				  	0x40  		//通道2与通道1组成互补输出
#define   C6PWM_Polarity_Not_Opposite	0x00  		//通道6PWM输出信号不反相
#define   C6PWM_Polarity_Opposite		0x20  		//通道6PWM输出信号反相
#define   C5PWM_Polarity_Not_Opposite	0x00  		//通道5PWM输出信号不反相
#define   C5PWM_Polarity_Opposite		0x10  		//通道5PWM输出信号反相
#define   C4PWM_Polarity_Not_Opposite	0x00  		//通道4PWM输出信号不反相
#define   C4PWM_Polarity_Opposite		0x08  		//通道4PWM输出信号反相
#define   C3PWM_Polarity_Not_Opposite	0x00  		//通道3PWM输出信号不反相
#define   C3PWM_Polarity_Opposite		0x04  		//通道3PWM输出信号反相
#define   C2PWM_Polarity_Not_Opposite	0x00  		//通道2PWM输出信号不反相
#define   C2PWM_Polarity_Opposite		0x02  		//通道2PWM输出信号反相
#define   C1PWM_Polarity_Not_Opposite	0x00  		//通道1PWM输出信号不反相
#define   C1PWM_Polarity_Opposite		0x01  		//通道1PWM输出信号反相

//定时器控制寄存器1 T5CR1
#define   T5_TCCLR                      0x01       	//清除T5计数器
#define   T5CF                          0x04       	//T5匹配中断标志
#define   T5_TIMER_MODE                 0x00       	//T5定时器/计数器模式
#define   T5_PWM_ONESHOT_MODE           0x20       	//T5PWM单脉冲模式
#define   T5_PWM_REPEAT_MODE            0x30       	//T5PWM多脉冲模式
#define   T5_PWM_ONESHOT_Enable         0x40       	//T5单脉冲输出使能
#define   T5EN                          0x80       	//T5使能

//定时器控制寄存器2 T5CR2
#define   T5_DIV1     					0x00        //定时器时钟分频选择:fx
#define   T5_DIV2  						0x20        //fx/2
#define   T5_DIV4  						0x40        //fx/4
#define   T5_DIV8  			  			0x60        //fx/8
#define   T5_DIV64 			  			0x80        //fx/64
#define   T5_DIV512			  			0xA0        //fx/512
#define   T5_DIV2048					0xC0        //fx/2048

//===================其他=============================================================
//使能
// #define DISABLE							0
// #define ENABLE							1
#define EA_ENABLE   					{EA = 1;}			//使能总中断

//WDT功能选择
#define TMR 			    			0					//WDT作为独立定时器
#define RST 			    			1					//WDT产生复位信号
#define	 WDT_TIME(X) 					WDTDR = X			//WDTDR数据寄存器,设置WDT计数周期

//WT
#define	 WT_TIME(X) 					WTDR = X			//WTDR数据寄存器,设置WDT计数溢出周期

//LVR
#define   LVR_OFF						{LVRCR = 0x00;}		//关闭LVR

//中断向量表
#define         EINT0_VECTOR		0
#define         EINT1_VECTOR		1
#define         EINT2_VECTOR		2
#define         EINT3_VECTOR   		3
#define         EINT4_VECTOR    	4
#define         EINT5_VECTOR		5
#define         LVD_VECTOR    		7
#define         I2C_VECTOR			8
#define         UART_VECTOR	        9
#define         TK_VECTOR			10
#define         TIM0_VECTOR			11
#define         TIM1_VECTOR			12
#define         TIM2_VECTOR			13
#define         TIM5_VECTOR			14
#define         ADC_VECTOR		    15
#define         SPI_VECTOR		    15
#define         WT_VECTOR		    16
#define         WDT_VECTOR		    16
#define         LED_VECTOR		    17
#define         COM_VECTOR		    17
#define         MDU_VECTOR		    17

#ifndef  uint8_t
typedef  unsigned char  uint8_t;
#endif
#ifndef  uint16_t
typedef  unsigned short  uint16_t;
#endif
#ifndef  uint32_t
typedef  unsigned long  uint32_t;
#endif
#ifndef  char_t
typedef char char_t;
#endif
#ifndef   int8_t
typedef signed  char int8_t;
#endif
#ifndef   int16_t
typedef signed  short  int16_t;
#endif
#ifndef  int32_t
typedef  signed long  int32_t;
#endif
#ifndef  float32_t
typedef float float32_t;
#endif
#ifndef  float64_t
typedef double  float64_t;
#endif


#endif
