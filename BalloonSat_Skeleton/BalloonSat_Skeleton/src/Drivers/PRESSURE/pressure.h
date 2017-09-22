/*
 * pressure.h
 *
 * Created: 9/20/2017 7:31:38 PM
 *  Author: Vegas
 */ 

#include <asf.h>

#ifndef PRESSURE_H_
#define PRESSURE_H_

uint16_t C1;
uint16_t C2;
uint16_t C3;
uint16_t C4;
uint16_t C5;
uint16_t C6;

void SPI_Init(void);
void SPI_Write(uint8_t iData);
uint8_t SPI_Read(void);
void MS5607_Init(void);
uint16_t PROM_Read(uint8_t iCommand);
uint32_t DATA_Read(uint8_t iCommand);
uint32_t GET_Pressure(void);

#endif /* PRESSURE_H_ */