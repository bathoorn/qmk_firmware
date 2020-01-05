#include QMK_KEYBOARD_H
#include "ronnie.h"

extern keymap_config_t keymap_config;

// modifier keys

#define LO(K01)  LT(_LOWER, K01)
#define RS(K01)  LT(_RAISE, K01)
#define LCT(K01) LCTL_T(K01)
#define LAT(K01) LALT_T(K01)
#define LGT(K01) LGUI_T(K01)
#define LST(K01) LSFT_T(K01)
#define RCT(K01) RCTL_T(K01)
#define RAT(K01) LALT_T(K01)
#define RGT(K01) LGUI_T(K01)
#define RST(K01) LSFT_T(K01)


// keycodes
#define ___x___ KC_TRNS
#define ___fn__ KC_TRNS
#undef  _______
#define _______ KC_NO

#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define EOT     LCTL(KC_D)
#define NAK     LCTL(KC_U)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)

// clang-format off
#define LAYOUT_ergotravel_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
    KC_ESC,  K01,    K02,     K03,      K04,     K05, KC_MINS,      KC_EQL , K06,     K07,     K08,     K09,     K0A,     KC_BSLS, \
    KC_TAB, LCT(K11),LGT(K12),LAT(K13),LST(K14), K15, KC_LBRC,      KC_RBRC, K16, RST(K17), RAT(K18), RGT(K19), RCT(K1A), KC_QUOT, \
    KC_LSFT, K21,    K22,     K23,      K24,     K25, KC_INS ,      KC_PSCR, K26,     K27,     K28,     K29,     K2A,     KC_RSFT, \
    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_SPC, LO(KC_DEL),           RS(KC_BSPC),  KC_ENT, KC_LEFT, KC_DOWN,     KC_UP,   KC_RGHT  \
  )
#define LAYOUT_ergotravel_base_wrapper(...)       LAYOUT_ergotravel_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_ergotravel_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_ergotravel_base_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_DVORAK] = LAYOUT_ergotravel_base_wrapper(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),

  [_WORKMAN] = LAYOUT_ergotravel_base_wrapper(
    _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
    _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
    _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
  ),

  [_LOWER] = LAYOUT_wrapper(
    KC_GRAVE, _________________LOWER_L1__________________, KC_MINS,      KC_EQL, _________________LOWER_R1__________________, _______,
    _______ , _________________LOWER_L2__________________, KC_F6 ,      KC_RBRC, _________________LOWER_R2__________________, _______,
    _______ , _________________LOWER_L3__________________, KC_F12,      KC_PSCR, _________________LOWER_R3__________________, _______,
    _______ , _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    KC_GRAVE, _________________RAISE_L1__________________, KC_MINS,      KC_EQL, _________________RAISE_R1__________________, _______,
    _______ , _________________RAISE_L2__________________, KC_F6 ,      KC_RBRC, _________________RAISE_R2__________________, _______,
    _______ , _________________RAISE_L3__________________, KC_F12,      KC_PSCR, _________________RAISE_R3__________________, _______,
    _______ , _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    _______ , _________________ADJUST_L1_________________, _______,     _______, _________________ADJUST_L1_________________, _______,
    _______ , _________________ADJUST_L2_________________, _______,     _______, _________________ADJUST_R2_________________, _______,
    _______ , _________________ADJUST_L3_________________, _______,     _______, _________________ADJUST_R3_________________, _______,
    _______ , _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______
  )

};
