/**
 * @file    util_int.c
 * @brief   stm32f4xx interrupt function declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#define UTIL_INT_SET
#include "util_int.h"
#include "util_clk.h"

/**
 * @brief handles NMI exception
 */
void NMI_Handler(void)
{
    /* empty */
}

/**
 * @brief handles Hard Fault exception
 */
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    for ( ; ; ) {
        /* panic */
    }
}

/**
  * @brief handles Memory Manage exception
  */
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    for ( ; ; ) {
        /* panic */
    }
}

/**
 * @brief handles Bus Fault exception
 */
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    for ( ; ; ) {
        /* panic */
    }
}

/**
 * @brief handles Usage Fault exception
 */
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    for ( ; ; ) {
        /* panic */
    }
}

/**
 * @brief handles SVCall exception
 */
void SVC_Handler(void)
{
    /* empty */
}

/**
 * @brief handles Debug Monitor exception
 */
void DebugMon_Handler(void)
{
    /* empty */
}

/**
 * @brief handles PendSVC exception
 */
void PendSV_Handler(void)
{
    /* empty */
}

/**
 * @brief handles SysTick Handler
 */
void SysTick_Handler(void)
{
    util_tick_increase();
}
