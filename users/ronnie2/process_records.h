#pragma once
#include "ronnie.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_QWERTY,                      // Sets default layer to QWERTY
    UC_FLIP,        // (ಠ痊ಠ)┻━┻
    UC_TABL,        // ┬─┬ノ( º _ ºノ)
    UC_SHRG,        // ¯\_(ツ)_/¯
    NEW_SAFE_RANGE  // use "NEWPLACEHOLDER for keymap specific codes
};

/* Define layer names */
enum layer_number {
    _QWERTY  = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _VIM
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_record_encoder(uint16_t keycode, keyrecord_t *record);
bool process_record_oled(uint16_t keycode, keyrecord_t *record);

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
#define RA(K01) RALT_T(K01)
#define RG(K01) RGUI_T(K01)
#define RS(K01) RSFT_T(K01)

// transparent
#undef  _______
#define _______ KC_TRNS
