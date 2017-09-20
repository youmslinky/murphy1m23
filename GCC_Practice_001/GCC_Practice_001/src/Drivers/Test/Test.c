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

void ledBounce4(uint32_t animationDelay)
{
	uint8_t ledPattern = 1<<4;
	for(int i=0;i<3;i++)
	{
		PORTE.OUT = ~ledPattern;
		ledPattern <<= 1;
		delay_ms(animationDelay);
	}
	ledPattern = 1<<7;
	for(int i=0;i<3;i++)
	{
		PORTE.OUT = ~ledPattern;
		ledPattern >>= 1;
		delay_ms(animationDelay);
	}
	PORTE.OUT = ~0;
}