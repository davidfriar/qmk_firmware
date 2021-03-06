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
#define _LOWER 1
#define _RAISE 2
#define _SETTINGS 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SETTINGS,
  RGBRST
};

#define CMD_TAB MT(MOD_LGUI, KC_TAB)
#define CMD_BSPC MT(MOD_RGUI, KC_BSPC)
#define CMD_ENT MT(MOD_RGUI, KC_ENT)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define ALT_QUOT MT(MOD_RALT, KC_QUOT)
enum macro_keycodes {
  KC_SAMPLEMACRO,
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CMD_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  CMD_ENT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ALT_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, ALT_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSPO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   RAISE,  KC_BSPC,     KC_SPC,  LOWER,  KC_RCTL \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,_______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,                      KC_MINS, KC_PLUS, KC_PIPE, KC_LCBR, KC_RCBR,  _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,                      KC_UNDS, KC_EQL, KC_BSLS, KC_LBRC, KC_RBRC, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SETTINGS] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  RGBRST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting SETTINGS layer RGB back to default
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
/* const char *read_layer_state(void); */
const char *read_logo(void);
const char *read_num(void);
const char *read_sym(void);
const char *read_settings(void);
const char *read_querty(void);
const char *read_rgb_info(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
/* const char *read_keylog(void); */
/* const char *read_keylogs(void); */

// const char *read_mode_icon(bool swap);
 const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    switch (layer_state) {
      case 0:
        matrix_write(matrix, read_querty());
        break;
      case 2:
        matrix_write(matrix, read_num());
        break;
      case 4:
        matrix_write(matrix, read_sym());
        break;
      case 8:
      case 14:
        matrix_write(matrix, read_settings());
        break;
      default:
        matrix_write(matrix, "undefined layer" );
    }
    // If you want to change the display of OLED, you need to change here
      /* matrix_write(matrix,read_sym()); */
    /* matrix_write_ln(matrix, read_layer_state()); */
    /* matrix_write_ln(matrix, read_keylog()); */

    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
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
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _SETTINGS);
      } else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _SETTINGS);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _SETTINGS);
      } else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _SETTINGS);
      }
      return false;
    case SETTINGS:
        if (record->event.pressed) {
          layer_on(_SETTINGS);
        } else {
          layer_off(_SETTINGS);
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
