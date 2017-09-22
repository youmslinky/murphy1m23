/*
 * main.h
 *
 * Created: 9/18/2017 7:37:18 PM
 *  Author: Vegas
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <asf.h>
#include "Drivers\USART\usart.h"
#include "Drivers\TIMER\timer_counter.h"
#include "Drivers\SPEAKER\speaker.h"
#include "Drivers\THERMISTOR\thermistor.h"
#include "Drivers\PRESSURE\pressure.h"

uint16_t iInitalTemperature, iCurrentTemperature;
uint32_t iInitialPressure, iCurrentPressure;
uint16_t iInitialAltitude, iCurrentAltitude, iTargetAltitude, iAscentLimitAltitude;

float interquartileRange(void);
uint16_t GET_Altitude(uint16_t iTemp, uint32_t iPressure);

void flightState0(void);
void flightState1(void);
void flightState2(void);
void flightState3(void);

#endif /* MAIN_H_ */