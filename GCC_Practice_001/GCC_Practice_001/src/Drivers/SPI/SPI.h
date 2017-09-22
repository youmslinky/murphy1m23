/*
 * SPI.h
 *
 * Created: 9/20/2017 7:49:20 PM
 *  Author: Johnny
 */ 


#ifndef SPI_H_
#define SPI_H_

void SPI_init(void);
void SPI_write(uint8_t data);
uint8_t SPI_read(void);
void SPI_SS_set(void);
void SPI_SS_clear(void);


#endif /* SPI_H_ */