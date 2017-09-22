/*
 * Pressure.c
 *
 * Created: 9/2/2017 2:15:55 PM
 *  Author: mjs0052
 */ 
uint16_t c1;
uint16_t c2;
uint16_t c3;
uint16_t c4;
uint16_t c5;
uint16_t c6;
uint16_t c7;

void pressure_init(void)
{
	SPI_SS_clear();
	SPI_write(0x1e); //reset command to ms5607
	SPI_SS_set();
	for(int i=0;i<7;i++)
	{
		uint8_t address = 0xA2;
		c[i] = pressure_prom_read(address);
		address += 2;
	}
	c1 = pressure_prom_read(0xa2)
}

uint16_t pressure_prom_read(uint8_t command)
{
	uint16_t data;
	SPI_SS_clear();
	SPI_write(command);
	//data from sensor is 2 bytes/16 bits, so need to shift
	data = ((uint16_t)SPI_read())<<8;
	data += SPI_read();
	SPI_SS_set();
	delay_ms(1);
	return data;
}

uint32_t pressure_data_read(uint8_t command)
{
	uint32_t data;
	SPI_SS_clear();
	SPI_write(command);
	SPI_SS_set();
	delay_ms(10);
	SPI_SS_clear();
	SPI_write(0x00); //we want adc data
	data = ((uint32_t)SPI_read())<<16;
	data += ((uint32_t)SPI_read())<<8;
	data += SPI_read();
	SPI_SS_set();
	delay_ms(1);
	return data;
}

uint32_t pressure_get(void)
{
	uint32_t D1 = pressure_data_read(0x48);
	uint32_t D2 = pressure_data_read(0x48);
	int32_t dT = D2 - c5 * 
}