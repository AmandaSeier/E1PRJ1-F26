/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 *  Author: amanda
 */ 

#include "frontLight.h"

void initFrontLight(void) {
	DDRB |= (1 << FRONTLIGHT_PIN); // PB5 (pin 11) som output

	// Timer 1 i 8-bit Fast PWM (Mode 5) i non-inverting mode
	TCCR1A = (1 << COM1A1) | (1 << WGM10); 
	TCCR1B = (1 << WGM12) | (1 << CS11); // Prescaler = 8

	OCR1A = FRONTLIGHT_OFF; //Forlyset er slukket som standard
}

void setFrontLight(bool state) {
	if (state == true) {
		OCR1A = FRONTLIGHT_ON; // Tænd forlyset
		TCCR1A = (1 << COM1A1) | (1 << WGM10);
		} else {
		TCCR1A &= ~(1 << COM1A1); 
		OCR1A = FRONTLIGHT_OFF; // Slukket forlys
	}
}