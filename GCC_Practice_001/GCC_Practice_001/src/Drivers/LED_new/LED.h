/*
 * LED.h
 *
 * Created: 9/16/2017 11:52:31 AM
 *  Author: Johnny
 *	This is all the functions for setting the LEDS to the appropriate frequency and duty cycle
 */ 

#include <stdint.h>
#include "Drivers\Drivers.h"

#ifndef LED_H_
#define LED_H_

void initLED(void);
void flashLED(int flightState);
void manualFlashLED(float frequency, float dutyCycle);
void offLED(void);

#endif /* LED_H_ */