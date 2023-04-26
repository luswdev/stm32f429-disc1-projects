/**
 * @file    util_sw_pwm.h
 * @brief   stm32f4xx software pwm function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __UTIL_SW_PWM_H__
#define __UTIL_SW_PWM_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef UTIL_SW_PWM_SET
#define EXT
#else
#define EXT extern
#endif

#define DUTY_BASE   1000

#include "util_gpio.h"

typedef struct sw_pwm_s {
    gpio_t output_pin;
    int32_t freq;
    int32_t duty;
} sw_pwm_t;

EXT void util_sw_pwm_start(sw_pwm_t pin, int32_t duty_cnt);

#endif /* __UTIL_SW_PWM_H__ */
