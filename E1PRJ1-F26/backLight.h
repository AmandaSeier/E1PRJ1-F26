/*
 * backLight.h
 *
 * Created: 06-05-2026 21:59:22
 *  Author: amandaseier
 */ 

#ifndef BACKLIGHT_H_
#endif BACKLIGHT_H_

#include <stdbool.h>

// BACK LIGHT METHODS
void backLightInit();
void setBackLight(bool state);
void backLightPWM(int intensity);

#endif

