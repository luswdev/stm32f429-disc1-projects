/**
 * @file    util_gpio.c
 * @brief   stm32f4xx gpio function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include <stddef.h>
#include <stdlib.h>

#define UTIL_GPIO_SET
#include "util_gpio.h"

gpio_t util_gpio_get_by_name(
    const char gpio_name[]
    )
{
    gpio_t gpio;

    char port = gpio_name[1];
    uint8_t pin = strtol(gpio_name + 2, NULL, 10);

    gpio.port = (GPIO_TypeDef *)(AHB1PERIPH_BASE + 0x0400 * (port - 'A'));
    gpio.pin = 0x01 << pin;
    gpio.source = pin;
    gpio.rcc_clock = 0x01 << (port - 'A');

    return gpio;
}

/**
 * @brief toggle gpio
 */
void util_gpio_toggle(
    gpio_t gpio     /**< target gpio */
    )
{
    gpio.port->ODR ^= gpio.pin;
}

/**
 * @brief turn on gpio
 */
void util_gpio_on(
    gpio_t gpio     /**< target gpio */
    )
{
    gpio.port->BSRRL = gpio.pin;
}

/**
 * @brief turn off gpio
 */
void util_gpio_off(
    gpio_t gpio     /**< target gpio */
    )
{
    gpio.port->BSRRH = gpio.pin;
}
