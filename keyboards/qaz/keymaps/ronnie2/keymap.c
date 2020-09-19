#include "ronnie.h"

#include QMK_KEYBOARD_H

enum combo_events {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_VIM_ESC,
  COMBO_QUOTE,
  COMBO_BSLS,
  COMBO_SLSH
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_space(
	KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
	LC(KC_A), LG(KC_S), LA(KC_D), LS(KC_F), KC_G, KC_H, RS(KC_J), RA(KC_K), RG(KC_L), RC(KC_SCLN),
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,
    KC_LCTL, KC_LGUI, LO(KC_DEL), KC_SPACE, KC_ENT, RZ(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_LOWER] = LAYOUT_split_space(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6  , KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12 , KC_UNDS, KC_PLUS, KC_LCBR,
    KC_LCTL, KC_LGUI, LO(KC_DEL), KC_SPACE, KC_ENT, RZ(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_RAISE] = LAYOUT_split_space(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCBR,
    KC_LCTL, KC_LGUI, LO(KC_DEL), KC_SPACE, KC_ENT, RZ(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_ADJUST] = LAYOUT_split_space(
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  AG_NORM,  AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_TRNS,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_LCTL, KC_LGUI, LO(KC_DEL), KC_SPACE, KC_ENT, RZ(KC_BSPC), KC_RGUI, KC_RCTL
  ),
  [_VIM] = LAYOUT_split_space(
	KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
	KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_RSFT, KC_X, KC_C, KC_V, KC_B, KC_N, KC_COMM, KC_DOT, KC_LSFT,
    KC_0, KC_1, KC_2, KC_SPACE, KC_ENT, KC_3, KC_4, KC_DLR
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bsls[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_quote[] = {RG(KC_L), RC(KC_SCLN), COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {LC(KC_A), LG(KC_S), COMBO_END};
const uint16_t PROGMEM combo_vim_esc[] = {KC_Z,   KC_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSLS] = COMBO(combo_bsls,KC_BSLS),
  [COMBO_QUOTE] = COMBO(combo_quote,KC_QUOTE),
  [COMBO_SLSH] = COMBO(combo_slsh,KC_SLSH),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_VIM_ESC] = COMBO(combo_vim_esc,VIM_ESC)
};
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  bool vim_handled = handle_vim_mode(keycode, record, _VIM);
  if (vim_handled)
    return false;

  return true;
}
