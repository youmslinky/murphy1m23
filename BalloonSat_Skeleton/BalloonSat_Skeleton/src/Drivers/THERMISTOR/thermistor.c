/*
 * thermistor.c
 *
 * Created: 9/20/2017 8:57:47 PM
 *  Author: Vegas
 */ 

#include "Drivers/THERMISTOR/thermistor.h"

void ADC_Init(void)
{
		
	// Only set the direction of PORTA:Pin0
	PORTA.DIRCLR = 0b00000001;
	
	/* Enable ADC:Pin0 */
	ADCA.CTRLA = 0b00000001; //XMega guide for programming data sheet under chapter 25
	ADCA.CTRLB = 0b00000000; // Set mode to 12bit
	ADCA.REFCTRL = 0b00010000; // Set ADC to Vcc/1.6
	ADCA.PRESCALER = 0b00000101; //Set pre-scalar
	ADCA.CAL = adc_get_calibration_data(ADC_CAL_ADCA); // Set ADC calibration with retrieved calibration data

	ADCA.CH0.CTRL = 0b00000001; // Configure control register channel to single-ended mode (One ADC reading instead of Two)
	ADCA.CH0.MUXCTRL = 0b00000000; // This only applies to Pin0
}

uint16_t GET_Voltage(void)
{
	ADCA.CH0.CTRL |= 0b10000000; // 7 bit (conversion >> set intflags [1 means data is ready])
	while(ADCA.CH0.INTFLAGS == 0);
	ADCA.CH0.INTFLAGS = 0; // Manually reset flags
	uint16_t iADC_Reading = ADCA.CH0.RES;
	
	float fVoltage = 0.00049*iADC_Reading - 0.0775; // find the two float value
	return (uint32_t)(fVoltage*1000); // to mV
}

uint8_t GET_Temperature(void)
{
	uint16_t iVoltage = GET_Voltage();
	//float resistance = function(voltage, series resistor);
	
	//uint8_t iTemperature = (Data Sheet Equation) - 273.15 :: Celsius
	//uint16_t iTemperature = (Data Sheet Equation) :: Kelvin
	
	//return iTemperature;
	return 0;
}