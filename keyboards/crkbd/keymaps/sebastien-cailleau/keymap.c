/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define CTGR LCTL_T(KC_GRAVE)
// Tap Dance declarations
enum {
    CT_CLN,
    CT_QUOT,
    MAIL_PERSO = SAFE_RANGE,
    MAIL_PRO,
};

// single : double ;
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_COLN);
    } else {
        register_code(KC_SCLN);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

// single ' double "
void dance_quote_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOT);
    } else {
        register_code16(KC_DQT);
    }
}

void dance_quote_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    } else {
        unregister_code16(KC_DQT);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAIL_PERSO:
            if (record->event.pressed) {
                SEND_STRING("sebastien.cailleau@protonmail.com");
            } else {
                // when keycode MAIL_PERSO is released
            }
            break;
        case MAIL_PRO:
            if (record->event.pressed) {
                SEND_STRING("s.cailleau@groupe-convergence.com");
            } else {
                // when keycode MAIL_PRO is released
            }
            break;
    };
    return true;
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [CT_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_quote_finished, dance_quote_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer: base
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  F  ├─────┐                          ┌─────┤  U  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  P  ├─────┐              ┌─────┤  L  ├─────┤  Y  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  S  ├─────┤  B  │              │  J  ├─────┤  E  ├─────┤  :  │ bsp │
     * ├─────┼─────┤  R  ├─────┤  T  ├─────┤              ├─────┤  N  ├─────┤  I  ├─────┼─────┤
     * │ ctr │  A  ├─────┤  C  ├─────┤  G  │              │  M  ├─────┤  ,  ├─────┤  O  │  '  │
     * ├─────┼─────┤  X  ├─────┤  D  ├─────┤              ├─────┤  H  ├─────┤  .  ├─────┼─────┤
     * │enter│  Z  ├─────┘     └─────┤  V  │              │  K  ├─────┘     └─────┤  /  │ del │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│ fn2 ││shift│    │space││ TO2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [0] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, TD(CT_CLN), KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        CTGR, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, TD(CT_QUOT),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ENT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(3), KC_LSFT, KC_SPC, MO(2), ALT_T(KC_TAB)

        //`--------------------------'  `--------------------------'

        ),
            /* layer: play
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
     * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
     * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
     * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
     * │ shi │  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │ to0 │
     * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
     * │ ctr │  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │ tab │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│ fn2 ││space│    │enter││ fn1 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, TG(1),
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TAB,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(3), KC_SPC, KC_ENT, MO(2), KC_LALT
        //`--------------------------'  `--------------------------'
        ),
    /* layer: fn1
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  2  ├─────┐                          ┌─────┤     ├─────┐
     * ┌─────┬─────┤  1  ├─────┤  3  ├─────┐              ┌─────┤     ├─────┤     ├─────┬─────┐
     * │ esc │  0  ├─────┤  5  ├─────┤  4  │              │ ins ├─────┤ up  ├─────┤pause│ bsp │
     * ├─────┼─────┤  4  ├─────┤  6  ├─────┤              ├─────┤left ├─────┤ down├─────┼─────┤
     * │ ctr │l-alt├─────┤  8  ├─────┤save │              │  .  ├─────┤ pgup├─────┤right│back │
     * ├─────┼─────┤  7  ├─────┤  9  ├─────┤              ├─────┤home ├─────┤ pgdo├─────┼─────┤
     * │ shi │r-alt├─────┘     └─────┤  0  │              │ TO1 ├─────┘     └─────┤ end │ del │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ tab │+
     *                      └─────┘│  fn3││shift│    │space││ TO2 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_0, KC_1, KC_2, KC_3, KC_4, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUSE, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_LALT, KC_4, KC_5, KC_6, C(KC_S), KC_DOT, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_BTN4,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_RALT, KC_7, KC_8, KC_9, KC_0, TG(1), KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_DEL,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, MO(4), KC_LSFT, KC_SPC, MO(2), ALT_T(KC_TAB)
        //`--------------------------'  `--------------------------'
        ),
    /* layer: fn2
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  &  ├─────┐                          ┌─────┤  (  ├─────┐
     * ┌─────┬─────┤     ├─────┤  %  ├─────┐              ┌─────┤  €  ├─────┤  )  ├─────┬─────┐
     * │ esc │  !  ├─────┤  $  ├─────┤altf4│              │  ^  ├─────┤  [  ├─────┤  °  │ bsp │
     * ├─────┼─────┤  *  ├─────┤  *  ├─────┤              ├─────┤  =  ├─────┤  ]  ├─────┼─────┤
     * │ ctr │  @  ├─────┤ copy├─────┤  #  │              │  -  ├─────┤  {  ├─────┤  \  │  ~  │
     * ├─────┼─────┤ cut ├─────┤paste├─────┤              ├─────┤  +  ├─────┤  }  ├─────┼─────┤
     * │ shi │undo ├─────┘     └─────┤redo │              │  _  ├─────┘     └─────┤  |  │ tab │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│     ││shift│    │space││ fn3 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [3] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC, KC_EXLM, XXXXXXX, KC_AMPR, KC_PERC, LALT(KC_F4), KC_CIRC, RALT(KC_5), KC_LPRN, KC_RPRN, RSA(KC_SCLN), KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_AT, KC_ASTR, KC_DLR, KC_ASTR, KC_HASH, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y), KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TAB,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, XXXXXXX, KC_LSFT, KC_SPC, MO(4), KC_RALT
        //`--------------------------'  `--------------------------'
        ),
    /* layer: fn3 (fn1 + fn2)
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┬─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F1  │ F2  ├─────┤     ├─────┤ F6  │              │ F7  ├─────┤prev ├─────┤ F11 │ F12 │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤play ├─────┤next ├─────┼─────┤
     * │ ctr │l-alt├─────┤     ├─────┤email│              │email├─────┤vol- ├─────┤     │     │
     * ├─────┼─────┤     ├─────┤     ├─────┤              ├─────┤mute ├─────┤vol+ ├─────┼─────┤
     * │ shi │r-alt├─────┘     └─────┤     │              │     ├─────┘     └─────┤     │reset│
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│     ││shift│    │space││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
    [4] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, MAIL_PERSO, MAIL_PRO, KC_MPLY, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_MPRV, XXXXXXX, RESET,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LGUI, XXXXXXX, KC_LSFT, KC_SPC, XXXXXXX, KC_LALT
        //`--------------------------'  `--------------------------'
)};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#    define L_BASE 0
#    define L_PLAY 2
#    define L_LOWER  4
#    define L_RAISE 8
#    define L_ADJUST 16

// Display layer info
void oled_render_layer_state(void) {
    oled_write_P(PSTR("--___--  SEB  --___--\n\n"), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("  --> Base"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("    --> Num"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("     --> Sym"), false);
            break;
        case L_PLAY:
            oled_write_ln_P(PSTR("__PLAAAY__"), false);
            break;
        case L_ADJUST:
        case L_ADJUST | L_LOWER:
        case L_ADJUST | L_RAISE:
        case L_ADJUST | L_LOWER | L_RAISE:
            oled_write_ln_P(PSTR("      --> Fun"), false);
            break;
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

// Display my Turtle
void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0,
            0x60, 0x60, 0x30, 0x30, 0x10, 0x18, 0x18, 0x18, 0x18, 0x18, 0x98, 0xd8, 0x58, 0x78, 0x10, 0x30,
            0x30, 0x20, 0x60, 0x60, 0xc0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0xc0, 0x40, 0x40, 0x60, 0x60, 0x60,
            0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xb8, 0x8c, 0x86, 0x83, 0x01, 0x03,
            0xc6, 0xfc, 0x8c, 0x04, 0x04, 0x04, 0x06, 0x06, 0x07, 0x8d, 0x89, 0xf8, 0x30, 0x00, 0x10, 0x90,
            0x88, 0xbc, 0xf4, 0xe2, 0x7b, 0x1d, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0xe0, 0x30, 0x14, 0xf6,
            0xf2, 0xf2, 0xe0, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x7c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x07, 0x0f, 0xfe, 0x3e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e,
            0x3e, 0xf7, 0x85, 0x85, 0xc7, 0xf7, 0x3f, 0x0d, 0x0d, 0x05, 0x0d, 0x0d, 0xfd, 0xfb, 0x1f, 0x1f,
            0x1f, 0x1f, 0x99, 0x90, 0xb0, 0xf0, 0x60, 0xe0, 0x60, 0xc0, 0xc0, 0x80, 0x87, 0x0c, 0x0c, 0x0c,
            0x0c, 0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x10,
            0x1c, 0x1f, 0x0d, 0x07, 0x0f, 0x1d, 0x18, 0x18, 0x18, 0x08, 0x1c, 0x1c, 0x1f, 0x1f, 0x01, 0x01,
            0x03, 0x07, 0x05, 0x05, 0x0c, 0x0e, 0x0c, 0x03, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03,
            0x03, 0x06, 0x06, 0x02, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };

    oled_write_raw_P(crkbd_logo, sizeof(crkbd_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_logo();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif  // OLED_DRIVER_ENABLE
