/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "user_include.h"


void sys_init()
{
    //上电延迟
    bsp_power_on_delay();

    // 关闭总中断
    GLOBAL_INT_DIS();

    // 初始化lvr，掉电记忆应用中，LVR设置必须大于2.1V
    bsp_lvr_init(LVR_2_44);

    // 使能相关时钟源，并初始化系统时钟；如果使用外振且起振失败，程序自动切换内振并返回ERROR
    if (ERROR == bsp_sysclock_init(SYS_CLK_HIRC_16M));

    // 初始化gpio
    bsp_gpio_init();

    // 全片FLASH保护
    bsp_flash_protect(FLASH_PROTECT_FFFF);

    // 初始化wdt
    bsp_wdt_init(100);

    // 初始化其他外设
    // bsp_timer0_init_us (TIMER_INT_PRIORITY_0, 125);  // 定时器0中断，125us
    // bsp_lvd_init(ENABLE, LVD_4_0);   // 低电压检测使能
    bsp_uart0_init(UART_BAUD_9600, UART0_RX_P20_TX_P21, ENABLE, ENABLE, UART_INT_PRIORITY_0);

    // 使能总中断
    GLOBAL_INT_EN();
}


void hal_app_init(void)
{
    ;
}


static unsigned int SysTick2ms = 0;
static unsigned int SysTick10ms = 0;
static unsigned int SysTick100ms = 0;
void main()
{
    sys_init();
    hal_app_init();
    TouchKeyInit();     // 触摸初始化放最后，systick初始化前
    systick_init();     // 初始化1ms tick定时器   放初始化最后

    while (1)
    {
        if (TRUE == is_systick_expired(&SysTick2ms, 2))
        {
            SysTick2ms = get_tick();
            TouchKeyScan();
#if TK_DEBUG_ENABLE
            r1ms_tkFrame++;
            if (r1ms_tkFrame >= 100)      //每隔100-150ms发送一次按键数据
            {
                r1ms_tkFrame = 0;
                TK_FrameSender(tkBaseLine, tkSensorDataBuff, TkTotalNum);
            }
#endif
        }
        if (TRUE == is_systick_expired(&SysTick10ms, 10))
        {
            WDT_CLR();
        }
        if (TRUE == is_systick_expired(&SysTick100ms, 100))
        {

        }
    }
}


// - - - - - - - - - - - - - - - - - - AIP8F3264中断服务函数 - - - - - - - - - - - - - - - - //

#if 0
 /**
  * @brief 外部中断0 - 中断服务函数
  *
  */
void eint0_interrupt_func(void) interrupt 0
{

}
#endif


#if 0
/**
 * @brief 外部中断1 - 中断服务函数
 *
 */
void eint1_interrupt_func(void) interrupt 1
{

}
#endif


#if 0
/**
 * @brief 外部中断2 - 中断服务函数
 *
 */
void eint2_interrupt_func(void) interrupt 2
{

}
#endif


#if 0
/**
 * @brief 外部中断3 - 中断服务函数
 *
 */
void eint3_interrupt_func(void) interrupt 3
{

}
#endif


#if 0
/**
 * @brief 外部中断4 - 中断服务函数
 *
 */
void eint4_interrupt_func(void) interrupt 4
{

}
#endif


#if 0
/**
 * @brief 外部中断5 - 中断服务函数
 *
 */
void eint5_interrupt_func(void) interrupt 5
{

}
#endif


#if 0
/**
 * @brief 低电压检测 - 中断服务函数
 *
 */
void lvd_interrupt_func(void) interrupt 7
{

}
#endif


#if 0
/**
 * @brief iic - 中断服务函数
 *
 */
void iic_interrupt_func(void) interrupt 8
{

}
#endif


#if 0
/**
 * @brief 串口 - 中断服务函数
 *
 */
void uart_interrupt_func(void) interrupt 9
{

}
#endif


#if 0
/**
 * @brief 定时器0 - 中断服务函数
 *
 */
void timer0_interrupt_func(void) interrupt 11
{
    T0CR1 &= 0xFB;	// 清除中断标志位
}
#endif


/*
 * @brief 定时器1 中断服务函数已在 "xx_timer.c" 中定义并执行系统tick功能
*/


#if 0
/**
 * @brief 定时器2 - 中断服务函数
 *
 */
void timer2_interrupt_func(void) interrupt 13
{

}
#endif


#if 0
/**
 * @brief 定时器5 - 中断服务函数
 *
 */
void timer5_interrupt_func(void) interrupt 14
{

}
#endif


#if 0
/**
 * @brief adc & spi - 中断服务函数
 *
 */
void adc_spi_interrupt_func(void) interrupt 15
{

}
#endif


#if 0
/**
 * @brief wt时钟 & 看门狗 - 中断服务函数
 *
 */
void wt_wdt_interrupt_func(void) interrupt 16
{

}
#endif


#if 0
/**
 * @brief led & lcd & 运算单元 - 中断服务函数
 *
 */
void led_com_mdu_interrupt_func(void) interrupt 17
{

}
#endif
