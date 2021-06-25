#include "Keyboard.h"

/**set one row to output low and other rows to input**/
void setRow(char row){
    DDRD &= 0xF0;
    DDRD |= row;
    PORTD &= ~row;
}
/**set one column to pull up input and other columns to normal input**/
void pullUpCol(char col){
    PORTD |= col;
}

/**remove pull up from column**/
void pullDownCol(char col){
    PORTD &= 0x0F;
}

/**get switch value**/
char switchVal(char sw){
    return PIND & sw;
}

/**Scan all switches states**/
char scanSwitchs(){
    char switch_ID = 0x00;
    char input = 0x00;
    for(char i=0x00; i<0x04; i++){
        setRow(1<<i);
        for(char j=0x04; j<0x08; j++){
            pullUpCol(1<<j);
            input = PIND;
            if(!(input & 1<<j)){
                switch_ID = i | (j-4)<<0x04;
                return switch_ID;
            }
            pullDownCol(1<<j);
        }
    }
    return 0xFF;
}

/**write switch ID on LCD**/
void writeSwitchID(char sw){
    char id = (0xF0 & sw)>>4;
    id += (0x0F & sw)*4;

    lcd_command_write(0x01, shift);  // Clear display
    if(id<0x0A){id += '0';}
    else{id = id - 0x0A + 'A';}
    lcd_data_write(id, shift);
}

/**### call this function in main.c ###**/
void run(){
    DDRD &= 0x00;   // Set PORTD to input
    DDRA |= 0x03;   // Set PORTA0/1 to output
    DDRB |= 0xFF;   // Set PORTB to output

    lcd_init(shift);    // Initialize LCD

    char sw;
    while(1){
        sw = scanSwitchs();
        if(~sw){writeSwitchID(sw);}

    }

}
