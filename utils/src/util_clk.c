/**
 * @file    util_clk.c
 * @brief   stm32f4xx clock and system tick declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include <stm32f4xx_rcc.h>

#define UTIL_CLK_SET
#include "util_clk.h"

static __IO uint32_t u32SysTicks;

/**
 * @brief initial system clock and tick
 */
void util_clock_init(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
    RCC_GetClocksFreq(&RCC_Clocks);

    SysTick_Config(RCC_Clocks.SYSCLK_Frequency / TICK_PER_SECOND);

    /* init system tick */
    util_tick_init();
}

/**
 * @brief initial system tick
 */
void util_tick_init(void)
{
    u32SysTicks = 0;
}

/**
 * @brief get current system tick
 */
uint32_t util_tick_get(void)
{
    return u32SysTicks;
}

/**
 * @brief increase current system tick
 */
void util_tick_increase(void)
{
    ++u32SysTicks;
}

/**
 * @brief delay # tick
 */
void util_delay_tick(
    tick_t tick     /**< tick to delay */
    )
{
    const uint32_t u32CurTick = util_tick_get();
    const uint32_t u32TargetTick = u32CurTick + tick;

    while (util_tick_get() <= u32TargetTick) {
        /* empty */
    }
}

/**
 * @brief delay # ms
 */
void util_delay_ms(
    uint32_t ms     /**< tick to ms */
    )
{
    const tick_t tick = MS_TO_TICK(ms);
    util_delay_tick(tick);
}
