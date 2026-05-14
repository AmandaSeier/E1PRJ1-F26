/*
 * backLight.c
 *
 * Created: 06-05-2026 21:59:01
 *  Author: amanda
 */ 

#include "backLight.h"

void initBackLight(void) {
	DDRB |= (1 << BACKLIGHT_PIN); // PB4 (pin 10) som output
	
	// Timer 2 i 8-bit Fast PWM (Mode 3) og non-inverting mode
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); 
	TCCR2B = (1 << CS21); // Prescaler = 8
	
	OCR2A = BACKLIGHT_OFF; // Start med lyset slukket
}

void setBackLight(bool state) {
	if (state == true) {
		OCR2A = BACKLIGHT_BRAKE; // Bremselys 
		TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); 
	}
	else {
		TCCR2A &= ~(1 << COM2A1); 
		OCR2A = BACKLIGHT_OFF; // Slukket baglys
	}
}

void backLightPWM(uint8_t intensity) {
	TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); 
	OCR2A = intensity; // Sætter PWM (0-255)
}