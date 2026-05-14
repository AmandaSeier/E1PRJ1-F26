/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 * Author: amanda
 */

#include "frontLight.h"

void initFrontLight(void) {
    DDRB |= (1 << FRONTLIGHT_PIN); // PB5 (pin 11) som output
    PORTB &= ~(1 << FRONTLIGHT_PIN); // Start med lyset slukket
}

void setFrontLight(bool state) {
    if (state == true) {
        PORTB |= (1 << FRONTLIGHT_PIN); // Tænd forlyset
    } else {
        PORTB &= ~(1 << FRONTLIGHT_PIN); // Sluk forlyset
    }
}
