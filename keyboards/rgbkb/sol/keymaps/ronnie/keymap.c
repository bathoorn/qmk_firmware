#include QMK_KEYBOARD_H
#include "ronnie.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

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
#define _______ KC_TRNS

#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define EOT     LCTL(KC_D)
#define NAK     LCTL(KC_U)
#define PASTE   LCTL(KC_V)
#define UNDO    LCTL(KC_Z)

// clang-format off
#define LAYOUT_sol2_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A,  \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
  ) \
  LAYOUT( \
    KC_ESC,  K01,    K02,     K03,      K04,     K05,    KC_MINS,     KC_EQL ,    K06,     K07,     K08,     K09,     K0A,     KC_BSPC,  \
    KC_TAB,  K11,    K12,     K13,      K14,     K15,    KC_LBRC,     KC_RBRC,    K16,     K17,     K18,     K19,     K1A,     KC_BSLS, \
    KC_CAPS,LCT(K21),LGT(K22),LAT(K23),LST(K24), K25,    KC_LCBR,     KC_RCBR,    K26,RST(K27),RAT(K28),RGT(K29),RCT(K2A),     KC_QUOT, \
    KC_LSFT, K31,    K32,     K33,      K34,     K35,    KC_LPRN,     KC_RPRN,    K36,     K37,     K38,     K39,     K3A,     KC_RSFT, \
    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_SPC,    KC_ENC1,     KC_ENC2, KC_ENT,RGB_MENU, KC_LEFT, KC_DOWN,   KC_UP,     KC_RGHT, \
                                              LO(KC_DEL), KC_SPC, KC_ENT, RS(KC_BSPC) \
  )
#define LAYOUT_sol2_base_wrapper(...)       LAYOUT_sol2_base(__VA_ARGS__)

// Define your non-alpha grouping in this define's LAYOUT, and all your BASE_LAYERS will share the same mod/macro columns

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty Layout
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | ESC  |   1  |   2  |  3   |  4   |  5   |   -  |  |   =  |  6   |  7   |  8   |  9   |  0   | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |  E   |  R   |  T   |   [  |  |   ]  |  Y   |  U   |  I   |  O   |  P   |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | CAPS |   A  |   S  |   D  |  F   |  G   |      |  |      |  H   |  J   |  K   |  L   |  ;   | Enter|
   * |------+------+------+------+------+------|      |  |      |------+------+------+------+------+------|
   * | Sft[ |   Z  |   X  |   C  |  V   |  B   |      |  |      |  N   |  M   |  ,   |  .   |  /   | Sft] |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctl- |  Win | LOWER| RAISE| Alt  | Space| ENC1 |  | ENC2 | Space| Left |  Up  | Down | Right| Ctl= |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_QWERTY] = LAYOUT_sol2_base_wrapper( \
    _________________RAISE_L1__________________,  _________________RAISE_R1__________________, \
    _________________QWERTY_L1_________________,  _________________QWERTY_R1_________________, \
    _________________QWERTY_L2_________________,  _________________QWERTY_R2_________________, \
    _________________QWERTY_L3_________________,  _________________QWERTY_R3_________________ \
  ),

  [_COLEMAK] = LAYOUT_sol2_base_wrapper(
    _________________RAISE_L1__________________, _________________RAISE_R1__________________,
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),

  [_DVORAK] = LAYOUT_sol2_base_wrapper(
    _________________RAISE_L1__________________, _________________RAISE_R1__________________,
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),

  [_WORKMAN] = LAYOUT_sol2_base_wrapper(
    _________________RAISE_L1__________________, _________________RAISE_R1__________________,
    _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
    _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
    _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
  ),

  [_LOWER] =  LAYOUT_wrapper( \
    KC_GRV  , _________________FUNC_LEFT_________________, KC_F11 , KC_F12 , _________________FUNC_RIGHT________________, _______, \
    _______ , _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________, _______, \
    _______ , _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________, _______, \
    _______ , _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________, _______, \
    _______ , ___________________BLANK___________________, _______, _______, ___________________BLANK___________________, _______, \
                                                  _______, _______, _______, _______ \
  ),

  [_RAISE] = LAYOUT_wrapper( \
    KC_GRV  , _________________FUNC_LEFT_________________, KC_F11 , KC_F12 , _________________FUNC_RIGHT________________, _______, \
    _______ , _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________, _______, \
    _______ , _________________RAISE_L2__________________, _______, _______, _________________RAISE_R2__________________, _______, \
    _______ , _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________, _______, \
    _______ , ___________________BLANK___________________, _______, _______, ___________________BLANK___________________, _______, \
                                                  _______, _______, _______, _______ \
  )

#ifdef TRILAYER_ENABLED
  ,
  [_ADJUST] = LAYOUT_wrapper( \
    RESET   , _________________FUNC_LEFT_________________, KC_F11 , KC_F12 , _________________FUNC_RIGHT________________, _______, \
    _______ , _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________, _______, \
    _______ , _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________, _______, \
    _______ , _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________, _______, \
    _______ , ___________________BLANK___________________, _______, _______, ___________________BLANK___________________, _______, \
                                                  _______, _______, _______, _______ \
  )
#endif
};



