/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 *  Author: amanda
 */ 

#include "frontLight.h"

void initFrontLight(void) {
	DDRB |= (1 << FRONTLIGHT_PIN); // Pin 11 output (PB5)
	
	// Timer 1: 8-bit Fast PWM (Mode 5)
	// Vi bruger Mode 5 i stedet for 14, så vi ikke er afhængige af ICR1
	TCCR1A = (1 << COM1A1) | (1 << WGM10);
	TCCR1B = (1 << WGM12) | (1 << CS11); // Prescaler 8
	
	OCR1A = FRONTLIGHT_OFF;
}

void setFrontLight(bool state) {
	if (state == true) {
		OCR1A = FRONTLIGHT_ON;
		TCCR1A = (1 << COM1A1) | (1 << WGM10);
		} else {
		TCCR1A &= ~(1 << COM1A1);
		OCR1A = FRONTLIGHT_OFF;
	}
}