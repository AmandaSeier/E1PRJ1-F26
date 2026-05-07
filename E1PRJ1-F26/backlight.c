/*
 * backLight.c
 *
 * Created: 06-05-2026 21:59:01
 *  Author: amandaseier
 */ 

#include "backLight.h"

void backLightInit() {
	DDRB |= (1 << PB6); // PB6 sættes som output
	
	// opsætning af Timer 1 til fast PWM mode
	TCCR1A |= (1 << COM1B1) | (1 << WGM10);
	TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
	
	OCR1B = 0; // baglyset er slukket som standard
}

void setBackLight(bool state) {
	// Hvis state er True
		// Baglysene tændes (PWM = 20%)
	
	// Hvis state er False
		// Baglysene slukkes (PWM = 0%)
}


void backLightPWM(int intensity) {
	
}


