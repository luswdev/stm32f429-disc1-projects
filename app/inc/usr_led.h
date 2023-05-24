/**
 * @file    usr_led.h
 * @brief   stm32f429i-disc1 leds function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __USR_LED_H__
#define __USR_LED_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef USR_LED_SET
#define EXT
#else
#define EXT extern
#endif

#include <stm32f4xx.h>

#include "util_sw_pwm.h"

#define PWM_CONTINUE_MS     10

typedef enum led_e {
    LED3,
    LED4,
    USR_LED,
} led_t;

typedef enum led_spd_e {
    LED_SPD_FAST,
    LED_SPD_MID,
    LED_SPD_SLOW,
} led_spd_t;

EXT void usr_led_init(led_t led);
EXT void usr_led_toggle(led_t led);
EXT void usr_led_on(led_t led);
EXT void usr_led_off(led_t led);

EXT void usr_led_set_spd(led_spd_t spd);
EXT led_spd_t usr_led_get_spd(void);

EXT void usr_led_pwm(led_t led, int32_t freq, int32_t duty);

#ifdef __cplusplus
}
#endif

#endif /* __USR_LED_H__ */
