#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  OS_CTSF,
  OS_CSA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    MO(2),          KC_TRANSPARENT, OSM(MOD_LALT), OSM(MOD_LCTL), KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  OSM(MOD_RCTL), OSM(MOD_RALT),  KC_TRANSPARENT, KC_TRANSPARENT,
    OSM(MOD_LSFT),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           OSM(MOD_RSFT),
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_NO,
    KC_NO,          KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       CW_TOGG,                                                                                               LGUI(KC_SPACE), KC_ENTER,       KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    OSL(1),         OSL(3),         OSM(MOD_MEH),                   OSM(MOD_HYPR),  OSM(MOD_RGUI), KC_ESC
  ),

  [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_0,           KC_1,           KC_2,           KC_3,           KC_4,           KC_NO,                                          KC_NO,          KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_DLR,         KC_NO,
    KC_NO,          KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_NO,                                                                          KC_NO,          KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_CIRC,        KC_PERC,        KC_NO,
    KC_NO,          KC_HASH,        KC_AMPR,        KC_PLUS,        KC_ASTR,        KC_EXLM,                                        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_PIPE,        KC_AT,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                         KC_NO,          KC_QUOTE,       S(KC_QUOTE),    KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),

  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_BRIU,        KC_BRID,        KC_NO,                                          KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_NO,          KC_NO,          KC_NO,          LGUI(LCTL(KC_Q)),
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),

  [3] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          HYPR(KC_T),     KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          HYPR(KC_O),     KC_NO,          KC_NO,
    KC_NO,          HYPR(KC_A),     HYPR(KC_S),     HYPR(KC_D),     HYPR(KC_F),     KC_NO,          KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                         KC_NO,          KC_GRAVE,       S(KC_GRAVE),    KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),

};


void matrix_init_user(void) {
    oneshot_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OS_CTSF:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LCTL | MOD_LSFT);
      }
      return false;

    case OS_CSA:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LCTL | MOD_LALT | MOD_LSFT);
      }
      return false;

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
