/**
 * @file    util_gpio.c
 * @brief   stm32f4xx gpio function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#define UTIL_GPIO_SET
#include "util_gpio.h"

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
