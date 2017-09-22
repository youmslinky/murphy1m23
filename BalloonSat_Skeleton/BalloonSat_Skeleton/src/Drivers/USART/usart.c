/*
 * usart.c
 *
 * Created: 9/7/2017 10:54:28 PM
 *  Author: danam
 */ 

 #include <asf.h>
 #include "Drivers\USART\usart.h"

 void USART_Init(void)
 {
	static usart_serial_options_t usart_options = 
	{
		.baudrate = 9600,
		.charlength = USART_CHSIZE_8BIT_gc,
		.paritytype = USART_PMODE_DISABLED_gc,
		.stopbits = true
	};

	PORTC.DIRSET = 0b00001000; // Only change the direction of pin:3
	PORTC.OUTSET = 0b00001000; 
 }
