// qmk compile
// OR
// qmk compile -kb lily58/rev1 -km natewilliford

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _COLMAK,
  _COLMAK_MAC,
  _NUMPAD,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  WORD_BACK = SAFE_RANGE,
  WORD_FOR,
  MLT_LN_DN,
  MLT_LN_UP,
  CUT,
  COPY,
  PASTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | CAPS |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |KC_DEL|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|TG CMAK|    |Mut/Vol|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtl | LAlt |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT(
  KC_CAPS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,  KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,  KC_P,    KC_DEL,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,TG(_COLMAK),KC_MUTE, KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                        KC_LCTRL, KC_LALT, MO(_LOWER), MEH_T(KC_SPC), HYPR_T(KC_BSPC), MO(_RAISE), KC_ENT, KC_RGUI
),

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | CAPS |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |KC_DEL|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------| MPLY  |    | MUTE  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtl | LAlt |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_COLMAK] = LAYOUT(
  _______, KC_1, KC_2,       KC_3,        KC_4,         KC_5,                   KC_6, KC_7,        KC_8,        KC_9,         KC_0,    _______,
  _______, KC_Q, KC_W,       KC_F,        KC_P,         KC_B,                   KC_J, KC_L,        KC_U,        KC_Y,         KC_SCLN, _______,
  _______, KC_A,LALT_T(KC_R),LSFT_T(KC_S),LCTL_T(KC_T), KC_G,                   KC_M, LCTL_T(KC_N),LSFT_T(KC_E),LALT_T(KC_I), KC_O,    _______,
  _______, KC_Z, KC_X,       KC_C,        KC_D,         KC_V, _______, _______, KC_K, KC_H,        _______,     _______,      _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
),

[_COLMAK_MAC] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,LGUI_T(KC_T),_______,                _______,LGUI_T(KC_N),_______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             KC_LGUI, _______, _______, _______, _______, _______, _______, KC_LCTRL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Undo | Cut  | Copy |Paste | Find |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCtl | LAlt |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, KC_UNDO, CUT,     COPY,    PASTE,   KC_FIND, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Home |Mlt Up|Mlt Dn|  End |      |-------.    ,-------|Ctrl->| Left | Down |  Up  |Right |Ctrl<-|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      | Mute | Vol+ | Vol- |Ply/Ps|      |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_HOME,MLT_LN_UP,MLT_LN_DN, KC_END,_______,                   WORD_BACK, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, WORD_FOR,
  _______, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY, _______, _______, _______, KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |QWERTY| Mac  |NUMPAD|MOUSE |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,DF(_QWERTY),TG(_COLMAK_MAC),TG(_NUMPAD),TG(_MOUSE), XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |  /   |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  *   |  4   |  5   |  6   |  +   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|      |  1   |  2   |  3   |  =   |      |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  0   |  0   |  .   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \BackSP\  |RAISE |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMPAD] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     KC_PSLS, KC_P7, KC_P8, KC_P9,    KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______,                     KC_PAST, KC_P4, KC_P5, KC_P6,    KC_PLUS, _______,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                     _______, KC_P1, KC_P2, KC_P3,    KC_PEQL,  _______,
  _______, _______, _______, _______, _______, _______,  KC_LPRN, KC_RPRN,  KC_PLUS, KC_P0, KC_0, KC_PDOT, _______, _______,
                             _______, _______, _______,  _______, _______, _______,   _______, _______
),

/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |scrlup|scrldn|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left |  up  | down |right |      |-------.    ,-------|      |l clik|r clik|      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | Back | Fwrd |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |TO(0) | /Space  /       \BackSP\  |TO(0) |Enter | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, KC_WH_U, KC_WH_D, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,                     _______, KC_BTN1, KC_BTN2, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, KC_WBAK, KC_WFWD, _______, _______, _______,
                             _______, _______, _______,  _______, _______, _______,   _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

void modded_tap_code(uint16_t code, int mod) {
  register_code(mod);
  tap_code(code);
  unregister_code(mod);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    int jump_lines = 5;
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    int word_mod = KC_LCTRL;
    int copy_pasta_mod = KC_LCTRL;
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
    case CUT:
      modded_tap_code(KC_X, copy_pasta_mod);
      break;
    case COPY:
      modded_tap_code(KC_C, copy_pasta_mod);
      break;
    case PASTE:
      modded_tap_code(KC_V, copy_pasta_mod);
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

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (get_highest_layer(layer_state|default_layer_state) == _LOWER) {
    int jump_lines = 5;
    if (clockwise) {
      for(int i = 0; i < jump_lines; i++) {
        tap_code(KC_UP);
      }
    } else {
      for(int i = 0; i < jump_lines; i++) {
        tap_code(KC_DOWN);
      }
    }
  } else {
    if (clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }
  }
  return false;
}
