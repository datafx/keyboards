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

void keyboard_pre_init_kb(void) {
  /* Setting status LEDs pins to output and +5V (off) */
  setPinOutput(F0);
  setPinOutput(F1);
  setPinOutput(F2);
  writePinHigh(F0);
  writePinHigh(F1);
  writePinHigh(F2);
}

void led_set_kb(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_NUM_LOCK)) {
    writePinLow(F0);
  } else {
    writePinHigh(F0);
  }
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    writePinLow(F2);
  } else {
    writePinHigh(F2);
  }
  if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
    writePinLow(F1);
  } else {
    writePinHigh(F1);
  }

  led_set_user(usb_led);
}
