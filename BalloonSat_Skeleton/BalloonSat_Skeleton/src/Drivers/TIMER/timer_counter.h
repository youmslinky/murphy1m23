/*
 * timer_counter.h
 *
 * Created: 9/7/2017 11:00:29 PM
 *  Author: danam
 */ 


#ifndef TIMER_COUNTER_H_
#define TIMER_COUNTER_H_

#include <asf.h>
//#define MCU_FREQUENCY 32000000UL :: Using F_CPU instead

void timer_counter_init(void);
void LED_Cycle(float fTargetFrequency, uint8_t iDutyCycle, uint16_t iConfigGroup);

#endif /* TIMER_COUNTER_H_ */