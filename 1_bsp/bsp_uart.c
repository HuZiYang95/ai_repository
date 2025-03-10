/**
 * @file bsp_uart.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_uart.h"
#include "bsp_sfr.h"
#include "typedef.h"
#include "bsp_timer.h"


 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 /*                           串口0相关函数                            */
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 /**
  * @brief
  *
  * @param Baud  波特率
  * @param Chan  串口通道
  * @param TxSwitch  发送使能
  * @param RxSwitch  接收使能位
  * @param IntPriority   中断优先级
  *
  * @note 默认数据位8bit，无校验位，停止位1bit
  */
void bsp_uart0_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    // 1-配置波特率
    bsp_uart0_baud(Baud);
    // 2-配置数据位
    bsp_uart0_data_bit(UART_DATA_8BIT);
    // 3-配置校验位
    bsp_uart0_check(UART_CHECK_UNCHECK);
    // 4-配置停止位
    bsp_uart0_stop(UART_STOP_1);
    // 5-配置串口映射端口
    bsp_uart0_chan(Chan);
    // 6-配置发送接收模式及中断优先级
    bsp_uart0_mode_priority(IntPriority);
    // 8-配置模块使能位
    bsp_uart0_tx_switch(TxEnable);
    bsp_uart0_rx_switch(RxEnable);
    bsp_uart0_switch(ENABLE);
}


/**
 * @brief 设置uart0波特率
 *
 * @param Baud 波特率
 */
void bsp_uart0_baud(TYPE_ENUM_UART_BAUD Baud)
{
    switch (Baud)
    {
        case UART_BAUD_2400:
            if (16 == SysClock) { UART0BRR2 = 0x2A; UART0BRR1 = 0x60; }
            else if (8 == SysClock) { UART0BRR2 = 0x35; UART0BRR1 = 0x30; }
            break;
        case UART_BAUD_4800:
            if (16 == SysClock) { UART0BRR2 = 0x35; UART0BRR1 = 0x30; }
            else if (8 == SysClock) { UART0BRR2 = 0x33; UART0BRR1 = 0x98; }
            break;
        case UART_BAUD_9600:
            if (16 == SysClock) { UART0BRR2 = 0x33; UART0BRR1 = 0x98; }
            else if (8 == SysClock) { UART0BRR2 = 0x31; UART0BRR1 = 0xCC; }
            break;
        case UART_BAUD_14400:
            if (16 == SysClock) { UART0BRR2 = 0x37; UART0BRR1 = 0xBB; }
            else if (8 == SysClock) { UART0BRR2 = 0x3C; UART0BRR1 = 0xDE; }
            break;
        case UART_BAUD_19200:
            if (16 == SysClock) { UART0BRR2 = 0x31; UART0BRR1 = 0xCC; }
            else if (8 == SysClock) { UART0BRR2 = 0x31; UART0BRR1 = 0xE6; }
            break;
        case UART_BAUD_115200:
            if (16 == SysClock) { UART0BRR2 = 0x3B; UART0BRR1 = 0xF8; }
            else if (8 == SysClock) { UART0BRR2 = 0x35; UART0BRR1 = 0xFC; }
            break;
        default:    break;
    }
}


/**
 * @brief 设置uart0数据位数
 *
 * @param DataBit 数据位
 */
void bsp_uart0_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit)
{
    switch (DataBit)
    {
        case UART_DATA_8BIT:
            UART0CR1 &= ~0x08;
            break;
        case UART_DATA_9BIT:
            UART0CR1 |= 0x08;
            break;
        default:
            break;
    }
}


/**
 * @brief 设置uart0校验位
 *
 * @param Check 校验位
 */
void bsp_uart0_check(TYPE_ENUM_UART_CHECK Check)
{
    switch (Check)
    {
        case UART_CHECK_UNCHECK:    UART0CR1 &= ~0x30;  break;
        case UART_CHECK_ODD:        UART0CR1 |= 0x30;  break;
        case UART_CHECK_EVEN:       UART0CR1 |= 0x20;  UART0CR1 &= ~0x10;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart0停止位
 *
 * @param Stop 停止位
 */
void bsp_uart0_stop(TYPE_ENUM_UART_STOP Stop)
{
    switch (Stop)
    {
        case UART_STOP_1:   UART0CR3 &= ~0x04;  break;
        case UART_STOP_2:   UART0CR3 |= 0x04;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart0端口
 *
 * @param Chan 端口
 */
void bsp_uart0_chan(TYPE_ENUM_UART_CHAN Chan)
{
    switch (Chan)
    {
        case UART0_RX_P20_TX_P21:   LCMCR1 &= U8_NBIT1;  P2IO &= U8_NBIT0; P2PU |= U8_BIT0; P2IO |= U8_BIT1;  P2 |= U8_BIT1; break;
        case UART0_RX_P20_TX_P17:   LCMCR1 |= U8_BIT1;   P2IO &= U8_NBIT0; P2PU |= U8_BIT0; P1IO |= U8_BIT7;  P1 |= U8_BIT7; break;
        default:    break;
    }
}


/**
 * @brief 设置串口0发送接收模式，及中断优先级
 *
 * @param Mode 发送接收模式
 * @param IntPriority 中断优先级
 */
void bsp_uart0_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    UART0SR = 0;
    UART0CR2 |= 0x60;
    IE1 |= 0x08;

    switch (IntPriority)
    {
        case UART_INT_PRIORITY_0:   IP0 &= ~0x08;   IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_1:   IP0 |= 0x08;    IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_2:   IP0 &= ~0x08;   IP1 |= 0x08;    break;
        case UART_INT_PRIORITY_3:   IP0 |= 0x08;    IP1 |= 0x08;    break;
        default:    break;
    }
}


/**
 * @brief uart0发送使能
 *
 * @param Switch
 */
void bsp_uart0_tx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART0CR2 |= 0x08;
    else UART0CR2 &= ~0x08;
}


/**
 * @brief uart0接收使能
 *
 * @param Switch
 */
void bsp_uart0_rx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART0CR2 |= 0x04;
    else UART0CR2 &= ~0x04;
}


/**
 * @brief uart0模块使能
 *
 * @param Switch
 */
void bsp_uart0_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART0CR2 |= 0x02;
    else UART0CR2 &= ~0x02;
}


/**
 * @brief uart0 阻塞发送
 *
 * @param Data 发送数据
 */
void bsp_uart0_send_block(unsigned char Data)
{
    UART0DR = Data;
    while (!(UART0SR & 0x40));
}


/**
 * @brief uart0 阻塞接收
 *
 * @return unsigned char 接收数据
 */
unsigned char bsp_uart0_rece_block(void)
{
    while (!(UART0SR & 0x20));
    UART0SR = ~0x28;
    return UART0DR;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                           串口1相关函数                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * @brief
 *
 * @param Baud  波特率
 * @param Chan  串口通道
 * @param TxSwitch  发送使能
 * @param RxSwitch  接收使能位
 * @param IntPriority   中断优先级
 *
 * @note 默认数据位8bit，无校验位，停止位1bit
 */
void bsp_uart1_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    // 1-配置波特率
    bsp_uart1_baud(Baud);
    // 2-配置数据位
    bsp_uart1_data_bit(UART_DATA_8BIT);
    // 3-配置校验位
    bsp_uart1_check(UART_CHECK_UNCHECK);
    // 4-配置停止位
    bsp_uart1_stop(UART_STOP_1);
    // 5-配置串口映射端口
    bsp_uart1_chan(Chan);
    // 6-配置发送接收模式及中断优先级
    bsp_uart1_mode_priority(IntPriority);
    // 8-配置模块使能位
    bsp_uart1_tx_switch(TxEnable);
    bsp_uart1_rx_switch(RxEnable);
    bsp_uart1_switch(ENABLE);
}


/**
 * @brief 设置uart1波特率
 *
 * @param Baud 波特率
 */
void bsp_uart1_baud(TYPE_ENUM_UART_BAUD Baud)
{
    switch (Baud)
    {
        case UART_BAUD_2400:
            if (16 == SysClock) { UART1BRR2 = 0x2A; UART1BRR1 = 0x60; }
            else if (8 == SysClock) { UART1BRR2 = 0x35; UART1BRR1 = 0x30; }
            break;
        case UART_BAUD_4800:
            if (16 == SysClock) { UART1BRR2 = 0x35; UART1BRR1 = 0x30; }
            else if (8 == SysClock) { UART1BRR2 = 0x33; UART1BRR1 = 0x98; }
            break;
        case UART_BAUD_9600:
            if (16 == SysClock) { UART1BRR2 = 0x33; UART1BRR1 = 0x98; }
            else if (8 == SysClock) { UART1BRR2 = 0x31; UART1BRR1 = 0xCC; }
            break;
        case UART_BAUD_14400:
            if (16 == SysClock) { UART1BRR2 = 0x37; UART1BRR1 = 0xBB; }
            else if (8 == SysClock) { UART1BRR2 = 0x3C; UART1BRR1 = 0xDE; }
            break;
        case UART_BAUD_19200:
            if (16 == SysClock) { UART1BRR2 = 0x31; UART1BRR1 = 0xCC; }
            else if (8 == SysClock) { UART1BRR2 = 0x31; UART1BRR1 = 0xE6; }
            break;
        case UART_BAUD_115200:
            if (16 == SysClock) { UART1BRR2 = 0x3B; UART1BRR1 = 0xF8; }
            else if (8 == SysClock) { UART1BRR2 = 0x35; UART1BRR1 = 0xFC; }
            break;
        default:    break;
    }
}


/**
 * @brief 设置uart1数据位数
 *
 * @param DataBit 数据位
 */
void bsp_uart1_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit)
{
    switch (DataBit)
    {
        case UART_DATA_8BIT:
            UART1CR1 &= ~0x08;
            break;
        case UART_DATA_9BIT:
            UART1CR1 |= 0x08;
            break;
        default:
            break;
    }
}


/**
 * @brief 设置uart1校验位
 *
 * @param Check 校验位
 */
void bsp_uart1_check(TYPE_ENUM_UART_CHECK Check)
{
    switch (Check)
    {
        case UART_CHECK_UNCHECK:    UART1CR1 &= ~0x30;  break;
        case UART_CHECK_ODD:        UART1CR1 |= 0x30;  break;
        case UART_CHECK_EVEN:       UART1CR1 |= 0x20;  UART1CR1 &= ~0x10;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart1停止位
 *
 * @param Stop 停止位
 */
void bsp_uart1_stop(TYPE_ENUM_UART_STOP Stop)
{
    switch (Stop)
    {
        case UART_STOP_1:   UART1CR3 &= ~0x04;  break;
        case UART_STOP_2:   UART1CR3 |= 0x04;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart1端口
 *
 * @param Chan 端口
 */
void bsp_uart1_chan(TYPE_ENUM_UART_CHAN Chan)
{
    switch (Chan)
    {
        case UART1_RX_P26_TX_P27:   LCMCR1 &= U8_NBIT5;  P2IO &= U8_NBIT6; P2PU |= U8_BIT6;  LCMCR1 &= U8_NBIT4;  P2IO |= U8_BIT7;  P2 |= U8_BIT7; break;
        case UART1_RX_P45_TX_P44:   LCMCR1 |= U8_BIT5;   P4IO &= U8_NBIT5; P4PU |= U8_BIT5;  LCMCR1 |= U8_BIT4;   P4IO |= U8_BIT4;  P4 |= U8_BIT4; break;
        default:    break;
    }
}


/**
 * @brief 设置串口1发送接收模式，及中断优先级
 *
 * @param Mode 发送接收模式
 * @param IntPriority 中断优先级
 */
void bsp_uart1_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    UART1SR = 0;
    UART1CR2 |= 0x60;
    IE1 |= 0x08;

    switch (IntPriority)
    {
        case UART_INT_PRIORITY_0:   IP0 &= ~0x08;   IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_1:   IP0 |= 0x08;    IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_2:   IP0 &= ~0x08;   IP1 |= 0x08;    break;
        case UART_INT_PRIORITY_3:   IP0 |= 0x08;    IP1 |= 0x08;    break;
        default:    break;
    }
}


/**
 * @brief uart1发送使能
 *
 * @param Switch
 */
void bsp_uart1_tx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART1CR2 |= 0x08;
    else UART1CR2 &= ~0x08;
}


/**
 * @brief uart1接收使能
 *
 * @param Switch
 */
void bsp_uart1_rx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART1CR2 |= 0x04;
    else UART1CR2 &= ~0x04;
}


/**
 * @brief uart1模块使能
 *
 * @param Switch
 */
void bsp_uart1_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART1CR2 |= 0x02;
    else UART1CR2 &= ~0x02;
}


/**
 * @brief uart1 阻塞发送
 *
 * @param Data 发送数据
 */
void bsp_uart1_send_block(unsigned char Data)
{
    UART1DR = Data;
    while (!(UART1SR & 0x40));
}


/**
 * @brief uart1 阻塞接收
 *
 * @return unsigned char 接收数据
 */
unsigned char bsp_uart1_rece_block(void)
{
    while (!(UART1SR & 0x20));
    UART1SR = ~0x28;
    return UART1DR;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                           串口2相关函数                            */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * @brief
 *
 * @param Baud 波特率
 * @param Chan 串口通道
 * @param TxEnable 发送使能
 * @param RxEnable 接收使能
 * @param IntPriority 串口中断优先级
 *
 * @note 默认数据位8bit，无校验位，停止位1bit
 */
void bsp_uart2_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    // 1-配置波特率
    bsp_uart2_baud(Baud);
    // 2-配置数据位
    bsp_uart2_data_bit(UART_DATA_8BIT);
    // 3-配置校验位
    bsp_uart2_check(UART_CHECK_UNCHECK);
    // 4-配置停止位
    bsp_uart2_stop(UART_STOP_1);
    // 5-配置串口映射端口
    bsp_uart2_chan(Chan);
    // 6-配置发送接收模式及中断优先级
    bsp_uart2_mode_priority(IntPriority);
    // 8-配置模块使能位
    bsp_uart2_tx_switch(TxEnable);
    bsp_uart2_rx_switch(RxEnable);
    bsp_uart2_switch(ENABLE);
}


/**
 * @brief 设置uart2波特率
 *
 * @param Baud 波特率
 */
void bsp_uart2_baud(TYPE_ENUM_UART_BAUD Baud)
{
    switch (Baud)
    {
        case UART_BAUD_2400:
            if (16 == SysClock) { UART2BRR2 = 0x2A; UART2BRR1 = 0x60; }
            else if (8 == SysClock) { UART2BRR2 = 0x35; UART2BRR1 = 0x30; }
            break;
        case UART_BAUD_4800:
            if (16 == SysClock) { UART2BRR2 = 0x35; UART2BRR1 = 0x30; }
            else if (8 == SysClock) { UART2BRR2 = 0x33; UART2BRR1 = 0x98; }
            break;
        case UART_BAUD_9600:
            if (16 == SysClock) { UART2BRR2 = 0x33; UART2BRR1 = 0x98; }
            else if (8 == SysClock) { UART2BRR2 = 0x31; UART2BRR1 = 0xCC; }
            break;
        case UART_BAUD_14400:
            if (16 == SysClock) { UART2BRR2 = 0x37; UART2BRR1 = 0xBB; }
            else if (8 == SysClock) { UART2BRR2 = 0x3C; UART2BRR1 = 0xDE; }
            break;
        case UART_BAUD_19200:
            if (16 == SysClock) { UART2BRR2 = 0x31; UART2BRR1 = 0xCC; }
            else if (8 == SysClock) { UART2BRR2 = 0x31; UART2BRR1 = 0xE6; }
            break;
        case UART_BAUD_115200:
            if (16 == SysClock) { UART2BRR2 = 0x3B; UART2BRR1 = 0xF8; }
            else if (8 == SysClock) { UART2BRR2 = 0x35; UART2BRR1 = 0xFC; }
            break;
        default:    break;
    }
}


/**
 * @brief 设置uart2数据位数
 *
 * @param DataBit 数据位
 */
void bsp_uart2_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit)
{
    switch (DataBit)
    {
        case UART_DATA_8BIT:
            UART2CR1 &= ~0x08;
            break;
        case UART_DATA_9BIT:
            UART2CR1 |= 0x08;
            break;
        default:
            break;
    }
}


/**
 * @brief 设置uart2校验位
 *
 * @param Check 校验位
 */
void bsp_uart2_check(TYPE_ENUM_UART_CHECK Check)
{
    switch (Check)
    {
        case UART_CHECK_UNCHECK:    UART2CR1 &= ~0x30; break;
        case UART_CHECK_ODD:        UART2CR1 |= 0x30;  break;
        case UART_CHECK_EVEN:       UART2CR1 |= 0x20;  UART2CR1 &= ~0x10;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart2停止位
 *
 * @param Stop 停止位
 */
void bsp_uart2_stop(TYPE_ENUM_UART_STOP Stop)
{
    switch (Stop)
    {
        case UART_STOP_1:   UART2CR3 &= ~0x04;  break;
        case UART_STOP_2:   UART2CR3 |= 0x04;  break;
        default:    break;
    }
}


/**
 * @brief 设置uart2端口
 *
 * @param Chan 端口
 */
void bsp_uart2_chan(TYPE_ENUM_UART_CHAN Chan)
{
    switch (Chan)
    {
        case UART2_RX_P00_TX_P01:   LCMCR1 &= U8_NBIT3;  P0IO &= U8_NBIT0; P0PU |= U8_BIT0;  LCMCR1 &= U8_NBIT2;  P0IO |= U8_BIT1; P0 |= U8_BIT1; break;
        case UART2_RX_P41_TX_P40:   LCMCR1 |= U8_BIT3;   P4IO &= U8_NBIT1; P4PU |= U8_BIT1;  LCMCR1 |= U8_BIT2;   P4IO |= U8_BIT0; P4 |= U8_BIT0; break;
        default:    break;
    }
}


/**
 * @brief 设置串口2发送接收模式，及中断优先级
 *
 * @param Mode 发送接收模式
 * @param IntPriority 中断优先级
 */
void bsp_uart2_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority)
{
    UART2SR = 0;
    UART2CR2 |= 0x60;
    IE1 |= 0x08;

    switch (IntPriority)
    {
        case UART_INT_PRIORITY_0:   IP0 &= ~0x08;   IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_1:   IP0 |= 0x08;    IP1 &= ~0x08;   break;
        case UART_INT_PRIORITY_2:   IP0 &= ~0x08;   IP1 |= 0x08;    break;
        case UART_INT_PRIORITY_3:   IP0 |= 0x08;    IP1 |= 0x08;    break;
        default:    break;
    }
}


/**
 * @brief uart2发送使能
 *
 * @param Switch
 */
void bsp_uart2_tx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART2CR2 |= 0x08;
    else UART2CR2 &= ~0x08;
}


/**
 * @brief uart2接收使能
 *
 * @param Switch
 */
void bsp_uart2_rx_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART2CR2 |= 0x04;
    else UART2CR2 &= ~0x04;
}


/**
 * @brief uart2模块使能
 *
 * @param Switch
 */
void bsp_uart2_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   UART2CR2 |= 0x02;
    else UART2CR2 &= ~0x02;
}


/**
 * @brief uart2 阻塞发送
 *
 * @param Data 发送数据
 */
void bsp_uart2_send_block(unsigned char Data)
{
    UART2DR = Data;
    while (!(UART2SR & 0x40));
}


/**
 * @brief uart2 阻塞接收
 *
 * @return unsigned char 接收数据
 */
unsigned char bsp_uart2_rece_block(void)
{
    while (!(UART2SR & 0x20));
    UART2SR = ~0x28;
    return UART2DR;
}
