/**
these functions are optimized for simulation
in file 07_Timers_1.pdsprj
**/
#ifndef timer_H_
#define timer_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initTimer0_1();
void startTimer();

#endif
