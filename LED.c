#include <avr/io.h>
#include <util/delay.h>

#define LED1 0x04
#define LED2 0x02
#define LED3 0x04
#define LED4 0x08

void toggle(){
    DDRA = 0x06;    // Set PORTA1/2 to output
    DDRD = 0x0C;    // Set PORTD2/3 to output

    while(1){
        PORTA = LED1;
        _delay_ms(1000);

        PORTA = LED2;
        _delay_ms(1000);

        PORTA &= 0x00;
        PORTD = LED3;
        _delay_ms(1000);

        PORTD = LED4;
        _delay_ms(1000);

        PORTA = LED1 | LED2;
        PORTD |= LED3;
        _delay_ms(1000);

        PORTA &= 0x00;
        PORTD &= 0x00;
        _delay_ms(1000);
    }
}
