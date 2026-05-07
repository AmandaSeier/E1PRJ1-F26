/*
 * frontLight.c
 *
 * Created: 07-05-2026 16:07:08
 *  Author: amandaseier
 */ 

#include "frontLight.h"

void frontLightInit() {
		DDRB |= (1 << PB7); // PB7 sættes som output
		PORTB &= ~(1 << PB7); // forlys er slukket som standard
}

void setFrontLight(bool state) {
	if (state == true) {
		PORTB |= (1 << PB7);  // tænd hvis True
	}
	else {
		PORTB &= ~(1 << PB7); // sluk hvis False
	}
}