#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

// layer enums

enum my_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAV
};

// modifier keys

#define OS_RALT  OSM (MOD_RALT)
#define OS_RCTL  OSM (MOD_RCTL)
#define OS_RGUI  OSM (MOD_RGUI)

#define OS_CTL  OSM  (MOD_LCTL)
#define OS_GUI  OSM  (MOD_LGUI)
#define OS_ALT  OSM  (MOD_LALT)

#define CT_HOME CTL_T(KC_HOME)
#define GT_PGDN GUI_T(KC_PGDN)
#define AT_PGUP ALT_T(KC_PGUP)
#define LT_END  LT   (_LOWER, KC_END)
#define LO_DEL  LT   (_LOWER, KC_DEL)
#define SH_SPC LSFT_T(KC_SPC)
#define RS_BSPC LT   (_RAISE, KC_BSPC)
#define SH_ENT RSFT_T(KC_ENT)
#define LT_LEFT LT   (_RAISE, KC_LEFT)
#define AT_DOWN ALT_T(KC_DOWN)
#define GT_UP   GUI_T(KC_UP)
#define CT_RGHT CTL_T(KC_RGHT)
#define NV_SCLN LT   (_NAV, KC_SCLN)
#define NV_A    LT   (_NAV, KC_A)

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

  [_QWERTY] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
     KC_ESC , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_MINS,      KC_EQL , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , NV_A  , KC_S  , KC_D  , KC_F  , KC_G  ,KC_LBRC,      KC_RBRC, KC_H  , KC_J  , KC_K  , KC_L  ,NV_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_INS ,      KC_PSCR, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------+-------.     .-------+-------+-------+-------+-------+-------+-------|
     CT_HOME,GT_PGDN,AT_PGUP,LT_END , SH_SPC, LO_DEL,                      RS_BSPC,SH_ENT ,LT_LEFT,AT_DOWN, GT_UP ,CT_RGHT
  //`-------+-------+-------+-------+-------/-------/                     \-------\-------+-------+-------+-------+-------'
  ),

  [_LOWER] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , KC_MINS,      KC_EQL, KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,      KC_RBRC, KC_H  , KC_J  , KC_K  , KC_L  ,NV_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,      KC_PSCR, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------+-------.     .-------+-------+-------+-------+-------+-------+-------|
     CT_HOME,GT_PGDN,AT_PGUP,LT_END , SH_SPC, LO_DEL,                      RS_BSPC,SH_ENT ,LT_LEFT,AT_DOWN, GT_UP ,CT_RGHT
  //`-------+-------+-------+-------+-------/-------/                     \-------\-------+-------+-------+-------+-------'
  ),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE,KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC, KC_MINS,      KC_EQL,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 ,      KC_RBRC, KC_H  , KC_J  , KC_K  , KC_L  ,NV_SCLN,KC_QUOT,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,      KC_PSCR, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------+-------.     .-------+-------+-------+-------+-------+-------+-------|
     CT_HOME,GT_PGDN,AT_PGUP,LT_END , SH_SPC, LO_DEL,                      RS_BSPC,SH_ENT ,LT_LEFT,AT_DOWN, GT_UP ,CT_RGHT
  //`-------+-------+-------+-------+-------/-------/                     \-------\-------+-------+-------+-------+-------'
  ),

  [_NAV] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------+-------.     ,-------+-------+-------+-------+-------+-------+-------.
    KC_GRAVE,KC_EXLM, KC_AT ,KC_HASH, KC_DLR,KC_PERC, KC_MINS,      KC_EQL,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL ,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_TAB , NV_A  ,KC_HOME,KC_PGDN,KC_PGUP,KC_END , KC_F6 ,      KC_RBRC,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,NV_SCLN,KC_BSLS,
  //|-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------|
     KC_LSFT, UNDO  , CUT   , COPY  , PASTE , KC_F11, KC_F12,      KC_PSCR, KC_N  , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
  //|-------+-------+-------+-------+-------+-------+-------.     .-------+-------+-------+-------+-------+-------+-------|
     CT_HOME,GT_PGDN,AT_PGUP,LT_END , SH_SPC, LO_DEL,                      RS_BSPC,SH_ENT ,LT_LEFT,AT_DOWN, GT_UP ,CT_RGHT
  //`-------+-------+-------+-------+-------/-------/                     \-------\-------+-------+-------+-------+-------'
  )

};
