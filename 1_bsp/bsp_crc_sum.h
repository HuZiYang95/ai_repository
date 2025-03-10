/**
 * @file bsp_crc_sum.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_CRC_SUM_H_
#define _BSP_CRC_SUM_H_

#include "typedef.h"

extern unsigned int crc_check_ram(unsigned char *StartAddr, unsigned int Len);
extern unsigned int crc_check_rom(unsigned int StartAddr, unsigned int Len);
extern unsigned char sum_check_ram(unsigned char *StartAddr, unsigned int Len);
extern unsigned char sum_check_rom(unsigned int StartAddr, unsigned int Len);

#endif
