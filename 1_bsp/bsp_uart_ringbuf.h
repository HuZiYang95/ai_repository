#ifndef _BSP_UART_RINGBUF_H_
#define _BSP_UART_RINGBUF_H_

#include "typedef.h"

typedef enum
{
    RINGBUF_EMPTY = 0,
    RINGBUF_NON_EMPTY
}TYPE_ENUM_RINGBUF_STATUS;

typedef enum
{
    SEND_SUCCESS = 0,
    SEND_OVERFLOW
}TYPE_ENUM_SEND_STATUS;

extern void bsp_uart0_err_deal(unsigned char Cnt);
extern TYPE_ENUM_SEND_STATUS bsp_uart0_write(unsigned char *pWriteData, unsigned char Len);
extern TYPE_ENUM_RINGBUF_STATUS bsp_uart0_sendbuf_status(void);
extern unsigned char bsp_uart0_read(unsigned char *pReadData, unsigned char Len);

extern void bsp_uart1_err_deal(unsigned char Cnt);
extern TYPE_ENUM_SEND_STATUS bsp_uart1_write(unsigned char *pWriteData, unsigned char Len);
extern TYPE_ENUM_RINGBUF_STATUS bsp_uart1_sendbuf_status(void);
extern unsigned char bsp_uart1_read(unsigned char *pReadData, unsigned char Len);

extern void bsp_uart2_err_deal(unsigned char Cnt);
extern TYPE_ENUM_SEND_STATUS bsp_uart2_write(unsigned char *pWriteData, unsigned char Len);
extern TYPE_ENUM_RINGBUF_STATUS bsp_uart2_sendbuf_status(void);
extern unsigned char bsp_uart2_read(unsigned char *pReadData, unsigned char Len);

#endif
