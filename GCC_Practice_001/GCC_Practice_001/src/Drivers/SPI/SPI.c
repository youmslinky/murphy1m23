/*
 * SPI.c
 *
 * Created: 9/20/2017 7:48:34 PM
 *  Author: Johnny
 */ 

void SPI_init(void)
{
	PORTC.DIRSET = 0b10110000;
	PORTC.DIRCLR = 0b01000000;
	PORTC.OUTSET = 0x10110000;
	
	//spi control register
	SPIC.CTRL =    0b01010011;
}

void SPI_write(uint8_t data)
{
	SPIC.DATA = data;
	while(!(SPIC.STATUS>>7));
}

uint8_t SPI_read(void)
{
	write_SPI(0xff);
	return SPIC.DATA;
}

void SPI_SS_set(void) PORTC.OUTSET = 0b000010000;
void SPI_SS_clear(void) PORTC.OUTCLR = 0b00010000;