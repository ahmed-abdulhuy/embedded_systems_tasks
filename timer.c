#include "timer.h"
volatile char counter_, tog;

/**initialize counter 0 & 1 settings **/
void initTimer0_1(){
    DDRB = 0x08;    // set pin PB7 to output
    DDRC = 0xFF;    // set port c to output

    //set timer 0 to CTC mode, OC0 to toggle mode & scale clk by 8
    TCCR0 = (1<<WGM01) | (1<<CS01) | (1<<COM00);
    OCR0 = 99;  // set counter 0 TOP value

    TCCR2 = (1<<WGM01) | (1<<CS01); //set timer 2 to CTC mode & scale clk by 256
    OCR2 = 249; // set counter 2 TOP value

    TIMSK = (1<<OCIE0) | (1<<OCIE2); // set compare interrupt mode for timer 0 and 2

    sei();  // initialize global interrupt

}

/**call this function in main.c**/
void startTimer(){
    initTimer0_1();

    while(1){
        if(counter_ >= 125){ // wait until 125 overflow of timer 0 occur
            PORTC = tog;
            tog ^= 0xFF;
            counter_ = 0;
        }
    }
}

ISR(TIMER2_COMP_vect){counter_++;}
ISR(TIMER0_COMP_vect){}
