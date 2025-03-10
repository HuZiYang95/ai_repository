/**
 * @file bsp_adc.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __BSP_ADC_H__
#define __BSP_ADC_H__

#include "typedef.h"
#include <intrins.h>  // 添加NOP()指令依赖的头文件

 /**
  * @brief adc - 通道
  */
typedef enum
    {
    ADC_CHAN_0 = 0,
    ADC_CHAN_1,
    ADC_CHAN_2,
    ADC_CHAN_3,
    ADC_CHAN_4,
    ADC_CHAN_5,
    ADC_CHAN_6,
    ADC_CHAN_7,
    ADC_CHAN_8,
    ADC_CHAN_9,
    ADC_CHAN_10,
    ADC_CHAN_11,
    ADC_CHAN_12,
    ADC_CHAN_13,
    ADC_CHAN_14,
    ADC_CHAN_15,
    ADC_CHAN_16,
    ADC_CHAN_17,
    ADC_CHAN_18,
    ADC_CHAN_19,
    ADC_CHAN_20,
    ADC_CHAN_21,
    ADC_CHAN_22,
    ADC_CHAN_23,
    ADC_CHAN_24,
    ADC_CHAN_25,
    ADC_CHAN_26,
    ADC_CHAN_27,
    ADC_CHAN_28,
    ADC_CHAN_1_4_vdd
    } TYPE_ENUM_ADC_CHAN;


/**
 * @brief adc - 采样分频
 */
typedef enum
    {
    ADC_FREQ_DIV_1 = 0,
    ADC_FREQ_DIV_2,
    ADC_FREQ_DIV_4,
    ADC_FREQ_DIV_8
    } TYPE_ENUM_ADC_FREQ_DIV;


/**
 * @brief adc - 参考电压
 */
typedef enum
    {
    ADC_VREF_VDD = 7,
    ADC_VREF_5V,
    ADC_VREF_4V,
    ADC_VREF_3V,
    ADC_VREF_2V
    } TYPE_ENUM_ADC_ADC_VREF;



extern void bsp_adc_init(TYPE_ENUM_ADC_CHAN AdcChan, TYPE_ENUM_ADC_FREQ_DIV AdcFreqDiv, TYPE_ENUM_ADC_ADC_VREF AdcVref);
extern unsigned int bsp_adc_get_raw(void);
extern void bsp_adc_switch_channel(TYPE_ENUM_ADC_CHAN AdcChan);
extern void bsp_adc_clr_channel(TYPE_ENUM_ADC_CHAN AdcChan);
extern void bsp_adc_switch_vref(TYPE_ENUM_ADC_ADC_VREF AdcVref);
extern void bsp_adc_switch_freq_div(TYPE_ENUM_ADC_FREQ_DIV AdcFreqDiv);

#endif
