/* Copyright 2019 %A428s%
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    RGBRST
};

//Tap Dance Declarations
enum {
  TD_MINS_GRV = 0,
  TD_CTL_PUS
};

enum macro_keycodes {
  KC_EXPN,
  KC_SHNK
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_MINS_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_GRV),
  //[TD_CTL_PUS]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_INS)
// Other declarations would go here, separated by commas, if you have them
};

#define EXPN LCTL(KC_WH_U)
#define SHRK LCTL(KC_WH_D)

#define EISU LALT(KC_GRV)
#define KC_BAR CTL_T(KC_TAB)
#define ADV_S LT(LOWER, KC_S)
#define ADV_L LT(RAISE, KC_L)
#define ALTAB LALT(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
      KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RBRC, \
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(TD_MINS_GRV), \
      KC_LCTL, KC_LGUI, KC_LALT,   EISU,    LOWER,   KC_SPC,  KC_DEL,  KC_BSPC, KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  \
    ),

  [_LOWER] = LAYOUT( \
      KC_F1,   KC_F2,      KC_F3,        KC_F4,       KC_F5,  KC_F6,                    KC_F7,   KC_F8,      KC_F9,      KC_F10,  KC_F11,  KC_F12, \
      _______, KC_EXLM,    KC_MS_UP,     KC_HASH,     KC_DLR, KC_PERC,                  KC_CIRC, KC_MS_BTN1, KC_MS_BTN2, KC_LPRN, KC_RPRN, _______, \
      ALTAB,   KC_MS_LEFT, KC_MS_DOWN,   KC_MS_RIGHT, KC_F4,  KC_F5,                    KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE, \
      _______, KC_F7,      KC_F8,        KC_F9,       KC_F10, KC_F11,                   KC_F12,  _______,    _______,    KC_HOME, KC_END,  _______, \
      _______, _______,    _______,     _______,      LOWER, _______, _______, _______, _______, RAISE,      KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  [_RAISE] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,\
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                    KC_F12,  _______, _______, KC_PGDN, KC_PGUP, _______, \
      _______, _______, _______, _______, LOWER,   _______, _______, _______, _______, RAISE,   KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
      ),

  [_ADJUST] =  LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_PAUSE, KC_F10,  KC_F11,  KC_F12, \
      _______, RESET,   RGBRST,  _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL, \
      _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM,                   AG_SWAP, _______,  _______, _______,  _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, _______, LOWER,   _______, _______, _______, _______, RAISE,   RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

#ifdef ENCODER_ENABLE
  void encoder_update_user(uint8_t index, bool clockwise) {
    // LEFT KNOB
    if (index == 0) {
    // LOWER LAYER
      if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
          tap_code(KC_TAB);
        } else {
            register_code(KC_LSFT);
            tap_code(KC_TAB);
            unregister_code(KC_LSFT);
          }
      }
  //  RAISE LAYER
      else if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
          }
      }
    // ADJUST Layer
      else if (IS_LAYER_ON(_ADJUST)) {
        if (clockwise) {
          tap_code(KC_DOWN);
        }
        else {
          tap_code(KC_UP);
        }
      }
      // DEFAULT
      else {
        if (clockwise) {
          tap_code(KC_DOWN);
        } else {
          tap_code(KC_UP);
          }
      }
    }
  // RIGHT KNOB
    else if (index == 1) {
  // LOWER LAYER
     if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
          }
      }
  //  RAISE LAYER
      else if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
          register_code(KC_LCTL);
          tap_code(KC_PMNS);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          tap_code(KC_EQL);
          unregister_code(KC_LCTL);
          }
      }
  // ADJUST Layer
     else if (IS_LAYER_ON(_ADJUST)) {
        if (clockwise) {
          tap_code(KC_SPC);
        } else {
          tap_code(KC_BSPC);
          }
      }
  // DEFAULT
      else {
        if (clockwise) {
          tap_code(KC_LEFT);
        } else {
          tap_code(KC_RGHT);
      }
      }
    }
  }
#endif


void matrix_init_user(void) {

}


void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
