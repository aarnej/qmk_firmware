#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 15

#define USB_SUSPEND_WAKEUP_DELAY 0

#define MK_KINETIC_SPEED

#define MOUSEKEY_MOVE_DELTA 64

// #undef MOUSEKEY_INTERVAL
// #define MOUSEKEY_INTERVAL 10

// #undef MOUSEKEY_DELAY
// #define MOUSEKEY_DELAY 40

// #undef MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED 10

// #undef MOUSEKEY_TIME_TO_MAX
// #define MOUSEKEY_TIME_TO_MAX 90

// #undef MOUSEKEY_WHEEL_INTERVAL
// #define MOUSEKEY_WHEEL_INTERVAL 150

#define AUTO_SHIFT_TIMEOUT 140
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC
#define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"BRWdd/wgpJ9"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_WINC KC_SCRL
