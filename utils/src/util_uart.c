/**
 * @file    util_uart.c
 * @brief   stm32f4xx uart/usart function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "util_gpio.h"

#define UTIL_UART_SET
#include "util_uart.h"

/**
 * @brief initial uart gpio
 */
static void uart_gpio_init(
    uart_t uart     /**< target u(s)art */
    )
{
    RCC_AHB1PeriphClockCmd(uart.tx.base.rcc_clock,  ENABLE);

    GPIO_PinAFConfig(uart.tx.base.port, uart.tx.source, uart.tx.af);
    GPIO_PinAFConfig(uart.rx.base.port, uart.rx.source, uart.rx.af);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_StructInit(&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin   = uart.tx.base.pin;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(uart.tx.base.port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin  = uart.rx.base.pin;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(uart.rx.base.port, &GPIO_InitStructure);
}

/**
 * @brief initial uart
 */
void util_uart_init(
    uart_t uart,         /**< target u(s)art */
    uint32_t baudrate    /**< uart baudrate  */
    )
{
    uart_gpio_init(uart);

    RCC_APB2PeriphClockCmd(uart.rcc_clock, ENABLE);

    USART_InitTypeDef USART_InitStructure;
    USART_StructInit(&USART_InitStructure);

    USART_InitStructure.USART_BaudRate            = baudrate;
    USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits            = USART_StopBits_1;
    USART_InitStructure.USART_Parity              = USART_Parity_No ;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(uart.uartx, &USART_InitStructure);

    USART_Cmd(uart.uartx, ENABLE);
}

/**
 * @brief output character to uart tx
 */
void util_uart_putc(
    uart_t uart,    /**< target u(s)art     */
    char ch         /**< target character   */
    )
{
    uart.uartx->DR = (uint8_t) ch;

    while (USART_GetFlagStatus(uart.uartx, USART_FLAG_TXE) == RESET);
}

/**
 * @brief output string to uart tx
 */
void util_uart_puts(
    uart_t uart,    /**< target u(s)art */
    char str[]      /**< target string  */
    )
{
    while (*str) {
        util_uart_putc(uart, *str++);
    }
}
