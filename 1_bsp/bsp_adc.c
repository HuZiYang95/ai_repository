/**
 * @file bsp_adc.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_adc.h"
#include "bsp_sfr.h"
#include "typedef.h"
 /**
  * @brief adc初始化
  *
  * @param AdcChan     adc通道
  * @param AdcFreqDiv  adc转换分频
  * @param AdcVref     adc基准电压
  *
  * @note 无
  */
void bsp_adc_init(TYPE_ENUM_ADC_CHAN AdcChan, TYPE_ENUM_ADC_FREQ_DIV AdcFreqDiv, TYPE_ENUM_ADC_ADC_VREF AdcVref)
    {
    ADCCRH = 0;
    ADCCRL = 0;

    // 1 - adc参考电压
    bsp_adc_switch_vref(AdcVref);
    // 2 - adc分频
    bsp_adc_switch_freq_div(AdcFreqDiv);
    // 3 - adc默认左对齐，结果存放(ADCDRH[7:0],ADCDRL[7:4])
    ADCCRH &= ~0x04;
    // 4 - adc通道选择
    bsp_adc_switch_channel(AdcChan);
    // 5 - adc模块使能
    ADCCRL |= 0x80;
    }


/**
 * @brief adc转换并返回结果
 *
 * @return unsigned int  12位ad值
 *
 * @note 无
 */
unsigned int bsp_adc_get_raw(void)
    {
    unsigned int i = 0;
    // 1 - adc启动转换
    ADCCRL |= 0x40;
    // 2 - adc等待转换结束
    while (!(ADCCRH & 0x40))
        {
        if (++i >= 500) return 0xFFFF;
        }
    // 3 - adc按配置位数取出转换结果
    i = ((unsigned int)ADCDRH << 8) | ADCDRL;
    i >>= 4;

    // 4 - adc返回采样结果
    return i;
    }


/**
 * @brief adc切换通道
 *
 * @param adc_chan  adc通道
 *
 * @note  注意多通道采集时，应当在当前通道采集完成后，切换通道，等下一次采集时直接开始；不建议切换通道后立刻开始adc采集
 */
void bsp_adc_switch_channel(TYPE_ENUM_ADC_CHAN AdcChan)
    {
    unsigned char i = 0;

    i = ADCCRL;
    i &= 0xE0;
    i |= (unsigned char)(AdcChan & 0x1F);
    ADCCRL = i;

    switch (AdcChan)
        {
            case ADC_CHAN_0:    P4IO &= U8_NBIT5;    ADAN4 |= U8_BIT5;    break;
            case ADC_CHAN_1:    P4IO &= U8_NBIT4;    ADAN4 |= U8_BIT4;    break;
            case ADC_CHAN_2:    P4IO &= U8_NBIT3;    ADAN4 |= U8_BIT3;    break;
            case ADC_CHAN_3:    P4IO &= U8_NBIT2;    ADAN4 |= U8_BIT2;    break;
            case ADC_CHAN_4:    P4IO &= U8_NBIT1;    ADAN4 |= U8_BIT1;    break;
            case ADC_CHAN_5:    P4IO &= U8_NBIT0;    ADAN4 |= U8_BIT0;    break;
            case ADC_CHAN_6:    P3IO &= U8_NBIT7;    ADAN3 |= U8_BIT7;    break;
            case ADC_CHAN_7:    P3IO &= U8_NBIT6;    ADAN3 |= U8_BIT6;    break;
            case ADC_CHAN_8:    P3IO &= U8_NBIT5;    ADAN3 |= U8_BIT5;    break;
            case ADC_CHAN_9:    P3IO &= U8_NBIT4;    ADAN3 |= U8_BIT4;    break;
            case ADC_CHAN_10:   P1IO &= U8_NBIT4;    ADAN1 |= U8_BIT4;    break;
            case ADC_CHAN_11:   P1IO &= U8_NBIT5;    ADAN1 |= U8_BIT5;    break;
            case ADC_CHAN_12:   P1IO &= U8_NBIT6;    ADAN1 |= U8_BIT6;    break;
            case ADC_CHAN_13:   P1IO &= U8_NBIT7;    ADAN1 |= U8_BIT7;    break;
            case ADC_CHAN_14:   P2IO &= U8_NBIT0;    ADAN2 |= U8_BIT0;    break;
            case ADC_CHAN_15:   P2IO &= U8_NBIT1;    ADAN2 |= U8_BIT1;    break;
            case ADC_CHAN_16:   P2IO &= U8_NBIT2;    ADAN2 |= U8_BIT2;    break;
            case ADC_CHAN_17:   P2IO &= U8_NBIT3;    ADAN2 |= U8_BIT3;    break;
            case ADC_CHAN_18:   P2IO &= U8_NBIT4;    ADAN2 |= U8_BIT4;    break;
            case ADC_CHAN_19:   P2IO &= U8_NBIT5;    ADAN2 |= U8_BIT5;    break;
            case ADC_CHAN_20:   P2IO &= U8_NBIT6;    ADAN2 |= U8_BIT6;    break;
            case ADC_CHAN_21:   P2IO &= U8_NBIT7;    ADAN2 |= U8_BIT7;    break;
            case ADC_CHAN_22:   P0IO &= U8_NBIT0;    ADAN0 |= U8_BIT0;    break;
            case ADC_CHAN_23:   P0IO &= U8_NBIT1;    ADAN0 |= U8_BIT1;    break;
            case ADC_CHAN_24:   P0IO &= U8_NBIT2;    ADAN0 |= U8_BIT2;    break;
            case ADC_CHAN_25:   P0IO &= U8_NBIT3;    ADAN0 |= U8_BIT3;    break;
            case ADC_CHAN_26:   P0IO &= U8_NBIT4;    ADAN0 |= U8_BIT4;    break;
            case ADC_CHAN_27:   P0IO &= U8_NBIT5;    ADAN0 |= U8_BIT5;    break;
            case ADC_CHAN_28:   P0IO &= U8_NBIT6;    ADAN0 |= U8_BIT6;    break;
            default: break;
        }
    NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
    }


/**
 * @brief adc清除通道，端口复位GPIO
 *
 * @param AdcChan AD通道
 */
void bsp_adc_clr_channel(TYPE_ENUM_ADC_CHAN AdcChan)
    {
    switch (AdcChan)
        {
            case ADC_CHAN_0:    P4IO |= U8_BIT5;    ADAN4 &= U8_NBIT5;    break;
            case ADC_CHAN_1:    P4IO |= U8_BIT4;    ADAN4 &= U8_NBIT4;    break;
            case ADC_CHAN_2:    P4IO |= U8_BIT3;    ADAN4 &= U8_NBIT3;    break;
            case ADC_CHAN_3:    P4IO |= U8_BIT2;    ADAN4 &= U8_NBIT2;    break;
            case ADC_CHAN_4:    P4IO |= U8_BIT1;    ADAN4 &= U8_NBIT1;    break;
            case ADC_CHAN_5:    P4IO |= U8_BIT0;    ADAN4 &= U8_NBIT0;    break;
            case ADC_CHAN_6:    P3IO |= U8_BIT7;    ADAN3 &= U8_NBIT7;    break;
            case ADC_CHAN_7:    P3IO |= U8_BIT6;    ADAN3 &= U8_NBIT6;    break;
            case ADC_CHAN_8:    P3IO |= U8_BIT5;    ADAN3 &= U8_NBIT5;    break;
            case ADC_CHAN_9:    P3IO |= U8_BIT4;    ADAN3 &= U8_NBIT4;    break;
            case ADC_CHAN_10:   P1IO |= U8_BIT4;    ADAN1 &= U8_NBIT4;    break;
            case ADC_CHAN_11:   P1IO |= U8_BIT5;    ADAN1 &= U8_NBIT5;    break;
            case ADC_CHAN_12:   P1IO |= U8_BIT6;    ADAN1 &= U8_NBIT6;    break;
            case ADC_CHAN_13:   P1IO |= U8_BIT7;    ADAN1 &= U8_NBIT7;    break;
            case ADC_CHAN_14:   P2IO |= U8_BIT0;    ADAN2 &= U8_NBIT0;    break;
            case ADC_CHAN_15:   P2IO |= U8_BIT1;    ADAN2 &= U8_NBIT1;    break;
            case ADC_CHAN_16:   P2IO |= U8_BIT2;    ADAN2 &= U8_NBIT2;    break;
            case ADC_CHAN_17:   P2IO |= U8_BIT3;    ADAN2 &= U8_NBIT3;    break;
            case ADC_CHAN_18:   P2IO |= U8_BIT4;    ADAN2 &= U8_NBIT4;    break;
            case ADC_CHAN_19:   P2IO |= U8_BIT5;    ADAN2 &= U8_NBIT5;    break;
            case ADC_CHAN_20:   P2IO |= U8_BIT6;    ADAN2 &= U8_NBIT6;    break;
            case ADC_CHAN_21:   P2IO |= U8_BIT7;    ADAN2 &= U8_NBIT7;    break;
            case ADC_CHAN_22:   P0IO |= U8_BIT0;    ADAN0 &= U8_NBIT0;    break;
            case ADC_CHAN_23:   P0IO |= U8_BIT1;    ADAN0 &= U8_NBIT1;    break;
            case ADC_CHAN_24:   P0IO |= U8_BIT2;    ADAN0 &= U8_NBIT2;    break;
            case ADC_CHAN_25:   P0IO |= U8_BIT3;    ADAN0 &= U8_NBIT3;    break;
            case ADC_CHAN_26:   P0IO |= U8_BIT4;    ADAN0 &= U8_NBIT4;    break;
            case ADC_CHAN_27:   P0IO |= U8_BIT5;    ADAN0 &= U8_NBIT5;    break;
            case ADC_CHAN_28:   P0IO |= U8_BIT6;    ADAN0 &= U8_NBIT6;    break;
            default: break;
        }
    }


/**
 * @brief adc切换基准电压
 *
 * @param adc_vref adc基准电压
 *
 * @note 无
 */
void bsp_adc_switch_vref(TYPE_ENUM_ADC_ADC_VREF AdcVref)
    {
    ADCCRL |= (unsigned char)((AdcVref & 0x08) << 2);  // 2023-5-6
    ADCCRH |= (unsigned char)((AdcVref & 0x03) << 4);
    }


/**
 * @brief adc切换转换分频
 *
 * @param adc_freq_div adc转换分频
 */
void bsp_adc_switch_freq_div(TYPE_ENUM_ADC_FREQ_DIV AdcFreqDiv)
    {
    ADCCRH |= (unsigned char)(AdcFreqDiv & 0x03);
    }
