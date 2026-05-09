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

void initBackLight(void); // Initialisering af baglys
void setBackLight(bool state); // Tænder/slukker baglyset
void backLightPWM(uint8_t intensity); // Duty cycle 0-255 (8-bit)

#endif