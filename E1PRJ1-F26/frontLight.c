/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 * Author: amanda
 */

#include "frontLight.h"

void initFrontLight(void) {
	DDRB |= (1 << FRONTLIGHT_PIN); // Pin 11 output (PB5)
	
	// Timer 1 sættes i 8-bit Fast PWM non-inverting mode
	TCCR1A = 0b10000001;           
	TCCR1B = 0b00001010; // prescaler 8

	OCR1A = FRONTLIGHT_OFF; // Forlyset starter slukket
}

void setFrontLight(bool state) {
	if (state == true) {
		OCR1A = FRONTLIGHT_ON; // Tænd forlys
		TCCR1A = 0b10000001; // Aktivér PWM 
	}
	else {
		TCCR1A &= 0b01111111; // Deaktivér PWM 
		OCR1A = FRONTLIGHT_OFF; // Sluk forlyset
	}
}