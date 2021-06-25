#include "ADC.h"
#include "LCD16X2.h"

/** Initialize ADC **/
void init_ADC(){
    ADMUX &= 0x00;      // Set PORTA0 to be ADC input bin
    ADMUX |= (0x40);     // Set Vref to AVCC
    ADCSRA |= 0x87;     // Enable ADC & adjust the scale of frequency devision to 128
}

/** Read the state of sensor **/
float read_ADC(){
    ADCSRA |= 0x40; // Start conversion
    while(!(ADCSRA & 0x10)); // Wait until conversion is done
    ADCSRA |= 0x10; // Get busy flag down
    return ADC;
}

/** Write temperature on the LCD **/
write_temp(float temp){
    char value[5];
    dtostrf(temp, 5, 1, value);     // Convert float variable to string
    lcd_command_write(0x01, shift); // clear the display before writing
    write_string(value, 5, shift);  // display string on LCD
}

/**### call this function in main.c ###**/
void run_procees(){
    DDRA = (0x03<<shift);   // Set PORTA0/1 to output
    DDRB = 0xFF;        // Set PORTB to output
    init_ADC();         // Initialize ADC
    lcd_init(shift);    // Initialize LCD
    float temperature;  // Variable to store temperature value
    while(1){
        _delay_ms(200);
        temperature = read_ADC()*0.4866; // Read ADC output and scale it by 2 to get temperature value
        write_temp(temperature);    // Write temperature on screen
        _delay_ms(4800);    // Wait for 5 seconds before rereading
    }


}

