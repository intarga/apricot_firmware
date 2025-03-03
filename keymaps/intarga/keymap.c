/* Copyright 2022 LAZYDESIGNERS
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

enum layers{
  BASE,
  FACTORIO,
  SYM,
  NUM,
  META
};

enum keycodes {
  NORMAL = SAFE_RANGE,
  FACTORI
};
// Norwegian letters
#define NO_AE LALT(KC_QUOT)
#define NO_AA LALT(KC_A)
#define NO_OE LALT(KC_O)

// App switch shortcut
#define SWITCH LALT(KC_TAB)

// Ctrl U and D
#define CTRL_U LCTL(KC_U)
#define CTRL_D LCTL(KC_D)

// How long (in milliseconds) to wait between animation steps for each of the "Snake" animations
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {250, 200, 150};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, _______, KC_DOT,
         KC_LGUI, _______, KC_LSFT,   KC_SPC,   MO(SYM),   MO(NUM), _______, KC_LCTL
  ),

  [FACTORIO] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_0,    KC_1,    KC_2,    KC_3,    KC_T,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_4,    KC_5,    KC_6,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_7,    KC_8,    _______, KC_9,
         KC_LCTL, _______, KC_LALT,   KC_SPC,   MO(SYM),   MO(NUM), _______, KC_LGUI
  ),

  [SYM] = LAYOUT(
    _______, _______, KC_SCLN, KC_GRV,  NO_AA,   _______, CTRL_D,  CTRL_U,  _______, KC_TAB,
    KC_DEL,  KC_ESC,  KC_TAB,  KC_ENT,  NO_OE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
    _______, _______, KC_BSLS, KC_TILD, NO_AE,   SWITCH,  KC_PGDN, KC_PGUP, _______, KC_SLSH,
         _______, _______, _______,   KC_BSPC,   _______,   _______, _______, _______
  ),

  [NUM] = LAYOUT(
    KC_MUTE, KC_VOLD, KC_VOLU, KC_LBRC, KC_RBRC, KC_0,    KC_1,    KC_2,    KC_3,    KC_TAB,
    _______, KC_BRID, KC_BRIU, KC_LPRN, KC_RPRN, KC_MINS, KC_4,    KC_5,    KC_6,    KC_BSPC,
    KC_MRWD, KC_MPLY, KC_MFFD, KC_LCBR, KC_RCBR, KC_EQL,  KC_7,    KC_8,    _______, KC_9,
         _______, _______, _______,   _______,   _______,   _______, _______, KC_ENT
  ),

  [META] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, UG_NEXT, UG_TOGG, NORMAL,  QK_BOOT,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, _______, _______, _______, FACTORI,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, EE_CLR,  _______,
         _______, _______, _______,   _______,   _______,   _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, SYM, NUM, META);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NORMAL:
      if (record->event.pressed) {
        set_single_persistent_default_layer(BASE);
      }
      return false;
      break;
    case FACTORI:
      if (record->event.pressed) {
        set_single_persistent_default_layer(FACTORIO);
      }
      return false;
      break;
  }
  return true;
}
