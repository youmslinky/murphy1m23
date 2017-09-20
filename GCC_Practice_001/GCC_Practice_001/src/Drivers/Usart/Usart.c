/*
 * Usart.c
 *
 * Created: 9/2/2017 2:16:50 PM
 *  Author: jdk0026
 */ 

#include "Usart.h"

void init_USART(void)
{
	static usart_serial_options_t usart_options = {
		.baudrate = 9600,
		.charlength = USART_CHSIZE_8BIT_gc,
		.paritytype = USART_PMODE_DISABLED_gc,
		.stopbits = true
	};
	PORTC.DIRSET = 0b00001000;
	PORTC.OUTSET = 0b00001000;
	stdio_serial_init(&USARTC0, &usart_options);
}