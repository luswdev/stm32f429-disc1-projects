/**
 * @file    util_clk.h
 * @brief   stm32f4xx clock and system tick function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __UTIL_CLK_H__
#define __UTIL_CLK_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef UTIL_CLK_SET
#define EXT
#else
#define EXT extern
#endif

#include <stm32f4xx.h>

#define TICK_PER_SECOND 10000
#define MS_TO_TICK(ms)      ((ms * TICK_PER_SECOND) / 1000)
#define TICK_TO_MS(tick)    ((tick * 1000) / TICK_PER_SECOND)

typedef uint32_t tick_t;

EXT void util_clock_init(void);
EXT void util_tick_init(void);
EXT tick_t util_tick_get(void);
EXT void util_tick_increase(void);

EXT void util_delay_tick(tick_t tick);
EXT void util_delay_ms(uint32_t ms);

#ifdef __cplusplus
}
#endif

#endif /* __UTIL_CLK_H__ */
