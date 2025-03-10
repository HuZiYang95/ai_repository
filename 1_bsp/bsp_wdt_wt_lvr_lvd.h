/**
 * @file bsp_wdt_wt_lvr_lvd.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_WDT_WT_LVR_LVD_H_
#define _BSP_WDT_WT_LVR_LVD_H_


#include "typedef.h"


 /**
  * @brief 清狗语句
  *
  */
#define WDT_CLR()   (WDTCR |= 0x20)

  /**
   * @brief lvr电压档位选择
   *
   */
typedef enum
{
    LVR_1_9 = 0,
    LVR_2_0,
    LVR_2_1,
    LVR_2_2,
    LVR_2_32,
    LVR_2_44,
    LVR_2_59,
    LVR_2_75,
    LVR_2_93
}TYPE_ENUM_LVR;


/**
 * @brief lvd电压档位选择
 *
 */
typedef enum
{
    LVD_2_0 = 0,
    LVD_2_1,
    LVD_2_2,
    LVD_2_32,
    LVD_2_44,
    LVD_2_59,
    LVD_2_75,
    LVD_2_93,
    LVD_3_14,
    LVD_3_38,
    LVD_3_67,
    LVD_4_0,
    LVD_4_4
}TYPE_ENUM_LVD;


typedef enum
{
    LXT_P50_P51,
    LXT_P53_P54
}TYPE_ENUM_LXT_GPIO;


extern void bsp_wdt_init(unsigned char wdt_cnt);
extern void bsp_wdt_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_lvr_init(TYPE_ENUM_LVR LvrVol);
extern void bsp_lvr_switch(TYPE_ENUM_SWITCH Switch);
extern void bsp_lvd_init(TYPE_ENUM_SWITCH Switch, TYPE_ENUM_LVD LvdVol);
extern TYPE_ENUM_FLAG bsp_lvd_status();
extern TYPE_ENUM_STATUS bsp_wt_init_32768(TYPE_ENUM_LXT_GPIO Gpio);
extern unsigned char bsp_wt_clock(void);

#endif
