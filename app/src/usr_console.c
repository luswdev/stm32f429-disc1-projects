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
        {   /**< PA9 */
            {
                GPIOA,
                GPIO_Pin_9,
                RCC_AHB1Periph_GPIOA
            },
            GPIO_PinSource9,
            GPIO_AF_USART1,
        },
        {   /**< PA10 */
            {
                GPIOA,
                GPIO_Pin_10,
                RCC_AHB1Periph_GPIOA
            },
            GPIO_PinSource10,
            GPIO_AF_USART1,
        },
    },
};

void usr_console_init(void)
{
    util_uart_init(uarts[CONSOLE_USB_TTY], 9600);
}

void uart_console_puts(char str[])
{
    util_uart_puts(uarts[CONSOLE_USB_TTY], str);
}

int _write(int file, char *ptr, int len)
{
    int idx;
    for (idx = 0; idx < len; idx++) {
       util_uart_putc(uarts[CONSOLE_USB_TTY], *ptr++);
    }
    return len;
}
