/* Copyright 2020 Obosob <obosob@riseup.net>
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
//gojishiba 2022-04-14
#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_SCLN RGUI_T(KC_SCLN)
#define HM_L LALT_T(KC_L)
#define HM_K RCTL_T(KC_K)
#define HM_J RSFT_T(KC_J)

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      
[_QWERTY] =  LAYOUT_split_3x5_2(
KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
HM_A,    HM_S,    HM_D,    HM_F,    KC_G,        KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,
KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                           LOWER,   KC_SPC,     KC_BSPC,  RAISE
),


[_LOWER] = LAYOUT_split_3x5_2(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,     KC_PPLS, KC_P7,   KC_P8,   KC_P9,  KC_PAST, 
KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,     KC_PMNS, KC_P4,   KC_P5,   KC_P6,  KC_P0, 
KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,     KC_PDOT, KC_P1,   KC_P2,   KC_P3,  KC_PSLS, 
                           _______, KC_PENT,     KC_DEL, _______
),


[_RAISE] = LAYOUT_split_3x5_2(
KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_PGUP, XXXXXXX, KC_HOME,  KC_PSCR, 
KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,     XXXXXXX, KC_PGDN, KC_UP,   KC_END, KC_INS, 
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, 
                           _______, _______,      KC_DEL, _______
),


[_ADJUST] = LAYOUT_split_3x5_2(
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
_______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, 
                           _______, _______,     _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

