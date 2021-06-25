/**
these functions are optimized for simulation
in file lab3_7seg.pdsprj
**/
#ifndef seg_H_
#define seg_H_
#include <avr/io.h>
#include <util/delay.h>

#define D0 0x01
#define D1 0x02

void toggleSeg(char, char);
void counter();

#endif // seg_H_
