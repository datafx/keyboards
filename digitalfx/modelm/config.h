/*
Copyright 2019 iw0rm3r

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4658 // FX for digitalfx
#define PRODUCT_ID      0x4D4D // MM for Model M
#define DEVICE_VER      0x0001
#define MANUFACTURER    digitalfx
#define PRODUCT         IBM Model M TERMINAL

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 16

#define AUDIO_PIN B7
#define AUDIO_CLICKY

#define RGB_DI_PIN D0
#define DRIVER_LED_TOTAL 3
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100 // limits maximum brightness of LEDs to 100 out of 255.
#define RGBLIGHT_LIMIT_VAL 200 // limits maximum brightness of LEDs to 100 out of 255.
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { E7, B0, B1, B2, B3, B4, B5, B6 }
#define MATRIX_COL_PINS { C7, C6, C5, C4, C3, C2, C1, C0, E1, E0, D7, D6, D5, D4, D3, D2 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed (5 is default) */
#define DEBOUNCE 5

/* The Model M has no diodes */
#define MATRIX_HAS_GHOST

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
