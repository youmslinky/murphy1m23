/*
 * pressure.c
 *
 * Created: 9/20/2017 7:31:21 PM
 *  Author: Vegas
 */ 

#include "Drivers/PRESSURE/pressure.h"

void SPI_Init(void)
{
	PORTC.DIRSET = 0b10110000; // given SPI Boards are set for PORTC, Pin 4 is slave pin
	PORTC.DIRCLR = 0b01000000; // Turn only one pin as input
	PORTC.OUTSET = 0b10110000; // When no data is given, output is consistently HI
	SPIC.CTRL = 0b01010011; //View registers in manual for info
}

void SPI_Write(uint8_t iData)
{
	SPIC.DATA = iData;
	while (!(SPIC.STATUS>>7));
}

uint8_t SPI_Read(void)
{
	SPI_Write(0xFF);
	return SPIC.DATA;
}

void MS5607_Init(void)
{
	PORTC.OUTCLR = 0b00010000; // Slave Select :: Active_HI
	SPI_Write(0x1E); // RESET CMD from manual: page 10
	PORTC.OUTSET = 0b00010000; // Slave Select :: Active_LO
	
	// Read pg 10 of manual :: This is for the RESET CMD
	C1 = PROM_Read(0xA2);
	C2 = PROM_Read(0xA4);
	C3 = PROM_Read(0xA6);
	C4 = PROM_Read(0xA8);
	C5 = PROM_Read(0xAA);
	C6 = PROM_Read(0xAC);
}

uint16_t PROM_Read(uint8_t iCommand)
{
	uint16_t iData;	
	PORTC.OUTCLR = 0b00010000; // Slave Select :: Active_HI
	SPI_Write(iCommand);
	
	// Bit shifting for 2 bytes of data
	iData = ((uint16_t)SPI_Read())<<8;
	iData += SPI_Read();
	
	PORTC.OUTSET = 0b00010000; // Slave Select :: Active_LO
	delay_ms(1); // Add some sort of delay or nothing will happen
	return iData;
}

uint32_t DATA_Read(uint8_t iCommand)
{
	uint32_t iData;
	PORTC.OUTCLR = 0b00010000; // Slave Select :: Active_HI
	
	//Commands correspond to pages 4 and 10 (OSR data, the higher the better(under most cases) but conversion times will increase)
	SPI_Write(iCommand);
	
	PORTC.OUTSET = 0b00010000; // Slave Select :: Active_HI
	delay_ms(9); // What ever the OSR conversion time, use that
	PORTC.OUTCLR = 0b00010000; // Slave Select :: Active_LO
	SPI_Write(0x00);
	
	
	// Bit shifting for 3 bytes of data
	iData = ((uint32_t)SPI_Read())<<16;
	iData += ((uint32_t)SPI_Read())<<8;
	iData += ((uint32_t)SPI_Read());
	
	PORTC.OUTSET = 0b00010000; // Slave Select :: Active_HI
	// Add delay here if no data return
	return iData;
	
}

uint32_t GET_Pressure(void)
{
	// use OSR 12bit RES :: the highest
	uint32_t iD1 = DATA_Read(0x48); // D1 MAX OSR
	uint32_t iD2 = DATA_Read(0x58); // D2 MAX OSR
	
	//review page 8 of MS Manual
	int64_t dT = (int64_t)iD2 - C5 * 256; // 2^8 = 256;
	int64_t P;
	
	return (uint32_t)P;
}