/**
 * @file bsp_flash_eep.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_flash_eep.h"
#include "bsp_sfr.h"
#include "typedef.h"


 /**
  * @brief 对flash地址进行保护
  *
  * @param ProteceFlashAddr 保护的地址段
  */
void bsp_flash_protect(TYPE_ENUM_FLASH_PROTECE ProteceFlashAddr)
{
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR1 = ProteceFlashAddr;
    KEYCODE = 0;
}


/**
 * @brief flash 页擦
 *
 * @param addr 页擦地址
 */
void bsp_flash_erase_page(TYPE_ENUM_FLASH_ERASE EraseFlashAddr)
{
    unsigned char Temp;

    Temp = IE0;
    EA = 0;
    bsp_flash_protect(FLASH_UNPROTECT);
    FSAHR = EraseFlashAddr << 2;
    FSALR = 0;
    FSDR = 0;
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR |= 0x02;
    while (FSCR & 0x02);
    _nop_();
    _nop_();
    _nop_();
    KEYCODE = 0;
    bsp_flash_protect(FLASH_PROTECT_FFFF);
    IE0 = Temp;
}


/**
 * @brief flash字写
 *
 * @param addr flash地址
 * @param dat  写入的数据
 */
void bsp_flash_write_byte(unsigned int addr, unsigned char dat)
{
    unsigned char Temp;

    Temp = IE0;
    EA = 0;
    bsp_flash_protect(FLASH_UNPROTECT);
    FSAHR = (unsigned char)(addr >> 8);
    FSALR = (unsigned char)(addr & 0xFF);
    FSDR = dat;
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR |= 0x01;
    while (FSCR & 0x01);
    _nop_();
    _nop_();
    _nop_();
    KEYCODE = 0;
    bsp_flash_protect(FLASH_PROTECT_FFFF);
    IE0 = Temp;
}


/**
 * @brief flash字读
 *
 * @param addr flash地址
 *
 * @return unsigned char 读取的数据
 */
unsigned char bsp_flash_read_byte(unsigned int addr)
{
    unsigned char dat = 0;
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    dat = CBYTE[addr];
    KEYCODE = 0;
    return dat;
}


/**
 * @brief eep页擦
 *
 */
void bsp_eep_erase_page(void)
{
    unsigned char Temp;

    Temp = IE0;
    EA = 0;
    FSAHR = 0x00;
    FSALR = 0x00;
    FSDR = 0x00;
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR |= 0x20;   //enable eep
    FSCR |= 0x04;   //erase
    while (FSCR & 0x04);
    FSCR = 0;
    KEYCODE = 0;
    IE0 = Temp;
}


/**
 * @brief eep字写
 *
 * @param addr eep地址  { 0x0000 ~ 0x03FF }
 *
 * @param dat  写入的数据
 *
 * @note 注意写完把 "FSCR" 清零
 */
void bsp_eep_write_byte(unsigned int addr, unsigned char dat)
{
    unsigned char Temp;

    Temp = IE0;
    EA = 0;
    FSAHR = (unsigned char)(addr >> 8);
    FSALR = (unsigned char)(addr & 0xFF);
    FSDR = dat;
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR |= 0x20;   //enable eep
    FSCR |= 0x10;   //write
    while (FSCR & 0x10);
    FSCR = 0;
    KEYCODE = 0;
    IE0 = Temp;
}


/**
 * @brief eep字读
 *
 * @param addr eep地址  { 0x0000 ~ 0x03FF }
 *
 * @return unsigned char 读取的数据
 *
 * @note 注意写完把 "FSCR" 清零
 */
unsigned char bsp_eep_read_byte(unsigned int addr)
{
    unsigned char dat = 0;
    unsigned char Temp;

    Temp = IE0;
    EA = 0;
    FSAHR = (unsigned char)(addr >> 8);
    FSALR = (unsigned char)(addr & 0xFF);
    KEYCODE = 0x3C;
    KEYCODE = 0x02;
    KEYCODE = 0xA1;
    FSCR |= 0x20;          //enable eep
    FSCR |= 0x08;          //read
    dat = CBYTE[addr];
    FSCR = 0;
    KEYCODE = 0;
    IE0 = Temp;
    return dat;
}
