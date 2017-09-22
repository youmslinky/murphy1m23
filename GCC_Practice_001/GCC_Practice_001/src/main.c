/**
 * \file
 *
 * \brief Empty user application template
 *
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
#include <asf.h>
#include "Drivers\Drivers.h"

#define LED_ON PORTE.OUT = 0b00000000;
#define DEBUG_LED
//#define DEBUG_USART

int main (void)
{
	sysclk_init();
	board_init();
	
	initLED();

	init_USART();
	
	//nvm_eeprom_write_byte(0,55);
	#ifdef DEBUG_USART
	while(1)
	{
		printf("eeprom at address 0: %i  \n",nvm_eeprom_read_byte(0));
		delay_ms(2000);
	}
	#endif
	

	#ifdef DEBUG_LED
	while (1)
	{
		for(int i=0;i<4;i++)
		{
			PORTE.OUT = ~i<<4;
			flashLED(i);
			for(int j=0;j<10;j++)
			{
				PORTE.OUT ^= 1<<7;
				delay_s(1);
			}
		}
		offLED();
		delay_s(5);
	}
	#endif

	
	while(1)
	{
		uint8_t flightState = nvm_eeprom_read_byte(0);
	}

}