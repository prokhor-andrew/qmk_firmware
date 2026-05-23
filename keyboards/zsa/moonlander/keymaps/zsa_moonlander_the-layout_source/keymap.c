#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_SPACE), OSM(MOD_RCTL),  OSL(3),          KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, OSL(3),          OSM(MOD_RCTL),  OSM(MOD_LGUI),  KC_TRANSPARENT, KC_TRANSPARENT,
    OSM(MOD_LALT),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           OSM(MOD_RALT),
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_GRAVE,                                                                       KC_QUOTE,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        OSM(MOD_HYPR),
    OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSM(MOD_RSFT),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       LGUI(LSFT(KC_3)),                                                                                               LGUI(KC_SPACE), KC_ENTER,       KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    OSL(1),         KC_NO,          MO(2),                          MO(2),          KC_NO,          OSL(1)
  ),

  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RCTL),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RCTL),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    OSM(MOD_LALT),  KC_0,           KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_DLR,         OSM(MOD_RALT),
    KC_ESCAPE,      KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_CIRC,        KC_PERC,        OSM(MOD_HYPR),
    OSM(MOD_LSFT),  KC_HASH,        KC_AMPR,        KC_PLUS,        KC_ASTR,        KC_EXLM,                                        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_PIPE,        KC_AT,          OSM(MOD_RSFT),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_ENTER,       KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIU,        KC_BRID,        LCTL(LGUI(KC_T)),                               KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_QUOTE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_RBRC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};


void matrix_init_user(void) {
    oneshot_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_1 ... KC_0:
      if (record->event.pressed && (get_mods() & MOD_MASK_SHIFT)) {
        uint8_t saved = get_mods();
        del_mods(MOD_MASK_SHIFT);
        tap_code(keycode);
        set_mods(saved);
        return false;
      }
      return true;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;

  }
  return true;
}
