/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
// #define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"LN7oD/JnlJp"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define MK_COMBINED

#define RGB_MATRIX_STARTUP_SPD 60

#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
#define UNICODE_KEY_WINC KC_SCRL

#define TAPPING_TERM 150
#define PERMISSIVE_HOLD


#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 64

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1
