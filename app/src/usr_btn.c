/**
 * @file    usr_btn.c
 * @brief   stm32f429i-disc1 buttons function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include "usr_led.h"

#define USR_BTN_SET
#include "usr_btn.h"

static button_type_t btns[] = {
    {
        "PA0",
        BTN_MODE_EXTI,
        {
            EXTI_Line0,             /**< match with gpio pin */
            EXTI_PortSourceGPIOA,   /**< match with gpio port */
            EXTI_PinSource0,        /**< match with gpio pin */
            EXTI0_IRQn,             /**< match with EXTI#_IRQHandler */
        },
    },
};

/**
 * @brief initial button
 */
void usr_btn_init(
    btn_t btn   /** button id */
    )
{
    gpio_t btn_gpio = util_gpio_get_by_name(btns[btn].gpio);

    RCC_AHB1PeriphClockCmd(btn_gpio.rcc_clock, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Pin = btn_gpio.pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(btn_gpio.port, &GPIO_InitStructure);

    if (btns[btn].mode == BTN_MODE_EXTI) {
        /* initial external interrupt for exti mode button */
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

        SYSCFG_EXTILineConfig(btns[btn].exti.port, btns[btn].exti.pin);

        EXTI_InitTypeDef EXTI_InitStructure;

        EXTI_InitStructure.EXTI_Line = btns[btn].exti.line;
        EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);

        NVIC_InitTypeDef NVIC_InitStructure;

        NVIC_InitStructure.NVIC_IRQChannel = btns[btn].exti.irqn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

        NVIC_Init(&NVIC_InitStructure);
    }
}

/**
 * @brief handles external interrupt #1
 *        set main blink led speed slow -> middle -> fast
 */
void EXTI0_IRQHandler(void)
{
    if (EXTI_GetITStatus(btns[BTN_USER].exti.line) == RESET) {
        return;
    }

    led_spd_t eCurSpd = usr_led_get_spd();

    switch (eCurSpd)
    {
    case LED_SPD_FAST:
        usr_led_set_spd(LED_SPD_SLOW);
        break;
    case LED_SPD_MID:
        usr_led_set_spd(LED_SPD_FAST);
        break;
    case LED_SPD_SLOW:
        usr_led_set_spd(LED_SPD_MID);
        break;
    default:
        break;
    }

    EXTI_ClearITPendingBit(btns[BTN_USER].exti.line);
}
