/*
 * thermistor.h
 *
 * Created: 9/18/2017 7:32:22 PM
 *  Author: Vegas
 */ 


#ifndef THERMISTOR_H_
#define THERMISTOR_H_

#include <asf.h>

void ADC_Init(void);
uint16_t GET_Voltage(void);
uint8_t GET_Temperature(void);

#endif /* THERMISTOR_H_ */