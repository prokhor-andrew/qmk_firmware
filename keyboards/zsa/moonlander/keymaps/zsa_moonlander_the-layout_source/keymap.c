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
    // row 0 — empty
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                               KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,
    // row 1 — app launchers left: teams teleg term | right: brwsr notes settings
    KC_NO, HYPR(KC_T), HYPR(KC_G), HYPR(KC_I), KC_NO, KC_NO, KC_NO,                               KC_NO, KC_NO, KC_NO, HYPR(KC_B),   HYPR(KC_N),   HYPR(KC_S),   KC_NO,
    // row 2 — window nav left: mctl-up lwind close open rwind | right: ltab otab ctab rtab mctl-dn
    KC_NO, LCTL(KC_UP), HYPR(KC_LEFT), LGUI(KC_W), LGUI(KC_N), HYPR(KC_RIGHT), KC_NO,                             KC_NO, LSFT(LGUI(KC_LBRC)), LGUI(KC_T), LGUI(KC_W), LSFT(LGUI(KC_RBRC)), LCTL(KC_DOWN), KC_NO,
    // row 3 — left: spread resize-l resize-t resize-b resize-r | right: move-l move-b move-t move-r unite
    KC_NO, HYPR(KC_O), HYPR(KC_H), HYPR(KC_K), HYPR(KC_J), HYPR(KC_L),                            KC_NO, HYPR(KC_A), HYPR(KC_Z), HYPR(KC_W), HYPR(KC_D), HYPR(KC_P),
    // row 4 — left: search hide | right: show-win jmp-search
    KC_NO, KC_NO, KC_NO, LGUI(KC_SPC), LGUI(KC_H), KC_NO,                                                         KC_NO, HYPR(KC_V), LGUI(KC_G), KC_NO, KC_NO, KC_NO,
    // thumbs
    KC_NO, KC_NO, KC_NO,                                                                            KC_NO, KC_NO, TO(1)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_LBRC,                                        KC_RBRC,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    LT(2, KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_GRAVE,                                                                       KC_QUOTE,       KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        LT(2, KC_TAB),
    OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSM(MOD_RSFT),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_ENTER,       OSM(MOD_RGUI),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_DLR,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_CIRC,        KC_PERC,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HASH,        KC_AMPR,        KC_PLUS,        KC_ASTR,        KC_EXLM,                                        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_PIPE,        KC_AT,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_ENTER,       OSM(MOD_RGUI),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
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
