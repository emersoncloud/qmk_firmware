#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _WINDOWS 1
#define _GAMING 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _MOUSE 6

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  WINDOWS,
  GAMING,
  LOWER,
  RAISE,
  ADJUST,
  MOUSE,
  BACKLIT,
  RGBRST,
  CMDSFT_T,
  CMDSFT_F,
  CMDSFT_R,
  CMDSFT_GRV
};

// enum combos {
//   JK_ESC
// };


// enum {
//   TD_C_S = 0
// };

// //Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for Esc, twice for Caps Lock
//   [TD_C_S]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLON)
// // Other declarations would go here, separated by commas, if you have them
// };

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [JK_ESC] = COMBO(jk_combo, KC_ESC),
// };

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LGUI,  KC_LSFT,    RAISE, KC_SPC, KC_ENT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_WINDOWS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LCTL,  KC_LSFT,    RAISE, KC_SPC, KC_ENT \
                                      //--------------------------'  --------------------------'
  ),

  [_GAMING] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, LOWER,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  KC_SPC,  KC_LCTL,    RAISE, KC_SPC, KC_ENT \
                                      //--------------------------'  --------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                 KC_MINS, KC_EQL, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LGUI,  KC_LSFT,    RAISE, KC_SPC, KC_ENT \
                                      //`--------------------------'  `--------------------------'
    ),



  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CMDSFT_GRV,  KC_1,    KC_2,   KC_3, CMDSFT_R, CMDSFT_T,                       KC_6,     KC_7,     KC_8,     KC_9,    KC_0, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1,   KC_2,     KC_3,     KC_4, CMDSFT_F, XXXXXXX,                      KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LGUI,  KC_LSFT,    RAISE, KC_SPC, KC_ENT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC__VOLDOWN, KC__VOLUP, KC_END, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,\

  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LGUI,  KC_LSFT,    RAISE, KC_SPC, KC_ENT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LOWER,  KC_LGUI,  KC_LSFT,    KC_MS_BTN1, KC_MS_BTN2, KC_ENT \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Sett\ing ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
const char *read_emerson_logo(void);
const char *read_qmk_logo(void);
const char *read_timelog(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_qmk_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case CMDSFT_T:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_T));
        } else {
            SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LSFT));
        }
        break;
    case CMDSFT_F:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_F));
        } else {
            SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LSFT));
        }
        break;
    case CMDSFT_R:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LSFT)SS_TAP(X_R));
        } else {
            SEND_STRING(SS_UP(X_LGUI)SS_UP(X_LSFT));
        }
        break;
    case CMDSFT_GRV:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_GRV));
        } else {
            SEND_STRING(SS_UP(X_LGUI));
        }
        break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
    case WINDOWS:
        if (record->event.pressed) {
          layer_on(_WINDOWS);
        } else {
          layer_off(_WINDOWS);
        }
        return false;
    case MOUSE:
        if (record->event.pressed) {
          layer_on(_MOUSE);
        } else {
          layer_off(_MOUSE);
        }
        return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
