// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Combos
const uint16_t PROGMEM combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo1, KC_TAB),
  COMBO(combo2, KC_ENT),
  COMBO(combo3, KC_BSLS),
};

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer 
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    LT(1, KC_ESC), LCTL_T(KC_SPC),    KC_LSFT, MO(2)
  ),

  // Numbers layer
  [1] = LAYOUT(
    KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_NO,    KC_NO, KC_7, KC_8, KC_9, KC_0,
    KC_NO, KC_LALT, KC_GRV, KC_TAB, KC_BSPC,      KC_PEQL, KC_4, KC_5, KC_6, KC_SCLN,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO, KC_1, KC_2, KC_3, KC_DOT,
    KC_TRNS, KC_SPC,                              MO(2), MO(3)
  ),

  // Special characters layer
  [2] = LAYOUT(
    KC_NO, KC_TILD, KC_LBRC, KC_RBRC, KC_CIRC,     KC_UNDS, KC_LT, KC_SLSH, KC_GT, KC_NO,
    KC_CAPS, KC_GRV, KC_LPRN, KC_RPRN, KC_DLR,     KC_EQL, KC_LCBR, KC_RCBR, KC_QUOT, KC_DQUO,
    KC_LGUI, KC_EXLM, KC_AT, KC_HASH, KC_PERC,     KC_AMPR, KC_BSLS, KC_PIPE, KC_NO, KC_NO,
    MO(4), MO(5),    KC_TRNS, KC_TRNS
  ),

  // Arrow keys layer 
  [3] = LAYOUT(
    KC_NO, KC_NO, KC_PGUP, KC_PGDN, KC_NO,     KC_NO, KC_HOME, KC_END, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_LCTL,                          KC_NO, KC_TRNS 
  ),


  [4] = LAYOUT(
    KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,     KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,     KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, KC_F1, KC_F2, KC_F3, KC_F4,
    KC_TRNS, KC_NO,                                 KC_NO, KC_NO 
  ),

  [5] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,                          KC_NO, KC_NO
  ),
};
