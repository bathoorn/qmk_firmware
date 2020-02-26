#include "ronnie.h"
#include "process_records.h"
#include "custom_keycodes.h"
#include "timer_utils.h"

#ifdef RGB_ENABLE
#include "custom_rgb.h"
#endif

uint16_t copy_paste_timer;


//#ifdef TRILAYER_ENABLED
//uint32_t layer_state_set_user(uint32_t state)
//{
//    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}
//#endif

// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t reset_timer;
    switch (keycode) {
        case KC_QWERTY ... KC_WORKMAN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            }
            return false;
        case RGBRST:
#ifdef RGB_ENABLE
            if (record->event.pressed)
                rgb_reset();
#endif
            return false;
        case RESET:
            if (record->event.pressed) {
                reset_timer = timer_read();
            } else {
                if (timer_elapsed(reset_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
        case RGB_TOG:
            if (record->event.pressed) {
                rgb_matrix_increase_flags();
            }
            return false;
#endif
    }
    return process_record_encoder(keycode, record) && process_record_oled(keycode, record) && process_record_keymap(keycode, record);
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
    return true;
}

__attribute__ ((weak))
bool process_record_encoder(uint16_t keycode, keyrecord_t *record)
{
    return true;
}

__attribute__ ((weak))
bool process_record_oled(uint16_t keycode, keyrecord_t *record)
{
    return true;
}
