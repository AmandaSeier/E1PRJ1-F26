/*
 * light.h
 *
 * Created: 06-05-2026 21:59:22
 *  Author: amandaseier
 */ 

#ifndef LIGHTS_H_
#endif LIGHTS_H_

#include <stdbool.h>

// FRONT LIGHT
void setFrontLightOn(bool state);

// BACK LIGHT
void setBackLightOn(bool state);
void backLightPWM(int intensity);

#endif

