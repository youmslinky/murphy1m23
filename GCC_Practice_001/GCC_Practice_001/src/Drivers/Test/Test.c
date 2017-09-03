/*
 * Test.c
 *
 * Created: 9/2/2017 2:16:42 PM
 *  Author: mjs0052
 */ 
#include "Test.h"

void ledRotation(uint32_t iDelay )
{
	uint8_t iLed = 1;
	
	for (int i = 0; i<=3; i++)
	{
		PORTE.OUT = ~iLed;
		iLed <<= 1;
		delay_ms(iDelay);
	}
	
	iLed = 0b10000000;
	
	for (int i = 0; i<4; i++)
	{
		PORTE.OUT = ~iLed;
		iLed >>= 1;
		delay_ms(iDelay);
	}
	
}