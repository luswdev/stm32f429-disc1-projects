/**
 * @file    usr_console.h
 * @brief   stm32f429i-disc1 uart output to usb tty console function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __USR_CONSOLE_H__
#define __USR_CONSOLE_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef USR_CONSOLE_SET
#define EXT
#else
#define EXT extern
#endif

#include <stdio.h>
#include "util_clk.h"

#define DEBUG_PRINT

#ifdef DEBUG_PRINT
#define DBG_MSG(fmt, args...) printf("[%d] %s():%d " fmt, (int)util_tick_get(), __func__, __LINE__, ## args);
#else
#define DBG_MSG
#endif

typedef enum console_e {
    CONSOLE_USB_TTY,
} console_t;

EXT void usr_console_init(void);
EXT void uart_console_puts(char str[]);

#ifdef __cplusplus
}
#endif

#endif /* __USR_CONSOLE_H__ */
