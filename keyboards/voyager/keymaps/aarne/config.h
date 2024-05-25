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
