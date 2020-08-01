#include QMK_KEYBOARD_H

enum jj40_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _WINMAP,
  _WINSYM,
  _ADJUST,
  _CALC
};

enum custom_keycodes { QWERTY = SAFE_RANGE, WINMAP, WINSYM, CALC };

#define QWERTY  MO(_QWERTY)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  MO(_ADJUST)
#define WINMAP  MO(_WINMAP)
#define WINSYM  MO(_WINSYM)
#define CALC    MO(_CALC)
#define JP_GRV  S(KC_LBRC)
#define JP_PERC S(KC_5) // %
#define JP_ASTR S(KC_QUOT) // *
#define JP_UNDS S(KC_RO) // _
#define JP_PIPE S(KC_JYEN)  // |
#define JP_DQUO S(KC_2)    // "
#define JP_QUOT S(KC_7)    // '

enum {
  TT_LINE,
  TT_JLINE,
  TT_QUO,
  TT_CLN,
  TT_JCLN,
  TD_EMAIL,
  TD_IME,
};

/* tap dance time */
void tdemail(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    SEND_STRING("liang.yunghsin@zuuonline.com");
  } else {
    SEND_STRING("bingo605@gmail.com");
  }
  reset_tap_dance (state);
}
void tdime(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    tap_code(KC_LANG1);
  } else {
    tap_code(KC_LANG2);
  }
  reset_tap_dance (state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TT_JLINE] = ACTION_TAP_DANCE_DOUBLE(JP_UNDS, KC_MINS),
  [TT_LINE]  = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),
  [TT_QUO]   = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
  [TT_CLN]   = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
  [TT_JCLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TD_EMAIL] = ACTION_TAP_DANCE_FN(tdemail),
  [TD_IME]   = ACTION_TAP_DANCE_FN(tdime),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |  P   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  UP  | /?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt  | Tab  | Esisu| Lower| SPC  | SPC  |Raise |  -_  | LEFT | DOWN |RIGHT |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,    KC_Q,    KC_W,                   KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,         KC_I,    KC_O,      KC_P, KC_BSPC,  \
  KC_LCTL,   KC_A,    KC_S,                   KC_D,  KC_F,   KC_G,   KC_H,  KC_J,         KC_K,    KC_L, TD(TT_CLN), KC_ENT,  \
  KC_LSFT,   KC_Z,    KC_X,                   KC_C,  KC_V,   KC_B,   KC_N,  KC_M,      KC_COMM,  KC_DOT,      KC_UP, KC_SLSH,  \
  KC_LGUI, KC_LALT, KC_TAB, TD(TD_IME), LOWER, KC_SPC, KC_SPC, RAISE,  TD(TT_LINE), KC_LEFT,    KC_DOWN, KC_RIGHT  \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  +   |   =  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  |   |   '  |  "   |  "'  | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt   | ESC |email |      |      |      |      |  _   | LEFT | RIGHT| PgDn |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM,   KC_AT,  KC_HASH,  KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,   KC_RPRN,  KC_BSPC, \
  KC_LCTL,   KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,   KC_F6,  KC_PLUS, KC_EQL, KC_LCBR,   KC_RCBR,  KC_ENT, \
  KC_LSFT,   KC_F7,   KC_F8,    KC_F9,  KC_F10,   KC_F11,  KC_F12, KC_PIPE, KC_QUOT, KC_DQUO, TD(TT_QUO), KC_PGUP, \
  KC_LGUI, KC_LALT,  KC_ESC,  TD(TD_EMAIL), _______,  _______, _______, _______, KC_UNDS, KC_LEFT,   KC_RIGHT, KC_PGDN \
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   '  |  "   |  :   |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | CTRL |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,     KC_9,    KC_0, KC_BSPC, \
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC,  KC_ENT, \
  KC_LSFT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_UNDS, KC_QUOT,  KC_DQUO, KC_COLON, KC_BSLS, \
  KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, _______,KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
/* WIN10
 * ,------------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E   |   R  |   T  |   Y  |   U  |   I  |   O  |  P   | Bksp |
 * |------+------+------+-------+------+-------------+------+------+------+------+------|
 * | WIN  |   A  |   S  |   D   |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |Enter |
 * |------+------+------+-------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C   |   V  |  B   |   N  |   M  |  ,<  |  .>  |  UP  | /?   |
 * |------+------+------+-------+------+------+------+------+------+------+------+------|
 * | CTRL | Opt  | Tab  |WINSYM |LOWER | SPC  | SPC  |RAISE | ZKHK | LEFT | DOWN |RIGHT |
 * `------------------------------------------------------------------------------------'
 */
[_WINMAP] = LAYOUT_ortho_4x12( \
  KC_ESC,     KC_Q,   KC_W,   KC_E,  KC_R,   KC_T,     KC_Y,   KC_U,    KC_I,    KC_O,        KC_P, KC_BSPC,  \
  KC_LGUI,    KC_A,   KC_S,   KC_D,  KC_F,   KC_G,     KC_H,   KC_J,    KC_K,    KC_L, TD(TT_JCLN),  KC_ENT,  \
  KC_LSFT,    KC_Z,   KC_X,   KC_C,  KC_V,   KC_B,     KC_N,   KC_M, KC_COMM,  KC_DOT,       KC_UP, KC_SLSH,  \
  KC_LCTL, KC_LALT, KC_TAB, WINSYM, LOWER, KC_SPC,   KC_SPC,  RAISE, KC_ZKHK, KC_LEFT,     KC_DOWN, KC_RIGHT  \
),
/* WINJP_SYM
 * ,-------------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |    #  |   $  |   %  |   ^  |   &   |   *  |   (  |   )  | Bksp |
 * |------+------+------+-------+------+-------------+-------+------+------+------+------|
 * |   `  |  A   | LEFT | RIGHT | PgUp | PgDn |  -   |   =   |   +  |   {  |   }  |Enter |
 * |------+------+------+-------+------+------|------+-------+------+------+------+------|
 * | Shift|  Z   |  X   |   C   |  V   |  |   |   [  |   ]   |   '  |   "  |  UP  |  \   |
 * |------+------+------+-------+------+------+------+-------+------+------+------+------|
 * | CTRL | Opt  | Tab  |  WIN  |LOWER | SPC  | SPC  | Raise |  _-  | LEFT | DOWN |RIGHT |
 * `-------------------------------------------------------------------------------------'
 */
[_WINSYM] = LAYOUT_ortho_4x12( \
  KC_PLUS, KC_EXLM, KC_LBRC,  KC_HASH,  KC_DLR,  JP_PERC,    KC_EQL, KC_CIRC,      JP_ASTR, KC_RPRN, KC_LPRN, KC_BSPC, \
  KC_LCBR, _______, KC_LEFT, KC_RIGHT, KC_PGUP,  KC_PGDN,   KC_MINS, KC_UNDS,     KC_COLON, KC_RCBR, KC_PIPE,  KC_ENT,  \
  KC_LSFT, _______, _______,  _______, JP_PIPE,  KC_JYEN,   KC_RBRC, KC_NUHS,      JP_QUOT, JP_DQUO, _______,   KC_RO, \
  KC_LCTL, KC_LALT,  KC_TAB,  KC_LGUI,   LOWER,   KC_SPC,    KC_SPC,   RAISE, TD(TT_JLINE), _______, _______, _______  \
),

/* CALC
 * ,-----------------------------------------.--------------,----------------------------.
 * |  Esc |      | DOWN |   UP |      |      |      |QWERTY |   7  |   8  |   9  |  Bksp |
 * |------+------+------+------+------+------|------+-------|------+------+------|-------|
 * |      |      | LEFT | RIGHT| PgDn | PgUp |      |   /   |   4  |   5  |   6  |   -   |
 * |------+------+------+------+------+------|------+-------|------+------+------+-------+
 * |      |      |      |      |      |      |      |   =   |   1  |   2  |   3  |   +   |
 * |------+------+------+------+------+------|------+-------|-------------+------|-------|
 * |      |      |      |      |Lower |      |      | Raise |   0  |   *  |   .  | Enter |
 * `-----------------------------------------'--------------`----------------------------'
 */
[_CALC] = LAYOUT_ortho_4x12( \
  _______, _______, KC_DOWN,    KC_UP, _______, _______, _______, QWERTY, KC_P7,    KC_P8,   KC_P9,   KC_BSPC, \
  _______, _______, KC_LEFT, KC_RIGHT, KC_PGDN, KC_PGUP, _______, KC_SLSH, KC_P4,    KC_P5,   KC_P6,   KC_PMNS,  \
  _______, _______, _______,  _______, _______, _______, _______, KC_EQL,  KC_P1,    KC_P2,   KC_P3,   KC_PPLS, \
  _______, _______, _______,  _______, _______, _______, _______, _______, KC_P0,   KC_ASTR, KC_PDOT, KC_PENT \
),

/* ADJUST
 * ,------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |Qwerty|  F9  | F10  | F11  | F12   |
 * |------+------+------+------+------+-------------+------+------+------+------+------ |
 * |      | RGB  | RGB  | RGB  | RGB  |  BL  |  BL  |  BL  |Rnbow |Swirl | Xmas |       |
 * |      | Togl | Hue+ | Sat+ | Brt+ | Togl |Breath| Brt+ |      |      |      |       |
 * |------+------+------+------+------+------|------+------+------+------+------+------ |
 * |      |      | RGB  | RGB  | RGB  |      |      |  BL  |      |      |      |       |
 * |      | CALC | Hue- | Sat- | Brt- |WINSYM|WINMAP| Brt- |      |      |PrScr |       |
 * |------+------+------+------+------+------+------+------+------+------+------+------ |
 * |      |      | RGB  |      |      |      |      |      |      |      |      |       |
 * |      |      | Mode |      |      |      |      |      |      |      |      |       |
 * `------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   QWERTY,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
    _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_TOGG,    BL_BRTG, BL_INC,  RGB_M_R, RGB_M_SW,RGB_M_X, _______, \
    _______,    CALC, RGB_HUD, RGB_SAD, RGB_VAD,  WINSYM,    WINMAP, BL_DEC,  _______, _______, KC_PSCR, _______, \
    _______, _______, RGB_MOD, _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
)
};

void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
    set_single_persistent_default_layer(_QWERTY);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      rgblight_disable();
      if (is_backlight_enabled()) {
        breathing_disable();
      }
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return true;
    case WINMAP:
      rgblight_enable();
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_setrgb_at(RGB_AZURE, 0);
      rgblight_setrgb_at(RGB_AZURE, 1);
      rgblight_setrgb_at(RGB_AZURE, 2);
      rgblight_setrgb_at(RGB_AZURE, 3);
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINMAP);
      }
      return true;
    case WINSYM:
      rgblight_enable();
      rgblight_setrgb(120, 155, 15);
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINSYM);
      }
      return true;
    case CALC:
      rgblight_enable();
      rgblight_setrgb(15, 120, 155);
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CALC);
      }
      return true;
    default:
      return true;
  }
}