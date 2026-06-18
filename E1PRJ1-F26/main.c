/*
 * E1PRJ1-F26.c
 *
 * Created: 06-05-2026 21:14:32
 * Author : amanda
 */ 

// Lightmodule test

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "backLight.h"
#include "frontLight.h"

int main(void) {
	// Initialisering af lysmoduler
    initBackLight();
    initFrontLight();

    DDRA &= ~(1 << PA0); // SW0 som input
    DDRA &= ~(1 << PA1); // SW1 som input

	// Aktiverer pull-up modstande 
    PORTA |= (1 << PA0); 
    PORTA |= (1 << PA1); 

    while (1) {
        bool sw0 = !(PINA & (1 << PA0));
        bool sw1 = !(PINA & (1 << PA1));

		// Bilen kører
        if (sw1 == true) {
            setFrontLight(true);
			backLightPWM(BACKLIGHT_DRIVE);
        }
		// Bilen bremser
        else if (sw0 == true) {
            setFrontLight(true);
            backLightPWM(BACKLIGHT_BRAKE);
        }
		// Hvis bilen er slukket
        else {
            // Ingen tryk, så slukkes begge lysmoduler
            setBackLight(false);
            setFrontLight(false);
        }
    }
}
