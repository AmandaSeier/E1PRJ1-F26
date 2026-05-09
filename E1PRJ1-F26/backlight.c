/*
 * backLight.c
 *
 * Created: 06-05-2026 21:59:01
 *  Author: amanda
 */ 

#include "backLight.h"

void initBackLight(void) {
	DDRB |= (1 << PB4); // Pin 10 output
	
	// Timer 2: 8-bit Fast PWM (Mode 3)
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << CS21); // Prescaler 8
	
	OCR2A = 0;
}

void setBackLight(bool state) {
	if (state) {
		OCR2A = 255; // Bremselys
		} else {
		OCR2A = 0; // Slukket
	}
}

void backLightPWM(uint8_t intensity) {
	OCR2A = intensity;
}