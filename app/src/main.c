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
#include "usr_btn.h"
#include "usr_console.h"

#define MAIN_SET
#include "main.h"

static led_spd_t preLedSpd;

/**
 * @brief main program
 */
int main(void)
{
    util_clock_init();

    usr_console_init();

    usr_led_init(LED3);
    usr_led_init(LED4);

    usr_btn_init(BTN_USER);

    usr_led_on(LED3);
    usr_led_off(LED4);

    DBG_MSG("press button to change led blink speed...\r\n");
    for ( ; ; ) {
        usr_led_toggle(LED3);
        usr_led_toggle(LED4);

        led_spd_t curLedSpd = usr_led_get_spd();
        if (preLedSpd != curLedSpd) {
            DBG_MSG("blink per %d ms...\r\n", (int)curLedSpd);
        }

        util_delay_ms(curLedSpd);
        preLedSpd = curLedSpd;
    }
}
