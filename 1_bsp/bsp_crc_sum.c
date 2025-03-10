/**
 * @file bsp_crc_sum.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_crc_sum.h"
#include "bsp_sfr.h"
#include "typedef.h"


 /**
  * @brief 对ram进行crc校验(x^16 + x^12 + x^5 + 1)
  *
  * @param StartAddr ram校验开始地址指针
  * @param Len 进行校验的长度
  *
  * @return unsigned int 12位crc校验结果
  *
  * @note 多项式为 x^16 + x^12 + x^5 + 1
  */
unsigned int crc_check_ram(unsigned char *StartAddr, unsigned int Len)
{
    unsigned int i = 0;

    CRCDH = 0;
    CRCDL = 0;
    CRCIN = 0;

    for (i = 0; i < Len; i++)
    {
        CRCIN = *(StartAddr + i);
    }

    NOP(); NOP(); NOP(); NOP(); NOP();
    NOP(); NOP(); NOP(); NOP(); NOP();

    i = CRCDH;
    i = i << 8;
    i += CRCDL;

    return i;
}


/**
 * @brief 对rom进行crc校验(x^16 + x^12 + x^5 + 1)
 *
 * @param StartAddr rom校验开始地址
 * @param Len 进行校验的长度
 *
 * @return unsigned int 12位crc校验结果
 *
 * @note 多项式为 x^16 + x^12 + x^5 + 1
 */
unsigned int crc_check_rom(unsigned int StartAddr, unsigned int Len)
{
    unsigned int i = 0;

    // MOV指令寻址Flash
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR = 0x00;
    KEYCODE = 0x00;

    CRCDH = 0;
    CRCDL = 0;
    CRCIN = 0;

    for (i = 0; i < Len; i++)
    {
        CRCIN = CBYTE[StartAddr + i];
    }

    NOP(); NOP(); NOP(); NOP(); NOP();
    NOP(); NOP(); NOP(); NOP(); NOP();

    i = CRCDH;
    i = i << 8;
    i += CRCDL;

    return i;
}


/**
 * @brief 对ram进行sum校验
 *
 * @param StartAddr rom校验开始地址指针
 * @param Len 进行校验的长度
 *
 * @return unsigned char 8位sum校验结果
 *
 * @note 无
 */
unsigned char sum_check_ram(unsigned char *StartAddr, unsigned int Len)
{
    unsigned int i = 0;
    unsigned int j = 0;

    for (i = 0; i < Len; i++)
    {
        j += *(StartAddr + i);
    }

    return j;
}


/**
 * @brief 对rom进行sum校验
 *
 * @param StartAddr rom校验开始地址
 * @param Len 进行校验的长度
 *
 * @return unsigned char 8位sum校验结果
 *
 * @note 无
 */
unsigned char sum_check_rom(unsigned int StartAddr, unsigned int Len)
{
    unsigned int i = 0;
    unsigned int j = 0;

    for (i = 0; i < Len; i++)
    {
        j += CBYTE[StartAddr + i];
    }

    return j;
}
