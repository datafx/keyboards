/* Copyright 2021 datafx
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

#include "kf87.h"
#include "quantum.h"
#include <string.h>
#include <stddef.h>

#include "matrix.h"
#include QMK_KEYBOARD_H

led_config_t g_led_config = { {
  // esc         f1   f2   f3   f4   f5   f6   f7   f8    f9    f10   f11   f12   prtscr scrl  brk
  {   0, NO_LED, 1,   2,   3,   4,   5,   6,   7,   8,   9,   10,    11,   12,   13,    14,   15 },
  //tilde 1    2   3    4    5    6    7    8    9    0    -    =    bspc  ins  home  pgup
  {  32,  31, 30,  29,  28,  27,  26,  25,  24,  23,  22,  21,   20,  19,  18,  17,  16 },
  //tab   q    w    e    r    t    y    u    i    o    p    [    ]   bsls  del   end  pgdn
  {  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46,   47,  48,  49 },
  //caps  a    s    d    f    g    h    j    k   l     ;    '  return 
  {  62,  61,  60,  59,  58,  57,  56,  55,  54,  53,  52,  51,  50, NO_LED, NO_LED, NO_LED  },
  //lshift z   x    c    v    b    n    m    ,    .    /          rshift         up  
  {  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  NO_LED, 74,  NO_LED, 75, NO_LED  },
  //ctrl win  alt                    space                           alt  win  mod          ctrl  left down right
  {  86,  85,  84,  NO_LED,  NO_LED,  83,  NO_LED,  NO_LED,  NO_LED,  82,  81,  80,  NO_LED, 79,   78,  77,  76 }


}, {
    //   esc           F1           F2           F3            F4            F5             F6             F7               F8            F9            F10          F11           F12        prtscr      scrlck         pause
    {   0,   0 }, {  25,   0 }, {  40,   0 }, {  55,   0 }, {  82,   0 }, {  108,   0 }, {  120,   0 }, {  130,   0 }, { 148,   0 }, { 172,   0 }, { 187,   0 }, { 190,   0 }, { 195,   0 }, { 206,   0 }, { 215,  0}, { 224,   0 },
    // pgup          home          ins        backspace        =            -             0              9             8             7            6               5              4             3             2            1         tilde
    { 224,  12 }, {215,  12}, { 206,  12 }, { 202,  12}, { 187,  12 }, { 172,  12 }, { 157,  12 }, { 142,  12 }, { 127,  12 }, { 112,  12 }, {  97,  12 }, {  82,  12 }, {  67,  12 }, {  52,  12 }, {  37,  12 }, {  22,  12}, {   0,  12 },
    //   tab           q             w             e             r            t             y             u              i             o             p              [             ]         backslash      del          end         pgdn
    {   0,  24 }, {  22,  24}, {  37,  24 }, {  52,  24 }, {  67,  24 }, {  82,  24 }, {  97,  24 }, { 112,  24 }, { 127,  24 }, { 142,  24 }, { 157,  24 }, { 172,  24 }, { 187,  24 }, { 202,  24}, { 206,  24 }, {215,  24}, { 224,  24 },
    // return         '              ;             l              k             j             h             g              f            d            s               a        capslock
    { 198,  36 }, { 180,  36 }, { 176,  36 }, { 161,  36 }, { 146,  36 }, { 131,  36 }, { 105,  36 }, { 101,  36 }, {  86,  36 }, {  71,  36 }, {  56,  36 }, {  41,  36 }, {  0,  36 },
    // lshift          z             x            c              v            b            n              m              comma       period       question       rshift         up
    {  0,  48 }, {  30,  48 }, {  45,  48 }, {  60,  48 }, {  75,  48 }, {  90,  48 }, { 105,  48 }, { 120,  48 }, { 135,  48 }, { 150,  48 }, { 165,  48 }, { 198,  48 }, { 215,  48},
    // right         down         left            rctl         mod           rwin          ralt          space         lalt           lwin         lctl
    { 224,  63 }, { 215,  63 }, { 206,  63 }, { 180,  63 }, { 168,  63}, { 153,  63 }, { 135,  63 }, { 101,  63 }, {  33,  63 }, {  22,  63 }, {  0,  63 }
}, {
    // Top Row
    1, 4, 4, 4, 4, 1, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 
    // 2nd Row
    1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
    // 3rd Row
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 
    // 4th Row
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 
    // 5th Row
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    // Bottom Row2
    1, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1

} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
