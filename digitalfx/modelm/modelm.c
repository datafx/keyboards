/* Copyright 2019 iw0rm3r
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "modelm.h"

led_config_t g_led_config = { {
  // Num Caps Scroll
    {   0,  1,   2  }
}, {
    { 206,   0 }, { 215,  0}, { 224,   0 }
}, {
     1,1,1
} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

void rgb_matrix_indicators_user(void) {
    led_t host_leds = host_keyboard_led_state();
    if (host_leds.caps_lock) {
        rgb_matrix_set_color(1, 0x20, 0x00, 0x00);
    } else {
//        rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
    }
    if (host_leds.num_lock) {
        rgb_matrix_set_color(0, 0x20, 0x00, 0x00);
    } else {
//        rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
    }
    if (host_leds.scroll_lock) {
        rgb_matrix_set_color(2, 0x20, 0x00, 0x00);
    } else {
//        rgb_matrix_set_color(2, 0x00, 0x00, 0x00);
    }
}