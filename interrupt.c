#include "interrupt.h"

/**toggling LED each 1 second**/
void toggleLED(){
    for(char i=0; i<8; i++){
        PORTC = 1<<i;
        _delay_ms(1000);
    }
}

/** Interrupt Service Routine for external interrupt Pin INT0**/
ISR(INT0_vect){
    PORTC |= 0xFF;
    _delay_ms(1000);
}

/**enable external interrupt on INT0**/
void interrupt(){
    GICR |= 1<<0x06; // Enable interrupt on Pin INT0
    MCUCR = 0x02;   // Set interrupt to to falling edge

    sei();  // Enable global interrupt
}

/**### call this function in main.c ###**/
void runi(){
    DDRC = 0xFF;
    interrupt();
    while(1){
        toggleLED();
    }
}
