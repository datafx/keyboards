/* Copyright 2021 digitalfx 
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

#include "selectriq.h"
void matrix_init_kb(void) {
    setPinOutput(D4); //capslock pin used for ding
    setPinOutput(B5); //backlight pin use for click
    matrix_init_user();
}

static uint16_t key_timer;

bool click_enabled = true;  //click enable
bool ding_enabled = true;  //ding enabled

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   
  switch (keycode) {
    case BL_TOGG:
      if (record->event.pressed) { 
        click_enabled = !click_enabled; //if BL_TOGG key pressed, turn off the click solenoid
        ding_enabled = !ding_enabled; //if BL_Togg key pressed, turn off the ding solenoid
      }
      return false;  
    case KC_ENTER:
      if (ding_enabled && record->event.pressed) {  //if enter key pressed,
        writePinHigh(D4);                          //activate ding solenoid
        key_timer = timer_read();
      }
      return true;
    default:
      if (click_enabled && record->event.pressed) {  //if any key pressed,
        writePinHigh(B5);                          //activate click solenoid
        key_timer = timer_read();
      }
      return true;
            
    }
}
 
void matrix_scan_user(void) {
    if (timer_elapsed(key_timer) > 15) {//15 delay for solenoid, stay around 10-30.
        writePinLow(B5);                            
        writePinLow(D4);
    }
}

