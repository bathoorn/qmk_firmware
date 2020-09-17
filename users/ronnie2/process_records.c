#include "ronnie.h"
#include "process_records.h"


// Defines actions tor my global custom keycodes. Defined in drashna.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t reset_timer;
    switch (keycode) {
        case RESET:
            if (record->event.pressed) {
                reset_timer = timer_read();
            } else {
                if (timer_elapsed(reset_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
    }
    return process_record_keymap(keycode, record);
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record)
{
    return true;
}

