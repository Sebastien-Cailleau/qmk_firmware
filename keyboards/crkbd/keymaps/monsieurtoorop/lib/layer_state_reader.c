#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case 0:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> Default");
            break;
        case 2:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> Num");
            break;
        case 4:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> $ymb");
            break;
        case 8:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> WTF?!");
            break;
        case 10:
        case 12:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> fn");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), " >> unknown (%ld)", layer_state);
            break;
    }

    return layer_state_str;
}
