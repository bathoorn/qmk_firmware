SRC += ronnie.c \
    process_records.c \
	vimmode.c

# Some usual defaults
MOUSEKEY_ENABLE         = no    # Mouse keys (+4700)
EXTRAKEY_ENABLE         = yes   # Audio control and System control (+450)

ifneq ($(strip $(DISABLE_LTO)), yes)
  EXTRAFLAGS += -flto
  OPT_DEFS += -DNO_ACTION_MACRO
  OPT_DEFS += -DNO_ACTION_FUNCTION
endif


