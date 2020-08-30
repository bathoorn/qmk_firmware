#include QMK_KEYBOARD_H

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define FORCE_NKRO
#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define TAP_CODE_DELAY 5

/* Define layer names */
enum layer_number {
    _QWERTY  = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAVI
};

// layer switching

#define LO(K01)  LT(_LOWER , K01)
#define RS(K01)  LT(_RAISE , K01)
#define NV(K01)  LT(_NAVI  , K01)
#define AD(K01)  LT(_ADJUST, K01)

// modifier keys

#define LCT(K01) LCTL_T(K01)
#define LAT(K01) LALT_T(K01)
#define LGT(K01) LGUI_T(K01)
#define LST(K01) LSFT_T(K01)
#define RCT(K01) RCTL_T(K01)
#define RAT(K01) LALT_T(K01)
#define RGT(K01) LGUI_T(K01)
#define RST(K01) LSFT_T(K01)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		LCT(KC_A), LGT(KC_S), LAT(KC_D), LST(KC_F), KC_G, KC_H, RST(KC_J), RAT(KC_K), RGT(KC_L), RCT(KC_ENT),
		KC_Z, KC_X, NV(KC_C), LO(KC_V), LST(KC_SPC), RS(KC_B), AD(KC_N), KC_M),

	[_LOWER] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
		KC_LSFT, KC_ESC, KC_TAB, KC_SCLN, KC_QUOT, KC_QUOT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
		KC_LCTL, KC_LGUI, KC_LALT, KC_NO, LST(KC_SPC), KC_COMM, KC_DOT, KC_SLSH),

	[_RAISE] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_LSFT, KC_ESC, KC_TAB, KC_PSCR, KC_PAUS, KC_DQUO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, LST(KC_SPC), KC_NO, KC_NO, KC_NO),

	[_ADJUST] = LAYOUT(
		KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_BSLS,
		KC_ESC, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_QUOT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_DEL, LST(KC_SPC), KC_BSPC, KC_NO, RESET),

	[_NAVI] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_LSFT, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_NO, KC_LALT, LST(KC_SPC), KC_SCLN, KC_QUOT, KC_BSLS),

};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
