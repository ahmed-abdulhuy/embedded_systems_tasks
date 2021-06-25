#include "seg.h"
/**toggle between segments for 10 mile seconds**/
void toggleSeg(char mono_seg, char tens_seg){
    for(char _ = 0; _<10; _++){
        PORTD = ~D0; // Enable write on Mono's 7-seg
        PORTC = mono_seg;     // Write on Mono's 7-seg
        _delay_us(500);

        PORTD = ~D1; // Enable write on tens' 7-seg
        PORTC = tens_seg;     // Write on tens' 7-seg
        _delay_us(500);
    }
}

/** Run counter
### call this function in main.c ###**/
void counter()
{

    DDRC = 0x0F;    // Set Port C 0-3 to output
    DDRD = 0x03;    // Set Port D0, D1 to output
    char mono_seg = 0, tens_seg = 0;    // mono & tens values

    while(1){

        toggleSeg(mono_seg, tens_seg);

        mono_seg++;
        if(mono_seg == 0x0A){       // Check if mono_seg variable value's consist of more than one digit
            mono_seg = 0x00;
            tens_seg++;

            if(tens_seg == 0x0A){   // Check if tens_seg variable value's consist of more than one digit
                tens_seg = 0x00;
            }
        }
    }

}

