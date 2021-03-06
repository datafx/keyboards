/* Copyright 2021 Kyle McCreery 
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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <print.h>

// Tap Dance declarations
enum {
    TD_TAB_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Tab, twice for Esc
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
                                                                                                                  KC_MUTE,
        TD(TD_TAB_ESC),   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        MO(3),            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT, KC_SLSH, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,          MO(1),   MO(2),            KC_SPC,           KC_RALT, KC_RGUI,          KC_RCTL ),

  [1] = LAYOUT_all(
                                                                                                                  KC_TRNS,
        KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_GRV,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_SCLN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_SLSH,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [2] = LAYOUT_all(
                                                                                                                  AG_TOGG,
        KC_GRV,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_CAPS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS ),

  [3] = LAYOUT_all(
                                                                                                                  RESET,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP,           KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,          KC_END,  KC_PGDN,           KC_TRNS )
};

#ifdef ENCODER_ENABLE       // Encoder Functionality. Does not work with VIAL encoder enabled.
    uint8_t selected_layer = 0;
    void encoder_update_user(uint8_t index, bool clockwise) {
        switch (index) {
            case 0:         // The only encoder
                if ( clockwise ) {
                    switch (get_highest_layer(layer_state)) {
                        case 0:
                           tap_code(KC_VOLU);
                           break;
                        case 1:
                            tap_code(KC_BRIU); 
                            break;
                        case 2:
                            register_code16(S(G(KC_Z)));
                            clear_keyboard();
                            break;
                        }
                } 
                else if ( !clockwise ) {
                    switch (get_highest_layer(layer_state)) {
                        case 0:
                            tap_code(KC_VOLD);
                            break;
                        case 1:
                            tap_code(KC_BRID); 
                            break;
                        case 2:
                            register_code16(G(KC_Z));
                            clear_keyboard();
                            break;
                        }
                }
        }
    }

#endif

#ifdef OLED_DRIVER_ENABLE   // OLED Functionality
    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_180;       // flips the display 180 degrees if offhand
    }
    bool clear_screen = false;          // used to manage singular screen clears to prevent display glitch
    static void render_screen(void) {     // Render screen
        oled_set_cursor(0,0);
        oled_write_P(PSTR("Mercutio Status"), false);
    }
    void oled_task_user(void) {
        render_screen();
        // Display highest layer on OLED as active layer
        oled_set_cursor(0,3);
            oled_write_P(PSTR("Layer "), false);
            switch (get_highest_layer(layer_state)) {
                case 0:
                    oled_write_P(PSTR("0"), false);
                    break;
                case 1:
                    oled_write_P(PSTR("1"), false);
                    break;
                case 2:
                    oled_write_P(PSTR("2"), false);
                    break;
                case 3:
                    oled_write_P(PSTR("3"), false);
                    break;
                default:
                    oled_write_P(PSTR("?"), false);    // Should never display, here as a catchall                
        }
        // Display mode on OLED based on magic MAGIC_TOGGLE_ALT_GUI for MAC
        oled_set_cursor(0,1);
            if (keymap_config.swap_ralt_rgui) {
                oled_write_P(PSTR("MAC Mode"), false);
            } else {
                oled_write_P(PSTR("PC Mode "), false);
            }
        // Dispplay caps/num/scroll lock on OLED
        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(16,3);
        oled_write_P(led_state.scroll_lock ? PSTR("SCLK") : PSTR("    "), false);
        oled_set_cursor(16,2);
        oled_write_P(led_state.num_lock ? PSTR("NLCK ") : PSTR("    "), false);
        oled_set_cursor(16,1);
        oled_write_P(led_state.caps_lock ? PSTR("CAPS ") : PSTR("    "), false);
        // Display WPM counter on OLED
        int current_wpm = 0;
        char wpm_str[8];
        current_wpm = get_current_wpm();
        oled_set_cursor(0,2);
        sprintf(wpm_str, "%03d", current_wpm);
        oled_write(wpm_str, false);
        oled_set_cursor(3,2);
        oled_write(" WPM", false);
    }
#endif