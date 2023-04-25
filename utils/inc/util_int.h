/**
 * @file    util_int.h
 * @brief   stm32f4xx interrupt function define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __UTIL_INT_H__
#define __UTIL_INT_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef UTIL_INT_SET
#define EXT
#else
#define EXT extern
#endif

#include <stm32f4xx.h>

EXT void NMI_Handler(void);
EXT void HardFault_Handler(void);
EXT void MemManage_Handler(void);
EXT void BusFault_Handler(void);
EXT void UsageFault_Handler(void);
EXT void SVC_Handler(void);
EXT void DebugMon_Handler(void);
EXT void PendSV_Handler(void);
EXT void SysTick_Handler(void);

#ifdef __cplusplus
}
#endif

#endif /* __UTIL_INT_H__ */
