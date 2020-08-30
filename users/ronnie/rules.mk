SRC += ronnie.c \
    process_records.c

# Some usual defaults
MOUSEKEY_ENABLE         = no    # Mouse keys (+4700)
EXTRAKEY_ENABLE         = yes   # Audio control and System control (+450)

ifneq ($(strip $(DISABLE_LTO)), yes)
  EXTRAFLAGS += -flto
  OPT_DEFS += -DNO_ACTION_MACRO
  OPT_DEFS += -DNO_ACTION_FUNCTION
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
  SRC += custom_encoder.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgb_stuff.c
    ifeq ($(strip $(RGBLIGHT_TWINKLE)), yes)
        OPT_DEFS += -DRGBLIGHT_TWINKLE
    endif
    ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
        OPT_DEFS += -DRGBLIGHT_NOEEPROM
    endif
    ifeq ($(strip $(RGBLIGHT_STARTUP_ANIMATION)), yes)
        OPT_DEFS += -DRGBLIGHT_STARTUP_ANIMATION
    endif
endif

ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
  OPT_DEFS += -DRGB_ENABLE
  SRC += custom_rgb.c
  SRC += rgb_matrix_stuff.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  OPT_DEFS += -DRGB_ENABLE
  SRC += custom_rgb.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
  SRC += custom_oled.c
endif
