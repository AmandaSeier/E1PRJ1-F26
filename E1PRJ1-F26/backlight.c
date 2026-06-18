/*
 * backLight.c
 *
 * Created: 06-05-2026 21:59:01
 *  Author: amanda
 */ 

#include "backLight.h"

void initBackLight(void) {
	DDRB |= (1 << BACKLIGHT_PIN); // PB4 (pin 10) som output

	// Timer 2 sættes i 8-bit Fast PWM non-inverting mode
	TCCR2A = 0b10000011;
	TCCR2B = 0b00000010; // Prescaler 8

	OCR2A = BACKLIGHT_OFF; // Start med baglys slukket
}

void setBackLight(bool state) {
	if (state == true) {
		OCR2A = BACKLIGHT_BRAKE; // Tænd bremselys
		TCCR2A = 0b10000011;  // Aktiver PWM 
	}
	else {
		OCR2A = BACKLIGHT_OFF; // Sluk baglys
		TCCR2A &= 0b01111111; // Deaktivér PWM

	}
}

void backLightPWM(uint8_t intensity) {
	TCCR2A = 0b10000011; // Aktiver PWM
	OCR2A = intensity; // Indstiller PWM (0–255)
}