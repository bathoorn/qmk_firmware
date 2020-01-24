#pragma once

enum custom_keycodes {
  RGB_ENC = SAFE_RANGE,
  KEYMAP_SAFE_RANGE
};


#ifdef ENCODER_ENABLE
#define KC_ENC1 RGB_ENC
#define KC_ENC2 KC_MPLY
#else
#define KC_ENC1 RGB_RMOD
#define KC_ENC2 RGB_MOD
#endif
