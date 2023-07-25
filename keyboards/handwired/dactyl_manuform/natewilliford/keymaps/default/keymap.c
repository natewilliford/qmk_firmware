 /*
 * Copyright 2022 Kevin Gee <info@controller.works>
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

enum layer_number {
  _QWERTY = 0,
  _COLMAK,
  _COLMAK_GAMING,
  _COLMAK_MAC,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  WORD_BACK = SAFE_RANGE,
  WORD_FOR,
  MLT_LN_DN,
  MLT_LN_UP,
  // I handle these custom because the "KC_" versions use keycodes not what you'd think.
  CUT,
  COPY,
  PASTE,
  FIND,
  UNDO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
    KC_CAPS,  KC_1,   KC_2,    KC_3,    KC_4,       KC_5,           KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,    KC_DEL,
    KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,       KC_G,           KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_PGUP, KC_PGDN, MO(_LOWER), KC_SPC,         KC_BSPC, MO(_RAISE), KC_HOME, KC_END,
                      KC_LCTL, KC_LGUI, KC_LALT,    KC_LSFT,        KC_RALT,  KC_ENT, KC_LGUI, KC_RSFT
  ),

  [_COLMAK] = LAYOUT_split_3x6_3(
    KC_CAPS, KC_1, KC_2,         KC_3,         KC_4,         KC_5,           KC_6,    KC_7,        KC_8,        KC_9,         KC_0,    KC_GRV,
    KC_TAB,  KC_Q, KC_W,         KC_F,         KC_P,         KC_B,           KC_J,    KC_L,        KC_U,        KC_Y,         KC_SCLN, KC_DEL,
    KC_ESC,  KC_A, LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_G,           KC_M,    LCTL_T(KC_N), LSFT_T(KC_E),LALT_T(KC_I), KC_O,    KC_QUOT,
    KC_LSFT, KC_Z, KC_X,         KC_C,         KC_D,         KC_V,           KC_K,    KC_H,        KC_COMM,     KC_DOT,      KC_SLSH, KC_RSFT,
                   _______,      _______,      _______,      _______,        _______, _______, _______, _______,
                   _______,      _______,      _______,      _______,        _______, _______, _______, _______
  ),

  // Disables the home row mods so I can hold down keys for gaming.
  [_COLMAK_GAMING] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, KC_R,    KC_S,    KC_T,    _______,        _______, KC_N,    KC_E,    KC_I,    _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______
  ),

  // Swaps CTRL and Super (GUI) for Mac. There is also affects some logic in process_record_user, e.g. using alt for jumping words.
  [_COLMAK_MAC] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,LGUI_T(KC_T),_______,     _______,LGUI_T(KC_N),_______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______,
                      _______, _______, _______, _______,        _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______,_______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    _______, UNDO,    CUT,     COPY,    PASTE,   FIND,           XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                      _______, _______, _______, _______,        _______,  _______, _______, _______,
                      _______, _______, _______, _______,        _______,  _______, _______, _______
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_HOME,MLT_LN_UP,MLT_LN_DN, KC_END,_______,        WORD_BACK, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, WORD_FOR,
    _______, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY, _______,        KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                      _______, _______, _______, _______,        _______,  _______, _______, _______,
                      _______, _______, _______, _______,        _______,  _______, _______, _______
  ),
    
  [_ADJUST] = LAYOUT_split_3x6_3(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,TO(_QWERTY), TO(_COLMAK), XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,TG(_COLMAK_GAMING),TG(_COLMAK_MAC), XXXXXXX,XXXXXXX, XXXXXXX,
                      _______, _______, _______, _______,        _______,  _______, _______, _______,
                      _______, _______, _______, _______,        _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void modded_tap_code(uint16_t code, int mod) {
  register_code(mod);
  tap_code(code);
  unregister_code(mod);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    const int jump_lines = 5;
    int word_mod = KC_LCTL;
    int copy_pasta_mod = KC_LCTL;
    if(IS_LAYER_ON(_COLMAK_MAC)) {
        word_mod = KC_LALT;
        copy_pasta_mod = KC_LGUI;
    }

    switch (keycode) {
    case WORD_BACK:
      modded_tap_code(KC_LEFT, word_mod);
      break;
    case WORD_FOR:
      modded_tap_code(KC_RIGHT, word_mod);
      break;
    case UNDO:
      modded_tap_code(KC_Z, copy_pasta_mod);
      break;
    case CUT:
      modded_tap_code(KC_X, copy_pasta_mod);
      break;
    case COPY:
      modded_tap_code(KC_C, copy_pasta_mod);
      break;
    case PASTE:
      modded_tap_code(KC_V, copy_pasta_mod);
      break;
    case FIND:
      modded_tap_code(KC_F, copy_pasta_mod);
      break;
    case MLT_LN_UP:
      for(int i = 0; i < jump_lines; i++) {
        tap_code(KC_UP);
      }
      break;
    case MLT_LN_DN:
      for(int i = 0; i < jump_lines; i++) {
        tap_code(KC_DOWN);
      }
      break;
    default:
      break;
    }
    // set_timelog();
  }
  return true;
}