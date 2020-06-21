#include QMK_KEYBOARD_H

enum jj40_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _WINMAP,
  _WINSYM,
  _FUNC
};

#define LOWER  TT(_LOWER)
#define WINMAP TO(_WINMAP)
#define WINSYM TO(_WINSYM)
#define QWERTY TO(_QWERTY)
#define TORAISE TO(_RAISE)
#define XRAISE  LT(_RAISE,KC_LANG1)
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
  TT_LEQL,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TT_JLINE] = ACTION_TAP_DANCE_DOUBLE(JP_UNDS, KC_MINS),
    [TT_LINE] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_MINS),
    [TT_QUO]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TT_CLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON),
    [TT_JCLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
    [TT_LEQL] = ACTION_TAP_DANCE_DOUBLE(KC_L, KC_EQL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |  P   | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |  L=  |  ;:  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  ,<  |  .>  |  UP  | /?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt  | Tab  | FUNC | Lower| SPC  |WIN10  |Raise |  -   | LEFT | DOWN |RIGHT|
 * |      |      |      | Esisu|      |      |       |Kana  |  _   |      |      |     |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,  \
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, TD(TT_LEQL), TD(TT_CLN), KC_ENT,  \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,  \
  KC_LGUI, KC_LALT, KC_TAB, LT(_FUNC, KC_LANG2), LOWER, KC_SPC, WINMAP, XRAISE,  TD(TT_LINE), KC_LEFT,KC_DOWN, KC_RIGHT  \
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CTRL |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  -   |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   '  |  "   |  "'  | PgUp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | Opt   | ESC |      |      |      |      |  |   |  _   | LEFT | RIGHT| PgDn |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM,   KC_AT,  KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_LCTL,   KC_F1,   KC_F2,    KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,  KC_ENT, \
  KC_LSFT,   KC_F7,   KC_F8,    KC_F9, KC_F10,   KC_F11,  KC_F12, _______, KC_QUOT, KC_DQUO, TD(TT_QUO), KC_PGUP, \
  KC_LGUI, KC_LALT, KC_ESC,  _______, _______,  _______, _______, KC_PIPE, KC_UNDS, KC_LEFT, KC_RIGHT, KC_PGDN \
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SHIFT|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |   '  |  "   |  "'  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CMD  | CTRL |      |      |      |      |      |WINMAP| Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,     KC_9,    KC_0, KC_BSPC, \
  KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC,  KC_ENT, \
  KC_LSFT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, KC_QUOT,  KC_DQUO, TD(TT_QUO), KC_BSLS, \
  KC_LGUI, KC_LCTL, _______, _______, _______, _______, _______, WINMAP,KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),
/* WIN10
 * ,------------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E   |   R  |   T  |   Y  |   U  |   I  |   O  |  P   | Bksp |
 * |------+------+------+-------+------+-------------+------+------+------+------+------|
 * | WIN  |   A  |   S  |   D   |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |Enter |
 * |------+------+------+-------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C   |   V  |  B   |   N  |   M  |  ,<  |  .>  |  UP  | /?   |
 * |------+------+------+-------+------+------+------+------+------+------+------+------|
 * | CTRL | Opt  | Tab  | FUNC  |WINSYM| SPC  |QWERTY|RAISE | ZKHK | LEFT | DOWN |RIGHT |
 * |      |      |      |(hold) |      |      |      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------'
 */
[_WINMAP] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W, KC_E, KC_R,   KC_T, KC_Y,   KC_U, KC_I,KC_O, KC_P,  KC_BSPC,  \
  KC_LGUI, KC_A,    KC_S, KC_D, KC_F,   KC_G, KC_H,   KC_J, KC_K,    KC_L,  TD(TT_JCLN), KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X, KC_C, KC_V,   KC_B, KC_N,   KC_M, KC_COMM,  KC_DOT,  KC_UP, KC_SLSH,  \
  KC_LCTL, KC_LALT, KC_TAB, MO(_FUNC), WINSYM, KC_SPC, QWERTY, TORAISE, KC_ZKHK, KC_LEFT, KC_DOWN, KC_RIGHT  \
),
/* WINJP_SYM
 * ,-------------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |    #  |   $  |   %  |   ^  |   &   |   *  |   (  |   )  | Bksp |
 * |------+------+------+-------+------+-------------+-------+------+------+------+------|
 * |   `  |  A   | LEFT | RIGHT | PgUp | PgDn |  -   |   =   |   +  |   {  |   }  |Enter |
 * |------+------+------+-------+------+------|------+-------+------+------+------+------|
 * | Shift|  Z   |  X   |   C   |  V   |  Â¥  |   [  |   ]   |   '  |   "  |  UP  |  \   |
 * |------+------+------+-------+------+------+------+-------+------+------+------+------|
 * | CTRL | Opt  | Tab  |  WIN  |WINMAP| SPC  |QWERTY|   |   |  _-  | LEFT | DOWN |RIGHT |
 * `-------------------------------------------------------------------------------------'
 */
[_WINSYM] = LAYOUT_ortho_4x12( \
  KC_PLUS, KC_EXLM, KC_LBRC,  KC_HASH,KC_DLR, JP_PERC, KC_EQL, KC_CIRC, JP_ASTR, KC_ASTR, KC_LPRN, KC_BSPC, \
  KC_LCBR, _______, KC_LEFT, KC_RIGHT, KC_PGUP, KC_PGDN, KC_MINS, KC_UNDS, KC_COLON, KC_RCBR, KC_PIPE, KC_ENT,  \
  KC_LSFT, _______, _______, _______, _______, KC_JYEN, KC_RBRC, KC_NUHS, JP_QUOT,  JP_DQUO,  _______, KC_RO, \
  KC_LCTL, KC_LALT, KC_TAB, KC_LGUI, WINMAP, KC_SPC, QWERTY, JP_PIPE, TD(TT_JLINE), _______, _______, _______  \
),

/* Functions
 *  Note: Terminal uses Calculator shortcut, change your OS keyboard shortcut appropriately.
 * ,------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12   |
 * |------+------+------+------+------+-------------+------+------+------+------+------ |
 * |      | RGB  | RGB  | RGB  | RGB  |  BL  |  BL  |  BL  |Rnbow |Swirl | Xmas |       |
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
    _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_TOGG, BL_BRTG, BL_INC,  RGB_M_R, RGB_M_SW,RGB_M_X, KC_VOLU, \
    _______, KC_CALC, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, BL_DEC,  _______, _______, KC_PSCR, KC_VOLD, \
    _______, _______, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)
};

void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      rgblight_disable();
      if (is_backlight_enabled()) {
        breathing_disable();
      }
      return true;
    case LOWER:
      if (layer_state_is(_LOWER)) {
        rgblight_disable();
      } else {
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb_at(RGB_GOLD, 0);
        rgblight_setrgb_at(RGB_GOLD, 1);
        rgblight_setrgb_at(RGB_GOLD, 2);
        rgblight_setrgb_at(RGB_GOLD, 3);
      }
      return true;
    case WINMAP:
      rgblight_enable();
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_setrgb_at(RGB_AZURE, 0);
      rgblight_setrgb_at(RGB_AZURE, 1);
      rgblight_setrgb_at(RGB_AZURE, 2);
      rgblight_setrgb_at(RGB_AZURE, 3);
      return true;
    case TORAISE:
      rgblight_enable();
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_setrgb_at(RGB_RED, 0);
      rgblight_setrgb_at(RGB_RED, 1);
      rgblight_setrgb_at(RGB_RED, 2);
      rgblight_setrgb_at(RGB_RED, 3);
      return true;
    case XRAISE:
      if (layer_state_is(_RAISE)) {
        rgblight_disable();
      } else {
        rgblight_enable();
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb_at(RGB_RED, 0);
        rgblight_setrgb_at(RGB_RED, 1);
        rgblight_setrgb_at(RGB_RED, 2);
        rgblight_setrgb_at(RGB_RED, 3);
      }
      return true;
    case WINSYM:
      rgblight_enable();
      rgblight_setrgb(120, 155, 15);
      return true;
    default:
      return true;
  }
}
