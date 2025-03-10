/**
 * @file bsp_gpio.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_GPIO_H_
#define _BSP_GPIO_H_

#include "typedef.h"
#include "bsp_sfr.h"

#define GPIO_DATA_HIGH(DATA_SFR, PIN)       (DATA_SFR |= PIN)
#define GPIO_DATA_LOW(DATA_SFR, PIN)        (DATA_SFR &= ~PIN)
#define GPIO_DATA_TURN(DATA_SFR, PIN)       (DATA_SFR ^= PIN)
#define GPIO_DATA_GET(DATA_SFR, PIN)        (DATA_SFR & PIN)
#define GPIO_DIR_OUTPUT(DIR_SFR, PIN)       (DIR_SFR |= PIN)
#define GPIO_DIR_INPUT(DIR_SFR, PIN)        (DIR_SFR &= ~PIN)
#define GPIO_PULL_ENABLE(PULL_SFR, PIN)     (PULL_SFR |= PIN)
#define GPIO_PULL_DISABLE(PULL_SFR, PIN)    (PULL_SFR &= ~PIN)
#define GPIO_MODE_OD(MODE_SFR, PIN)         (MODE_SFR |= PIN)
#define GPIO_MODE_PP(MODE_SFR, PIN)         (MODE_SFR &= ~PIN)


 /**
  * @brief gpio - 端口号
  *
  */
typedef enum
{
    GPIO_PORT_0 = 0,
    GPIO_PORT_1,
    GPIO_PORT_2,
    GPIO_PORT_3,
    GPIO_PORT_4,
    GPIO_PORT_5
}TYPE_ENUM_GPIO_PORT;


typedef enum
{
    GPIO_COM0_P30 = 0x01,
    GPIO_COM1_P31 = 0x02,
    GPIO_COM2_P32 = 0x04,
    GPIO_COM3_P33 = 0x08,
    GPIO_COM4_P34 = 0x10,
    GPIO_COM5_P35 = 0x20,
    GPIO_COM6_P36 = 0x40,
    GPIO_COM7_P37 = 0x80
}TYPE_ENUM_GPIO_COM;

#define GPIO_DATA_0     P0
#define GPIO_DATA_1     P1
#define GPIO_DATA_2     P2
#define GPIO_DATA_3     P3
#define GPIO_DATA_4     P4
#define GPIO_DATA_5     P5
#define GPIO_DIR_0      P0IO
#define GPIO_DIR_1      P1IO
#define GPIO_DIR_2      P2IO
#define GPIO_DIR_3      P3IO
#define GPIO_DIR_4      P4IO
#define GPIO_DIR_5      P5IO
#define GPIO_PULL_0     P0PU
#define GPIO_PULL_1     P1PU
#define GPIO_PULL_2     P2PU
#define GPIO_PULL_3     P3PU
#define GPIO_PULL_4     P4PU
#define GPIO_PULL_5     P5PU
#define GPIO_MODE_0     P0OD
#define GPIO_MODE_1     P1OD
#define GPIO_MODE_2     P2OD
#define GPIO_MODE_3     P3OD
#define GPIO_MODE_4     P4OD
#define GPIO_MODE_5     P5OD



extern void bsp_gpio_init(void);
extern unsigned char bsp_gpio_get(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_high(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_low(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_turn(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_output(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_input(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_pullup_enable(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_pullup_disable(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_od(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_pp(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin);
extern void bsp_gpio_bigdrive(TYPE_ENUM_GPIO_COM GpioCom, TYPE_ENUM_SWITCH SwitchFlag);

#endif
