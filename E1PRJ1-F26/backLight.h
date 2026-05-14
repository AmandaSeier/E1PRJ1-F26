/*
 * backLight.h
 *
 * Created: 06-05-2026 21:59:22
 *  Author: amanda
 */ 

#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <avr/io.h>
#include <stdbool.h>

#define BACKLIGHT_PIN PB4
#define BACKLIGHT_BRAKE 255
#define BACKLIGHT_OFF 0
#define BACKLIGHT_DRIVE 51

void initBackLight(void); // Initialisering af baglys
void setBackLight(bool state); // Tænder/slukker baglyset
void backLightPWM(uint8_t intensity); // Duty cycle 0-255 (8-bit)

#endif