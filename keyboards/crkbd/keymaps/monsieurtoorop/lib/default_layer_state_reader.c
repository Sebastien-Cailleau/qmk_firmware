#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

char default_layer_state_str[24];

const char *read_default_layer_state(void) {
    snprintf(default_layer_state_str, sizeof(default_layer_state_str), "Monsieur_Toorop \n");

    return default_layer_state_str;
}
