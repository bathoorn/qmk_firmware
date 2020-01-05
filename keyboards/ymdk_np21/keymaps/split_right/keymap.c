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

// layout flip macro
#define LAYOUT_FLIP( \
    K01, K02, K03, K04, K05, K06, \
    K11, K12, K13, K14, K15, K16, \
    K21, K22, K23, K24, K25, K26, \
    K31, K32, K33, K34, K35, K36  \
) \
LAYOUT ( \
  K36, K35, K34, K33, K32, K31, \
  K26, K25, K24, K23, K22, K21, \
  K16, K15, K14, K13, K12, K11, \
  K06, K05, K04, K03, K02, K01  \
)

// modifier keys

#define OS_RALT  OSM (MOD_RALT)
#define OS_RCTL  OSM (MOD_RCTL)
#define OS_RGUI  OSM (MOD_RGUI)

#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
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
  // | ^GUI |   y  |   u  |   i  |   o  |   p  |
  // |------+------+------+------+------+------|
  // | ↑GUI |   h  |   j  |   k  |   l  |   ;  |
  // |------+------+------+------+------+------|
  // |^Shift|   n  |   m  |   ,  |   .  |   '  |
  // |------+------+------+------+------+------|
  // | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'

	[_QWE] = LAYOUT_FLIP(
        CNTR_TR, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
        CNTR_HR, KC_H   , KC_J   , KC_K   , KC_L   , LT_SCLN,
        CNTR_BR, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_QUOT,
        LT_BSPC, LT_ENT , LT_LEFT, AT_DOWN, GT_UP  , CT_RGHT
    ),
  // ,-----------------------------------------.
  // |   ]  |   Y  |   U  |   I  |   O  |   P  |
  // |------+------+------+------+------+------|
  // |   }  |   H  |   J  |   K  |   L  |   :  |
  // |------+------+------+------+------+------|
  // |   )  |   N  |   M  |   /  |   ?  |   "  |
  // |------+------+------+------+------+------|
  // |  Del |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'
	[_SFT] = LAYOUT_FLIP(
        KC_RBRC, S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P),
        KC_RCBR, S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_SCLN),
        KC_RPRN, S(KC_N), S(KC_M), KC_PSLS, KC_QUES, KC_DQUO,
        KC_DEL , ___fn__, ___x___, ___x___, ___x___, ___x___
    ),
  // ,-----------------------------------------.
  // |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
  // |------+------+------+------+------+------|
  // | ↑GUI |   6  |   7  |   8  |   9  |   0  |
  // |------+------+------+------+------+------|
  // |^Shift|      |      |   \  |   -  |   =  |
  // |------+------+------+------+------+------|
  // | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'
	[_NUM] = LAYOUT_FLIP(
        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        ___x___, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
        ___x___, _______, _______, KC_BSLS, KC_MINS, KC_EQL ,
        ___x___, ___x___, ___fn__, ___x___, ___x___, ___x___
    ),
  // ,-----------------------------------------.
  // | ^GUI |      |      |      |      |      |
  // |------+------+------+------+------+------|
  // | ↑GUI |   ^  |   &  |   *  |   (  |   )  |
  // |------+------+------+------+------+------|
  // |^Shift|      |      |   |  |   _  |   +  |
  // |------+------+------+------+------+------|
  // | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'
	[_SYM] = LAYOUT_FLIP(
        ___x___, _______, _______, _______, _______, _______,
        ___x___, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        ___x___, _______, _______, KC_PIPE, KC_UNDS, KC_PLUS,
        ___fn__, MO(_LED), ___x___, ___x___, ___x___, ___x___
    ),
  // ,-----------------------------------------.
  // | ^GUI |      |  INS | HOME | PGUP |      |
  // |------+------+------+------+------+------|
  // | ↑GUI | LEFT | DOWN |  UP  | RGHT |      |
  // |------+------+------+------+------+------|
  // |^Shift|      |  DEL |  END | PGDN |      |
  // |------+------+------+------+------+------|
  // | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'
	[_NAV] = LAYOUT_FLIP(
        ___x___, _______, KC_INS , KC_HOME, KC_PGUP, _______,
        ___x___, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, ___fn__,
        ___x___, _______, KC_DEL , KC_END , KC_PGDN, _______,
        ___x___, ___x___, ___x___, ___x___, ___x___, ___x___
    ) ,
  // ,-----------------------------------------.
  // | ^GUI |      |      |  ON  |  INC |      |
  // |------+------+------+------+------+------|
  // | ↑GUI | TOGG | STEP |  OFF |  DEC | BRTG |
  // |------+------+------+------+------+------|
  // |^Shift|      |      |      |      |      |
  // |------+------+------+------+------+------|
  // | Bksp |  Ent | Left | Down |  Up  | Right|
  // `-----------------------------------------'
	[_LED] = LAYOUT_FLIP(
        ___x___, _______, _______, BL_ON  , BL_INC , _______,
        ___x___, BL_TOGG, BL_STEP, BL_OFF , BL_DEC , BL_BRTG,
        ___x___, _______, _______, _______, _______, _______,
        ___fn__, ___fn__, ___x___, ___x___, ___x___, ___x___
    )
};
