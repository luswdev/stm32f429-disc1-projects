/**
 * @file    usr_led.c
 * @brief   stm32f429i-disc1 leds function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "util_gpio.h"
#include "util_clk.h"
#include "util_sw_pwm.h"

#define USR_LED_SET
#include "usr_led.h"

static led_spd_t eBlinkSpd = LED_SPD_MID;

static char leds[][8] = {
    "PG13", "PG14", "PG12",
};

/**
 * @brief initial led gpio
 */
void usr_led_init(
    led_t led   /**< led id */
    )
{
    gpio_t led_gpio = util_gpio_get_by_name(leds[led]);

    RCC_AHB1PeriphClockCmd(led_gpio.rcc_clock, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = led_gpio.pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(led_gpio.port, &GPIO_InitStructure);
}

/**
 * @brief toggle led
 */
void usr_led_toggle(
    led_t led   /**< led id */
    )
{
    gpio_t led_gpio = util_gpio_get_by_name(leds[led]);
    util_gpio_toggle(led_gpio);
}

/**
 * @brief turn on led
 */
void usr_led_on(
    led_t led   /**< led id */
    )
{
    gpio_t led_gpio = util_gpio_get_by_name(leds[led]);
    util_gpio_on(led_gpio);
}

/**
 * @brief turn off led
 */
void usr_led_off(
    led_t led   /**< led id */
    )
{
    gpio_t led_gpio = util_gpio_get_by_name(leds[led]);
    util_gpio_off(led_gpio);
}

/**
 * @brief set led output speed control level
 */
void usr_led_set_spd(
    led_spd_t spd   /** led blink speed in main */
    )
{
    eBlinkSpd = spd;
}

/**
 * @brief get led output speed control level
 */
led_spd_t usr_led_get_spd(void)
{
    return eBlinkSpd;
}

/**
 * @brief generate led output pwn with period PWM_CONTINUE_MS
 */
void usr_led_pwm(
    led_t led,      /**< target led     */
    int32_t freq,   /**< pwm frequency  */
    int32_t duty    /**< pwm duty       */
    )
{
    sw_pwm_t pwm = {
        util_gpio_get_by_name(leds[led]),
        freq,
        duty,
    };

    int32_t period_ms = TICK_TO_MS(TICK_PER_SECOND / freq);
    if (period_ms > PWM_CONTINUE_MS) {
        period_ms = PWM_CONTINUE_MS;
        freq = TICK_PER_SECOND / MS_TO_TICK(PWM_CONTINUE_MS);
    }

    int32_t duty_cnt = PWM_CONTINUE_MS / period_ms;
    util_sw_pwm_start(pwm, duty_cnt);
}