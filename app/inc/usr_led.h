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

typedef enum led_e {
    LED3,
    LED4,
} led_t;

EXT void usr_led_init(led_t led);
EXT void usr_led_toggle(led_t led);
EXT void usr_led_on(led_t led);
EXT void usr_led_off(led_t led);

#ifdef __cplusplus
}
#endif

#endif /* __USR_LED_H__ */
