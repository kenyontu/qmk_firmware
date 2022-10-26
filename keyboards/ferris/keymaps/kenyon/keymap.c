// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Custom keycodes
enum my_keycodes {
  // DWM
  DWM_TERM = SAFE_RANGE, // Opens the terminal
  DWM_SWAP, // Swaps windows
  DWM_RUN, // Open menu to run programs
  DWM_NEXT, // Move focus to the next window
  DWM_PREV, // Move focus to the previous window
  DWM_TAG_ONE, // Move to tag 1 
  DWM_TAG_TWO, // Move to tag 2
  DWM_TAG_THREE, // Move to tag 3

  // Tmux
  TMUX_NEXT, // Go to next tab
  TMUX_NEW, // Create new tab
  TMUX_SPLIT_H, // Horizontal split
  TMUX_SPLIT_V, // Vertical split
  TMUX_CYCLE_PANE, // Cycle between panes
};

/*
* SEND_STRING modifiers
*
* X_<Basic key code> 
* SS_LCTL - Left control
* SS_LSFT - Left shift
* SS_LALT - Left alt
* SS_LGUI - Left GUI
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DWM_TERM:
      if (record->event.pressed) {
        // Shift + Alt + Enter
        SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENTER))));
      }
      return false; // Skip all further processing of this key

    case DWM_SWAP:
      if (record->event.pressed) {
        // Alt + Enter
        SEND_STRING(SS_LGUI(SS_TAP(X_ENTER)));
      }
      return false;

    case DWM_RUN:
      if (record->event.pressed) {
        // Alt + p
        SEND_STRING(SS_LGUI(SS_TAP(X_P)));
      }
      return false;

    case DWM_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_J)));
      }
      return false;

    case DWM_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_K)));
      }
      return false;

    case DWM_TAG_ONE:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_1)));
      }
      return false;

    case DWM_TAG_TWO:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_2)));
      }
      return false;

    case DWM_TAG_THREE:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_3)));
      }
      return false;

    case TMUX_NEW:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_B)) "c");
      }
      return false;

    case TMUX_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_B)) "n");
      }
      return false;

    case TMUX_SPLIT_H:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_B)) "%");
      }
      return false;

    case TMUX_SPLIT_V:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_B)) "\"");
      }
      return false;

    case TMUX_CYCLE_PANE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_B)) "o");
      }
      return false;

    default:
      return true; // Process all other keycodes normally
  }
}

// Combos
const uint16_t PROGMEM combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo5[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo6[] = {KC_C, KC_V, COMBO_END};

// Tap dance
enum {
  TD_SHIFT__MOUSE_LAYER = 0 
};

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base layer 
  [0] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,     KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    LT(1, KC_ESC), LCTL_T(KC_SPC),    TD(TD_SHIFT__MOUSE_LAYER), MO(2)
  ),

  // Numbers layer
  [1] = LAYOUT(
    KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_NO,    KC_COMM, KC_7, KC_8, KC_9, KC_0,
    KC_NO, KC_LALT, KC_GRV, KC_TAB, KC_BSPC,      KC_PEQL, KC_4, KC_5, KC_6, KC_SCLN,
    KC_NO, TMUX_CYCLE_PANE, TMUX_NEW, TMUX_SPLIT_H, TMUX_SPLIT_V,       TMUX_NEXT, KC_1, KC_2, KC_3, KC_DOT,
    KC_TRNS, KC_SPC,                              MO(2), MO(3)
  ),

  // Special characters layer
  [2] = LAYOUT(
    KC_NO, KC_TILD, KC_LBRC, KC_RBRC, KC_CIRC,     KC_UNDS, KC_LT, KC_SLSH, KC_GT, KC_NO,
    KC_NO, KC_GRV, KC_LPRN, KC_RPRN, KC_DLR,       KC_EQL, KC_LCBR, KC_RCBR, KC_QUOT, KC_DQUO,
    KC_LGUI, KC_EXLM, KC_AT, KC_HASH, KC_PERC,     KC_AMPR, KC_BSLS, KC_PIPE, KC_NO, KC_NO,
    MO(4), KC_SPC,                                  KC_TRNS, KC_TRNS
  ),

  // Arrow keys layer 
  [3] = LAYOUT(
    KC_NO, KC_NO, KC_PGUP, KC_PGDN, KC_NO,     KC_NO, KC_HOME, KC_END, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_LCTL,                          KC_NO, KC_TRNS 
  ),

  // Media and F1 ~ F12 keys 
  [4] = LAYOUT(
    KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,     KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,     KC_NO, KC_F5, KC_F6, KC_F7, KC_F8,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, KC_F1, KC_F2, KC_F3, KC_F4,
    KC_TRNS, KC_NO,                              KC_NO, KC_NO 
  ),

  // Mouse keys and bootloader mode
  [5] = LAYOUT(
    KC_NO, KC_ESC, KC_WH_U, KC_BTN3, KC_HOME,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_WH_L, KC_WH_D, KC_WH_R, KC_END,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_BTN2, KC_BTN1,                             TG(5), KC_ACL2
  ),

//  DWM_TERM = SAFE_RANGE, // Opens the terminal
//  DWM_SWAP = SAFE_RANGE, // Swaps windows
//  DWM_RUN = SAFE_RANGE, // Open menu to run programs
//  DWM_NEXT = SAFE_RANGE, // Move focus to the next window
//  DWM_PREV = SAFE_RANGE, // Move focus to the previous window
//  DWM_TAG_ONE = SAFE_RANGE, // Move to tag 1 
//  DWM_TAG_TWO = SAFE_RANGE, // Move to tag 2
//  DWM_TAG_THREE = SAFE_RANGE, // Move to tag 3

  // Utils
  [6] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, DWM_TERM, KC_NO, DWM_RUN, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, DWM_NEXT, DWM_PREV, DWM_SWAP, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, DWM_TAG_ONE, DWM_TAG_TWO, DWM_TAG_THREE, KC_NO,
    KC_NO, KC_NO,                          TG(6), KC_NO
  ),

  // Unused empty definition
  [7] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,                          KC_NO, KC_NO
  ),

};


// Combo definitions
combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo1, KC_TAB),
  COMBO(combo2, KC_ENT),
  COMBO(combo3, KC_BSLS),
  COMBO(combo4, KC_CAPS),
  COMBO(combo5, KC_LEAD),
  COMBO(combo6, TG(6))
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Single tap: Shift | Double tap: Toggle layer 5
  [TD_SHIFT__MOUSE_LAYER] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LSFT, 5)
};
