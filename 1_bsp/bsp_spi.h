/**
 * @file bsp_spi.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_SPI_H_
#define _BSP_SPI_H_


#include "typedef.h"


typedef enum
{
    SPI_MASTER = 0,
    SPI_SLAVE = 1
}TYPE_ENUM_SPI_M_S;


typedef enum
{
    SPI_DATA_MSB = 0,
    SPI_DATA_LSB = 1
}TYPE_ENUM_SPI_SEND_MODE;


typedef enum
{
    SPI_CLK_DIV_4 = 0x00,
    SPI_CLK_DIV_16 = 0x01,
    SPI_CLK_DIV_64 = 0x02,
    SPI_CLK_DIV_128 = 0x03,
    SPI_CLK_DIV_2 = 0x04,
    SPI_CLK_DIV_8 = 0x05,
    SPI_CLK_DIV_32 = 0x06
    //    SPI_CLK_DIV_64 = 0x07
}TYPE_ENUM_SPI_CLK;


typedef enum
{
    SPI_S_POLL_R_POLL = 0,
    SPI_S_INT_R_POLL = 1,
    SPI_S_POLL_R_INT = 2,
    SPI_S_INT_R_INT = 3
}TYPE_ENUM_SPI_INT_MODE;


typedef enum
{
    SPI_CHAN_P2 = 0,
    SPI_CHAN_P1 = 1
}TYPE_ENUM_SPI_CHAN;


#define BSP_SPI_INT_FLAG_GET()  (SPISR & 0x80)
#define BSP_SPI_INT_FLAG_CLR()  (SPISR &= ~0x80)

#define BSP_SPI_SEND_EMPTY_FLAG_GET()   (SPISR & 0x02)
#define BSP_SPI_SEND_EMPTY_FLAG_CLR()   (SPISR &= ~0x02)

#define BSP_SPI_RECE_NOT_EMPTY_FLAG_GET()   (SPISR & 0x01)
#define BSP_SPI_RECE_NOT_EMPTY_FLAG_CLR()   (SPISR &= ~0x01)


extern void bsp_spi_init(TYPE_ENUM_SPI_M_S MasterSlave, TYPE_ENUM_SPI_SEND_MODE MsbLsb, TYPE_ENUM_SPI_CLK Clk, TYPE_ENUM_SPI_INT_MODE IntMode, TYPE_ENUM_SPI_CHAN Chan);
extern void bsp_spi_m_s(TYPE_ENUM_SPI_M_S MasterSlave);
extern void bsp_spi_send_mode(TYPE_ENUM_SPI_SEND_MODE MsbLsb);
extern void bsp_spi_clk(TYPE_ENUM_SPI_CLK Clk);
extern void bsp_spi_int_mode(TYPE_ENUM_SPI_INT_MODE IntMode);
extern void bsp_spi_chan(TYPE_ENUM_SPI_CHAN Chan, TYPE_ENUM_SPI_M_S MasterSlave);
extern void bsp_spi_switch(TYPE_ENUM_SWITCH Switch);
extern unsigned char bsp_spi_send_irq(unsigned char Data);
extern unsigned char bsp_spi_write_read_poll(unsigned char Data);

#endif
