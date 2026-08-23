#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  OS_GUI,
  OS_CTSF,
  OS_CSA,
  SCR_UP,
  SCR_DN,
};

// Flick-scroll: each tap of SCR_UP/SCR_DN adds a velocity impulse (kick) in
// that direction, on top of whatever velocity is already there. Velocity
// decays every tick (friction), producing a throw that gradually slows to a
// stop instead of cutting off. Tapping the same direction again stacks more
// speed on top of the current glide; tapping the opposite direction cancels
// velocity out and can reverse the scroll.
#define SCROLL_KICK         27.0f // velocity (notches/sec) added by the first tap
#define SCROLL_STACK_FACTOR  0.35f // extra taps in the same direction add only this fraction of a kick
#define SCROLL_MAX_VEL      85.0f // clamp on stacked velocity
#define SCROLL_MIN_VEL        3.0f // below this, snap to a full stop (avoids a draggy slow trickle)
#define SCROLL_DECAY_PER_TICK 0.975f // multiplicative friction each tick (~0.5s glide from one tap)
#define SCROLL_TICK_MS 8 // 125Hz: quicker first notch, finer decay resolution

static float    scroll_velocity = 0.0f; // signed, notches/sec
static float    scroll_accum    = 0.0f; // fractional notch carry
static uint16_t scroll_timer    = 0;

void matrix_scan_user(void) {
  if (scroll_velocity == 0.0f) return;
  if (timer_elapsed(scroll_timer) < SCROLL_TICK_MS) return;
  scroll_timer = timer_read();

  scroll_accum += scroll_velocity * (SCROLL_TICK_MS / 1000.0f);
  int16_t notches = (int16_t)scroll_accum; // truncate toward zero
  if (notches != 0) {
    scroll_accum -= notches;
    report_mouse_t report = {0};
    report.v = notches;
    host_mouse_send(&report);
  }

  scroll_velocity *= SCROLL_DECAY_PER_TICK;
  if (scroll_velocity < SCROLL_MIN_VEL && scroll_velocity > -SCROLL_MIN_VEL) {
    scroll_velocity = 0.0f;
    scroll_accum    = 0.0f;
  }
}

static void scroll_kick(float amount) {
  bool same_dir = (scroll_velocity > 0 && amount > 0) || (scroll_velocity < 0 && amount < 0);
  scroll_velocity += same_dir ? (amount * SCROLL_STACK_FACTOR) : amount;
  if (scroll_velocity > SCROLL_MAX_VEL) scroll_velocity = SCROLL_MAX_VEL;
  if (scroll_velocity < -SCROLL_MAX_VEL) scroll_velocity = -SCROLL_MAX_VEL;
  scroll_timer = timer_read();
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    MO(2),          KC_TRANSPARENT, OSM(MOD_LALT), OSM(MOD_LCTL), KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  OSM(MOD_RCTL), OSM(MOD_RALT),  KC_TRANSPARENT, KC_TRANSPARENT,
    OS_GUI,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           OS_GUI,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_GRAVE,                                                                       KC_QUOT,        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        OSM(MOD_HYPR),
    OSM(MOD_LSFT),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSM(MOD_RSFT),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       CW_TOGG,                                                                                               LGUI(KC_SPACE), KC_ENTER,       KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    OSL(1),         OSL(3),         MO(4),                          MO(4),          OSL(3),         OSL(1)
  ),

  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_LALT), OSM(MOD_LCTL), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSM(MOD_RCTL), OSM(MOD_RALT),  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_EQUAL,       KC_LCBR,        KC_RCBR,        KC_BSLS,        KC_DLR,         KC_TRANSPARENT,
    KC_ESCAPE,      KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MINUS,       KC_LPRN,        KC_RPRN,        KC_CIRC,        KC_PERC,        OSM(MOD_HYPR),
    OS_GUI,         KC_HASH,        KC_AMPR,        KC_PLUS,        KC_ASTR,        KC_EXLM,                                        KC_UNDS,        KC_LBRC,        KC_RBRC,        KC_PIPE,        KC_AT,          OS_GUI,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_ENTER,       KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BRIU,        KC_BRID,        LGUI(LSFT(KC_3)),                               KC_MUTE,        KC_VOLD,        KC_VOLU,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LCTL(KC_Q)),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OS_CSA,         OS_CTSF,        KC_TRANSPARENT, KC_TRANSPARENT,                                                     KC_TRANSPARENT, KC_TRANSPARENT, OS_CTSF,        OS_CSA,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_Z,                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  // Mouse testing layer (hold either inner thumb key from layer 0 to activate).
  // Right hand home row = vim-style cursor movement (H/J/K/L = left/down/up/right, diagonals free).
  // Left hand WASD = scroll (W/A/S/D = up/left/down/right).
  // Both thumb clusters = click buttons 1/2/3.
  // Row 1 = instant speed-override keys: hold ACL0 for slow/precise, ACL2 for fast, ACL1 for medium.
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, MS_ACL0,        MS_ACL1,        MS_ACL2,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, MS_ACL0,        MS_ACL1,        MS_ACL2,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, SCR_UP,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MS_WHLL,        SCR_DN,         MS_WHLR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, MS_LEFT,        MS_DOWN,        MS_UP,          MS_RGHT,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MS_BTN1,        MS_BTN2,        MS_BTN3,                                                                                               KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MS_BTN1,        MS_BTN2,        MS_BTN3,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};


void matrix_init_user(void) {
    oneshot_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OS_GUI:
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LGUI);
      }
      return false;

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

    case SCR_UP:
      if (record->event.pressed) {
        scroll_kick(SCROLL_KICK);
      }
      return false;

    case SCR_DN:
      if (record->event.pressed) {
        scroll_kick(-SCROLL_KICK);
      }
      return false;

  }
  return true;
}
