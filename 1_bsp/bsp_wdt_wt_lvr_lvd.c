/**
 * @file bsp_wdt_wt_lvr_lvd.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_wdt_wt_lvr_lvd.h"
#include "bsp_sfr.h"


 /**
  * @brief 看门狗初始化，初始化默认开启
  *
  * @param wdt_cnt wdt时间设定
  *
  * @note 看门狗时间 = (1 + wdt_cnt) * 256 / F(LIRC) = (1 + wdt_cnt) * 256 / 15K 单位为秒
  */
void bsp_wdt_init(unsigned char wdt_cnt)
{
    WDTCR = 0x42;       // 看门狗使用独立定时器，时钟源 LIRC/256
    WDTDR = wdt_cnt;
    WDT_CLR();
    WDTCR |= 0x80;      // 看门狗使能
}


/**
 * @brief 看门狗开关
 *
 * @param Switch
 */
void bsp_wdt_switch(TYPE_ENUM_SWITCH Switch)
{
    if (DISABLE == Switch) WDTCR &= ~0x80;
    else WDTCR |= 0x80;
}


/**
 * @brief lvr初始化，初始化默认开启
 *
 * @param LvrVol lvr电压档位选择
 */
void bsp_lvr_init(TYPE_ENUM_LVR LvrVol)
{
    LVRCR = LvrVol;
    LVRCR |= 0x80;
}


/**
 * @brief 低压复位开关
 *
 * @param Switch
 */
void bsp_lvr_switch(TYPE_ENUM_SWITCH Switch)
{
    if (Switch == DISABLE) LVRCR &= ~0x80;
    else LVRCR |= 0x80;
}


/**
 * @brief lvd初始化
 *
 * @param Switch
 * @param LvdVol lvd电压档位选择
 */
void bsp_lvd_init(TYPE_ENUM_SWITCH Switch, TYPE_ENUM_LVD LvdVol)
{
    LVICR = LvdVol;
    if (Switch == ENABLE) LVICR |= U8_BIT7;
}


/**
 * @brief 读取lvd状态标志位
 *
 * @return TYPE_ENUM_FLAG 触发状态
 */
TYPE_ENUM_FLAG bsp_lvd_status()
{
    if (LVICR & U8_BIT4)
    {
        LVICR &= U8_NBIT4;
        return TRIGGER;
    }
    else return STABLE;
}


/**
 * @brief WT定时器及32.768KHz晶振使能
 *
 * @param Gpio 晶振所接端口选择
 */
TYPE_ENUM_STATUS bsp_wt_init_32768(TYPE_ENUM_LXT_GPIO Gpio)
{
    unsigned int i = 0;

    if (LXT_P50_P51 == Gpio)
    {
        OSCCR1 |= 0x80;
    }
    else if (LXT_P53_P54 == Gpio)
    {
        OSCCR1 &= ~0x80;     // P53/P54 接32.768
    }
    OSCTS = 0;
    OSCCR |= 0x80;
    while (!(OSCCR1 & 0x02))
    {
        if (++i >= 30000)
        {
            OSCCR &= ~0x80;
            return ERROR;
        }
    }
    WTCR = 0x08;
    WTCR |= 0x80;
    return SUCCESS;
}


/**
 * @brief 读取wt定时器状态
 *
 * @return unsigned char 每0.5s时刻返回值为"1"，其余时刻为"0"
 */
unsigned char bsp_wt_clock(void)
{
    if (0 == (WTCR & 0x10)) return 0;
    WTCR &= ~0x10;
    return 1;
}
