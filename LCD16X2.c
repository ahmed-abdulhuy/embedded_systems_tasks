#include "LCD16X2.h"

/** Write data on LCD **/
void lcd_data_write(char data, char shift){


    LCD_CONTROL_PORT |= ((LCD_RS|LCD_EN) << shift); // Enable LCD to read data
    LCD_DATA_PORT = data;   // Read command
     _delay_ms(3);  // Wait until writing is finished

     LCD_CONTROL_PORT &= LCD_RS<<shift;   //disable LCD to read
}

/** Write command on LCD **/
void lcd_command_write(char command, char shift){


    LCD_CONTROL_PORT |= (LCD_EN << shift);  // Enable LCD read command
    LCD_CONTROL_PORT &= (LCD_EN << shift);  // make sure that LCD is prepared to read command
    LCD_DATA_PORT = command;    // Read command
    _delay_ms(3);  // Wait until writing is finished
    LCD_CONTROL_PORT &= 0x00;   //disable LCD read/write

}


void lcd_init(char shift){

    lcd_command_write(0x01, shift);   // clear display
    lcd_command_write(0x38, shift);   // set LCD to 8-bit operation, 2 lines display and the font to 5.8
    lcd_command_write(0x0E, shift);   // Turn on display and cursor
    lcd_command_write(0x06, shift);   // Set mode to increment the address by  one and shift the cursor by one at time of writing
}

void write_string(char* line, char length, char shift){
    for(char i=0; i<length; i++){lcd_data_write(line[i], shift);}
}

/** Write my full-name and department name on LCD
######## call this function in main.c ########**/
void write_func(){

    DDRB = 0xFF;       // Set Port B to output
    DDRA = 0xFF;       // Set Port A to output

    lcd_init(0x06);        // Initialize LCD

   char* line_1 = "CSE 2020";   // Department title and year
   char* line_2 = "Ahmed Abdulhuy";     // Full-name

    write_string(line_1, 8, 0x06);  // Write first line
   lcd_command_write(0XC0, 0x06);   // Go to the second line of the LCD
   write_string(line_2, 14, 0x06);  // Write Full name

}


