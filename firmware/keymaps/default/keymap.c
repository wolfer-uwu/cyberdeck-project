#include QMK_KEYBOARD_H
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_6x10(
        KC_0,    KC_9,    KC_8,    KC_7,    KC_6,    KC_5,    KC_4,    KC_3,    KC_2,     KC_1,
        KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_T,    KC_R,    KC_E,    KC_W,     KC_Q,
        KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_D,    KC_S,     KC_A,
        KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_B,    KC_V,    KC_C,    KC_X,     KC_Z,
        KC_ENT,  KC_MINS, KC_TAB,  KC_BSPC, MO(1),   KC_SPC,  KC_LALT, KC_LSFT, KC_LCTL,  KC_ESC,
        KC_J,    KC_I,    KC_H,    KC_G,    KC_F,    KC_E,    KC_D,    KC_C,    MS_BTN2,  MS_BTN1
    ),
    [1] = LAYOUT_6x10(
        KC_F10,  KC_F9,   KC_F8,   KC_F7,   KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,    KC_F1,
        KC_RBRC, KC_LBRC, KC_INS,  KC_U,    KC_Y,    KC_T,    KC_R,    KC_PGDN, KC_UP,    KC_PGUP,
        KC_SCLN, KC_PSCR, KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_RGHT, KC_DOWN,  KC_LEFT,
        KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_B,    KC_V,    KC_C,    KC_END,   KC_HOME,
        KC_QUOTE, KC_EQL, KC_TAB,  KC_DEL,  KC_TRNS, KC_SPC,  KC_RALT, KC_RSFT, KC_RCTL,  KC_ESC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN2,  MS_BTN1
    )
};
