/*
 * frontLight.h
 *
 * Created: 06-05-2026 21:59:22
 *  Author: amanda
 */ 

#ifndef FRONTLIGHT_H
#define FRONTLIGHT_H

#include <avr/io.h>
#include <stdbool.h>

#define FRONTLIGHT_PIN PB5

void initFrontLight(void); // Initialisering af forlys
void setFrontLight(bool state); // Slukker/tænder forlyset

#endif