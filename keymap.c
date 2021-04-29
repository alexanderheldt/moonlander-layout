#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  SE_LSPO,
  SE_RSPC,
};


enum workspace_codes {
  WSPC_1,
  WSPC_2,
  WSPC_3,
  WSPC_4,
  WSPC_5,
  WSPC_6,
  WSPC_7,
  WSPC_8,
  WSPC_9,
  WSPC_0,
};

#define QWERTY 0
#define SYMBOLS 1
#define MEDIA 2
#define BSPWM 3
#define GAME 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 TO(4),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,               KC_DELETE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,               SE_AA,
    KC_ESCAPE,      LGUI_T(KC_A),   LALT_T(KC_S),   LSFT_T(KC_D),   LCTL_T(KC_F),   LT(1, KC_G),    MO(2),                                          MO(2),          LT(1, KC_H),    RCTL_T(KC_J),   RSFT_T(KC_K),   LALT_T(KC_L),   RGUI_T(SE_OSLH),    SE_ADIA,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,            KC_NO,
    MO(1),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          MO(3),                                                          MO(3),                          KC_NO,          KC_NO,          KC_NO,          KC_NO,              MO(1),
                                                                    KC_BSPACE,      KC_ENTER,       KC_PGDOWN,                                      KC_PGUP,        KC_ENTER,       KC_SPACE
  ),
  [SYMBOLS] = LAYOUT_moonlander(
    SE_TILD,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_EXLM,        SE_AT,          SE_LCBR,        SE_RCBR,        SE_EQL,         KC_TRANSPARENT,                                 KC_TRANSPARENT, SE_PLUS,        SE_MINS,        SE_ASTR,        SE_BSLS,        SE_QUES,        KC_F12,
    KC_ESCAPE,      KC_HASH,        SE_DLR,         SE_LPRN,        SE_RPRN,        SE_GRV,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,
    KC_TRANSPARENT, SE_AMPR,        SE_PIPE,        SE_LBRC,        SE_RBRC,        SE_SLSH,                                                                        SE_APOS,        SE_DQUO,        SE_SCLN,        SE_COLN,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC,        SE_CIRC,        SE_LESS,        SE_GRTR,                        KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_NO,          KC_NO,          KC_NO,          KC_LCTRL,       KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [MEDIA] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,     LGUI(KC_PSCREEN),       LGUI(LSFT(KC_PSCREEN)), LCTL(LGUI(LSFT(KC_PSCREEN))),   KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_NO,          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,              KC_NO,                  KC_NO,                  KC_NO,                          KC_NO,          WEBUSB_PAIR,
    KC_ESCAPE,      KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,              LALT(LGUI(KC_LEFT)),    LALT(LGUI(KC_DOWN)),    LALT(LGUI(KC_RIGHT)),           KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,              KC_NO,                  KC_NO,                  KC_NO,                          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_VAD,        RGB_VAI,        RGB_TOG,        TOGGLE_LAYER_COLOR,             KC_TRANSPARENT,                                 KC_TRANSPARENT,                     KC_AUDIO_VOL_DOWN,      KC_AUDIO_VOL_UP,        KC_AUDIO_MUTE,                  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_MS_BTN1,     KC_MS_BTN2,     KC_NO,                                          KC_NO,          KC_NO,              KC_NO
  ),
  [BSPWM] = LAYOUT_moonlander(
    ST_MACRO_0,     TD(WSPC_1),     TD(WSPC_2),     TD(WSPC_3),     TD(WSPC_4),     TD(WSPC_5),     KC_TRANSPARENT,                                 KC_TRANSPARENT, TD(WSPC_6),     TD(WSPC_7),     TD(WSPC_8),     TD(WSPC_9),     TD(WSPC_0),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          LCTL(KC_LGUI),  LALT(KC_LGUI),  KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_ESCAPE,      KC_NO,          KC_NO,          LSFT(KC_LGUI),  KC_LGUI,        KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_NO,          KC_NO,
    KC_TRANSPARENT, ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,
    ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_6,
                                                                    LGUI(KC_SPACE), LGUI(KC_ENTER), KC_NO,                                          KC_NO,          LGUI(KC_ENTER), LGUI(KC_SPACE)
  ),
  [GAME] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_PGUP,                                        TO(0),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSPACE,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_PGDOWN,                                      KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_DELETE,                                      KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LCTRL,       KC_NO,          KC_NO,          KC_NO,          KC_LALT,                        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,        KC_TRANSPARENT,
                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ENTER,       KC_SPACE
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {0,0,0}, {14,255,255}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {249,228,255}, {35,255,255}, {154,255,255}, {0,0,0}, {105,255,255}, {249,228,255}, {35,255,255}, {154,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {14,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {195,61,255}, {0,0,0}, {35,255,255}, {105,255,255}, {0,0,0}, {195,61,255}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {195,61,255}, {0,0,0}, {35,255,255}, {105,255,255}, {0,0,0}, {195,61,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {249,228,255}, {35,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {249,228,255}, {105,255,255}, {0,0,0}, {154,255,255}, {0,0,0}, {249,228,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {14,255,255}, {0,0,0}, {14,255,255}, {0,0,0}, {14,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {35,255,255}, {0,0,0}, {205,255,255}, {154,255,255}, {154,255,255}, {35,255,255}, {0,0,0}, {205,255,255}, {154,255,255}, {154,255,255}, {35,255,255}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {14,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {105,255,255}, {141,255,233}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
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

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_W)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_F))));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_F)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_T)));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_M)));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_X)));

    }
    break;
    case SE_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
      return false;
    case SE_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

void on_use_or_move_to_workspace_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_10_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_1_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_1));
        tap_code16(LGUI(KC_1));
        tap_code16(LGUI(KC_1));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_1));
    }
}

uint8_t dance_10_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_10_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_1)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_1))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_1)); register_code16(LGUI(KC_1));
    }
}

void use_or_move_to_workspace_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_1)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(LSFT(KC_1))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_1)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_2(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_11_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_2_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_2));
        tap_code16(LGUI(KC_2));
        tap_code16(LGUI(KC_2));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_2));
    }
}

uint8_t dance_11_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_11_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_2)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_2))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_2)); register_code16(LGUI(KC_2));
    }
}

void use_or_move_to_workspace_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_2)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_2))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_2)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_2)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_3(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_12_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_3_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_3));
        tap_code16(LGUI(KC_3));
        tap_code16(LGUI(KC_3));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_3));
    }
}

uint8_t dance_12_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_12_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_3)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_3))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_3)); register_code16(LGUI(KC_3));
    }
}

void use_or_move_to_workspace_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_3)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_3))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_3)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_3)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_4(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_13_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_4_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_4));
        tap_code16(LGUI(KC_4));
        tap_code16(LGUI(KC_4));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_4));
    }
}

uint8_t dance_13_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_13_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_4)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_4))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_4)); register_code16(LGUI(KC_4));
    }
}

void use_or_move_to_workspace_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_4)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_4))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_4)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_4)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_5(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_14_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_5_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_5));
        tap_code16(LGUI(KC_5));
        tap_code16(LGUI(KC_5));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_5));
    }
}

uint8_t dance_14_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_14_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_5)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_5))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_5)); register_code16(LGUI(KC_5));
    }
}

void use_or_move_to_workspace_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_5)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_5))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_5)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_5)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_6(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_15_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_6_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_6));
        tap_code16(LGUI(KC_6));
        tap_code16(LGUI(KC_6));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_6));
    }
}

uint8_t dance_15_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_15_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_6)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_6))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_6)); register_code16(LGUI(KC_6));
    }
}

void use_or_move_to_workspace_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_6)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_6))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_6)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_6)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_7(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_16_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_7_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_7));
        tap_code16(LGUI(KC_7));
        tap_code16(LGUI(KC_7));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_7));
    }
}

uint8_t dance_16_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_16_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_7)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_7))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_7)); register_code16(LGUI(KC_7));
    }
}

void use_or_move_to_workspace_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_7)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_7))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_7)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_7)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_8(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_17_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_8_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_8));
        tap_code16(LGUI(KC_8));
        tap_code16(LGUI(KC_8));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_8));
    }
}

uint8_t dance_17_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_17_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_8)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_8))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_8)); register_code16(LGUI(KC_8));
    }
}

void use_or_move_to_workspace_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_8)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_8))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_8)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_8)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_9(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_18_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_9_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_9));
        tap_code16(LGUI(KC_9));
        tap_code16(LGUI(KC_9));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_9));
    }
}

uint8_t dance_18_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_18_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_9)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_9))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_9)); register_code16(LGUI(KC_9));
    }
}

void use_or_move_to_workspace_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_9)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_9))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_9)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_9)); break;
    }
    dance_state.step = 0;
}
void on_use_or_move_to_workspace_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_19_dance_step(qk_tap_dance_state_t *state);
void use_or_move_to_workspace_0_finished(qk_tap_dance_state_t *state, void *user_data);
void use_or_move_to_workspace_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_use_or_move_to_workspace_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_0));
        tap_code16(LGUI(KC_0));
        tap_code16(LGUI(KC_0));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_0));
    }
}

uint8_t dance_19_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void use_or_move_to_workspace_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_19_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(LGUI(KC_0)); break;
        case DOUBLE_TAP: register_code16(LGUI(LSFT(KC_0))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_0)); register_code16(LGUI(KC_0));
    }
}

void use_or_move_to_workspace_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_0)); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_0))); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_0)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_0)); break;
    }
    dance_state.step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [WSPC_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_1, use_or_move_to_workspace_1_finished, use_or_move_to_workspace_1_reset),
    [WSPC_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_2, use_or_move_to_workspace_2_finished, use_or_move_to_workspace_2_reset),
    [WSPC_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_3, use_or_move_to_workspace_3_finished, use_or_move_to_workspace_3_reset),
    [WSPC_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_4, use_or_move_to_workspace_4_finished, use_or_move_to_workspace_4_reset),
    [WSPC_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_5, use_or_move_to_workspace_5_finished, use_or_move_to_workspace_5_reset),
    [WSPC_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_6, use_or_move_to_workspace_6_finished, use_or_move_to_workspace_6_reset),
    [WSPC_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_7, use_or_move_to_workspace_7_finished, use_or_move_to_workspace_7_reset),
    [WSPC_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_8, use_or_move_to_workspace_8_finished, use_or_move_to_workspace_8_reset),
    [WSPC_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_9, use_or_move_to_workspace_9_finished, use_or_move_to_workspace_9_reset),
    [WSPC_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_use_or_move_to_workspace_0, use_or_move_to_workspace_0_finished, use_or_move_to_workspace_0_reset),
};
