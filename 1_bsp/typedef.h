/**
 * @file typedef.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <intrins.h>  // 修正包含格式

typedef unsigned char   u8;
typedef unsigned int    u16;
typedef unsigned long   u32;
typedef char            s8;
typedef int             s16;
typedef long            s32;

#define CBYTE ((unsigned char volatile code  *) 0)
#define DBYTE ((unsigned char volatile data  *) 0)
#define XBYTE ((unsigned char volatile xdata *) 0)

typedef enum
    {
    DISABLE = 0x00,
    ENABLE = 0x01
    }TYPE_ENUM_SWITCH;

typedef enum
    {
    FALSE = 0x00,
    TRUE = 0x01
    }TYPE_ENUM_BOOL;

typedef enum
    {
    ERROR = 0x00,
    SUCCESS = 0x01
    }TYPE_ENUM_STATUS;

typedef enum
    {
    STABLE = 0x00,
    TRIGGER = 0x01
    }TYPE_ENUM_FLAG;

typedef enum
    {
    U8_BIT0 = 0x01,
    U8_BIT1 = 0x02,
    U8_BIT2 = 0x04,
    U8_BIT3 = 0x08,
    U8_BIT4 = 0x10,
    U8_BIT5 = 0x20,
    U8_BIT6 = 0x40,
    U8_BIT7 = 0x80,
    U8_NBIT0 = ~0x01,
    U8_NBIT1 = ~0x02,
    U8_NBIT2 = ~0x04,
    U8_NBIT3 = ~0x08,
    U8_NBIT4 = ~0x10,
    U8_NBIT5 = ~0x20,
    U8_NBIT6 = ~0x40,
    U8_NBIT7 = ~0x80
    }TYPE_ENUM_BYTE;

typedef enum
    {
    U16_BIT0 = 0x0001,
    U16_BIT1 = 0x0002,
    U16_BIT2 = 0x0004,
    U16_BIT3 = 0x0008,
    U16_BIT4 = 0x0010,
    U16_BIT5 = 0x0020,
    U16_BIT6 = 0x0040,
    U16_BIT7 = 0x0080,
    U16_BIT8 = 0x0100,
    U16_BIT9 = 0x0200,
    U16_BIT10 = 0x0400,
    U16_BIT11 = 0x0800,
    U16_BIT12 = 0x1000,
    U16_BIT13 = 0x2000,
    U16_BIT14 = 0x4000,
    U16_BIT15 = 0x8000,
    U16_NBIT0 = ~0x0001,
    U16_NBIT1 = ~0x0002,
    U16_NBIT2 = ~0x0004,
    U16_NBIT3 = ~0x0008,
    U16_NBIT4 = ~0x0010,
    U16_NBIT5 = ~0x0020,
    U16_NBIT6 = ~0x0040,
    U16_NBIT7 = ~0x0080,
    U16_NBIT8 = ~0x0100,
    U16_NBIT9 = ~0x0200,
    U16_NBIT10 = ~0x0400,
    U16_NBIT11 = ~0x0800,
    U16_NBIT12 = ~0x1000,
    U16_NBIT13 = ~0x2000,
    U16_NBIT14 = ~0x4000,
    U16_NBIT15 = ~0x8000
    }TYPE_ENUM_WORD;

typedef enum
    {
    PIN_0 = 0x01,
    PIN_1 = 0x02,
    PIN_2 = 0x04,
    PIN_3 = 0x08,
    PIN_4 = 0x10,
    PIN_5 = 0x20,
    PIN_6 = 0x40,
    PIN_7 = 0x80,
    NPIN_0 = ~0x01,
    NPIN_1 = ~0x02,
    NPIN_2 = ~0x04,
    NPIN_3 = ~0x08,
    NPIN_4 = ~0x10,
    NPIN_5 = ~0x20,
    NPIN_6 = ~0x40,
    NPIN_7 = ~0x80
    }TYPE_ENUM_PIN;


#endif
