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

#define SFGR LSFT_T(KC_GRAVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* layer: base
    *                   ┌─────┐                                      ┌─────┐
    *             ┌─────┤  E  ├─────┐                          ┌─────┤  I  ├─────┐
    * ┌─────┬─────┤  W  ├─────┤  R  ├─────┐              ┌─────┤  U  ├─────┤  O  ├─────┬─────┐
    * │ esc │  Q  ├─────┤  D  ├─────┤  T  │              │  Y  ├─────┤  K  ├─────┤  P  │ bsp │
    * ├─────┼─────┤  S  ├─────┤  F  ├─────┤              ├─────┤  J  ├─────┤  L  ├─────┼─────┤
    * │ ctr │  A  ├─────┤  C  ├─────┤  G  │              │  H  ├─────┤  ,  ├─────┤  ;  │  '  │
    * ├─────┼─────┤  X  ├─────┤  V  ├─────┤              ├─────┤  M  ├─────┤  .  ├─────┼─────┤
    * │ shi │  Z  ├─────┘     └─────┤  B  │              │  N  ├─────┘     └─────┤  /  │ del │
    * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
    *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
    *                      └─────┘│ fn2 ││space│    │enter││ fn1 │└─────┘
    *                             └─────┘└─────┘    └─────┘└─────┘
    */
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,   KC_K,     KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    SFGR,       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI ,  MO(2),  KC_SPC,    KC_ENT, MO(1) , ALT_T(KC_TAB)
                                      //`--------------------------'  `--------------------------'

  ),
    /* layer: fn1
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  2  ├─────┐                          ┌─────┤  7  ├─────┐
     * ┌─────┬─────┤  1  ├─────┤  3  ├─────┐              ┌─────┤  6  ├─────┤  8  ├─────┬─────┐
     * │ esc │  0  ├─────┤  5  ├─────┤  4  │              │  5  ├─────┤down ├─────┤  9  │ bsp │
     * ├─────┼─────┤  4  ├─────┤  6  ├─────┤              ├─────┤left ├─────┤ up  ├─────┼─────┤
     * │ ctr │  4  ├─────┤  8  ├─────┤  .  │              │     ├─────┤pgdwn├─────┤right│     │
     * ├─────┼─────┤  7  ├─────┤  9  ├─────┤              ├─────┤ end ├─────┤pgup ├─────┼─────┤
     * │ shi │     ├─────┘     └─────┤  0  │              │     ├─────┘     └─────┤home │ tab │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│  fn3││space│    │enter││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    KC_0,    KC_1,   KC_2,    KC_3,     KC_4,                       KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,    KC_4,    KC_4,   KC_5,    KC_6,    KC_DOT,                      XXXXXXX, KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT,  XXXXXXX,    KC_7,   KC_8,    KC_9,     KC_0,                       XXXXXXX, KC_HOME,  KC_PGUP, KC_PGDN, KC_END, KC_TAB,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, MO(3),  KC_SPC,     KC_ENT, XXXXXXX , KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
    /* layer: fn2
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤  &  ├─────┐                          ┌─────┤  *  ├─────┐
     * ┌─────┬─────┤  @  ├─────┤  $  ├─────┐              ┌─────┤  &  ├─────┤  (  ├─────┬─────┐
     * │ esc │  !  ├─────┤  #  ├─────┤  %  │              │  ^  ├─────┤  [  ├─────┤  )  │ bsp │
     * ├─────┼─────┤  $  ├─────┤  *  ├─────┤              ├─────┤  =  ├─────┤  ]  ├─────┼─────┤
     * │ ctr │  @  ├─────┤ cop ├─────┤  c  │              │  -  ├─────┤  {  ├─────┤  \  │  ~  │
     * ├─────┼─────┤ cut ├─────┤ pas ├─────┤              ├─────┤  +  ├─────┤  }  ├─────┼─────┤
     * │ shi │ und ├─────┘     └─────┤ red │              │  _  ├─────┘     └─────┤  |  │ tab │
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│     ││space│    │enter││ fn3 │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,  KC_EXLM,  KC_AT,  KC_AMPR, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL , KC_AT,  KC_DLR,  KC_HASH, KC_ASTR, ALGR(KC_COMM),                     KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TAB,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX,  KC_SPC,  KC_ENT,  MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
    /* layer: fn3 (fn1 + fn2)
     *                   ┌─────┐                                      ┌─────┐
     *             ┌─────┤ F4  ├─────┐                          ┌─────┤ F9  ├─────┐
     * ┌─────┬─────┤ F3  ├─────┤ F5  ├─────┐              ┌─────┤ F8  ├─────┤ F10 ├─────┬─────┐
     * │ F1  │ F2  ├─────┤prev ├─────┤ F6  │              │ F7  ├─────┤     ├─────┤ F11 │ F12 │
     * ├─────┼─────┤play ├─────┤next ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │ ctr │     ├─────┤vol- ├─────┤     │              │     ├─────┤     ├─────┤     │     │
     * ├─────┼─────┤mute ├─────┤vol+ ├─────┤              ├─────┤     ├─────┤     ├─────┼─────┤
     * │ shi │     ├─────┘     └─────┤     │              │     ├─────┘     └─────┤     │reset│
     * └─────┴─────┘        ┌─────┐  └─────┘              └─────┘  ┌─────┐        └─────┴─────┘
     *                      │ os  │┌─────┐┌─────┐    ┌─────┐┌─────┐│ alt │
     *                      └─────┘│     ││space│    │enter││     │└─────┘
     *                             └─────┘└─────┘    └─────┘└─────┘
     */
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, XXXXXXX, KC_SPC,  KC_ENT,  XXXXXXX, KC_LALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("--___--  SEB  --___--\n\n"), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("    --> Let"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("     --> Num"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("     --> Sym"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
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

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_DRIVER_ENABLE
