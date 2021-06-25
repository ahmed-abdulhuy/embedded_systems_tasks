/**
these functions are optimized for simulation
in file lab4_keypad_switches.pdsprj
**/
#ifndef SW_H_
#define SW_H_
#include <avr/io.h>
#include <util/delay.h>
#include "LCD16X2.h"

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS 0x02//PORTA1
#define LCD_EN 0x01//PORTA0
#define shift 0x00

void sw1_4();
void display_switch(int);

#endif
