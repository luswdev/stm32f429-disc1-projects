/**
 * @file    util_sw_pwm.c
 * @brief   stm32f4xx software pwm function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "util_clk.h"

#define UTIL_SW_PWM_SET
#include "util_sw_pwm.h"

/**
 * @brief generate software pwm with n duty cycle
 */
void util_sw_pwm_start(
    sw_pwm_t pin,       /**< pwm output target gpio pin */
    int32_t duty_cnt    /**< n duty cycle to generate   */
    )
{
    if (pin.freq > TICK_PER_SECOND) {
        pin.freq = TICK_PER_SECOND;
    }

    if (pin.duty > DUTY_BASE) {
        pin.duty = DUTY_BASE;
    }

    int32_t period_tick = TICK_PER_SECOND / pin.freq;

    while (duty_cnt--) {
        GPIO_SetBits(pin.output_pin.port, pin.output_pin.pin);
        util_delay_tick((period_tick * pin.duty) / DUTY_BASE);
        GPIO_ResetBits(pin.output_pin.port, pin.output_pin.pin);
        util_delay_tick((period_tick * (DUTY_BASE - pin.duty)) / DUTY_BASE);
    }
}
