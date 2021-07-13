#include QMK_KEYBOARD_H
#include <keymap_polish.h>

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _CODE   1
#define _NAV    2
#define _FUNC   3
#define _RAISE  4

#define KC_____     KC_NO                   // ignore
#define KC_LSFTC    MT(MOD_LSFT, KC_CAPS)   // caps + lshift
#define KC_NAV      NAV                     // navigation
#define KC_RAISE    RAISE                   // raise
#define KC_CODE     CODE                    // code_layer
#define KC_FUNC     FUNC                    // code_layer
#define KC_LPAR     S(KC_9)                 // (
#define KC_RPAR     S(KC_0)                 // )
#define KC_ATAB     A(KC_TAB)               // )

// Polish diacritics
#define KC_DA       PL_AOGO
#define KC_DC       PL_CACU
#define KC_DE       PL_EOGO
#define KC_DL       PL_LSTR
#define KC_DN       PL_NACU
#define KC_DO       PL_OACU
#define KC_DS       PL_SACU
#define KC_DX       PL_ZACU
#define KC_DZ       PL_ZDOT

enum custom_keycodes {
    DVORAK = SAFE_RANGE,
    FUNC,
    CODE,
    NAV,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_kc(
        //┌───────┬───────┬───────┬───────┬───────┬───────┐                          ┌───────┬───────┬───────┬───────┬───────┬───────┐
            ESC,    1,      2,      3,      4,      5,                                 6,      7,      8,      9,      0,      DEL,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            TAB,    QUOT,   COMM,   DOT,    P,      Y,                                 F,      G,      C,      R,      L,      BSPC,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            LSFTC,  A,      O,      E,      U,      I,                                 D,      H,      T,      N,      S,      RSFT,
        //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐          ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            LCTL,   SCLN,   Q,      J,      K,      X,      RAISE,             RALT,   B,      M,      W,      V,      Z,      RCTL,
        //└───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘          └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
                                        LGUI,   CODE,   SPC,                       ENT,    NAV,    FUNC
                                    //└───────┴───────┴───────┘                  └───────┴───────┴───────┘
    ),
    [_CODE] = LAYOUT_kc(
        //┌───────┬───────┬───────┬───────┬───────┬───────┐                          ┌───────┬───────┬───────┬───────┬───────┬───────┐
            ESC,    ____,   ____,   ____,   ____,   ____,                              ____,   ____,   ____,   ____,   ____,   DEL,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            TAB,    ____,   ____,   ____,   LBRC,   ____,                              ____,   RBRC,   ____,   ____,   ____,   BSPC,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            LSFTC,  ____,   EQL,    BSLS,   LPAR,   GRAVE,                             ____,   RPAR,   SLSH,   MINS,   ____,   RSFT,
        //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐          ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            LCTL,   ____,   MUTE,   VOLD,   VOLU,   PSCR,   ____,              ____,   ____,   COPY,   PSTE,   ____,   ____,   RCTL,
        //└───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘          └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
                                        LGUI,   ____,   SPC,                       ENT,    ____,   ____
                                    //└───────┴───────┴───────┘                  └───────┴───────┴───────┘
    ),
    [_NAV] = LAYOUT_kc(
        //┌───────┬───────┬───────┬───────┬───────┬───────┐                          ┌───────┬───────┬───────┬───────┬───────┬───────┐
            ESC,    ____,   ____,   ____,   ____,   ____,                              ____,   ____,   ____,   ____,   ____,   DEL,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            TAB,    ____,   ____,   ____,   LBRC,   ____,                              PGUP,   HOME,   END,    PGDN,   ____,   BSPC,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            LSFTC,  ____,   EQL,    BSLS,   LPAR,   GRAVE,                             LEFT,   DOWN,   UP,     RGHT,   ____,   RSFT,
        //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐          ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            LCTL,   ____,   MUTE,   VOLD,   VOLU,   PSCR,   ____,              ____,   ____,   ____,   ____,   ____,   ____,   RCTL,
        //└───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘          └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
                                        LGUI,   ____,   SPC,                       ENT,    ____,   ____
                                    //└───────┴───────┴───────┘                  └───────┴───────┴───────┘
    ),
    [_FUNC] = LAYOUT_kc(
        //┌───────┬───────┬───────┬───────┬───────┬───────┐                          ┌───────┬───────┬───────┬───────┬───────┬───────┐
            F1,     F2,     F3,     F4,     F5,     F6,                                F7,     F8,     F9,     F10,    F11,    F12,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            ATAB,   F8,     F9,     F10,    F11,    F12,                               BRIU,   BRID,   DC,     ____,   DL,     BSPC,
        //├───────┼───────┼───────┼───────┼───────┼───────┤                          ├───────┼───────┼───────┼───────┼───────┼───────┤
            LSFTC,  DA,     DO,     DE,     ____,   ____,                              MUTE,   VOLU,   VOLD,   DN,     DS,     RSFT,
        //├───────┼───────┼───────┼───────┼───────┼───────┼───────┐          ┌───────┼───────┼───────┼───────┼───────┼───────┼───────┤
            LCTL,   ____,   ____,   ____,   ____,   ____,   ____,              ____,   ____,   ____,   ____,   DX,     DZ,     RCTL,
        //└───────┴───────┴───────┴───┬───┴───┬───┴───┬───┴───┬───┘          └───┬───┴───┬───┴───┬───┴───┬───┴───────┴───────┴───────┘
                                        LGUI,   ____,   SPC,                       ENT,    ____,   ____
                                    //└───────┴───────┴───────┘                  └───────┴───────┴───────┘
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case CODE:
            if (record->event.pressed) {
                layer_on(_CODE);
            } else {
                layer_off(_CODE);
            }
            return false;
        case NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
            return false;
        case FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
            } else {
                layer_off(_FUNC);
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case _DVORAK:
            backlight_level(1);
            break;
        case _FUNC:
            backlight_level(2);
            break;
        case _NAV:
            backlight_level(2);
            break;
        case _CODE:
            backlight_level(2);
            break;
    }
};


