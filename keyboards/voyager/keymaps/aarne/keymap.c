#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL

enum planck_layers {
    _BASE,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJ,
};

#define SLEEP KC_SYSTEM_SLEEP
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK
#define PAUSE KC_MEDIA_PLAY_PAUSE

enum {
    ADIA_LOWER,
    ADIA_UPPER,
    ODIA_LOWER,
    ODIA_UPPER,
    ARING_LOWER,
    ARING_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [ADIA_LOWER] = 0xe4,
    [ADIA_UPPER] = 0xc3,
    [ODIA_LOWER] = 0xf6,
    [ODIA_UPPER] = 0xd6,
    [ARING_LOWER] = 0xe5,
    [ARING_UPPER] = 0xc5
};

#define ADIA UP(ADIA_LOWER, ADIA_UPPER)
#define ODIA UP(ODIA_LOWER, ODIA_UPPER)
#define ARING UP(ARING_LOWER, ARING_UPPER)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define COPY C(KC_C)
#define CUT C(KC_X)
#define PASTE C(S(KC_V))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_voyager(
    _______,        _______,        COPY,           CUT,            PASTE,          KC_INS,                TG(_GAME),      _______,        _______,        KC_F2,          KC_F5,           KC_F12,
    KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                  KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,            ADIA,
    KC_TAB,         LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   LT(_ADJ, KC_G),        LT(_ADJ, KC_H), LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   LGUI_T(KC_SCLN), ODIA,
    CW_TOGG,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                  KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,         _______,
                                                                       RAISE,         KC_SPC,         KC_ENT,      LOWER
  ),
  [_GAME] = LAYOUT_voyager(
    _______,        _______,        _______,        _______,        _______,        _______,               _______,      _______,        _______,        _______,        _______,         _______,
    _______,        _______,        _______,        _______,        _______,        _______,               _______,        _______,        _______,        _______,        _______,         _______,
    KC_LSFT,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                  KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,         _______,
    KC_LCTL,        _______,        _______,        _______,        _______,        _______,               _______,        _______,        _______,        _______,        _______,         _______,
                                                                        LOWER,        _______,          _______,        RAISE
  ),
  [_LOWER] = LAYOUT_voyager(
    _______,        _______,        _______,        _______,        _______,        _______,               _______,        _______,        _______,        _______,        _______,         _______,
    HYPR(KC_1),     KC_1,           KC_2,           KC_3,           KC_4,           HYPR(KC_A),            HYPR(KC_D),     KC_PGUP,        KC_UP,          KC_HOME,        KC_SCRL,         HYPR(KC_3),
    KC_LALT,        KC_5,           KC_6,           KC_7,           KC_8,           HYPR(KC_B),            HYPR(KC_E),     KC_LEFT,        KC_DOWN,        KC_RIGHT,       XXXXXXX,         HYPR(KC_4),
    _______,        KC_J,           KC_K,           KC_9,           KC_0,           HYPR(KC_C),            HYPR(KC_F),     KC_PGDN,        XXXXXXX,        KC_END,         XXXXXXX,         _______,
                                                                       _______,        _______,        _______,        _______
  ),
  [_RAISE] = LAYOUT_voyager(
    _______,        _______,        _______,        _______,        _______,        _______,               _______,        _______,        _______,        _______,        _______,         _______,
    HYPR(KC_5),     KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,               KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_DQUO,        KC_QUOTE,        HYPR(KC_7),
    HYPR(KC_6),     KC_TILD,        KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_PLUS,               KC_EQL,         KC_LCBR,        KC_RCBR,        KC_MINS,        KC_COLN,         HYPR(KC_8),
    _______,        KC_GRV,         KC_PIPE,        KC_LBRC,        KC_RBRC,        ARING,                 XXXXXXX,        KC_BSLS,        KC_LT,          KC_GT,          KC_QUES,         _______,
                                                                      _______,        _______,         KC_BSPC,        KC_DEL
  ),
  [_ADJ] = LAYOUT_voyager(
    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,               XXXXXXX,        LED_LEVEL,      RGB_VAD,        RGB_VAI,        XXXXXXX,         QK_BOOT,
    XXXXXXX,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          XXXXXXX,               XXXXXXX,        XXXXXXX,        KC_MS_U,        XXXXXXX,        XXXXXXX,         XXXXXXX,
    XXXXXXX,        KC_F5,          KC_F6,          KC_F7,          KC_F8,          XXXXXXX,               XXXXXXX,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_WH_U,         XXXXXXX,
    XXXXXXX,        KC_F9,          KC_F10,         KC_F11,         KC_F12,         XXXXXXX,               XXXXXXX,        KC_BTN1,        KC_BTN3,        KC_BTN2,        KC_WH_D,         XXXXXXX,
                                                                      XXXXXXX,        XXXXXXX,         XXXXXXX,        XXXXXXX
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_BASE] = {
        {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},   {140, 255, 64},
        {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},   {140, 255, 64},
        {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 255},  {140, 255, 64},
        {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},   {140, 255, 64},
                                                                                 {140, 255, 64},   {140, 255, 64},

           {140, 255, 64},  {140, 255, 64},   {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},
           {140, 255, 64},  {140, 255, 64},   {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},
           {140, 255, 64},  {140, 255, 255},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},
           {140, 255, 64},  {140, 255, 64},   {140, 255, 64},  {140, 255, 64},  {140, 255, 64},  {140, 255, 64},
        {140, 255, 64},  {140, 255, 64}
    },
    [_GAME] = {
        {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},   {11,  255, 64},
        {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},   {11,  255, 64},
        {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 255},  {11,  255, 64},
        {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},   {11,  255, 64},
                                                                                 {11,  255, 64},   {11,  255, 64},

           {11,  255, 64},  {11,  255, 64},   {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},
           {11,  255, 64},  {11,  255, 64},   {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},
           {11,  255, 64},  {11,  255, 255},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},
           {11,  255, 64},  {11,  255, 64},   {11,  255, 64},  {11,  255, 64},  {11,  255, 64},  {11,  255, 64},
        {11,  255, 64},  {11,  255, 64}
    },
    [_LOWER] = {
        {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},   {40,  255, 64},
        {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},   {40,  255, 64},
        {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 255},  {40,  255, 64},
        {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},   {40,  255, 64},
                                                                                 {40,  255, 64},   {40,  255, 64},

           {40,  255, 64},  {40,  255, 64},   {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},
           {40,  255, 64},  {40,  255, 64},   {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},
           {40,  255, 64},  {40,  255, 255},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},
           {40,  255, 64},  {40,  255, 64},   {40,  255, 64},  {40,  255, 64},  {40,  255, 64},  {40,  255, 64},
        {40,  255, 64},  {40,  255, 64}
    },
    [_RAISE] = {
        {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},   {210, 255, 64},
        {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},   {210, 255, 64},
        {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 255},  {210, 255, 64},
        {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},   {210, 255, 64},
                                                                                 {210, 255, 64},   {210, 255, 64},

           {210, 255, 64},  {210, 255, 64},   {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},
           {210, 255, 64},  {210, 255, 64},   {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},
           {210, 255, 64},  {210, 255, 255},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},
           {210, 255, 64},  {210, 255, 64},   {210, 255, 64},  {210, 255, 64},  {210, 255, 64},  {210, 255, 64},
        {210, 255, 64},  {210, 255, 64}
    },
    [_ADJ] = {
        {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},   {90,  255, 64},
        {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},   {90,  255, 64},
        {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 255},  {90,  255, 64},
        {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},   {90,  255, 64},
                                                                                 {90,  255, 64},   {90,  255, 64},

           {90,  255, 64},  {90,  255, 64},   {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},
           {90,  255, 64},  {90,  255, 64},   {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},
           {90,  255, 64},  {90,  255, 255},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},
           {90,  255, 64},  {90,  255, 64},   {90,  255, 64},  {90,  255, 64},  {90,  255, 64},  {90,  255, 64},
        {90,  255, 64},  {90,  255, 64}
    },
};

// uint8_t layer_state_set_user(uint8_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJ);
// }

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  set_layer_color(biton32(layer_state));
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case SE_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}
