/**
 * @file bsp_spi.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_spi.h"
#include "bsp_sfr.h"


void bsp_spi_init(TYPE_ENUM_SPI_M_S MasterSlave, TYPE_ENUM_SPI_SEND_MODE MsbLsb, TYPE_ENUM_SPI_CLK Clk, \
    TYPE_ENUM_SPI_INT_MODE IntMode, TYPE_ENUM_SPI_CHAN Chan)
{
    // 1-配置主从机模式
    bsp_spi_m_s(MasterSlave);
    // 2-空闲状态SCK保持1
    SPICR1 &= U8_NBIT4;
    // 3-SCK周期第一个沿采样
    SPICR1 &= U8_NBIT3;
    // 4-配置大小端模式
    bsp_spi_send_mode(MsbLsb);
    // 5-配置时钟分频
    bsp_spi_clk(Clk);
    // 6-配置中断模式及优先级
    bsp_spi_int_mode(IntMode);
    // 7-配置端口
    bsp_spi_chan(Chan, MasterSlave);
    // 8-使能spi模块
    bsp_spi_switch(ENABLE);

}


void bsp_spi_m_s(TYPE_ENUM_SPI_M_S MasterSlave)
{
    switch (MasterSlave)
    {
        case SPI_MASTER: SPICR1 |= U8_BIT5; break;
        case SPI_SLAVE: SPICR1 &= U8_NBIT5; break;
        default: break;
    }
}


void bsp_spi_send_mode(TYPE_ENUM_SPI_SEND_MODE MsbLsb)
{
    switch (MsbLsb)
    {
        case SPI_DATA_MSB: SPICR1 |= U8_BIT6; break;
        case SPI_DATA_LSB: SPICR1 &= U8_NBIT6; break;
        default: break;
    }
}


void bsp_spi_clk(TYPE_ENUM_SPI_CLK Clk)
{
    unsigned char i;

    i = SPICR1;
    i &= 0xF8;
    i |= Clk;
    SPICR1 = i;
}


void bsp_spi_int_mode(TYPE_ENUM_SPI_INT_MODE IntMode)
{
    switch (IntMode)
    {
        case SPI_S_POLL_R_POLL: SPICR2 &= U8_NBIT6; SPICR2 &= U8_NBIT7; break;
        case SPI_S_INT_R_POLL: SPICR2 |= U8_BIT7; SPICR2 &= U8_NBIT6; IE2 |= U8_BIT1; break;
        case SPI_S_POLL_R_INT: SPICR2 |= U8_BIT6; SPICR2 &= U8_NBIT7; IE2 |= U8_BIT1; break;
        case SPI_S_INT_R_INT: SPICR2 |= U8_BIT6; SPICR2 |= U8_BIT7; IE2 |= U8_BIT1; break;
        default:  break;
    }
}


void bsp_spi_chan(TYPE_ENUM_SPI_CHAN Chan, TYPE_ENUM_SPI_M_S MasterSlave)
{
    switch (Chan)
    {
        case SPI_CHAN_P2:
            SEGCR3 &= U8_NBIT0; LCMCR2 &= (U8_NBIT0 & U8_NBIT0 & U8_NBIT0); // 端口映射
            if (SPI_MASTER == MasterSlave)
            {
                P2 |= (U8_BIT2 | U8_BIT4 | U8_BIT5);
                P2IO |= (U8_BIT2 | U8_BIT4 | U8_BIT5);
                P2IO &= U8_NBIT3;
                P2PU |= U8_BIT3;
            }
            else if (SPI_SLAVE == MasterSlave)
            {
                P2 |= U8_BIT3;
                P2IO &= (U8_NBIT2 & U8_NBIT4 & U8_NBIT5);
                P2IO |= U8_BIT3;
                P2PU |= (U8_BIT2 | U8_BIT4 | U8_BIT5);
            }
            break;
        case SPI_CHAN_P1:
            SEGCR3 |= U8_BIT0; LCMCR2 |= (U8_BIT0 & U8_BIT0 & U8_BIT0); // 端口映射
            if (SPI_MASTER == MasterSlave)
            {
                P1 |= (U8_BIT0 | U8_BIT2 | U8_BIT3);
                P1IO |= (U8_BIT0 | U8_BIT2 | U8_BIT3);
                P1IO &= U8_NBIT1;
                P1PU |= U8_BIT1;
            }
            else if (SPI_SLAVE == MasterSlave)
            {
                P2 |= U8_BIT1;
                P2IO &= (U8_NBIT0 & U8_NBIT2 & U8_NBIT3);
                P2IO |= U8_BIT1;
                P2PU |= (U8_BIT0 | U8_BIT2 | U8_BIT3);
            }
            break;

        default:
            break;
    }
}


void bsp_spi_switch(TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch)   SPICR1 |= U8_BIT7;
    else SPICR1 &= U8_NBIT7;
}


unsigned char bsp_spi_send_irq(unsigned char Data)
{
    SPIDR = Data;
    return SPIDR;
}


unsigned char bsp_spi_write_read_poll(unsigned char Data)
{
    while (!(SPISR & 0x02));
    SPIDR = Data;
    while (!(SPISR & 0x01));
    SPISR &= ~0x01;
    return SPIDR;
}
