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
  DWM_TO_TAG_ONE, // Move focused window to tag 1
  DWM_TO_TAG_TWO, // Move focused window to tag 2
  DWM_TO_TAG_THREE, // Move focused window to tag 3
  DWM_CLOSE, // Close current program
  DWM_QUIT, // Quits DWM
  DWM_INCR_MSIZE, // Increases master window size
  DWM_DECR_MSIZE, // Decreases master window size
  DWM_LAYOUT_TILE, // Swaps active layout to tile mode
  DWM_LAYOUT_MONOCLE, // Swaps active layout to monocle (singe full screen window)
  DWM_LAYOUT_BSTACK, // Swaps active layout to bottom stack
  DWM_FOCUS_NSCREEN, // Focus next screen
  DWM_SEND_NSCREEN, // Send focused window to the next screen
 
  // Tmux
  TMUX_NEXT, // Go to next tab
  TMUX_NEW, // Create new tab
  TMUX_SPLIT_H, // Horizontal split
  TMUX_SPLIT_V, // Vertical split
  TMUX_CYCLE_PANE, // Cycle between panes

  // Browser
  WWW_OPEN_TAB,
  WWW_NEXT_TAB,
  WWW_PREV_TAB,
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
    //////////////////////////////////////////////
    // DWM
    //////////////////////////////////////////////
    case DWM_TERM:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_ENTER))));
        layer_off(6); 
      }
      return false; // Skip all further processing of this key

    case DWM_SWAP:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_ENTER)));
      }
      return false;

    case DWM_RUN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_P)));
        layer_off(6); 
      }
      return false;

    case DWM_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_J)));
      }
      return false;

    case DWM_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_K)));
      }
      return false;

    case DWM_TAG_ONE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_1)));
      }
      return false;

    case DWM_TAG_TWO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_2)));
      }
      return false;

    case DWM_TAG_THREE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_3)));
      }
      return false;

    case DWM_TO_TAG_ONE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_1))));
      }
      return false;

    case DWM_TO_TAG_TWO:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_2))));
      }
      return false;

    case DWM_TO_TAG_THREE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_3))));
      }
      return false;

    case DWM_CLOSE:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_C))));
      }
      return false;
    
    case DWM_QUIT:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_Q))));
        layer_off(6);
      }
      return false;

    case DWM_INCR_MSIZE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_L)));
      }
      return false;
    
    case DWM_DECR_MSIZE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_H)));
      }
      return false;

    case DWM_LAYOUT_TILE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_T)));
      }
      return false;
      
    case DWM_LAYOUT_MONOCLE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_M)));
      }
      return false;

    case DWM_LAYOUT_BSTACK:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_U)));
      }
      return false;

    case DWM_FOCUS_NSCREEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_DOT)));
      }
      return false;

    case DWM_SEND_NSCREEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_DOT))));
      }
      return false;


    //////////////////////////////////////////////
    // TMUX
    //////////////////////////////////////////////
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

    //////////////////////////////////////////////
    // Browser
    //////////////////////////////////////////////
    case WWW_OPEN_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_T)));
        layer_off(5);
      }
      return false;

    case WWW_NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
      }
      return false;

    case WWW_PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
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
    KC_NO, KC_TILD, KC_LBRC, KC_RBRC, KC_CIRC,     KC_UNDS, KC_LT, KC_SLSH, KC_GT, KC_DEL,
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
    KC_NO, KC_ESC, KC_WH_U, KC_F5, WWW_OPEN_TAB,  LCTL(KC_T), KC_BTN3, KC_HOME, KC_END, LCTL(KC_W),
    KC_NO, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
    QK_BOOT, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,    KC_NO, WWW_PREV_TAB, WWW_NEXT_TAB, KC_WBAK, KC_WFWD,
    TG(5), KC_ACL1,                               KC_BTN1, KC_BTN2
  ),

  // Utils + DWM
  [6] = LAYOUT(
    DWM_QUIT, DWM_SEND_NSCREEN, DWM_LAYOUT_BSTACK, DWM_LAYOUT_MONOCLE, DWM_LAYOUT_TILE,     KC_NO, DWM_TERM, KC_NO, DWM_RUN, DWM_CLOSE,
    KC_NO, DWM_TO_TAG_ONE, DWM_TO_TAG_TWO, DWM_TO_TAG_THREE, DWM_FOCUS_NSCREEN,     DWM_DECR_MSIZE, DWM_NEXT, DWM_PREV, DWM_INCR_MSIZE, DWM_SWAP,
    KC_NO, KC_NO, KC_C, KC_V, KC_NO,       KC_NO, DWM_TAG_ONE, DWM_TAG_TWO, DWM_TAG_THREE, KC_NO,
    TG(6), MO(7),                          KC_NO, KC_NO
  ),

  // DWM alternative layer 
  [7] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, DWM_TO_TAG_ONE, DWM_TO_TAG_TWO, DWM_TO_TAG_THREE, KC_NO,
    KC_NO, KC_NO,                          KC_NO, KC_NO
  ),

  // Unused empty definition
  [8] = LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,                          KC_NO, KC_NO
  ),

};

// Combo definition
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
