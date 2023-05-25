/**
 * @file    usr_console.c
 * @brief   stm32f429i-disc1 uart output to usb tty console function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "util_gpio.h"
#include "util_uart.h"

#define USR_CONSOLE_SET
#include "usr_console.h"

static uart_t uarts[] = {
    {   /**< USART1 */
        USART1,
        RCC_APB2Periph_USART1,
        "PA9",
        "PA10",
        GPIO_AF_USART1,
    },
};

/**
 * @brief initial uart to usb tty
 */
void usr_console_init(void)
{
    util_uart_init(uarts[CONSOLE_USB_TTY], 9600);
}

/**
 * @brief output string to usb tty
 */
void uart_console_puts(
    char str[]  /**< target string */
    )
{
    util_uart_puts(uarts[CONSOLE_USB_TTY], str);
}

/**
 * @brief syscalls _write redirect to uart putc
 */
int _write(int file, char *ptr, int len)
{
    int idx;
    for (idx = 0; idx < len; idx++) {
       util_uart_putc(uarts[CONSOLE_USB_TTY], *ptr++);
    }
    return len;
}
