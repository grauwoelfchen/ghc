#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "keymap_extras/keymap_dvorak.h"

extern keymap_config_t keymap_config;
extern uint8_t is_master;

enum layer_number {
  _DVORAK = 0,
  _LOWER,
  _RAISE
};

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE
};


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define M_SAMPLE M(KC_SAMPLEMACRO)

// HELIX_ROWS == 4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Dvorak
   * ,-----------------------------------------.               ,-----------------------------------------.
   * |      |  '   |  ,   |  .   |  P   |  Y   |               |   F  |   G  |   C  |   R  |   L  |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |  A   |  O   |  E   |  U   |  I   |               |   D  |   H  |   T  |   N  |   S  |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |  ;   |  Q   |  J   |  K   |  X   |               |   B  |   M  |   W  |   V  |   Z  |      |
   * |------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
   * |      | Esc  |      |      | Shft | Bksp | Ctrl | |  Alt | Spce | Lowr |   _  |   /  | Entr |      |
   * `------------------------------------------------- -------------------------------------------------'
   */
  [_DVORAK] = LAYOUT( \
    XXXXXXX, DV_QUOT, DV_COMM, DV_DOT,  DV_P,    DV_Y,                      DV_F,    DV_G,    DV_C,    DV_R,    DV_L,   XXXXXXX, \
    XXXXXXX, DV_A,    DV_O,    DV_E,    DV_U,    DV_I,                      DV_D,    DV_H,    DV_T,    DV_N,    DV_S,   XXXXXXX, \
    XXXXXXX, DV_SCLN, DV_Q,    DV_J,    DV_K,    DV_X,                      DV_B,    DV_M,    DV_W,    DV_V,    DV_Z,   XXXXXXX, \
    XXXXXXX, KC_ESC,  KC_TAB,  _______, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  LOWER,   DV_MINS, DV_SLSH, KC_ENT, XXXXXXX  \
  ),
  /* Lower
   * ,-----------------------------------------.               ,-----------------------------------------.
   * |      |  !   |  @   |  {   |  }   |  |   |               | Pgup |   7  |   8  |   9  |   *  |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |  #   |  $   |  (   |  )   |  `   |               | Pgdn |   4  |   5  |   6  |   +  |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |  %   |  ^   |  [   |  ]   |  ~   |               |   &  |   1  |   2  |   3  |   \  |      |
   * |------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
   * |      | Rais | Tab  |      |      |      | Ctrl | |  Alt |      | Rset |      |   0  |   =  |      |
   * `------------------------------------------------- -------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    XXXXXXX, DV_EXLM, DV_AT,   DV_LCBR, DV_RCBR, DV_PIPE,                   KC_PGUP, DV_7,    DV_8,    DV_9,    DV_ASTR, XXXXXXX, \
    XXXXXXX, DV_HASH, DV_DLR,  DV_LPRN, DV_RPRN, DV_GRV,                    KC_PGDN, DV_4,    DV_5,    DV_6,    DV_PLUS, XXXXXXX, \
    XXXXXXX, DV_PERC, DV_CIRC, DV_LBRC, DV_RBRC, DV_TILD,                   DV_AMPR, DV_1,    DV_2,    DV_3,    DV_BSLS, XXXXXXX, \
    XXXXXXX, RAISE,   KC_TAB,  _______, _______, _______, KC_LCTL, KC_LALT, _______, RESET,   _______, DV_0,    DV_EQL,  XXXXXXX  \
  ),
  /* Raise
   * ,-----------------------------------------.               ,-----------------------------------------.
   * |      |      |      |  ↑   |      |      |               |      |   F7 |   F8 |   F9 |      |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |      |  ←   |  ↓   |  →   |      |               |      |   F4 |   F5 |   F6 |      |      |
   * |------+------+------+------+------+------|               |------+------+------+------+------+------|
   * |      |      |      |      |      |      |               |      |   F1 |   F2 |   F3 |      |      |
   * |------+------+------+------+------+------+------- -------+------+------+------+------+------+------|
   * |      | Rest |      |      |      |      | Ctrl | |  Alt |      | Rset |      |      |      |      |
   * `------------------------------------------------- -------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    XXXXXXX, _______, _______, KC_UP,   _______, _______,                   _______, KC_F7,   KC_F8,   KC_F9,   _______, XXXXXXX, \
    XXXXXXX, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   _______, KC_F4,   KC_F5,   KC_F6,   _______, XXXXXXX, \
    XXXXXXX, _______, _______, _______, _______, _______,                   _______, KC_F1,   KC_F2,   KC_F3,   _______, XXXXXXX, \
    XXXXXXX, RESET,   KC_TAB,  _______, _______, _______, KC_LCTL, KC_LALT, _______, RESET,   _______, _______, _______, XXXXXXX  \
  )
};

bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        if (TOG_STATUS) {
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_LOWER);
      } else {
        TOG_STATUS = false;
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        if (TOG_STATUS) {
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_RAISE);
      } else {
        TOG_STATUS = false;
      }
      layer_on(_RAISE);
      return false;
      break;
    case RESET:
      if (record->event.pressed) {
      } else {
        TOG_STATUS = false;
      }
      layer_off(_RAISE);
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());
#endif
}


#ifdef SSD1306OLED

__attribute__ ((weak))
void led_test_init(void) {}

void matrix_scan_user(void) {
  led_test_init();
  iota_gfx_task();
}

void matrix_update(struct CharacterMatrix *dest,
                   const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)

void render_status(struct CharacterMatrix *matrix) {
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));

  switch (layer_state) {
    case L_BASE:
      matrix_write_P(matrix, PSTR("Dvorak"));
      break;
    case L_RAISE:
      matrix_write_P(matrix, PSTR("Raise"));
      break;
    case L_LOWER:
      matrix_write_P(matrix, PSTR("Lower"));
      break;
    default:
      matrix_write(matrix, buf);
  }

  char led[40];
  snprintf(
    led, sizeof(led), "\n%s  %s  %s",
    (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))    ? "LOCK" : "    ",
    (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))   ? "CAPS" : "    ",
    (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    "
  );
  matrix_write(matrix, led);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  render_status(&matrix);
  matrix_update(&display, &matrix);
}

#endif
