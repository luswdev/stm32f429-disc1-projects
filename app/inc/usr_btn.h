/**
 * @file    usr_btn.h
 * @brief   stm32f429i-disc1 buttons function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __USR_BTN_H__
#define __USR_BTN_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef USR_BTN_SET
#define EXT
#else
#define EXT extern
#endif

#include <stm32f4xx.h>

#include "util_gpio.h"

typedef enum btn_e {
    BTN_USER,
} btn_t;

typedef enum btn_mode_e {
    BTN_MODE_GPIO,
    BTN_MODE_EXTI,
} btn_mode_t;

typedef struct button_type_s {
    char gpio[8];
    btn_mode_t      mode;
    struct exti_t{
        uint16_t    line;
        uint8_t     port;
        uint8_t     pin;
        uint8_t     irqn;
    } exti;
} button_type_t;

EXT void usr_btn_init(btn_t btn);

#ifdef __cplusplus
}
#endif

#endif /* __USR_LED_H__ */
