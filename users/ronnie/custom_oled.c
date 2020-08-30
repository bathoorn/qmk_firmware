#include "ronnie.h"
#include "process_records.h"

#include <stdio.h>


#ifdef RGBLIGHT_ENABLE
rgblight_config_t rgblight_config;
#endif

#if KEYBOARD_helix_rev2
extern uint8_t is_master;
bool is_keyboard_master(void) { return is_master; }
#endif

#ifdef RGB_OLED_MENU
extern uint8_t rgb_encoder_state;
#endif

static uint32_t oled_timer                       = 0;

#ifdef KEYLOG_OLED
#    define KEYLOGGER_LENGTH 5
static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
static uint16_t log_timer                        = 0;
// clang-format off
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        // add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}
#endif


#if defined(OLED_90ROTATION)

#ifdef RGB_ENABLE
static void render_rgb_state(void)
{
    // TODO: need to do a bit more handling here for horizontal rendering
#if defined(RGB_MATRIX_ENABLE)
    static char buffer[31] = {0};
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
#elif defined(RGBLIGHT_ENABLE)
    static char buffer[26] = {0};
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d s%3d m%3d ", rgblight_config.hue, rgblight_config.sat, rgblight_config.val, rgblight_config.speed, rgblight_config.mode);
#endif

#ifdef RGB_OLED_MENU
    buffer[4 + rgb_encoder_state * 5] = '<';
#endif
    oled_write(buffer, false);
}
#endif

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR(" COLE"), false);
            break;
        case _DVORAK:
            oled_write_P(PSTR(" DVRK"), false);
            break;
        case _WORKMAN:
            oled_write_P(PSTR(" WKMN"), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("Lower"), layer_state_is(_LOWER));
    oled_write_P(PSTR("Raise"), layer_state_is(_RAISE));
#ifdef TRILAYER_ENABLED
    oled_write_P(PSTR("Adjst"), layer_state_is(_ADJUST));
#endif
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}


void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_keylock_status(host_keyboard_leds());

#ifdef KEYLOG_OLED
    render_keylogger_status();
#endif
#ifdef RGB_ENABLE
    render_rgb_state();
#endif
}

void render_status_secondary(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_layer_state();
    render_mod_status(get_mods());
    /* | get_oneshot_mods()); */

#ifdef KEYLOG_OLED
    render_keylogger_status();
#endif
#ifdef RGB_ENABLE
    render_rgb_state();
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_270;
  return rotation;
}

#else  // OLED_90ROTATION

#ifdef RGB_ENABLE
static void render_rgb_state(void)
{
    // TODO: need to do a bit more handling here for horizontal rendering
#if defined(RGB_MATRIX_ENABLE)
    static char buffer[37] = {0};
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d       s%3d m%3d e%3d ", rgb_matrix_config.hsv.h, rgb_matrix_config.hsv.s, rgb_matrix_config.hsv.v, rgb_matrix_config.speed, rgb_matrix_config.mode, rgb_matrix_get_flags());
#elif defined(RGBLIGHT_ENABLE)
    static char buffer[32] = {0};
    snprintf(buffer, sizeof(buffer), "h%3d s%3d v%3d       s%3d m%3d ", rgblight_config.hue, rgblight_config.sat, rgblight_config.val, rgblight_config.speed, rgblight_config.mode);
#endif

#ifdef RGB_OLED_MENU
    buffer[4 + rgb_encoder_state * 5] = '<';
#endif
    oled_write(buffer, false);
}
#endif

static void render_status(void)
{
    render_icon();

    // Host Layer Status
    oled_set_cursor(6, 0);
    render_layer();

    // Host Keyboard LED Status
    oled_set_cursor(6, 1);
    render_keyboard_leds();
#ifdef KEYLOG_OLED
    oled_set_cursor(6, 2);
    render_keylogger_status();
#endif
#ifdef RGB_ENABLE
    oled_set_cursor(6, 3);
    render_rgb_state();
#endif

}

#endif // OLED_90ROTATION

bool process_record_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef KEYLOG_OLED
        add_keylog(keycode);
        #endif
        oled_timer = timer_read();
    }
    return true;
}

void oled_task_user(void)
{
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#    ifndef SPLIT_KEYBOARD
    else {
        oled_on();
    }
#    endif

#    ifdef KEYLOG_OLED
    update_log();
#    endif
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}

