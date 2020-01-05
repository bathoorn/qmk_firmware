#include QMK_KEYBOARD_H

// layer enums

enum my_layers {
  _QWE,
  _NUM,
  _ADJ,
  _NAV,
  _MOU
};


// modifier keys

#define OS_RALT  OSM (MOD_RALT)
#define OS_RCTL  OSM (MOD_RCTL)
#define OS_RGUI  OSM (MOD_RGUI)

#define OS_ALT  OSM (MOD_LALT)
#define OS_CTL  OSM (MOD_LCTL)
#define OS_GUI  OSM (MOD_LGUI)
#define LT_END  LT  (_NUM, KC_END)
#define LT_ESC  LT  (_NUM, KC_ESC)
#define LS_SPC  LSFT_T(KC_SPC)
#define LT_TAB  LT  (_ADJ, KC_TAB)
#define LT_BSPC LT  (_ADJ, KC_BSPC)
#define RS_ENT  RSFT_T(KC_ENT)
#define LT_LEFT LT  (_NUM, KC_LEFT)
#define LT_SCLN LT  (_NAV, KC_SCLN)
#define LT_A    LT  (_NAV, KC_A)
#define AT_DOWN ALT_T(KC_DOWN)
#define GT_UP   GUI_T(KC_UP)
#define CT_RGHT CTL_T(KC_RGHT)
#define AT_PGUP ALT_T(KC_PGUP)
#define GT_PGDN   GUI_T(KC_PGDN)
#define CT_HOME CTL_T(KC_HOME)

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
  /* Base layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ - │Esc│ = │ 6 │ 7 │ 8 │ 9 │ 0 │Psc│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │Tab│ Q │ W │ E │ R │ T │ [ │Cut│ ] │ Y │ U │ I │ O │ P │ \ │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │Cps│ A │ S │ D │ F │ G │ { │Cpy│ } │ H │ J │ K │ L │ ; │ ' │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │LSf│ Z │ X │ C │ V │ B │ ( │Pst│ ) │ N │ M │ , │ . │ / │RSf│
   * ├───┼───┼───┼───┼───────┼───┼───┼───┼───────┼───┼───┼───┼───┤
   * │Hom│PgD│PgU│End│  Spc  │Tab│Del│Bsp│  Ent  │ ← │ ↓ │ ↑ │ → │
   * └───┴───┴───┴───┴───────┴───┴───┴───┴───────┴───┴───┴───┴───┘
   */
  [_QWE] = LAYOUT_ortho_5x15( \
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_MINS, KC_ESC, KC_EQL,  KC_6,    KC_7,   KC_8,   KC_9,     KC_0,     KC_PSCR, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC, CUT,     KC_RBRC, KC_Y,    KC_U,   KC_I,   KC_O,     KC_P,    KC_BSLS, \
    KC_CAPS, LT_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_LCBR, COPY,    KC_RCBR, KC_H,    KC_J,   KC_K,   KC_L,     LT_SCLN, KC_QUOT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_LPRN, PASTE,   KC_RPRN, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    CT_HOME, GT_PGDN, AT_PGUP, LT_END, KC_NO, LS_SPC, LT_TAB,  KC_DEL,  LT_BSPC, KC_NO, RS_ENT, LT_LEFT, AT_DOWN, GT_UP,   CT_RGHT  \
  ),

  /* Function layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Num│Scr│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │M4 │M2 │M↑ │M1 │M3 │M5 │   │PgU│ ↑ │PgD│Ply│Prv│Nxt│Clr│Ins│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │M← │M↓ │M→ │MW↑│   │Hom│ ← │ ↓ │ → │End│   │   │   │Top│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │MA0│MA2│MW←│MW→│   │   │   │VoD│VoU│Mut│   │   │PgU│Btm│
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │MW↓│MW↓│MW↓│   │   │   │   │   │App│Hom│PgD│End│
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [_NUM] = LAYOUT_ortho_5x15( \
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, \
    KC_TRNS, KC_MPRV, KC_MSTP, KC_MPLY, KC_MPLY, KC_MNXT, BL_TOGG, KC_TRNS, RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, BL_STEP, BL_INC,  BL_ON,   KC_TRNS, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_BRTG, BL_DEC,  BL_OFF,  KC_TRNS, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS  \
  ),

  /* Numpad layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │Num│   │   │   │   │   │   │P7 │P8 │P9 │P- │ − │ = │Num│   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │P4 │P5 │P6 │P+ │ ( │ ) │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │P1 │P2 │P3 │P* │ × │PEn│PEn│   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │P0 │ , │P. │P/ │ ÷ │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [_ADJ] = LAYOUT_ortho_5x15( \
    RESET, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PMNS, KC_PEQL, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, KC_PAST, KC_PENT, KC_PENT, _______, \
    _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PCMM, KC_PDOT, KC_PSLS, KC_SLCK, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  /* Nav layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │ ← │ ↓ │ ↑ │ → │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
   * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
   * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
   */
  [_NAV] = LAYOUT_ortho_5x15( \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

};
