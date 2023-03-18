#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_brazilian_abnt2.h"

#define QWERTY 0 // qwerty for the faint of heart
#define DONTQY 1 // ex-default layer

#define SYMBOL 2 // symbols
#define ANALOG 3 // media & mouse keys

#define BR_NDCR LALT(BR_CIRC)  // Non-dead key circumflex accent   ^   alt+^ (alt+shift+~)
#define BR_NDTD LALT(BR_TILD)  // Non-dead key tilde               ~   alt+~


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT_ergodox(
        // left hand
                          KC_ESC,                   KC_1,               KC_2,    KC_3,    KC_4,   KC_5,   KC_CAPS,
                          KC_TAB,                   KC_Q,               KC_W,    KC_E,    KC_R,   KC_T,   KC_EXLM,
                          LT(SYMBOL,BR_QUOT),       KC_A,               KC_S,    KC_D,    KC_F,   KC_G,
                          KC_LSFT,                  KC_Z,               KC_X,    KC_C,    KC_V,   KC_B,   KC_MINS,
                          KC_LGUI,                  BR_BSLS,            BR_COLN, KC_LEFT, KC_RGHT,
                                                                                                                  KC_PGUP,  KC_HYPR,
                                                                                                                            KC_PGDN,
                                                                                                         KC_ENT,  KC_LCTL,  KC_DEL,
        // right hand
                          TO(DONTQY),               KC_6,               KC_7,    KC_8,    KC_9,    KC_0,                _______,
                          BR_QUES,                  KC_Y,               KC_U,    KC_I,    KC_O,    KC_P,                BR_ACUT,
                                                    KC_H,               KC_J,    KC_K,    KC_L,    LT(ANALOG, BR_CCED), LT(SYMBOL,BR_TILD),
                          KC_UNDS,                  KC_N,               KC_M,    KC_COMM, KC_DOT,  BR_SCLN,             KC_RSFT,
                                                                        KC_DOWN, KC_UP,   KC_EQL,  BR_SLSH,             KC_RGUI,
            KC_MEH, KC_END,
            KC_HOME,
            KC_BSPC,KC_LALT, KC_SPC
    ),

[DONTQY] = LAYOUT_ergodox(  // layer 0 : default
                            // left hand
                            KC_ESC,              KC_1,               KC_2,    KC_3,    KC_4,   KC_5,   _______,
                            KC_TAB,              KC_X,               KC_Y,    KC_O,    KC_U,   KC_J,   KC_EXLM,
                            LT(SYMBOL,BR_QUOT),  KC_C,               KC_I,    KC_E,    KC_A,   KC_K,
                            KC_LSFT,             LT(ANALOG,BR_CCED), KC_V,    KC_L,    KC_H,   KC_Z,   KC_MINS,
                            KC_LGUI,             BR_BSLS,            BR_COLN, KC_LEFT, KC_RGHT,
                                                                                                               KC_PGUP,  KC_HYPR,
                                                                                                                         KC_PGDN,
                                                                                                      KC_ENT,  KC_LCTL,  KC_DEL,
        // right hand
                        TO(QWERTY),     KC_6,         KC_7,   KC_8,   KC_9,   KC_0,   _______,
                        BR_QUES,        BR_SCLN,      KC_F,   KC_D,   KC_W,   KC_Q,   BR_ACUT,
                                        KC_COMM,      KC_N,   KC_T,   KC_S,   KC_P,   LT(SYMBOL,BR_TILD),
                        KC_UNDS,        KC_DOT,       KC_R,   KC_M,   KC_G,   KC_B,   KC_RSFT,
                                                      KC_DOWN,KC_UP,  KC_EQL, BR_SLSH,KC_RGUI,
             KC_MEH, KC_END,
             KC_HOME,
             KC_BSPC,KC_LALT, KC_SPC
    ),

[SYMBOL] = LAYOUT_ergodox(
       // left hand
       _______,KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  _______,
       _______,KC_ASTR, KC_HASH,BR_LBRC,BR_RBRC,BR_PIPE,_______,
       _______,KC_AT,   KC_DLR, KC_LPRN,KC_RPRN,SAGR(BR_TILD),
       _______,KC_EXLM, KC_AMPR,BR_LCBR,BR_RCBR,ALGR(BR_TILD),_______,
       _______,KC_MINUS,KC_EQL, KC_LABK,KC_RABK,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_PERC, KC_7,   KC_8,    KC_9,    KC_KP_MINUS,KC_F12,
                KC_COMMA,KC_4,   KC_5,    KC_6,    KC_KP_ASTERISK,_______,
       _______, KC_DOT,  KC_1,   KC_2,    KC_3,    KC_KP_PLUS, _______,
                         KC_0,   KC_DOT,  KC_EQUAL,KC_KP_SLASH,_______,
       _______, _______,
       _______,
       _______, _______,_______
),

[ANALOG] = LAYOUT_ergodox(
       _______, _______, _______, _______, KC_PSCR, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, NK_TOGG, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, QK_BOOTLOADER,
       _______,  _______, KC_WH_U, KC_WH_D, _______, _______, _______,
                 _______, KC_BTN1, KC_BTN2, _______, _______, _______,
       _______,  _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
