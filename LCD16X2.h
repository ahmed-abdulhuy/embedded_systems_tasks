/**
these functions are optimized for simulation
in file LED_7Seg_LCD.pdsprj
**/

#ifndef LCD16X2_H_
#define LCD16X2_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include<string.h>

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS 0x02//PORTA1
#define LCD_EN 0x01//PORTA0

void lcd_data_write(char, char);
void lcd_command_write(char , char);
void lcd_init(char);
void write_string(char*, char, char);

#endif /* LCD16X2_H_ */
