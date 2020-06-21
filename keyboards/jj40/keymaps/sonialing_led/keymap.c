#include QMK_KEYBOARD_H

enum jj40_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _DVORAK,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    DVORAK,
};

enum {
    TT_LINE,
    TT_QUO,
    TT_CLN,
    TT_PEQL,
};
// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TT_LINE] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),
    [TT_QUO]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TT_CLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
    [TT_PEQL] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_EQL),
    // [TT_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_LBRC),
    // [TT_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RCBR, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |  P=  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |  B   |   N  |   M  |  ,<  |  .>  |  UP  | /?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt  | Tab  | Func | Lower| SPC  |DVORAK|Raise |  -   | LEFT | DOWN |RIGHT |
 * |      |      |      | Esisu|      |      |      |Kana  |  _   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,                  KC_E,       KC_R,   KC_T,       KC_Y,                KC_U,          KC_I,    KC_O, TD(TT_PEQL), KC_BSPC,  \
  KC_LCTL, KC_A,    KC_S,                  KC_D,       KC_F,   KC_G,       KC_H,                KC_J,          KC_K,    KC_L,  TD(TT_CLN),  KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,                  KC_C,       KC_V,   KC_B,       KC_N,                KC_M,       KC_COMM,  KC_DOT,       KC_UP, KC_SLSH,  \
  KC_LGUI, KC_LALT, KC_TAB, KC_LANG2, LOWER, KC_SPC, DVORAK, RAISE,  TD(TT_LINE), KC_LEFT,     KC_DOWN, KC_RIGHT  \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |  UP  | '"   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt   |     |      |      |      |      |      |  |   | LEFT | DOWN |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM,   KC_AT,  KC_HASH,      KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
   KC_DEL,   KC_F1,   KC_F2,    KC_F3,       KC_F4,    KC_F5,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_ENT, \
  _______,   KC_F7,   KC_F8,    KC_F9,      KC_F10,   KC_F11,  KC_F12, _______, _______, _______,   KC_UP, TD(TT_QUO), \
  KC_LGUI, KC_LALT, _______,  _______, QWERTY,  _______, _______, _______, KC_PIPE, KC_LEFT, KC_DOWN, KC_RIGHT \
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | ESC  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,     KC_9,    KC_0, KC_BSPC, \
   KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC,  KC_ENT, \
   KC_ESC,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______,  _______, _______, KC_BSLS, \
  KC_LGUI, _______, _______, _______, _______, _______, _______,  _______, KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY \
),
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |  S   |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Sft  |  ;   |   Q  |   J  |   K  |  X   |   B  |   M  |   W  |   V  |  Z   | /?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt  |      | _FUNC|_LOWER| SPC  |Qwerty|Raise |  ←   |  ↓  |   ↑　  |　→   |
 * |      |      |      | Esisu|      |      |      |Kana  |      |     |        |     |
 * `-----------------------------------------------------------------------------------'
*/
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,                KC_P,   KC_Y,         KC_F,                 KC_G,   KC_C,     KC_R,  KC_L,  KC_BSPC, \
  KC_ESC,    KC_A,     KC_O,   KC_E,                KC_U,   KC_I,         KC_D,                 KC_H,   KC_T,     KC_N,  KC_S,   KC_ENT, \
  KC_LSFT, KC_SCLN,    KC_Q,   KC_J,                KC_K,   KC_X,         KC_B,                 KC_M,   KC_W,     KC_V,  KC_Z,  KC_SLSH, \
  KC_LGUI, KC_LALT, _______, _______, LT(_LOWER, KC_LANG2), KC_SPC, TO(_QWERTY), LT(_RAISE, KC_LANG1), KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT \
),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    break;
  case LOWER:
    if (record->event.pressed) {
      rgblight_enable();
      rgblight_setrgb(120, 155, 15);
      layer_on(_LOWER);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
      rgblight_enable();
      rgblight_setrgb(74, 74, 186);
      layer_on(_RAISE);
    }
    return false;
    break;
  }
  return true;
}