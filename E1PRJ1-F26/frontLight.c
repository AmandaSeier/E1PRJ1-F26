/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 * Author: amanda
 */

#include "frontLight.h"

void initFrontLight(void) {
	DDRB |= (1 << PB5); // Pin 11 output
	DDRB |= (1 << FRONTLIGHT_PIN); // Pin 11 output (PB5)
	
	// Timer 1: 8-bit Fast PWM (Mode 5)
	TCCR1A = (1 << COM1A1) | (1 << WGM10);
	TCCR1B = (1 << WGM12) | (1 << CS11); // Prescaler 8

	OCR1A = FRONTLIGHT_OFF; // Forlys slukket fra start
}

void setFrontLight(bool state) {
	if (state == true) {
		OCR1A = FRONTLIGHT_ON; // Tændt forlys
		TCCR1A = (1 << COM1A1) | (1 << WGM10); // Aktivér PWM
	} 
	else {
		TCCR1A &= ~(1 << COM1A1); // Deaktivér PWM
		OCR1A = FRONTLIGHT_OFF; // Slukket forlys
	}
}