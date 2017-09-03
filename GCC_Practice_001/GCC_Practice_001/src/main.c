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

int main (void)
{
	sysclk_init();
	board_init();
	
	#ifdef DEBUG_LED
		printf("ASDADA");
	#endif
	
	while (1)
	{
		ledRotation(256);
	}
	
	//hello 
	//no

}
