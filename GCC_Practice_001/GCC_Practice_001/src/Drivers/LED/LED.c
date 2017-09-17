/*
 * LED.c
 *
 * Created: 9/16/2017 11:52:20 AM
 *  Author: Johnny
 *
 */ 

#include "LED.h"

void initLED()
{
	PORTE.DIR = 0b11111111;
}

void flashLED(int flightState)
{
	/* FS is flight state
	 * FSn: frequency Hz, period s, % duty
	 *
	 * FS0:  0.2 Hz,   5s,  5% duty
	 * FS1:    5 Hz, 0.2s, 10% duty
	 * FS2:   10 Hz, 0.1s, 10% duty
	 * FS3: 0.25 Hz,   4s, 10% duty
	 */
	 
	PORTE.DIR = 0b11111111;
	TCE0.CTRLA = 0b00000111;
	TCE0.CTRLB = 0b11110011;

	// from: _PER = (_Fclk/_ExpectedFrequency * _PS_GroupConfig) - 1
	TCE0.PER = 31249; //where _Fclk = 32000000, _ExpectedFrequency = 10Hz, _PS_GroupConfig = 256

	TCE0.CCA = TCE0.PER - (TCE0.PER/99); // LED Duty cycle of 99
	TCE0.CCB = TCE0.PER - (TCE0.PER/50); // LED Duty cycle of 50
	TCE0.CCC = TCE0.PER - (TCE0.PER/25); // LED Duty cycle of 25
	TCE0.CCD = TCE0.PER - (TCE0.PER/01); // LED Duty cycle of 01
}