/**
these functions are optimized for simulation
in file Interrupt.pdsprj
**/
#ifndef interrupt_H_
#define interrupt_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void toggleLED();
void intertupt();
void runi();
#endif // interrupt_H_
