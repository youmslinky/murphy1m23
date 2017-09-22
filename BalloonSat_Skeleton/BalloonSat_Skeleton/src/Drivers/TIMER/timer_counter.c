/*
 * timer_counter.c
 *
 * Created: 9/7/2017 11:00:37 PM
 *  Author: danam
 */ 

 #include "Drivers\TIMER\timer_counter.h"

void timer_counter_init(void)
{
	PORTE.DIR = 0b11111111;
	TCE0.CTRLA = 0b00000111;
	TCE0.CTRLB = 0b11110011;
}

void LED_Cycle(float fTargetFrequency, uint8_t iDutyCycle, uint16_t iConfigGroup)
{
	uint32_t iCalculatedPER = ((F_CPU/fTargetFrequency) * iConfigGroup) - 1;
	TCE0.PER = iCalculatedPER;
	
	TCE0.CCA = TCE0.PER - (TCE0.PER/iDutyCycle);
	//TCE0.CCB = TCE0.PER - (TCE0.PER/iDutyCycle);
	//TCE0.CCC = TCE0.PER - (TCE0.PER/iDutyCycle);
	//TCE0.CCD = TCE0.PER - (TCE0.PER/iDutyCycle);
}