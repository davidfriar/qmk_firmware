#include QMK_KEYBOARD_H

#define BASE 0
#define NUM 1
#define SYM 2
#define SETTINGS 3

/*
 * Default Layout
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_default(
        KC_ESC  , KC_Q , KC_W , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I    , KC_O   , KC_P    , KC_QUOT , KC_BSPC , \
        KC_TAB  , KC_A , KC_S , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K    , KC_L   , KC_SCLN , KC_ENT           , \
        KC_LSPO , KC_Z , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT , KC_SLSH , KC_RSPC , \
                  KC_LCTL, KC_LALT, MO(SYM), KC_LGUI,         KC_SPC, MO(NUM), KC_RALT, KC_RCTL
      ),
[NUM] = LAYOUT_default(
       _______ , KC_1    , KC_2    , KC_3    , KC_4   , KC_5  , KC_6    , KC_7    , KC_8  , KC_9     , KC_0   , _______ , KC_DEL , \
       _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END , KC_NO , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT , KC_NO  , _______ , \
       _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4  , KC_F5 , KC_F6   , KC_F7   , KC_F8 , KC_F9    , KC_F10 , _______ , \
                 _______,  _______,  MO(SETTINGS),  _______,         _______,  _______,  _______, _______
      ),
[SYM] = LAYOUT_default(
        _______ , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , _______ , KC_DEL , \
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_TILD , KC_MINS , KC_PLUS , KC_PIPE , KC_LCBR , KC_RCBR , _______ , \
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_GRV  , KC_UNDS , KC_EQL  , KC_BSLS , KC_LBRC , KC_RBRC , _______ , \
                  _______,  _______,  _______,  _______,            _______,  MO(SETTINGS),  _______,  _______
      ),
[SETTINGS] = LAYOUT_default(
        _______ , RESET   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , OUT_USB   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , \
        _______ , OUT_AUTO, KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , \
        _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , OUT_BT  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , \
                  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______
      ),
};


