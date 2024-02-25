#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "i18n.h"

enum planck_keycodes {
    RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA,
    _GAMING,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define HYPER(KEY) LALT(LGUI(LCTL(LSFT(KEY))))
#define SLEEP KC_SYSTEM_SLEEP
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK
#define PAUSE KC_MEDIA_PLAY_PAUSE

enum {
    TD_ESC_Q,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_planck_grid(
        XXXXXXX,        TD(TD_ESC_Q),   KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_ADIA,
        KC_TAB,         LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,           KC_H,           LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),   SE_SCLN,        SE_OSLH,
        XXXXXXX,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_SLSH,        XXXXXXX,
        CW_TOGG,        XXXXXXX,        XXXXXXX,        XXXXXXX,        RAISE,          KC_SPACE,       XXXXXXX,        LOWER,          XXXXXXX,        XXXXXXX,        MO(_EXTRA),     KC_ENTER),

    [_LOWER] = LAYOUT_planck_grid(
        HYPER(KC_1),    KC_1,           KC_2,           KC_3,           KC_4,           HYPER(KC_A),    HYPER(KC_D),    KC_PAGE_UP,     KC_UP,          KC_HOME,        KC_SCRL,        HYPER(KC_3),
        HYPER(KC_2),    KC_5,           KC_6,           KC_7,           KC_8,           HYPER(KC_B),    HYPER(KC_E),    KC_LEFT,        KC_DOWN,        KC_RIGHT,       XXXXXXX,        HYPER(KC_4),
        _______,        KC_J,           KC_K,           KC_9,           KC_0,           HYPER(KC_C),    HYPER(KC_F),    KC_PGDN,        XXXXXXX,        KC_END,         XXXXXXX,        _______,
        _______,        _______,        _______,        _______,        _______,        KC_BSPC,        XXXXXXX,        _______,        _______,        _______,        _______,        _______),

    [_RAISE] = LAYOUT_planck_grid(
        HYPER(KC_5),    KC_EXLM,        SE_AT,          KC_HASH,        SE_DLR,         KC_PERC,        SE_CIRC,        SE_AMPR,        SE_ASTR,        SE_DQUO,        SE_APOS,        HYPER(KC_7),
        HYPER(KC_6),    SE_TILD,        SE_UNDS,        SE_LPRN,        SE_RPRN,        SE_PLUS,        SE_EQL,         SE_LCBR,        SE_RCBR,        SE_MINS,        SE_COLN,        HYPER(KC_8),
        _______,        SE_GRV,         SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_AA,          SE_SECT,        SE_BSLS,        SE_LESS,        SE_GRTR,        SE_QUES,        _______,
        _______,        _______,        _______,        _______,        _______,        KC_DELETE,      XXXXXXX,        _______,        _______,        _______,        _______,        _______),

    [_ADJUST] = LAYOUT_planck_grid(
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MS_UP,       XXXXXXX,        XXXXXXX,        _______,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_UP,    _______,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_WH_DOWN,  _______,
        _______,        _______,        _______,        _______,        _______,        _______,        XXXXXXX,        _______,        _______,        _______,        _______,        _______),

    [_EXTRA] = LAYOUT_planck_grid(
        _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          XXXXXXX,        TG(_GAMING),    XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        QK_BOOT,
        _______,        KC_F5,          KC_F6,          KC_F7,          KC_F8,          XXXXXXX,        LED_LEVEL,      XXXXXXX,        RGB_VAD,        RGB_VAI,        XXXXXXX,        _______,
        _______,        KC_F9,          KC_F10,         KC_F11,         KC_F12,         XXXXXXX,        XXXXXXX,        PREV_TRACK,     PAUSE,          NEXT_TRACK,     XXXXXXX,        _______,
        SLEEP,          XXXXXXX,        _______,        _______,        _______,        _______,        XXXXXXX,        _______,        _______,        _______,        _______,        _______),

    [_GAMING] = LAYOUT_planck_grid(
        KC_ESCAPE,      KC_Q,           _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        KC_A,           KC_S,           KC_D,           KC_F,           _______,        _______,        KC_J,           KC_K,           KC_L,           _______,        _______,
        KC_LEFT_SHIFT,  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        KC_RIGHT_SHIFT,
        _______,        KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   LOWER,          _______,        XXXXXXX,        RAISE,          KC_LEFT_CTRL,   KC_LEFT_ALT,    _______,        _______),

};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
        {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},   {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},
        {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 255},  {145, 255, 64},  {145, 255, 64},  {145, 255, 255}, {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},
        {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},   {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},
        {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},           {145, 255, 64},           {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64},  {145, 255, 64}
        },

    [1] = {
        {188, 255, 255}, {0, 247, 235},   {31, 255, 255},  {0, 247, 235},   {31, 255, 255},   {188, 255, 255}, {188, 255, 255}, {154, 255, 255}, {105, 255, 255}, {35, 255, 255},  {236, 213, 203}, {188, 255, 255},
        {188, 255, 255}, {0, 247, 235},   {31, 255, 255},  {0, 247, 235},   {31, 255, 255},   {188, 255, 255}, {188, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {0, 0, 0},       {188, 255, 255},
        {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 247, 235},   {31, 255, 255},   {188, 255, 255}, {188, 255, 255}, {154, 255, 255}, {0, 0, 0},       {35, 255, 255},  {0, 0, 0},       {0, 0, 0},
        {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},                  {0, 0, 0},              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}
        },

    [2] = {
        {188, 255, 255}, {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},   {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {188, 255, 255},
        {188, 255, 255}, {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},   {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {188, 255, 255},
        {0, 0, 0},       {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},   {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {105, 255, 255}, {14, 255, 255},  {0, 0, 0},
        {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},                  {0, 0, 0},              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}
        },

    [3] = {
        {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},           {0,0,0},         {0,0,0},        {0,0,0},         {14,255,255},    {0,0,0},        {0,0,0},         {0,0,0},
        {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},           {0,0,0},         {0,0,0},        {14,255,255},    {14,255,255},    {14,255,255},   {249,228,255},   {0,0,0},
        {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},           {0,0,0},         {0,0,0},        {105,255,255},   {105,255,255},   {105,255,255},  {249,228,255},   {0,0,0},
        {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},         {0,0,0},                     {0,0,0},               {0,0,0},         {0,0,0},         {0,0,0},        {0,0,0},         {0,0,0}
        },

    [4] = {
        {0, 0, 0},       {33, 255, 255},  {30, 96, 255},   {33, 255, 255},  {30, 96, 255},    {0, 0, 0},       {74, 255, 255},  {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {141, 255, 233},
        {0, 0, 0},       {33, 255, 255},  {30, 96, 255},   {33, 255, 255},  {30, 96, 255},    {0, 0, 0},       {0, 205, 155},   {0, 0, 0},       {105, 255, 255}, {105, 255, 255}, {0, 0, 0},       {205, 255, 255},
        {0, 0, 0},       {33, 255, 255},  {30, 96, 255},   {33, 255, 255},  {30, 96, 255},    {0, 0, 0},       {0, 0, 0},       {14, 255, 255},  {14, 255, 255},  {14, 255, 255},  {0, 0, 0},       {0, 0, 0},
        {188, 255, 255}, {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},                  {0, 0, 0},              {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0},       {0, 0, 0}
        },

    [5] = {
        {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},    {93, 208, 71},   {74, 255, 255},  {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},
        {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},    {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},
        {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},    {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},
        {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {93, 208, 71},            {93, 208, 71},            {93, 208, 71},   {93, 208, 71},   {93, 208, 71},   {74, 255, 255},  {93, 208, 71}
        },

};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return false;
    }
    if (keyboard_config.disable_layer_led) {
        return false;
    }
    switch (biton32(layer_state)) {
        case 0:
            set_layer_color(0);
            break;
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_SLD:
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
