/**
 * @file    util_uart.h
 * @brief   stm32f4xx uart/usart function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __UTIL_UART_H__
#define __UTIL_UART_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef UTIL_UART_SET
#define EXT
#else
#define EXT extern
#endif

#include <stm32f4xx.h>

typedef struct uart_s {
    USART_TypeDef*  uartx;
    uint32_t        rcc_clock;

    char            tx[8];
    char            rx[8];

    uint8_t         af;
} uart_t;


EXT void util_uart_init(uart_t uart, uint32_t baudrate);
EXT void util_uart_putc(uart_t uart, char ch);
EXT void util_uart_puts(uart_t uart, char str[]);

#ifdef __cplusplus
}
#endif

#endif /* __UTIL_UART_H__ */
