/*
 * LED.c
 *
 * Created: 9/16/2017 11:52:20 AM
 *  Author: Johnny
 *
 */ 

#include "LED.h"

void initLED(void)
{
	//enable timer counter on portE
	sysclk_enable_peripheral_clock(&TCE0);
	sysclk_enable_module(SYSCLK_PORT_E,SYSCLK_HIRES);
	PORTE.DIR = 0b11111111;	//set port e as output
	TCE0.CTRLA = 0b00000111; //prescaler 1024
	TCE0.CTRLB = 0b11110011; //single ramp PWM and all 4 outputs controlled by timer/counter
}

void flashLED(int flightState)
{
	/* FS is flight state
	 * FSn: frequency Hz, period s, % duty
	 *
	 * FS0:  0.5 Hz,   5s,  5% duty
	 * FS1:    5 Hz, 0.2s, 10% duty
	 * FS2:   10 Hz, 0.1s, 10% duty
	 * FS3:    1 Hz,   4s, 10% duty
	 */
	
	TCE0.CNT = 0;
	float FS_Hz[4] = {0.5,5,10,0.25};	//frequency for blink at each flight state
	int FS_DS[4] = {5,10,10,10};  //% duty cycle for each each flight state
	 
	 
	// from: _PER = (_Fclk/_ExpectedFrequency * _PS_GroupConfig) - 1
	//PER is a 16 bit number, so its max is 2^16-1=65535
	//PER max: 65535
	TCE0.PER = 32000000/(FS_Hz[flightState]*1024)-1; //where _Fclk = 32000000, _ExpectedFrequency = 10Hz, _PS_GroupConfig = 256
	float dutyCycle = 1/((float)FS_DS[flightState]/100);
	
	TCE0.CCA = TCE0.PER - (TCE0.PER/dutyCycle);
	TCE0.CCB = TCE0.CCA;
	TCE0.CCC = TCE0.CCA;
	TCE0.CCD = TCE0.CCA;
	
	TCE0.CTRLA = 0b00000111; //prescaler 1024
}

void manualFlashLED(float frequency, float dutyCycle)
{
	
	TCE0.PER = 32000000/(frequency*1024)-1;
	float DS = 1/((float)dutyCycle/100);
	
	TCE0.CCA = TCE0.PER - (TCE0.PER/dutyCycle);
	TCE0.CCB = TCE0.CCA;
	TCE0.CCC = TCE0.CCA;
	TCE0.CCD = TCE0.CCA;
	
	TCE0.CTRLA = 0b00000111; //prescaler 1024
}

void offLED(void)
{
	TCE0.CTRLA = 0b00000000;
	TCE0.CNT = 0;
}
