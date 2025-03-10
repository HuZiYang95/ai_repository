/**
 * @file bsp_gpio.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_gpio.h"
#include "bsp_sfr.h"
#include "typedef.h"


 /**
  * @brief gpio初始化
  *
  */
void bsp_gpio_init(void)
{
    // 数据寄存器初始化
    P0 = 0x00;
    P1 = 0x00;
    P2 = 0x00;
    P3 = 0x00;
    P4 = 0x00;
    P5 = 0x00;

    // 方向寄存器初始化
    P0IO = 0x00;
    P1IO = 0x00;
    P2IO = 0x00;
    P3IO = 0x00;
    P4IO = 0x00;
    P5IO = 0x00;

    // 上拉寄存器
    P0PU = 0x00;
    P1PU = 0x00;
    P2PU = 0x00;
    P3PU = 0x00;
    P4PU = 0x00;
    P5PU = 0x00;
}


/**
 * @brief 读取gpio电平
 *
 * @param GpioPort gpio端口号
 * @param GpioPin  gpio位号
 *
 * @return unsigned char gpio电平
 *
 * @example if (PIN_0 == bsp_gpio_get(GPIO_PORT_0, PIN_0))
 */
unsigned char bsp_gpio_get(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  return (P0 & GpioPin);
        case GPIO_PORT_1:  return (P1 & GpioPin);
        case GPIO_PORT_2:  return (P2 & GpioPin);
        case GPIO_PORT_3:  return (P3 & GpioPin);
        case GPIO_PORT_4:  return (P4 & GpioPin);
        case GPIO_PORT_5:  return (P5 & GpioPin);
        default:  return 0;
    }
}


/**
 * @brief gpio-高电平
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_high (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_high(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0 |= GpioPin;  break;
        case GPIO_PORT_1:  P1 |= GpioPin;  break;
        case GPIO_PORT_2:  P2 |= GpioPin;  break;
        case GPIO_PORT_3:  P3 |= GpioPin;  break;
        case GPIO_PORT_4:  P4 |= GpioPin;  break;
        case GPIO_PORT_5:  P5 |= GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-低电平
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_low (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_low(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0 &= ~GpioPin;  break;
        case GPIO_PORT_1:  P1 &= ~GpioPin;  break;
        case GPIO_PORT_2:  P2 &= ~GpioPin;  break;
        case GPIO_PORT_3:  P3 &= ~GpioPin;  break;
        case GPIO_PORT_4:  P4 &= ~GpioPin;  break;
        case GPIO_PORT_5:  P5 &= ~GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-取反
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_turn (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_turn(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0 ^= GpioPin;  break;
        case GPIO_PORT_1:  P1 ^= GpioPin;  break;
        case GPIO_PORT_2:  P2 ^= GpioPin;  break;
        case GPIO_PORT_3:  P3 ^= GpioPin;  break;
        case GPIO_PORT_4:  P4 ^= GpioPin;  break;
        case GPIO_PORT_5:  P5 ^= GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-输出
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_output (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_output(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0IO |= GpioPin;  break;
        case GPIO_PORT_1:  P1IO |= GpioPin;  break;
        case GPIO_PORT_2:  P2IO |= GpioPin;  break;
        case GPIO_PORT_3:  P3IO |= GpioPin;  break;
        case GPIO_PORT_4:  P4IO |= GpioPin;  break;
        case GPIO_PORT_5:  P5IO |= GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-输入
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_input (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_input(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0IO &= ~GpioPin;  break;
        case GPIO_PORT_1:  P1IO &= ~GpioPin;  break;
        case GPIO_PORT_2:  P2IO &= ~GpioPin;  break;
        case GPIO_PORT_3:  P3IO &= ~GpioPin;  break;
        case GPIO_PORT_4:  P4IO &= ~GpioPin;  break;
        case GPIO_PORT_5:  P5IO &= ~GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-上拉使能
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_pullup_enable (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_pullup_enable(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0PU |= GpioPin;  break;
        case GPIO_PORT_1:  P1PU |= GpioPin;  break;
        case GPIO_PORT_2:  P2PU |= GpioPin;  break;
        case GPIO_PORT_3:  P3PU |= GpioPin;  break;
        case GPIO_PORT_4:  P4PU |= GpioPin;  break;
        case GPIO_PORT_5:  P5PU |= GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-上拉除能
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_pullup_disable (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_pullup_disable(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0PU &= ~GpioPin;  break;
        case GPIO_PORT_1:  P1PU &= ~GpioPin;  break;
        case GPIO_PORT_2:  P2PU &= ~GpioPin;  break;
        case GPIO_PORT_3:  P3PU &= ~GpioPin;  break;
        case GPIO_PORT_4:  P4PU &= ~GpioPin;  break;
        case GPIO_PORT_5:  P5PU &= ~GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-开漏模式
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_od (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_od(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0OD |= GpioPin;  break;
        case GPIO_PORT_1:  P1OD |= GpioPin;  break;
        case GPIO_PORT_2:  P2OD |= GpioPin;  break;
        case GPIO_PORT_3:  P3OD |= GpioPin;  break;
        case GPIO_PORT_4:  P4OD |= GpioPin;  break;
        case GPIO_PORT_5:  P5OD |= GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio-推挽模式
 *
 * @param GpioPort gpio端口号
 * @param GpioPin gpio位号
 *
 * @example bsp_gpio_od (GPIO_PORT_0, PIN_0);
 */
void bsp_gpio_pp(TYPE_ENUM_GPIO_PORT GpioPort, unsigned char GpioPin)
{
    switch (GpioPort)
    {
        case GPIO_PORT_0:  P0OD &= ~GpioPin;  break;
        case GPIO_PORT_1:  P1OD &= ~GpioPin;  break;
        case GPIO_PORT_2:  P2OD &= ~GpioPin;  break;
        case GPIO_PORT_3:  P3OD &= ~GpioPin;  break;
        case GPIO_PORT_4:  P4OD &= ~GpioPin;  break;
        case GPIO_PORT_5:  P5OD &= ~GpioPin;  break;
        default:  break;
    }
}


/**
 * @brief gpio - 大灌电流端口配置（80mA @ 5V）
 *
 * @param GpioCom COM口序号
 * @param Switch 开关
 *
 * @example bsp_gpio_bigdrive (GPIO_COM0_P00, ENABLE);
 */
void bsp_gpio_bigdrive(TYPE_ENUM_GPIO_COM GpioCom, TYPE_ENUM_SWITCH SwitchFlag)
{
    if (ENABLE == SwitchFlag)
    {
        BIGDRIVE |= GpioCom;
    }
    else
    {
        BIGDRIVE &= ~GpioCom;
    }
}
