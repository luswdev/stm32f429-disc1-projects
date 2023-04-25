/**
 * @file    main.c
 * @brief   main entry point declare
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#include <stdint.h>

#include "util_clk.h"
#include "usr_led.h"

#define MAIN_SET
#include "main.h"

/**
 * @brief main program
 */
int main(void)
{
    util_clock_init();

    usr_led_init(LED3);
    usr_led_init(LED4);

    usr_led_on(LED3);
    usr_led_off(LED4);

    for ( ; ; ) {
        usr_led_toggle(LED3);
        usr_led_toggle(LED4);

        util_delay_ms(1000);
    }
}
