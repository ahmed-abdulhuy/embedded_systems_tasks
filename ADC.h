/**
these functions are optimized for simulation
in file ADC_LM35.pdsprj
**/
#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "LCD16X2.h"

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS 0x02//PORTA1
#define LCD_EN 0x01//PORTA0
#define shift 0x06

void init_ADC();
float read_ADC();
void read_display();
void write_temp(float);
#endif // ADC_H_
