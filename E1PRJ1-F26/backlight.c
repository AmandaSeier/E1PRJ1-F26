/*
 * backLight.c
 *
 * Created: 06-05-2026 21:59:01
 *  Author: amanda
 */ 

#include "backLight.h"

void initBackLight(void) {
	DDRB |= (1 << BACKLIGHT_PIN); // Pin 10 output (PB4)
	
	// Timer 2: 8-bit Fast PWM (Mode 3)
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
	TCCR2B = (1 << CS21); // Prescaler 8
	
	OCR2A = BACKLIGHT_OFF; // Slukket fra starten
}

void setBackLight(bool state) {
	if (state == true) {
		OCR2A = BACKLIGHT_BRAKE; // Bremselys
		TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
		} else {
		TCCR2A &= ~(1 << COM2A1);
		OCR2A = BACKLIGHT_OFF; // Slukket
	}
}

void backLightPWM(uint8_t intensity) {
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20);
	OCR2A = intensity;
}