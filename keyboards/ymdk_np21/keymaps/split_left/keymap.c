#include QMK_KEYBOARD_H

// layer enums

enum my_layers {
  _QWE,
  _SFT,
  _NUM,
  _SYM,
  _NAV,
  _LED
};

// modifier keys

#define OS_RALT  OSM (MOD_RALT)
#define OS_RCTL  OSM (MOD_RCTL)
#define OS_RGUI  OSM (MOD_RGUI)

#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define OS_ALT  OSM (MOD_LALT)
#define LT_ESC  LT  (_NUM, KC_ESC)
#define LT_SPC  LT  (_SFT, KC_SPC)
#define LT_TAB  LT  (_SYM, KC_TAB)
#define LT_BSPC LT  (_SYM,   KC_BSPC)
#define LT_ENT  LT  (_SFT, KC_ENT)
#define LT_LEFT LT  (_NUM, KC_LEFT)
#define AT_DOWN ALT_T(KC_DOWN)
#define GT_UP   GUI_T(KC_UP)
#define CT_RGHT CTL_T(KC_RGHT)

#define LT_SCLN LT  (_NAV, KC_SCLN)
#define MO_LED  MO  (_LED)

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

#define CNTR_TL OSM (MOD_LALT | MOD_LCTL)
#define CNTR_HL OSM (MOD_LALT | MOD_LSFT)

#define CNTR_TR OSM (MOD_LGUI | MOD_LCTL)
#define CNTR_HR OSM (MOD_LGUI | MOD_LSFT)
#define CNTR_BR OSM (MOD_LSFT | MOD_LCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ,-----------------------------------------.
  // |   q  |   w  |   e  |   r  |   t  | ^Alt |
  // |------+------+------+------+------+------|
  // |   a  |   s  |   d  |   f  |   g  | ↑Alt |
  // |------+------+------+------+------+------|
  // |   z  |   x  |   c  |   v  |   b  |   -  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_QWE] = LAYOUT(
        KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  , CNTR_TL,
        KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , CNTR_HL,
        KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , LT(_NAV,KC_MINS),
        OS_ALT, OS_GUI, OS_ALT, LT_ESC, LT_SPC, LT_TAB
    ),
  // ,-----------------------------------------.
  // |   Q  |   W  |   E  |   R  |   T  |   [  |
  // |------+------+------+------+------+------|
  // |   A  |   S  |   D  |   F  |   G  |   {  |
  // |------+------+------+------+------+------|
  // |   Z  |   X  |   C  |   V  |   B  |   (  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_SFT] = LAYOUT(
        S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), KC_LBRC,
        S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), KC_LCBR,
        S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), KC_LPRN,
        ___x___, ___x___, ___x___, ___x___, ___fn__, ___x___
    ),
  // ,-----------------------------------------.
  // |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
  // |------+------+------+------+------+------|
  // |   1  |   2  |   3  |   4  |   5  | ↑Alt |
  // |------+------+------+------+------+------|
  // |   `  |      |      |      |      |   -  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_NUM] = LAYOUT(
        KC_F1  , KC_F2 , KC_F3   , KC_F4  , KC_F5  , KC_F6  ,
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , ___x___,
        KC_GRV , KC_NO  , KC_NO  , KC_NO  , KC_NO  , ___x___,
        ___x___, ___x___, ___x___, ___fn__, ___x___, ___x___
    ),
  // ,-----------------------------------------.
  // |      |      |      |      |      | ^Alt |
  // |------+------+------+------+------+------|
  // |   !  |   @  |   #  |   $  |   %  | ↑Alt |
  // |------+------+------+------+------+------|
  // |   ~  |   /  |   *  |   <  |   >  |   -  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, ___x___,
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, ___x___,
        KC_TILD, KC_PSLS, KC_PAST, KC_LT  , KC_GT  , ___x___,
        ___x___, ___x___, ___x___, ___x___, MO_LED , ___fn__
    ),
  // ,-----------------------------------------.
  // | HOME |  UP  |  END | PGUP |      | ^Alt |
  // |------+------+------+------+------+------|
  // | LEFT | DOWN | RGHT | PGDN |      | ↑Alt |
  // |------+------+------+------+------+------|
  // |  INS |  DEL |      |      |      |   -  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_NAV] = LAYOUT(
        KC_HOME, KC_UP  , KC_END , KC_PGUP, _______, ___x___,
        KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, ___x___,
        KC_INS , KC_DEL , _______, _______, _______, ___fn__,
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___
    ),
  // ,-----------------------------------------.
  // |      |      |  ON  |  INC |      | ^Alt |
  // |------+------+------+------+------+------|
  // | TOGG | STEP |  OFF |  DEC | BRTG | ↑Alt |
  // |------+------+------+------+------+------|
  // |      |      |      |      |      |   -  |
  // |------+------+------+------+------+------|
  // | Ctrl |  GUI |  Alt |  Esc | Space|  Tab |
  // `-----------------------------------------'
	[_LED] = LAYOUT(
        _______, _______, BL_ON  , BL_INC , _______, ___x___,
        BL_TOGG, BL_STEP, BL_OFF , BL_DEC , BL_BRTG, ___x___,
        _______, _______, _______, _______, _______, ___x___,
        ___x___, ___x___, ___x___, ___x___, ___fn__, ___fn__
    )
};
