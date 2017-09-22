/**
 * main.c
 *
 * Created: 9/7/2017 10:00:17 PM
 *  Author: danam
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "main.h"

int main (void)
{
	sysclk_init();
	
	//Enable Timer for LED
	sysclk_enable_peripheral_clock(&TCE0);
	sysclk_enable_module(SYSCLK_PORT_E, SYSCLK_HIRES);
	timer_counter_init();
	
	//Enable Pressure Sensor
	sysclk_enable_peripheral_clock(&SPIC);
	SPI_Init();
	MS5607_Init();
	
	//Enable ADC on PORTA
	sysclk_enable_peripheral_clock(&ADCA);
	ADC_Init();
	
	//Enable Communications for OPENLOG on PORTC
	sysclk_enable_peripheral_clock(&USARTC0);
	USART_Init();
	
	iInitalTemperature = GET_Temperature();
	iInitialPressure = GET_Pressure();
	iInitialAltitude = GET_Altitude(iInitalTemperature, iInitialPressure);
	iCurrentAltitude = iInitialAltitude; // Just to give it some value to start testing 
	
	iAscentLimitAltitude = iInitialAltitude + 30;
	iTargetAltitude = iInitialAltitude + 700;

	while(1)
	{
		/* Hold */
		LED_Cycle(0.5f, 5, 256);
		while (iCurrentAltitude<iAscentLimitAltitude)
			flightState0();
		
		/* Ascending */
		LED_Cycle(5.0f, 10, 256);
		while (iCurrentAltitude > iAscentLimitAltitude && iCurrentAltitude < iTargetAltitude)
			flightState1();
		
		/* Falling */
		LED_Cycle(10.0f, 10, 256);
		//Hot Wire for x amount of seconds
		while (iCurrentAltitude < iTargetAltitude && interquartileRange()>10)
			flightState2();
		
		/* Landed */
		LED_Cycle(1.0f, 10, 256);
		//Buzzer on timer
		while (iCurrentAltitude < iTargetAltitude-100 && interquartileRange()<=10)	
			flightState3();
	}
}

// for Hot Wire:
	/*
	PORT<>.DIR = what ever pin the Hot Wire is using
	PORT<>.OUT = again... pin
	delay x amount
	PORT<>.OUT = again... pin
	*/

void flightState0(void)
{
	iCurrentPressure = GET_Pressure();
	iCurrentTemperature = GET_Temperature();
	iCurrentAltitude = GET_Altitude(iCurrentTemperature, iCurrentPressure);
}

void flightState1(void)
{
	iCurrentPressure = GET_Pressure();
	iCurrentTemperature = GET_Temperature();
	iCurrentAltitude = GET_Altitude(iCurrentTemperature, iCurrentPressure);
}

void flightState2(void)
{
	iCurrentPressure = GET_Pressure();
	iCurrentTemperature = GET_Temperature();
	iCurrentAltitude = GET_Altitude(iCurrentTemperature, iCurrentPressure);
}

void flightState3(void)
{
	iCurrentPressure = GET_Pressure();
	iCurrentTemperature = GET_Temperature();
	iCurrentAltitude = GET_Altitude(iCurrentTemperature, iCurrentPressure);
}

float interquartileRange(void)
{
	return 0.0;
}

uint16_t GET_Altitude(uint16_t iTemp, uint32_t iPressure)
{
	return (uint16_t)0; 
}