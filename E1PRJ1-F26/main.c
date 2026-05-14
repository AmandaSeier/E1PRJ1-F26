/*
 * E1PRJ1-F26.c
 *
 * Created: 06-05-2026 21:14:32
 * Author : anton, isam, jamal, abdi, hewad & amamda (SW5)
 */ 

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

    PORTA |= (1 << PA0); // pull-up SW0
    PORTA |= (1 << PA1); // pull-up SW1

    while (1) {
        bool sw0 = !(PINA & (1 << PA0));   // aktiv LOW
        bool sw1 = !(PINA & (1 << PA1));   // aktiv LOW

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
