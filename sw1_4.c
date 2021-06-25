#include "SW.h"

/** print the switch name on LCD **/
void display_sw(int sw_number){
    lcd_command_write(0x01, shift);  // Clear display
    char* sw = "SW0";       // Switch name
    switch(sw_number){      // set switch name based on input of PORTD
        case 0xE0:
            sw[2] = '1';
            break;
        case 0xD0:
            sw[2] = '2';
            break;
        case 0xB0:
            sw[2] = '3';
            break;
        case 0x70:
            sw[2] = '4';
            break;
        default:
            sw[2] = '!';
    }
    write_string(sw, 3, shift);  // Display switch name on LCD
}
/**### call this function in main.c ###**/
void sw1_4(){
    DDRD &= 0x00;   // Set PORTD to input
    DDRA |= 0x03;   // Set PORTA0/1 to output
    DDRB |= 0xFF;   // Set PORTB to output
    PORTD &= 0x00;
    lcd_init(shift);    // Initialize LCD
    while(1){
        if(PIND != 0xFE){   // if the default value of PIND changed do some action
            _delay_ms(10);  // Wait 0.04 second until button be stable
            display_sw(PIND&0xF0);   // Display on LCD
            _delay_ms(10);      // Wait until button be stable again
        }
    }



}
