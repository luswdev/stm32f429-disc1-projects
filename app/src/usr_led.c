/**
 * @file    usr_led.c
 * @brief   stm32f429i-disc1 leds function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "util_gpio.h"

#define USR_LED_SET
#include "usr_led.h"

static led_spd_t eBlinkSpd = LED_SPD_MID;

static gpio_t leds[] = {
    {
        GPIOG,
        GPIO_Pin_13,
        RCC_AHB1Periph_GPIOG,
    },
    {
        GPIOG,
        GPIO_Pin_14,
        RCC_AHB1Periph_GPIOG,
    },
};

/**
 * @brief initial led gpio
 */
void usr_led_init(
    led_t led   /**< led id */
    )
{
    RCC_AHB1PeriphClockCmd(leds[led].rcc_clock, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = leds[led].pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(leds[led].port, &GPIO_InitStructure);
}

/**
 * @brief toggle led
 */
void usr_led_toggle(
    led_t led   /**< led id */
    )
{
    util_gpio_toggle(leds[led]);
}

/**
 * @brief turn on led
 */
void usr_led_on(
    led_t led   /**< led id */
    )
{
    util_gpio_on(leds[led]);
}

/**
 * @brief turn off led
 */
void usr_led_off(
    led_t led   /**< led id */
    )
{
    util_gpio_off(leds[led]);
}

void usr_led_set_spd(
    led_spd_t spd   /** led blink speed in main */
    )
{
    eBlinkSpd = spd;
}

led_spd_t usr_led_get_spd(void)
{
    return eBlinkSpd;
}