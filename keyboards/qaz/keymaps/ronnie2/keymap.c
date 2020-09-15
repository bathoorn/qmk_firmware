#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};
enum combo_events {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_QUOTE,
  COMBO_BSLS,
  COMBO_SLSH
};

// layer switching

#define LO(K01)  LT(_LOWER , K01)
#define RZ(K01)  LT(_RAISE , K01)
#define AD(K01)  LT(_ADJUST, K01)

// modifier keys

#define LC(K01) LCTL_T(K01)
#define LA(K01) LALT_T(K01)
#define LG(K01) LGUI_T(K01)
#define LS(K01) LSFT_T(K01)
#define RC(K01) RCTL_T(K01)
#define RA(K01) LALT_T(K01)
#define RG(K01) LGUI_T(K01)
#define RS(K01) LSFT_T(K01)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
	KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
	KC_A, KC_S, LA(KC_D), LS(KC_F), KC_G, KC_H, RS(KC_J), RA(KC_K), KC_L, KC_SCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,
    KC_LCTL, KC_LGUI, RZ(KC_DEL), KC_SPACE, KC_ENT, LO(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_LOWER] = LAYOUT_split_space(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6  , KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12 , KC_UNDS, KC_PLUS, KC_LCBR,
    KC_LCTL, KC_LGUI, RS(KC_DEL), KC_SPACE, KC_ENT, LO(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_RAISE] = LAYOUT_split_space(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCBR,
    KC_LCTL, KC_LGUI, RS(KC_DEL), KC_SPACE, KC_ENT, LO(KC_BSPC), KC_RGUI, KC_RCTL
  ),

  [_ADJUST] = LAYOUT_split_space(
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  AG_NORM,  AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_TRNS,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_LCTL, KC_LGUI, RS(KC_DEL), KC_SPACE, KC_ENT, LO(KC_BSPC), KC_RGUI, KC_RCTL
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bsls[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_quote[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_slsh[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_A, KC_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSLS] = COMBO(combo_bsls,KC_BSLS),
  [COMBO_QUOTE] = COMBO(combo_quote,KC_QUOTE),
  [COMBO_SLSH] = COMBO(combo_slsh,KC_SLSH),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),

};
#endif

layer_state_t layer_state_set_keymap(layer_state_t state);

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}
