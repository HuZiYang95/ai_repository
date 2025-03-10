/**
 * @file bsp_uart.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "typedef.h"
#include "bsp_sfr.h"


typedef enum
{
    UART_BAUD_2400 = 0,
    UART_BAUD_4800,
    UART_BAUD_9600,
    UART_BAUD_14400,
    UART_BAUD_19200,
    UART_BAUD_115200
}TYPE_ENUM_UART_BAUD;

typedef enum
{
    UART_DATA_8BIT = 0,
    UART_DATA_9BIT
}TYPE_ENUM_UART_DATA_BIT;

typedef enum
{
    UART_CHECK_EVEN = 0,
    UART_CHECK_ODD,
    UART_CHECK_UNCHECK,
}TYPE_ENUM_UART_CHECK;

typedef enum
{
    UART_STOP_1 = 0,
    UART_STOP_2,
}TYPE_ENUM_UART_STOP;

typedef enum
{
    UART0_RX_P20_TX_P21 = 0,
    UART0_RX_P20_TX_P17,
    UART1_RX_P26_TX_P27,
    UART1_RX_P45_TX_P44,
    UART2_RX_P00_TX_P01,
    UART2_RX_P41_TX_P40
}TYPE_ENUM_UART_CHAN;

typedef enum
{
    UART_INT_PRIORITY_0 = 0,
    UART_INT_PRIORITY_1,
    UART_INT_PRIORITY_2,
    UART_INT_PRIORITY_3
}TYPE_ENUM_UART_INT_PRIORITY;


// 读取串口0接收标志位
#define BSP_UART0_RX_BUF_EMPTY_FLAG_GET()   (UART0SR & 0x20)
// 清零串口0接收标志位
#define BSP_UART0_RX_BUF_EMPTY_FLAG_CLR()   (UART0SR = ~0x28)
// 读取串口0发送完成标志位
#define BSP_UART0_TX_COMPLETE_FLAG_GET()    (UART0SR & 0x40)
// 清零串口0发送完成标志位
#define BSP_UART0_TX_COMPLETE_FLAG_CLR()    (UART0SR = ~0x48)
// 读取串口0发送完成中断使能
#define BSP_UART0_TX_CONPLETE_INT_GET()     (UART0CR2 & 0x40)
// 使能串口0发送完成中断
#define BSP_UART0_TX_CONPLETE_INT_ENABLE()  (UART0CR2 |= 0x40)
// 关闭串口0发送完成中断
#define BSP_UART0_TX_CONPLETE_INT_DISABLE() (UART0CR2 &= ~0x40)
// 使能串口0发送
#define BSP_UART0_TX_ENABLE()               (UART0CR2 |= 0x80)
// 关闭串口0发送
#define BSP_UART0_TX_DISABLE()              (UART0CR2 &= ~0x80)
// 读取串口0溢出错误标志位
#define BSP_UART0_OVERFLOW_ERR_GET()        (UART0SR & 0x04)
// 清零串口0溢出错误标志位
#define BSP_UART0_OVERFLOW_ERR_CLR()        (UART0SR = ~0x0C)
// 读取串口0帧错误标志位
#define BSP_UART0_FRAME_ERR_GET()           (UART0SR & 0x02)
// 清零串口0帧错误标志位
#define BSP_UART0_FRAME_ERR_CLR()           (UART0SR = ~0x0A)
// 读取串口0校验错误标志位
#define BSP_UART0_CHECK_ERR_GET()           (UART0SR & 0x01)
// 清零串口0校验错误标志位
#define BSP_UART0_CHECK_ERR_CLR()           (UART0SR = ~0x09)
// 串口0写入数据至数据寄存器
#define BSP_UART0_WRITE_BYTE(x)             (UART0DR = x)
// 串口0从数据寄存器读取数据
#define BSP_UART0_READ_BYTE(x)              (x = UART0DR)


// 读取串口1接收标志位
#define BSP_UART1_RX_BUF_EMPTY_FLAG_GET()   (UART1SR & 0x20)
// 清零串口1接收标志位
#define BSP_UART1_RX_BUF_EMPTY_FLAG_CLR()   (UART1SR = ~0x28)
// 读取串口1发送完成标志位
#define BSP_UART1_TX_COMPLETE_FLAG_GET()    (UART1SR & 0x40)
// 清零串口1发送完成标志位
#define BSP_UART1_TX_COMPLETE_FLAG_CLR()    (UART1SR = ~0x48)
// 读取串口1发送完成中断使能
#define BSP_UART1_TX_CONPLETE_INT_GET()     (UART1CR2 & 0x40)
// 使能串口1发送完成中断
#define BSP_UART1_TX_CONPLETE_INT_ENABLE()  (UART1CR2 |= 0x40)
// 关闭串口1发送完成中断
#define BSP_UART1_TX_CONPLETE_INT_DISABLE() (UART1CR2 &= ~0x40)
// 使能串口1发送
#define BSP_UART1_TX_ENABLE()               (UART1CR2 |= 0x80)
// 关闭串口1发送
#define BSP_UART1_TX_DISABLE()              (UART1CR2 &= ~0x80)
// 读取串口1溢出错误标志位
#define BSP_UART1_OVERFLOW_ERR_GET()        (UART1SR & 0x04)
// 清零串口1溢出错误标志位
#define BSP_UART1_OVERFLOW_ERR_CLR()        (UART1SR = ~0x0C)
// 读取串口1帧错误标志位
#define BSP_UART1_FRAME_ERR_GET()           (UART1SR & 0x02)
// 清零串口1帧错误标志位
#define BSP_UART1_FRAME_ERR_CLR()           (UART1SR = ~0x0A)
// 读取串口1校验错误标志位
#define BSP_UART1_CHECK_ERR_GET()           (UART1SR & 0x01)
// 清零串口1校验错误标志位
#define BSP_UART1_CHECK_ERR_CLR()           (UART1SR = ~0x09)
// 串口1写入数据至数据寄存器
#define BSP_UART1_WRITE_BYTE(x)             (UART1DR = x)
// 串口1从数据寄存器读取数据
#define BSP_UART1_READ_BYTE(x)              (x = UART1DR)


// 读取串口2接收标志位
#define BSP_UART2_RX_BUF_EMPTY_FLAG_GET()   (UART2SR & 0x20)
// 清零串口2接收标志位
#define BSP_UART2_RX_BUF_EMPTY_FLAG_CLR()   (UART2SR = ~0x28)
// 读取串口2发送完成标志位
#define BSP_UART2_TX_COMPLETE_FLAG_GET()    (UART2SR & 0x40)
// 清零串口2发送完成标志位
#define BSP_UART2_TX_COMPLETE_FLAG_CLR()    (UART2SR = ~0x48)
// 读取串口2发送完成中断使能
#define BSP_UART2_TX_CONPLETE_INT_GET()     (UART2CR2 & 0x40)
// 使能串口2发送完成中断
#define BSP_UART2_TX_CONPLETE_INT_ENABLE()  (UART2CR2 |= 0x40)
// 关闭串口2发送完成中断
#define BSP_UART2_TX_CONPLETE_INT_DISABLE() (UART2CR2 &= ~0x40)
// 使能串口2发送
#define BSP_UART2_TX_ENABLE()               (UART2CR2 |= 0x80)
// 关闭串口2发送
#define BSP_UART2_TX_DISABLE()              (UART2CR2 &= ~0x80)
// 读取串口2溢出错误标志位
#define BSP_UART2_OVERFLOW_ERR_GET()        (UART2SR & 0x04)
// 清零串口2溢出错误标志位
#define BSP_UART2_OVERFLOW_ERR_CLR()        (UART2SR = ~0x0C)
// 读取串口2帧错误标志位
#define BSP_UART2_FRAME_ERR_GET()           (UART2SR & 0x02)
// 清零串口2帧错误标志位
#define BSP_UART2_FRAME_ERR_CLR()           (UART2SR = ~0x0A)
// 读取串口2校验错误标志位
#define BSP_UART2_CHECK_ERR_GET()           (UART2SR & 0x01)
// 清零串口2校验错误标志位
#define BSP_UART2_CHECK_ERR_CLR()           (UART2SR = ~0x09)
// 串口2写入数据至数据寄存器
#define BSP_UART2_WRITE_BYTE(x)             (UART2DR = x)
// 串口2从数据寄存器读取数据
#define BSP_UART2_READ_BYTE(x)              (x = UART2DR)


extern void bsp_uart0_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart0_baud(TYPE_ENUM_UART_BAUD Baud);
extern void bsp_uart0_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit);
extern void bsp_uart0_check(TYPE_ENUM_UART_CHECK Check);
extern void bsp_uart0_stop(TYPE_ENUM_UART_STOP Stop);
extern void bsp_uart0_chan(TYPE_ENUM_UART_CHAN Chan);
extern void bsp_uart0_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart0_tx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart0_rx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart0_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart0_send_block(unsigned char Data);
extern unsigned char bsp_uart0_rece_block(void);

extern void bsp_uart1_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart1_baud(TYPE_ENUM_UART_BAUD Baud);
extern void bsp_uart1_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit);
extern void bsp_uart1_check(TYPE_ENUM_UART_CHECK Check);
extern void bsp_uart1_stop(TYPE_ENUM_UART_STOP Stop);
extern void bsp_uart1_chan(TYPE_ENUM_UART_CHAN Chan);
extern void bsp_uart1_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart1_tx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart1_rx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart1_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart1_send_block(unsigned char Data);
extern unsigned char bsp_uart1_rece_block(void);

extern void bsp_uart2_init(TYPE_ENUM_UART_BAUD Baud, TYPE_ENUM_UART_CHAN Chan, TYPE_ENUM_SWITCH TxEnable, TYPE_ENUM_SWITCH RxEnable, TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart2_baud(TYPE_ENUM_UART_BAUD Baud);
extern void bsp_uart2_data_bit(TYPE_ENUM_UART_DATA_BIT DataBit);
extern void bsp_uart2_check(TYPE_ENUM_UART_CHECK Check);
extern void bsp_uart2_stop(TYPE_ENUM_UART_STOP Stop);
extern void bsp_uart2_chan(TYPE_ENUM_UART_CHAN Chan);
extern void bsp_uart2_mode_priority(TYPE_ENUM_UART_INT_PRIORITY IntPriority);
extern void bsp_uart2_tx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart2_rx_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart2_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_uart2_send_block(unsigned char Data);
extern unsigned char bsp_uart2_rece_block(void);

#endif
