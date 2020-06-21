#include QMK_KEYBOARD_H

enum jj40_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SYMBOLS,
  _FUNC
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  DVORAK,
  FUNC,
  CC_ARRW,
  CC_PRN,
  CC_BRC,
  CC_CBR
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
 * | Shift|   Z  |   X  |   C  |   V  |  B   |   N  |   M  |  ,<  |  .>  |  '"  | /?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt  | Tab  | Func | Lower| SPC  |DVORAK|Raise |  -   | LEFT | DOWN |RIGHT |
 * |      |      |      | Esisu|      |      |      |Kana  |  _   |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,                  KC_E,       KC_R,   KC_T,       KC_Y,                KC_U,          KC_I,    KC_O, TD(TT_PEQL), KC_BSPC,  \
  KC_LCTL, KC_A,    KC_S,                  KC_D,       KC_F,   KC_G,       KC_H,                KC_J,          KC_K,    KC_L,  TD(TT_CLN),  KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,                  KC_C,       KC_V,   KC_B,       KC_N,                KC_M,       KC_COMM,  KC_DOT,  TD(TT_QUO), KC_SLSH,  \
  KC_LGUI, KC_LALT, KC_TAB, LT(_FUNC, KC_LANG2), TT(_LOWER), KC_SPC, TT(_SYMBOLS), LT(_RAISE,KC_LANG1),  TD(TT_LINE), KC_LEFT,     KC_DOWN, KC_RIGHT  \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |  UP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt   |     |      |      |      |      |      |  |   | LEFT | DOWN |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM,   KC_AT,  KC_HASH,      KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
   KC_DEL,   KC_F1,   KC_F2,    KC_F3,       KC_F4,    KC_F5,   KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_ENT, \
  _______,   KC_F7,   KC_F8,    KC_F9,      KC_F10,   KC_F11,  KC_F12, _______, _______, _______,   KC_UP, _______, \
  KC_LGUI, KC_LALT, _______,  _______, TO(_QWERTY),  _______, _______, _______, KC_PIPE, KC_LEFT, KC_DOWN, KC_RIGHT \
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
/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * | Caps |  +   |  -   |  =   |   (  |   )  |      |   7  |   8  |   9  | Bksp | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Lock |  ~   |  _   |      |   [  |   ]  |      |   4  |   5  |   6  |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ins  |  `   |   \  |   |  |   {  |   }  |      |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |_FUNC |_LOWER|      |      |Raise |   0  |      | Home | End  |
 * |      |      |      | Esisu|      |      |      |Kana  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOLS] = LAYOUT_ortho_4x12( \
  KC_CAPS, KC_PLUS, KC_MINS, KC_EQL, KC_LPRN, KC_RPRN, _______, KC_7,  KC_8,    KC_9, KC_BSPC, KC_DEL, \
  KC_LOCK,  KC_TILD, KC_UNDS, _______,KC_LBRC, KC_RBRC, _______, KC_4,  KC_5,    KC_6, _______, _______, \
  KC_INS, KC_GRV, KC_BSLS, KC_PIPE,  KC_LCBR, KC_RCBR, _______, KC_1,  KC_2,    KC_3, KC_DOT, _______, \
  KC_LCTL, KC_LALT, _______, _______, LT(_LOWER, KC_LANG2), KC_SPC, TO(_QWERTY), LT(_RAISE, KC_LANG1), KC_0, _______, KC_HOME,  KC_END \
)

/* Functions
 *  Note: Terminal uses Calculator shortcut, change your OS keyboard shortcut appropriately.
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |       |
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12   |
 * |------+------+------+------+------+-------------+------+------+------+------+------ |
 * |      | RGB  | RGB  | RGB  | RGB  |  BL  |  BL  |  BL  |      |      |      |       |
 * |      | Togl | Hue+ | Sat+ | Brt+ | Togl |Breath| Brt+ |      |      |      |VolUp  |
 * |------+------+------+------+------+------|------+------+------+------+------+------ |
 * |      |      | RGB  | RGB  | RGB  |      |      |  BL  |      |      |      |       |
 * |      | Term | Hue- | Sat- | Brt- |      |      | Brt- |      |      |PrScr |VolDn  |
 * |------+------+------+------+------+------+------+------+------+------+------+------ |
 * |      |      | RGB  |      |      |      |      |      |CC_CBR|CC_BRC|CC_PRN|CC_ARRW|
 * |      |      | Mode |      |      |      |      |      |      |      |      |       |
 * `------------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_ortho_4x12( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_TOGG, BL_BRTG, BL_INC,  _______, _______, _______, KC_VOLU, \
    _______, KC_CALC, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, BL_DEC,  _______, _______, KC_PSCR, KC_VOLD, \
    _______, _______, RGB_MOD, _______, _______, _______, _______, _______, CC_CBR, CC_BRC, CC_PRN, CC_ARRW \
)
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case CC_ARRW:
        SEND_STRING("->");
        return false;
      case CC_PRN:
        SEND_STRING("()"SS_TAP(X_LEFT));
        return false;
      case CC_BRC:
        SEND_STRING("[]"SS_TAP(X_LEFT));
        return false;
      case CC_CBR:
        SEND_STRING("{}"SS_TAP(X_LEFT));
        return false;
    }
  }
  return true;
}