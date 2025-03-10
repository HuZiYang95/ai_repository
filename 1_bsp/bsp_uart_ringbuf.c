#include "bsp_uart_ringbuf.h"
#include "bsp_sfr.h"
#include "bsp_uart.h"


#define UART0_SEND_RINGBUF_LEN  10
#define UART0_RECE_RINGBUF_LEN  10

#define UART1_SEND_RINGBUF_LEN  10
#define UART1_RECE_RINGBUF_LEN  10

#define UART2_SEND_RINGBUF_LEN  10
#define UART2_RECE_RINGBUF_LEN  10


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
//                                   uart 0 ringbuf code                                     //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
#if (UART0_SEND_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART0_SEND_RINGBUF_LEN];
}TYPE_STR_UART0_SEND_Q;
xdata TYPE_STR_UART0_SEND_Q Uart0SendQue = { 0,0,1 };
unsigned char Uart0OverTimeCnt = 0;
#endif

#if (UART0_RECE_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART0_RECE_RINGBUF_LEN];
}TYPE_STR_UART0_RECE_Q;
xdata TYPE_STR_UART0_RECE_Q Uart0ReceQue = { 0,0,1 };
#endif


#if (UART0_SEND_RINGBUF_LEN)
void bsp_uart0_err_deal(unsigned char Cnt)
{
    if (1 == Uart0SendQue.Flag)
    {
        if (++Uart0OverTimeCnt > Cnt)
        {
            Uart0OverTimeCnt = 0;
            Uart0SendQue.Flag = 0;
        }
    }
}
TYPE_ENUM_SEND_STATUS bsp_uart0_write(unsigned char *pWriteData, unsigned char Len)
{
    unsigned char TailTemp;
    unsigned char i = 0;
    TYPE_ENUM_SEND_STATUS j = SEND_SUCCESS;

    for (i = 0; i < Len; i++)
    {
        TailTemp = Uart0SendQue.Tail;
        if (++TailTemp == UART0_SEND_RINGBUF_LEN) TailTemp = 0;
        if (Uart0SendQue.Head == TailTemp)
        {
            j = SEND_OVERFLOW;
            if (++Uart0SendQue.Head == UART0_SEND_RINGBUF_LEN) Uart0SendQue.Head = 0;
        }
        Uart0SendQue.Buf[Uart0SendQue.Tail] = *(pWriteData + i);
        Uart0SendQue.Tail = TailTemp;

        if (0 == Uart0SendQue.Flag)
        {
            Uart0SendQue.Flag = 1;
            if (++Uart0SendQue.Head >= UART0_SEND_RINGBUF_LEN) Uart0SendQue.Head = 0;
            BSP_UART0_WRITE_BYTE(Uart0SendQue.Buf[Uart0SendQue.Head]);
            UART0CR2 |= 0x40;
            BSP_UART0_TX_CONPLETE_INT_ENABLE();
        }
    }

    return j;
}
TYPE_ENUM_RINGBUF_STATUS bsp_uart0_sendbuf_status(void)
{
    unsigned char HeadTemp;
    HeadTemp = Uart0SendQue.Head;
    if (++HeadTemp >= UART0_SEND_RINGBUF_LEN) HeadTemp = 0;
    if (Uart0SendQue.Tail == HeadTemp) return RINGBUF_EMPTY;
    else return RINGBUF_NON_EMPTY;
}
void bsp_uart0_send_isr()
{
    unsigned char HeadTemp;

    if ((UART0SR & 0x40) && (UART0CR2 & 0x40))
    {
        UART0SR &= ~0x40;
        Uart0OverTimeCnt = 0;
        HeadTemp = Uart0SendQue.Head;
        if (++HeadTemp >= UART0_SEND_RINGBUF_LEN) HeadTemp = 0;
        if (Uart0SendQue.Tail == HeadTemp)
        {
            UART0CR2 &= ~0x40;
            Uart0SendQue.Flag = 0;
        }
        else
        {
            UART0DR = Uart0SendQue.Buf[HeadTemp];
            Uart0SendQue.Head = HeadTemp;
        }
    }
}
#endif


#if (UART0_RECE_RINGBUF_LEN)
unsigned char bsp_uart0_read(unsigned char *pReadData, unsigned char Len)
{
    unsigned char HeadTemp;
    unsigned char i = 0;

    for (i = 0; i < Len; i++)
    {
        HeadTemp = Uart0ReceQue.Head;
        if (++HeadTemp >= UART0_RECE_RINGBUF_LEN) HeadTemp = 0;
        if (Uart0ReceQue.Tail == HeadTemp) break;
        else
        {
            Uart0ReceQue.Head = HeadTemp;
            *(pReadData + i) = Uart0ReceQue.Buf[HeadTemp];
        }
    }
    return i;
}
void bsp_uart0_rece_isr()
{
    unsigned char ReceData;
    unsigned char TailTemp;

    if (UART0SR & 0x20)
    {
        UART0SR &= ~0x20;
        ReceData = UART0DR;
        TailTemp = Uart0ReceQue.Tail;
        if (++TailTemp == UART0_RECE_RINGBUF_LEN) TailTemp = 0;
        if (Uart0ReceQue.Head == TailTemp)
        {
            if (++Uart0ReceQue.Head >= UART0_RECE_RINGBUF_LEN) Uart0ReceQue.Head = 0;
            Uart0ReceQue.Flag |= 0x01;
        }
        Uart0ReceQue.Buf[Uart0ReceQue.Tail] = ReceData;
        Uart0ReceQue.Tail = TailTemp;
    }
    if (UART0SR & 0x02)
    {
        Uart0ReceQue.Flag |= 0x02;
        UART0SR &= ~0x02;
    }
    if (UART0SR & 0x04)
    {
        Uart0ReceQue.Flag |= 0x04;
        UART0SR &= ~0x04;
    }
}
#endif


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
//                                   uart 1 ringbuf code                                     //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
#if (UART1_SEND_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART1_SEND_RINGBUF_LEN];
}TYPE_STR_UART1_SEND_Q;
xdata TYPE_STR_UART1_SEND_Q Uart1SendQue = { 0,0,1 };
unsigned char Uart1OverTimeCnt = 0;
#endif

#if (UART1_RECE_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART1_RECE_RINGBUF_LEN];
}TYPE_STR_UART1_RECE_Q;
xdata TYPE_STR_UART1_RECE_Q Uart1ReceQue = { 0,0,1 };
#endif


#if (UART1_SEND_RINGBUF_LEN)
void bsp_uart1_err_deal(unsigned char Cnt)
{
    if (1 == Uart1SendQue.Flag)
    {
        if (++Uart1OverTimeCnt > Cnt)
        {
            Uart1OverTimeCnt = 0;
            Uart1SendQue.Flag = 0;
        }
    }
}
TYPE_ENUM_SEND_STATUS bsp_uart1_write(unsigned char *pWriteData, unsigned char Len)
{
    unsigned char TailTemp;
    unsigned char i = 0;
    TYPE_ENUM_SEND_STATUS j = SEND_SUCCESS;

    for (i = 0; i < Len; i++)
    {
        TailTemp = Uart1SendQue.Tail;
        if (++TailTemp == UART1_SEND_RINGBUF_LEN) TailTemp = 0;
        if (Uart1SendQue.Head == TailTemp)
        {
            j = SEND_OVERFLOW;
            if (++Uart1SendQue.Head == UART1_SEND_RINGBUF_LEN) Uart1SendQue.Head = 0;
        }
        Uart1SendQue.Buf[Uart1SendQue.Tail] = *(pWriteData + i);
        Uart1SendQue.Tail = TailTemp;

        if (0 == Uart1SendQue.Flag)
        {
            Uart1SendQue.Flag = 1;
            if (++Uart1SendQue.Head >= UART1_SEND_RINGBUF_LEN) Uart1SendQue.Head = 0;
            UART1DR = Uart1SendQue.Buf[Uart1SendQue.Head];
            UART1CR2 |= 0x40;
        }
    }

    return j;
}
TYPE_ENUM_RINGBUF_STATUS bsp_uart1_sendbuf_status(void)
{
    unsigned char HeadTemp;
    HeadTemp = Uart1SendQue.Head;
    if (++HeadTemp >= UART1_SEND_RINGBUF_LEN) HeadTemp = 0;
    if (Uart1SendQue.Tail == HeadTemp) return RINGBUF_EMPTY;
    else return RINGBUF_NON_EMPTY;
}
void bsp_uart1_send_isr()
{
    unsigned char HeadTemp;

    if ((UART1SR & 0x40) && (UART1CR2 & 0x40))
    {
        UART1SR &= ~0x40;
        Uart1OverTimeCnt = 0;
        HeadTemp = Uart1SendQue.Head;
        if (++HeadTemp >= UART1_SEND_RINGBUF_LEN) HeadTemp = 0;
        if (Uart1SendQue.Tail == HeadTemp)
        {
            UART1CR2 &= ~0x40;
            Uart1SendQue.Flag = 0;
        }
        else
        {
            UART1DR = Uart1SendQue.Buf[HeadTemp];
            Uart1SendQue.Head = HeadTemp;
        }
    }
}
#endif


#if (UART1_RECE_RINGBUF_LEN)
unsigned char bsp_uart1_read(unsigned char *pReadData, unsigned char Len)
{
    unsigned char HeadTemp;
    unsigned char i = 0;

    for (i = 0; i < Len; i++)
    {
        HeadTemp = Uart1ReceQue.Head;
        if (++HeadTemp >= UART1_RECE_RINGBUF_LEN) HeadTemp = 0;
        if (Uart1ReceQue.Tail == HeadTemp) break;
        else
        {
            Uart1ReceQue.Head = HeadTemp;
            *(pReadData + i) = Uart1ReceQue.Buf[HeadTemp];
        }
    }
    return i;
}
void bsp_uart1_rece_isr()
{
    unsigned char ReceData;
    unsigned char TailTemp;

    if (UART1SR & 0x20)
    {
        UART1SR &= ~0x20;
        ReceData = UART1DR;
        TailTemp = Uart1ReceQue.Tail;
        if (++TailTemp == UART1_RECE_RINGBUF_LEN) TailTemp = 0;
        if (Uart1ReceQue.Head == TailTemp)
        {
            if (++Uart1ReceQue.Head >= UART1_RECE_RINGBUF_LEN) Uart1ReceQue.Head = 0;
            Uart1ReceQue.Flag |= 0x01;
        }
        Uart1ReceQue.Buf[Uart1ReceQue.Tail] = ReceData;
        Uart1ReceQue.Tail = TailTemp;
    }
    if (UART1SR & 0x02)
    {
        Uart1ReceQue.Flag |= 0x02;
        UART1SR &= ~0x02;
    }
    if (UART1SR & 0x04)
    {
        Uart1ReceQue.Flag |= 0x04;
        UART1SR &= ~0x04;
    }
}
#endif


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
//                                   uart 2 ringbuf code                                     //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
#if (UART2_SEND_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART2_SEND_RINGBUF_LEN];
}TYPE_STR_UART2_SEND_Q;
xdata TYPE_STR_UART2_SEND_Q Uart2SendQue = { 0,0,1 };
unsigned char Uart2OverTimeCnt = 0;
#endif

#if (UART2_RECE_RINGBUF_LEN)
typedef struct
{
    volatile unsigned char Flag;
    volatile unsigned char Head;
    volatile unsigned char Tail;
    volatile unsigned char Buf[UART2_RECE_RINGBUF_LEN];
}TYPE_STR_UART2_RECE_Q;
xdata TYPE_STR_UART2_RECE_Q Uart2ReceQue = { 0,0,1 };
#endif


#if (UART2_SEND_RINGBUF_LEN)
void bsp_uart2_err_deal(unsigned char Cnt)
{
    if (1 == Uart2SendQue.Flag)
    {
        if (++Uart2OverTimeCnt > Cnt)
        {
            Uart2OverTimeCnt = 0;
            Uart2SendQue.Flag = 0;
        }
    }
}
TYPE_ENUM_SEND_STATUS bsp_uart2_write(unsigned char *pWriteData, unsigned char Len)
{
    unsigned char TailTemp;
    unsigned char i = 0;
    TYPE_ENUM_SEND_STATUS j = SEND_SUCCESS;

    for (i = 0; i < Len; i++)
    {
        TailTemp = Uart2SendQue.Tail;
        if (++TailTemp == UART2_SEND_RINGBUF_LEN) TailTemp = 0;
        if (Uart2SendQue.Head == TailTemp)
        {
            j = SEND_OVERFLOW;
            if (++Uart2SendQue.Head == UART2_SEND_RINGBUF_LEN) Uart2SendQue.Head = 0;
        }
        Uart2SendQue.Buf[Uart2SendQue.Tail] = *(pWriteData + i);
        Uart2SendQue.Tail = TailTemp;

        if (0 == Uart2SendQue.Flag)
        {
            Uart2SendQue.Flag = 1;
            if (++Uart2SendQue.Head >= UART2_SEND_RINGBUF_LEN) Uart2SendQue.Head = 0;
            UART2DR = Uart2SendQue.Buf[Uart2SendQue.Head];
            UART2CR2 |= 0x40;
        }
    }
    return j;
}
TYPE_ENUM_RINGBUF_STATUS bsp_uart2_sendbuf_status(void)
{
    unsigned char HeadTemp;
    HeadTemp = Uart2SendQue.Head;
    if (++HeadTemp >= UART2_SEND_RINGBUF_LEN) HeadTemp = 0;
    if (Uart2SendQue.Tail == HeadTemp) return RINGBUF_EMPTY;
    else return RINGBUF_NON_EMPTY;
}
void bsp_uart2_send_isr()
{
    unsigned char HeadTemp;

    if ((UART2SR & 0x40) && (UART2CR2 & 0x40))
    {
        UART2SR &= ~0x40;
        Uart2OverTimeCnt = 0;
        HeadTemp = Uart2SendQue.Head;
        if (++HeadTemp >= UART2_SEND_RINGBUF_LEN) HeadTemp = 0;
        if (Uart2SendQue.Tail == HeadTemp)
        {
            UART2CR2 &= ~0x40;
            Uart2SendQue.Flag = 0;
        }
        else
        {
            UART2DR = Uart2SendQue.Buf[HeadTemp];
            Uart2SendQue.Head = HeadTemp;
        }
    }
}
#endif


#if (UART2_RECE_RINGBUF_LEN)
unsigned char bsp_uart2_read(unsigned char *pReadData, unsigned char Len)
{
    unsigned char HeadTemp;
    unsigned char i = 0;

    for (i = 0; i < Len; i++)
    {
        HeadTemp = Uart2ReceQue.Head;
        if (++HeadTemp >= UART2_RECE_RINGBUF_LEN) HeadTemp = 0;
        if (Uart2ReceQue.Tail == HeadTemp) break;
        else
        {
            Uart2ReceQue.Head = HeadTemp;
            *(pReadData + i) = Uart2ReceQue.Buf[HeadTemp];
        }
    }
    return i;
}
void bsp_uart2_rece_isr()
{
    unsigned char ReceData;
    unsigned char TailTemp;

    if (UART2SR & 0x20)
    {
        UART2SR &= ~0x20;
        ReceData = UART2DR;
        TailTemp = Uart2ReceQue.Tail;
        if (++TailTemp == UART2_RECE_RINGBUF_LEN) TailTemp = 0;
        if (Uart2ReceQue.Head == TailTemp)
        {
            if (++Uart2ReceQue.Head >= UART2_RECE_RINGBUF_LEN) Uart2ReceQue.Head = 0;
            Uart2ReceQue.Flag |= 0x01;
        }
        Uart2ReceQue.Buf[Uart2ReceQue.Tail] = ReceData;
        Uart2ReceQue.Tail = TailTemp;
    }
    if (UART2SR & 0x02)
    {
        Uart2ReceQue.Flag |= 0x02;
        UART2SR &= ~0x02;
    }
    if (UART2SR & 0x04)
    {
        Uart2ReceQue.Flag |= 0x04;
        UART2SR &= ~0x04;
    }
}
#endif



#if ((UART0_RECE_RINGBUF_LEN) || (UART0_SEND_RINGBUF_LEN) || (UART1_RECE_RINGBUF_LEN) || (UART1_SEND_RINGBUF_LEN) || (UART2_RECE_RINGBUF_LEN) || (UART2_SEND_RINGBUF_LEN))
void uart_interrupt_func(void) interrupt 9
{
#if (UART0_RECE_RINGBUF_LEN)
    bsp_uart0_rece_isr();
#endif
#if (UART0_SEND_RINGBUF_LEN)
    bsp_uart0_send_isr();
#endif

#if (UART1_RECE_RINGBUF_LEN)
    bsp_uart1_rece_isr();
#endif
#if (UART1_SEND_RINGBUF_LEN)
    bsp_uart1_send_isr();
#endif

#if (UART2_RECE_RINGBUF_LEN)
    bsp_uart2_rece_isr();
#endif
#if (UART2_SEND_RINGBUF_LEN)
    bsp_uart2_send_isr();
#endif
}
#endif
