/**
 * @file bsp_timer.h
 * @author your name (you@domain.com)
 * @brief 中微爱芯 & aip8f3264
 * @brief RD8F12AE2207A / RD8F04DS1407A / RD8F04DS1007A
 * @version 0.1
 * @date 2024-01-04
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _BSP_TIMER_H_
#define _BSP_TIMER_H_


#include "typedef.h"


#define GLOBAL_INT_EN()     (IE0 |= U8_BIT7)
#define GLOBAL_INT_DIS()	(IE0 &= U8_NBIT7)


 /**
  * @brief system_clk - 系统时钟选择
  *
  */
typedef enum _TYPE_ENUM_SYS_CLK
{
    SYS_CLK_HIRC_16M = 0,
    SYS_CLK_HIRC_8M,
    SYS_CLK_HIRC_4M,
    SYS_CLK_HXT_16M,
    SYS_CLK_HXT_12M,
    SYS_CLK_HXT_8M,
    SYS_CLK_HXT_4M
} TYPE_ENUM_SYS_CLK;


/**
 * @brief timer - 定时器分频
 *
 */
typedef enum
{
    TIMER_FREQ_DIV_1 = 0,
    TIMER_FREQ_DIV_2,
    TIMER_FREQ_DIV_4,
    TIMER_FREQ_DIV_8,
    TIMER_FREQ_DIV_64,
    TIMER_FREQ_DIV_512,
    TIMER_FREQ_DIV_2048,
    TIMER_FREQ_TCN
} TYPE_ENUM_TIMER_FREQ;


/**
 * @brief timer - 定时器中断优先级
 *
 * @note 优先级顺序，0为最低，3为最高
 */
typedef enum
{
    TIMER_INT_PRIORITY_0 = 0,
    TIMER_INT_PRIORITY_1,
    TIMER_INT_PRIORITY_2,
    TIMER_INT_PRIORITY_3
} TYPE_ENUM_TIMER_INT_PRIORITY;


/**
 * @brief timer - pwm极性
 *
 */
typedef enum
{
    TIMER_PWM_DIR_POSITIVE = 0,
    TIMER_PWM_DIR_NEGATIVE
} TYPE_ENUM_TIMER_PWM_DIR;


/**
 * @brief timer - pwm端口选择
 *
 */
typedef enum
{
    TIMER_PWM_0_P51 = 0,
    TIMER_PWM_0_P22,
    TIMER_PWM_1_P52,
    TIMER_PWM_1_P23,
    TIMER_PWM_2_P53,
    TIMER_PWM_2_P24,
    TIMER_PWM_A_P00,
    TIMER_PWM_A_P45,
    TIMER_PWM_B_P01,
    TIMER_PWM_B_P44,
    TIMER_PWM_C_P02,
    TIMER_PWM_C_P43,
    TIMER_PWM_D_P03,
    TIMER_PWM_D_P42,
    TIMER_PWM_E_P04,
    TIMER_PWM_F_P05
} TYPE_ENUM_TIMER_PWM_CHAN;


typedef enum
{
    TIMER5_PWM_COMPLE_DEAD_RISING = 0,
    TIMER5_PWM_COMPLE_DEAD_FALLING,
    TIMER5_PWM_COMPLE,
    TIMER5_PWM_INDEPEND
} TYPE_ENUM_TIMER5_PWM_MODE;


typedef enum
{
    TIMER5_PWM_A = 0,
    TIMER5_PWM_B,
    TIMER5_PWM_C,
    TIMER5_PWM_D,
    TIMER5_PWM_E,
    TIMER5_PWM_F
} TYPE_ENUM_TIMER5_PWM_CHAN;


extern unsigned int get_tick(void);
extern TYPE_ENUM_BOOL is_systick_expired(unsigned int *pTaskTick, unsigned int SetTimeTick);
extern void systick_init(void);
extern void bsp_power_on_delay(void);

extern unsigned char SysClock;
extern TYPE_ENUM_STATUS bsp_sysclock_init(TYPE_ENUM_SYS_CLK SysClockSel);

extern void bsp_timer0_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period);
extern void bsp_timer0_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt);
extern void bsp_pwm0_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmChan, unsigned int Period, unsigned int Duty);
extern void bsp_pwm0_set(unsigned int Period, unsigned int Duty);
extern void bsp_pwm0_switch(TYPE_ENUM_SWITCH Switch);

extern void bsp_timer1_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period);
extern void bsp_timer1_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt);
extern void bsp_pwm1_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmChan, unsigned int Period, unsigned int Duty);
extern void bsp_pwm1_set(unsigned int Period, unsigned int Duty);
extern void bsp_pwm1_switch(TYPE_ENUM_SWITCH Switch);

extern void bsp_timer2_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period);
extern void bsp_timer2_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt);
extern void bsp_pwm2_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_PWM_DIR PwmDir, TYPE_ENUM_TIMER_PWM_CHAN PwmChan, unsigned int Period, unsigned int Duty);
extern void bsp_pwm2_set(unsigned int Period, unsigned int Duty);
extern void bsp_pwm2_switch(TYPE_ENUM_SWITCH Switch);

extern void bsp_timer5_init(TYPE_ENUM_TIMER_FREQ TimerFreq, TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int Period);
extern void bsp_timer5_init_us(TYPE_ENUM_TIMER_INT_PRIORITY IntPriority, unsigned int usCnt);
extern void bsp_pwm5_init_period(TYPE_ENUM_TIMER_FREQ TimerFreq, unsigned int Period);
extern void bsp_pwm5a_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty);
extern void bsp_pwm5b_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode);
extern void bsp_pwm5c_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty);
extern void bsp_pwm5d_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode);
extern void bsp_pwm5e_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty);
extern void bsp_pwm5f_init(TYPE_ENUM_TIMER_PWM_CHAN PwmChan, TYPE_ENUM_TIMER_PWM_DIR PwmDir, unsigned int Duty, TYPE_ENUM_TIMER5_PWM_MODE PwmMode);
extern void bsp_pwm5_switch(TYPE_ENUM_TIMER5_PWM_CHAN PwmChan, TYPE_ENUM_SWITCH Switch);
extern void bsp_pwm5_duty_set(TYPE_ENUM_TIMER5_PWM_CHAN PwmChan, unsigned int Duty);

#endif
