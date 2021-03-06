#include QMK_KEYBOARD_H

#define BASE 0
#define FN 1
#define NUM 2
#define RGB 3
#define RGB_SH 4


/*
 * Default HHKB Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_60_hhkb(
      KC_LGUI,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, MT(MOD_RGUI, KC_GRV),
      LT(FN, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, TT(FN),
      KC_LCTRL, KC_LALT,                   KC_SPACE,                 KC_RALT, KC_RCTRL
      ),

  [FN] = LAYOUT_60_hhkb(
      KC_POWER,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______ , _______,
      _______, KC_BRID, KC_BRIU, _______, TG(RGB), _______, _______, KC_PGUP, _______, _______, KC_PAUSE, _______, _______, KC_DEL,
      KC_CAPS, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT  ,_______, _______, _______,
      _______, _______, _______, _______, _______, _______, TG(NUM), KC_PGDN,  _______, _______,   _______, _______, _______,
      _______, _______,                   _______,                   _______, _______
      ),
  [NUM] = LAYOUT_60_hhkb(
      _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,   KC_9,   KC_PPLS,   _______,   _______,   _______,   _______,
      _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,   KC_6, KC_PMNS, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,   KC_3, KC_PAST, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_PEQL,   KC_0,   KC_DOT, KC_PSLS, _______, _______,
      _______, _______,                   _______,                   _______, _______
      ),
  [RGB] = LAYOUT_60_hhkb(
      RGB_TOG, RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS, RGB_MODE_GRADIENT, RGB_MODE_RGBTEST,   _______,   _______,   _______,   _______,   _______,
      _______, _______, _______, _______, _______, _______, _______, UC_MOD,    _______,   _______, _______, _______, _______, _______,
      _______, _______, RGB_SAI, _______, _______, _______, RGB_HUI, _______, _______,    _______,   _______, _______, _______,
      MO(4), _______, _______, _______, RGB_VAI, _______, _______, _______,   _______,   _______, _______, MO(4), _______,
      RESET, _______,                   _______,                   _______, _______
      ),
  [RGB_SH] = LAYOUT_60_hhkb(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______,   _______,   _______,   _______,
      _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______, _______, _______, _______, _______,
      _______, _______, RGB_SAD, _______, _______, _______, RGB_HUD, _______, _______,    _______,   _______, _______, _______,
      _______, _______, _______, _______, RGB_VAD, _______, _______, _______,   _______,   _______, _______, _______, _______,
      _______, _______,                   _______,                   _______, _______
      )
};


