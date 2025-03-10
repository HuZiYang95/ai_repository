/**
 * @file bsp_timer.c
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "bsp_timer.h"
#include "bsp_sfr.h"


 /**
  * @brief 定时器0中断服务函数，执行系统1ms定时
  *
  */
volatile unsigned int SysTick = 0;
volatile unsigned int SysTickTemp = 0;
volatile unsigned char SysTickFlag = 0;
/**
 * @brief 定时器1 - 中断服务函数，执行1ms-tick定时
 *
 */
void timer1_interrupt_func(void) interrupt 12
{
    T1CR1 &= 0xFB;	// 清除中断标志位
    SysTick++;
    if (0 == SysTickFlag)
    {
        SysTickTemp = SysTick;
    }
}


/**
 * @brief Get the tick object
 *
 * @return unsigned int
 */
unsigned int get_tick(void)
{
    unsigned int Temp;
    SysTickFlag = 1;
    Temp = SysTickTemp;
    SysTickFlag = 0;
    return Temp;
}


/**
 * @brief 判断定时时间是否达到
 *
 * @param pTaskTick 任务定时变量指针
 * @param SetTimeTick 目标定时时刻
 * @return TYPE_ENUM_BOOL 是否达到设定时刻
 */
TYPE_ENUM_BOOL is_systick_expired(unsigned int *pTaskTick, unsigned int SetTimeTick)
{
    if ((get_tick() - *pTaskTick) >= SetTimeTick)
    {
        *pTaskTick += SetTimeTick;
        return TRUE;
    }
    return FALSE;
}


/**
 * @brief 系统tick初始化，占用timer0
 *
 */
void systick_init(void)
{
    if (SysClock == 16)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_64, TIMER_INT_PRIORITY_0, 249);
    }
    else if (SysClock == 8)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_64, TIMER_INT_PRIORITY_0, 124);
    }
    else if (SysClock == 4)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_8, TIMER_INT_PRIORITY_0, 499);
    }
}


/**
 * @brief 上电延时函数
 *
 */
void bsp_power_on_delay(void)
{
    unsigned int i = 10000;
    while (--i) WDTCR |= 0x20;
}


/**
 * @brief 系统时钟初始化
 *
 * @param sys_clk 系统时钟  { SYS_CLK_HIRC_16M, SYS_CLK_HIRC_8M, SYS_CLK_HIRC_4M, SYS_CLK_HXT_16M, SYS_CLK_HXT_8M, SYS_CLK_HXT_4M }
 */
unsigned char SysClock = 0;
TYPE_ENUM_STATUS bsp_sysclock_init(TYPE_ENUM_SYS_CLK SysClockSel)
{
    unsigned int i = 0;
    TYPE_ENUM_STATUS Status = SUCCESS;

    if ((SysClockSel == SYS_CLK_HXT_16M) || (SysClockSel == SYS_CLK_HXT_8M) || (SysClockSel == SYS_CLK_HXT_4M))
    {
        // 3264上电默认高速内振使能并作为时钟源

        // 使能外振并切换为主频
        OSCCR1 = 0x80;
        OSCTS = 0x00;
        OSCCR |= 0x20;
        while (!(OSCCR1 & 0x01))
        {
            if (++i >= 30000)
            {
                Status = ERROR;
                OSCCR = 0x10;   // 外振起振超时，关闭
                break;
            }
        }

        if (ERROR == Status)    // 外振起振失败，切换同频率内振
        {
            if (SysClockSel == SYS_CLK_HXT_16M) SysClockSel = SYS_CLK_HIRC_16M;
            else if (SysClockSel == SYS_CLK_HXT_8M) SysClockSel = SYS_CLK_HIRC_8M;
            else if (SysClockSel == SYS_CLK_HXT_4M) SysClockSel = SYS_CLK_HIRC_4M;
        }
        else
        {
            KEYCODE = 0x3C;
            KEYCODE = 0x02;
            KEYCODE = 0xA0;
            CKCR = 0x01;
            KEYCODE = 0x00;
            if (SysClockSel == SYS_CLK_HXT_16M) SysClock = 16;
            else if (SysClockSel == SYS_CLK_HXT_8M) SysClock = 8;
            else if (SysClockSel == SYS_CLK_HXT_4M) SysClock = 4;
            return SUCCESS;
        }
    }

    if (SysClockSel == SYS_CLK_HIRC_16M)
    {
        OSCCR = 0x10;
        SysClock = 16;
    }
    else if (SysClockSel == SYS_CLK_HIRC_8M)
    {
        OSCCR = 0x14;
        SysClock = 8;
    }
    else if (SysClockSel == SYS_CLK_HIRC_4M)
    {
        OSCCR = 0x15;
        SysClock = 4;
    }
    return Status;
}


/**
 * @brief 定时器0初始化为定时器模式
 *
 * @param TimerFreq            定时器分频
 * @param IntPriority     定时中断优先级
 * @param Period              定时周期 - 16bit
 *
 * @note 定时中断周期计算：(Period + 1) * TimerFreq / SysClock * 1000000 us
 * @example 16M内振，定时中断125us，最低优先级 : bsp_timer0_init (TIMER_FREQ_DIV_8, TIMER_INT_PRIORITY_0, 249);
 * @example 8M内振，定时中断125us，最低优先级 : bsp_timer0_init (TIMER_FREQ_DIV_4, TIMER_INT_PRIORITY_0, 249);
 */
void bsp_timer0_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period)
{
    T0CR1 = 0;
    T0CR2 = 0;
    // 1 - timer模式选择
    T0CR1 |= (unsigned char)((0x00 & 0x03) << 4);
    // 2 - timer分频选择
    T0CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置定时周期
    T0DR1L = (unsigned char)(Period & 0x00FF);
    T0DR1H = (unsigned char)(Period >> 8);
    // 4 - 配置中断优先级并使能中断
    switch (IntPriority)
    {
        case TIMER_INT_PRIORITY_0:    IP0 &= ~0x20;   IP1 &= ~0x20;   break;
        case TIMER_INT_PRIORITY_1:    IP0 |= 0x20;    IP1 &= ~0x20;   break;
        case TIMER_INT_PRIORITY_2:    IP0 &= ~0x20;   IP1 |= 0x20;    break;
        case TIMER_INT_PRIORITY_3:    IP0 |= 0x20;    IP1 |= 0x20;    break;
        default: break;
    }
    IE1 |= 0x20;
    T0CR1 &= 0xFB;
    T0CR1 |= 0x80;
}


/**
 * @brief 快速初始化定时器0，定时单位us
 *
 * @param IntPriority   定时中断优先级
 * @param usCnt             定时值，范围 0~32767 单位us
 */
void bsp_timer0_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt)
{
    if (usCnt > 32767) return;

    if (SysClock == 16)
    {
        bsp_timer0_init(TIMER_FREQ_DIV_8, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 8)
    {
        bsp_timer0_init(TIMER_FREQ_DIV_4, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 4)
    {
        bsp_timer0_init(TIMER_FREQ_DIV_2, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
}


/**
 * @brief 定时器0初始化为pwm模式
 *
 * @param TimerFreq    定时器分频
 * @param PwmDir     pwm极性
 * @param PwmChan    pwm端口
 * @param Period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param Duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(period+1) * freq_div / sys_clk * 1000000 us
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note duty为0，则pwm口恒定输出低电平（极性为正）；duty > period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm0_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmChan, unsigned int Period, unsigned int Duty)
{
    T0CR1 = 0;
    T0CR2 = 0;
    // 1 - timer模式选择
    T0CR1 |= (unsigned char)((0x03 & 0x03) << 4);
    // 2 - timer分频选择
    T0CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置gpio、pwm极性
    if (PwmChan == TIMER_PWM_0_P51)
    {
        LCMCR0 &= U8_NBIT3;
        P5 |= U8_BIT1;
        P5IO |= U8_BIT1;
    }
    else if (PwmChan == TIMER_PWM_0_P22)
    {
        LCMCR0 |= 0x08;
        P2 |= 0x04;
        P2IO |= 0x04;
    }
    T0CR2 |= 0x01;
    T0CR2 |= (unsigned char)((PwmDir & 0x01) << 2);
    // 4 - 配置pwm周期及占空比
    T0DR1L = (unsigned char)(Period & 0x00FF);
    T0DR1H = (unsigned char)(Period >> 8);
    T0DR2H = (unsigned char)(Duty >> 8);
    T0DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器0配置pwm周期及占空比
 *
 * @param period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(period+1) * freq_div / sys_clk * 1000000 us
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note duty为0，则pwm口恒定输出低电平（极性为正）；duty > period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm0_set(unsigned int Period, unsigned int Duty)
{
    T0DR1L = (unsigned char)(Period & 0x00FF);
    T0DR1H = (unsigned char)(Period >> 8);
    T0DR2H = (unsigned char)(Duty >> 8);
    T0DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器0开关pwm
 *
 * @param Switch    pwm开关 { DISABLE, ENABLE }
 */
void bsp_pwm0_switch(TYPE_ENUM_SWITCH Switch)
{
    T0CR1 |= U8_BIT0;
    if (Switch == ENABLE) T0CR1 |= 0x80;
    else T0CR1 &= ~0x80;
}


/**
 * @brief 定时器1初始化为定时器模式
 *
 * @param TimerFreq           定时器分频
 * @param IntPriority         定时中断优先级
 * @param Period              定时周期 - 16bit
 *
 * @note 定时中断周期计算：(Period + 1) * TimerFreq / SysClock * 1000000 us
 * @example 16M内振，定时中断125us，最低优先级 : bsp_timer1_init (TIMER_FREQ_DIV_8, TIMER_INT_PRIORITY_0, 249);
 * @example 8M内振，定时中断125us，最低优先级 : bsp_timer1_init (TIMER_FREQ_DIV_4, TIMER_INT_PRIORITY_0, 249);
 */
void bsp_timer1_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period)
{
    T1CR1 = 0;
    T1CR2 = 0;
    // 1 - timer模式选择
    T1CR1 |= (unsigned char)((0x00 & 0x03) << 4);
    // 2 - timer分频选择
    T1CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置定时周期
    T1DR1L = (unsigned char)(Period & 0x00FF);
    T1DR1H = (unsigned char)(Period >> 8);
    // 4 - 配置中断优先级并使能中断
    switch (IntPriority)
    {
        case TIMER_INT_PRIORITY_0:    IP0 &= ~0x01;   IP1 &= ~0x01;   break;
        case TIMER_INT_PRIORITY_1:    IP0 |= 0x01;    IP1 &= ~0x01;   break;
        case TIMER_INT_PRIORITY_2:    IP0 &= ~0x01;   IP1 |= 0x01;    break;
        case TIMER_INT_PRIORITY_3:    IP0 |= 0x01;    IP1 |= 0x01;    break;
        default: break;
    }
    IE1 |= 0x40;
    T1CR1 &= 0xFB;
    T1CR1 |= 0x80;
}


/**
 * @brief 快速初始化定时器1，定时单位us
 *
 * @param IntPriority   定时中断优先级
 * @param usCnt             定时值，范围 0~32767 单位us
 */
void bsp_timer1_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt)
{
    if (usCnt > 32767) return;

    if (SysClock == 16)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_8, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 8)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_4, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 4)
    {
        bsp_timer1_init(TIMER_FREQ_DIV_2, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
}


/**
 * @brief 定时器1初始化为pwm模式
 *
 * @param freq_div    定时器分频        { TIMER_FREQ_DIV_1, TIMER_FREQ_DIV_2, TIMER_FREQ_DIV_4, TIMER_FREQ_DIV_8, TIMER_FREQ_DIV_64, TIMER_FREQ_DIV_512, TIMER_FREQ_DIV_2048, TIMER_FREQ_TCN }
 * @param pwm_dir     pwm极性           { TIMER_PWM_DIR_POSITIVE, TIMER_PWM_DIR_NEGATIVE }
 * @param pwm_gpio    pwm端口           { TIMER_PWM_1_P50, TIMER_PWM_1_P01 }
 * @param period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(period+1) * freq_div / sys_clk * 1000000 us
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note duty为0，则pwm口恒定输出低电平（极性为正）；duty > period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm1_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmGpio, unsigned int Period, unsigned int Duty)
{
    T1CR1 = 0;
    T1CR2 = 0;
    // 1 - timer模式选择
    T1CR1 |= (unsigned char)((0x03 & 0x03) << 4);
    // 2 - timer分频选择
    T1CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置gpio、pwm极性
    if (PwmGpio == TIMER_PWM_1_P52)
    {
        LCMCR0 &= U8_NBIT2;
        P5 |= U8_BIT2;
        P5IO |= U8_BIT2;
    }
    else if (PwmGpio == TIMER_PWM_1_P23)
    {
        LCMCR0 |= U8_BIT2;
        P2 |= U8_BIT3;
        P2IO |= U8_BIT3;
    }
    T1CR2 |= 0x01;
    T1CR2 |= (unsigned char)((PwmDir & 0x01) << 2);
    // 4 - 配置pwm周期及占空比
    T1DR1L = (unsigned char)(Period & 0x00FF);
    T1DR1H = (unsigned char)(Period >> 8);
    T1DR2H = (unsigned char)(Duty >> 8);
    T1DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器1配置pwm周期及占空比
 *
 * @param period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(period+1) * freq_div / sys_clk * 1000000 us
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note duty为0，则pwm口恒定输出低电平（极性为正）；duty > period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm1_set(unsigned int Period, unsigned int Duty)
{
    T1DR1L = (unsigned char)(Period & 0x00FF);
    T1DR1H = (unsigned char)(Period >> 8);
    T1DR2H = (unsigned char)(Duty >> 8);
    T1DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器1开关pwm
 *
 * @param Switch    pwm开关 { DISABLE, ENABLE }
 */
void bsp_pwm1_switch(TYPE_ENUM_SWITCH Switch)
{
    T1CR1 |= U8_BIT0;
    if (Switch == ENABLE) T1CR1 |= 0x80;
    else T1CR1 &= ~0x80;
}


/**
 * @brief 定时器2初始化为定时器模式
 *
 * @param TimerFreq           定时器分频
 * @param IntPriority         定时中断优先级
 * @param Period              定时周期 - 16bit
 *
 * @note 定时中断周期计算：(Period + 1) * TimerFreq / SysClock * 1000000 us
 * @example 16M内振，定时中断125us，最低优先级 : bsp_timer2_init (TIMER_FREQ_DIV_8, TIMER_INT_PRIORITY_0, 249);
 * @example 8M内振，定时中断125us，最低优先级 : bsp_timer2_init (TIMER_FREQ_DIV_4, TIMER_INT_PRIORITY_0, 249);
 */
void bsp_timer2_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period)
{
    T2CR1 = 0;
    T2CR2 = 0;
    // 1 - timer模式选择
    T2CR1 |= (unsigned char)((0x00 & 0x03) << 4);
    // 2 - timer分频选择
    T2CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置定时周期
    T2DR1L = (unsigned char)(Period & 0x00FF);
    T2DR1H = (unsigned char)(Period >> 8);
    // 4 - 配置中断优先级并使能中断
    switch (IntPriority)
    {
        case TIMER_INT_PRIORITY_0:    IP0 &= ~0x02;   IP1 &= ~0x02;   break;
        case TIMER_INT_PRIORITY_1:    IP0 |= 0x02;    IP1 &= ~0x02;   break;
        case TIMER_INT_PRIORITY_2:    IP0 &= ~0x02;   IP1 |= 0x02;    break;
        case TIMER_INT_PRIORITY_3:    IP0 |= 0x02;    IP1 |= 0x02;    break;
        default: break;
    }
    IE1 |= 0x80;
    T2CR1 &= 0xFB;
    T2CR1 |= 0x80;
}


/**
 * @brief 快速初始化定时器2，定时单位us
 *
 * @param IntPriority   定时中断优先级
 * @param usCnt             定时值，范围 0~32767 单位us
 */
void bsp_timer2_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt)
{
    if (usCnt > 32767) return;

    if (SysClock == 16)
    {
        bsp_timer2_init(TIMER_FREQ_DIV_8, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 8)
    {
        bsp_timer2_init(TIMER_FREQ_DIV_4, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 4)
    {
        bsp_timer2_init(TIMER_FREQ_DIV_2, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
}


/**
 * @brief 定时器2初始化为pwm模式
 *
 * @param TimerFreq    定时器分频
 * @param PwmDir     pwm极性
 * @param PwmChan
 * @param Period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param Duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(Period+1) * TimerFreq / SysClock * 1000000 us
 * @note pwm占空比计算：(Duty+1) * TimerFreq / SysClock * 1000000 us
 * @note Duty为0，则pwm口恒定输出低电平（极性为正）；Duty > Period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm2_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmChan, unsigned int Period, unsigned int Duty)
{
    T2CR1 = 0;
    T2CR2 = 0;
    // 1 - timer模式选择
    T2CR1 |= (unsigned char)((0x03 & 0x03) << 4);
    // 2 - timer分频选择
    T2CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置gpio、pwm极性
    if (PwmChan == TIMER_PWM_2_P53)
    {
        LCMCR0 &= U8_NBIT1;
        P5 |= U8_BIT3;
        P5IO |= U8_BIT3;
    }
    else if (PwmChan == TIMER_PWM_2_P24)
    {
        LCMCR0 |= U8_BIT1;
        P2 |= U8_BIT4;
        P2IO |= U8_BIT4;
    }
    T2CR2 |= 0x01;
    T2CR2 |= (unsigned char)((PwmDir & 0x01) << 2);
    // 4 - 配置pwm周期及占空比
    T2DR1L = (unsigned char)(Period & 0x00FF);
    T2DR1H = (unsigned char)(Period >> 8);
    T2DR2H = (unsigned char)(Duty >> 8);
    T2DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器2配置pwm周期及占空比
 *
 * @param period      pwm周期计数器     16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us
 * @param duty        pwm占空比计数器   16bit，范围 0~65535， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us
 *
 * @note pwm周期计算：(period+1) * freq_div / sys_clk * 1000000 us
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note duty为0，则pwm口恒定输出低电平（极性为正）；duty > period，则pwm口恒定输出高电平（极性为正）
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 * @example 若需要50%占空比，则设置 duty 为 period 一半
 */
void bsp_pwm2_set(unsigned int Period, unsigned int Duty)
{
    T2DR1L = (unsigned char)(Period & 0x00FF);
    T2DR1H = (unsigned char)(Period >> 8);
    T2DR2H = (unsigned char)(Duty >> 8);
    T2DR2L = (unsigned char)Duty;
}


/**
 * @brief 定时器2开关pwm
 *
 * @param Switch    pwm开关
 */
void bsp_pwm2_switch(TYPE_ENUM_SWITCH Switch)
{
    T2CR1 |= U8_BIT0;
    if (Switch == ENABLE) T2CR1 |= 0x80;
    else T2CR1 &= ~0x80;
}


/**
 * @brief 定时器5初始化为定时器模式
 *
 * @param TimerFreq           定时器分频
 * @param IntPriority         定时中断优先级
 * @param Period              定时周期 - 16bit   { 0 ~ 65535 }
 *
 * @note 定时中断周期计算：(Period + 1) * TimerFreq / SysClock * 1000000 us
 * @example 16M内振，定时中断125us，最低优先级 : bsp_timer5_init (TIMER_FREQ_DIV_8, TIMER_INT_PRIORITY_0, 249);
 * @example 8M内振，定时中断125us，最低优先级 : bsp_timer5_init (TIMER_FREQ_DIV_4, TIMER_INT_PRIORITY_0, 249);
 */
void bsp_timer5_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period)
{
    T5CR1 = 0;
    T5CR2 = 0;
    // 1 - timer模式选择
    T5CR1 |= (unsigned char)((0x00 & 0x03) << 4);
    // 2 - timer分频选择
    T5CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置定时周期
    T5DR0L = (unsigned char)(Period & 0x00FF);
    T5DR0H = (unsigned char)(Period >> 8);
    // 4 - 配置中断优先级并使能中断
    switch (IntPriority)
    {
        case TIMER_INT_PRIORITY_0:    IP0 &= ~0x04;   IP1 &= ~0x04;   break;
        case TIMER_INT_PRIORITY_1:    IP0 |= 0x04;    IP1 &= ~0x04;   break;
        case TIMER_INT_PRIORITY_2:    IP0 &= ~0x04;   IP1 |= 0x04;    break;
        case TIMER_INT_PRIORITY_3:    IP0 |= 0x04;    IP1 |= 0x04;    break;
        default: break;
    }
    IE2 |= 0x01;
    T5CR1 &= 0xFB;
    T5CR1 |= 0x88;
}


/**
 * @brief 快速初始化定时器5，定时单位us
 *
 * @param IntPriority   定时中断优先级
 * @param usCnt             定时值，范围 0~2000
 */
void bsp_timer5_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt)
{
    if (usCnt > 32767) return;

    if (SysClock == 16)
    {
        bsp_timer5_init(TIMER_FREQ_DIV_8, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 8)
    {
        bsp_timer5_init(TIMER_FREQ_DIV_4, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
    else if (SysClock == 4)
    {
        bsp_timer5_init(TIMER_FREQ_DIV_2, IntPriority, (unsigned int)((usCnt << 1) - 1));
    }
}


/**
 * @brief 定时器5初始化为pwm模式
 *
 * @param TimerFreq    定时器分频
 * @param Period      pwm周期计数器     { 16bit，范围 0~65535， 计算公式：(period+1) * freq_div / sys_clk * 1000000 us }
 *
 * @note pwm周期计算：(Period+1) * TimerFreq / SysClock * 1000000 us
 *
 * @example 16M内振，pwm频率20K，即周期50us，周期计算 : (199 + 1) * 4 / 16M * 1000000 = 50us   即 period = 199 , freq_div = TIMER_FREQ_DIV_4
 */
void bsp_pwm5_init_period(TYPE_ENUM_TIMER_FREQ TimerFreq, unsigned int Period)
{
    T5CR1 = 0;
    T5CR2 = 0;
    // 1 - timer模式选择
    T5CR1 |= (unsigned char)((0x03 & 0x03) << 4);
    // 2 - timer分频选择
    T5CR2 |= (unsigned char)((TimerFreq & 0x07) << 5);
    // 3 - 配置pwm周期
    T5DR0L = (unsigned char)(Period & 0x00FF);
    T5DR0H = (unsigned char)(Period >> 8);
    // 4 - 定时器使能，开始计数
    T5CR1 &= 0xFB;
    T5CR1 |= 0x88;
}


/**
 * @brief 初始化pwma通道
 *
 * @param PwmChan  pwm端口
 * @param PwmDir   pwm极性
 * @param Duty      pwm占空比计数器
 *
 * @note pwm占空比计算：(Duty+1) * TimerFreq / SysClock * 1000000 us
 */
void bsp_pwm5a_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty)
{
    // 1 - 配置pwma通道
    if (TIMER_PWM_A_P00 == PwmChan)
    {
        LCMCR2 &= U8_NBIT3;
        P0 |= U8_BIT0;
        P0IO |= U8_BIT0;
    }
    else if (TIMER_PWM_A_P45 == PwmChan)
    {
        LCMCR2 |= U8_BIT3;
        P4 |= U8_BIT5;
        P4IO |= U8_BIT5;
    }
    // 2 - 配置pwma极性
    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT0;
    else T5DCR2 &= U8_NBIT0;
    // 3 - 配置pwma占空比
    T5DR1H = (unsigned char)(Duty >> 8);
    T5DR1L = (unsigned char)Duty;
}


/**
 * @brief 初始化pwmb通道
 *
 * @param PwmChan  pwm端口
 * @param Duty      pwm占空比计数器：独立模式下，设置PWM占空比，长度12位，(duty+1) * freq_div / sys_clk * 1000000 us；互补死区模式下，设置互补通道的死区宽度，长度8位，(duty+1) / sys_clk * 1000000 us
 * @param PwmDir   pwm极性  独立模式下表示输出是否反相，互补模式下表示输出与a通道是否反相
 * @param PwmMode  pwmB通道模式 互补上升沿死区，互补下降沿死区，互补，独立四种模式
 *
 * @note pwm占空比计算：(Duty+1) * TimerFreq / SysClock * 1000000 us
 * @note pwm死区计算：(Duty+1) / SysClock * 1000000 us
 */
void bsp_pwm5b_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode)
{
    if (TIMER_PWM_B_P01 == PwmChan)
    {
        LCMCR2 &= U8_NBIT4;
        P0 |= U8_BIT1;
        P0IO |= U8_BIT1;
    }
    else if (TIMER_PWM_B_P44 == PwmChan)
    {
        LCMCR2 |= U8_BIT4;
        P4 |= U8_BIT4;
        P4IO |= U8_BIT4;
    }

    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT1;
    else T5DCR2 &= U8_NBIT1;

    if (TIMER5_PWM_COMPLE_DEAD_RISING == PwmMode)
    {
        T5DCR2 |= U8_BIT6;  // pwmB互补模式
        T5DCR1 |= U8_BIT0;  // AB插入死区
        T5DCR1 |= U8_BIT1;  // 主波形上升沿插入死区
        T5DR2L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE_DEAD_FALLING == PwmMode)
    {
        T5DCR2 |= U8_BIT6;  // pwmB互补模式
        T5DCR1 |= U8_BIT0;  // AB插入死区
        T5DCR1 &= U8_NBIT1; // 主波形下降沿插入死区
        T5DR2L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE == PwmMode)
    {
        T5DCR2 |= U8_BIT6;  // pwmB互补模式
    }
    else if (TIMER5_PWM_INDEPEND == PwmMode)
    {
        T5DR2H = (unsigned char)(Duty >> 8);
        T5DR2L = (unsigned char)Duty;
    }
}


/**
 * @brief 初始化pwmc通道
 *
 * @param PwmChan  pwm端口
 * @param PwmDir   pwm极性
 * @param Duty      pwm占空比计数器   { 12bit，范围 0~4095， 计算公式：(Duty+1) * TimerFreq / SysClock * 1000000 us }
 *
 * @note pwm占空比计算：(Duty+1) * TimerFreq / SysClock * 1000000 us
 */
void bsp_pwm5c_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty)
{
    if (TIMER_PWM_C_P02 == PwmChan)
    {
        LCMCR2 &= U8_NBIT5;
        P0 |= U8_BIT2;
        P0IO |= U8_BIT2;
    }
    else if (TIMER_PWM_C_P43 == PwmChan)
    {
        LCMCR2 |= U8_BIT5;
        P4 |= U8_BIT3;
        P4IO |= U8_BIT3;
    }

    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT2;
    else T5DCR2 &= U8_NBIT2;

    T5DR3H = (unsigned char)(Duty >> 8);
    T5DR3L = (unsigned char)Duty;
}


/**
 * @brief 初始化pwmd通道
 *
 * @param PwmChan  pwm端口
 * @param Duty      pwm占空比计数器：独立模式下，设置PWM占空比，长度12位，(duty+1) * freq_div / sys_clk * 1000000 us；互补死区模式下，设置互补通道的死区宽度，长度8位，(duty+1) / sys_clk * 1000000 us
 * @param PwmDir   pwm极性  独立模式下表示输出是否反相，互补模式下表示输出与a通道是否反相
 * @param PwmMode  pwmB通道模式 互补上升沿死区，互补下降沿死区，互补，独立四种模式
 *
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note pwm死区计算：(duty+1) / sys_clk * 1000000 us
 */
void bsp_pwm5d_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode)
{
    if (TIMER_PWM_D_P03 == PwmChan)
    {
        LCMCR2 &= U8_NBIT6;
        P0 |= U8_BIT3;
        P0IO |= U8_BIT3;
    }
    else if (TIMER_PWM_D_P42 == PwmChan)
    {
        LCMCR2 |= U8_BIT6;
        P4 |= U8_BIT2;
        P4IO |= U8_BIT2;
    }

    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT3;
    else T5DCR2 &= U8_NBIT3;

    if (TIMER5_PWM_COMPLE_DEAD_RISING == PwmMode)
    {
        T5DCR1 |= U8_BIT6;  // pwmD互补模式
        T5DCR1 |= U8_BIT2;  // CD插入死区
        T5DCR1 |= U8_BIT3;  // 主波形上升沿插入死区
        T5DR4L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE_DEAD_FALLING == PwmMode)
    {
        T5DCR1 |= U8_BIT6;  // pwmD互补模式
        T5DCR1 |= U8_BIT2;  // CD插入死区
        T5DCR1 &= U8_NBIT3; // 主波形下降沿插入死区
        T5DR4L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE == PwmMode)
    {
        T5DCR1 |= U8_BIT6;  // pwmD互补模式
    }
    else if (TIMER5_PWM_INDEPEND == PwmMode)
    {
        T5DR4H = (unsigned char)(Duty >> 8);
        T5DR4L = (unsigned char)Duty;
    }
}


/**
 * @brief 初始化pwme通道
 *
 * @param pwm_gpio  pwm端口     { TIMER_PWM_E_P04, TIMER_PWM_E_P44 }
 * @param pwm_dir   pwm极性     { TIMER_PWM_DIR_POSITIVE, TIMER_PWM_DIR_NEGATIVE }
 * @param duty      pwm占空比计数器   { 12bit，范围 0~4095， 计算公式：(duty+1) * freq_div / sys_clk * 1000000 us }
 *
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 */
void bsp_pwm5e_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty)
{
    if (TIMER_PWM_E_P04 == PwmChan)
    {
        LCMCR2 &= U8_NBIT7;
        P0 |= U8_BIT4;
        P0IO |= U8_BIT4;
    }

    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT4;
    else T5DCR2 &= U8_NBIT4;

    T5DR5H = (unsigned char)(Duty >> 8);
    T5DR5L = (unsigned char)Duty;
}


/**
 * @brief 初始化pwmf通道
 *
 * @param pwm_gpio  pwm端口
 * @param duty      pwm占空比计数器：独立模式下，设置PWM占空比，长度12位，(duty+1) * freq_div / sys_clk * 1000000 us；互补死区模式下，设置互补通道的死区宽度，长度8位，(duty+1) / sys_clk * 1000000 us
 * @param pwm_dir   pwm极性   独立模式下表示输出是否反相，互补模式下表示输出与a通道是否反相
 * @param pwm_mode  pwmB通道模式    互补上升沿死区，互补下降沿死区，互补，独立四种模式
 *
 * @note pwm占空比计算：(duty+1) * freq_div / sys_clk * 1000000 us
 * @note pwm死区计算：(duty+1) / sys_clk * 1000000 us
 */
void bsp_pwm5f_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode)
{
    if (TIMER_PWM_F_P05 == PwmChan)
    {
        LCMCR1 |= U8_BIT0;
        P0 |= U8_BIT5;
        P0IO |= U8_BIT5;
    }

    if (TIMER_PWM_DIR_NEGATIVE == PwmDir) T5DCR2 |= U8_BIT5;
    else T5DCR2 &= U8_NBIT5;

    if (TIMER5_PWM_COMPLE_DEAD_RISING == PwmMode)
    {
        T5DCR1 |= U8_BIT7;  // pwmF互补模式
        T5DCR1 |= U8_BIT4;  // EF插入死区
        T5DCR1 |= U8_BIT5;  // 主波形上升沿插入死区
        T5DR6L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE_DEAD_FALLING == PwmMode)
    {
        T5DCR1 |= U8_BIT7;  // pwmF互补模式
        T5DCR1 |= U8_BIT4;  // EF插入死区
        T5DCR1 &= U8_NBIT5; // 主波形下降沿插入死区
        T5DR6L = (unsigned char)Duty;
    }
    else if (TIMER5_PWM_COMPLE == PwmMode)
    {
        T5DCR1 |= U8_BIT7;  // pwmF互补模式
    }
    else if (TIMER5_PWM_INDEPEND == PwmMode)
    {
        T5DR6H = (unsigned char)(Duty >> 8);
        T5DR6L = (unsigned char)Duty;
    }
}


/**
 * @brief pwma ~ pwmf 通道开关
 *
 * @param PwmChan pwm通道
 * @param Switch 开关
 */
void bsp_pwm5_switch(TYPE_ENUM_TIMER5_PWM_CHAN PwmChan, TYPE_ENUM_SWITCH Switch)
{
    if (ENABLE == Switch) T5PWMOE |= (0x01 << PwmChan);
    else T5PWMOE &= ~(0x01 << PwmChan);
}


/**
 * @brief pwma ~ pwmf 设置占空比或死区
 *
 * @param PwmChan pwm通道
 * @param Duty  pwm占空比计数器：独立模式下，设置PWM占空比，长度12位，(duty+1) * freq_div / sys_clk * 1000000 us；互补死区模式下，设置互补通道的死区宽度，长度8位，(duty+1) / sys_clk * 1000000 us
 */
void bsp_pwm5_duty_set(TYPE_ENUM_TIMER5_PWM_CHAN PwmChan, unsigned int Duty)
{
    switch (PwmChan)
    {
        case TIMER5_PWM_A:
            T5DR1H = (unsigned char)(Duty >> 8);
            T5DR1L = (unsigned char)Duty;
            break;
        case TIMER5_PWM_B:
            T5DR2H = (unsigned char)(Duty >> 8);
            T5DR2L = (unsigned char)Duty;
            break;
        case TIMER5_PWM_C:
            T5DR3H = (unsigned char)(Duty >> 8);
            T5DR3L = (unsigned char)Duty;
            break;
        case TIMER5_PWM_D:
            T5DR4H = (unsigned char)(Duty >> 8);
            T5DR4L = (unsigned char)Duty;
            break;
        case TIMER5_PWM_E:
            T5DR5H = (unsigned char)(Duty >> 8);
            T5DR5L = (unsigned char)Duty;
            break;
        case TIMER5_PWM_F:
            T5DR6H = (unsigned char)(Duty >> 8);
            T5DR6L = (unsigned char)Duty;
            break;

        default:
            break;
    }
}
