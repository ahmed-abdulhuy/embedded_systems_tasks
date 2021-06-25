/**
these functions are optimized for simulation
in file lab4_keypad_switches.pdsprj
**/
#ifndef Keyboard_H_
#define Keyboard_H_
#include "SW.h"

void setRow(char);
void pullUpCol(char);
void pullDownCol(char);
char switchVal(char);
char scanSwitchs();
void writeSwitchID(char);
void run();

#endif // Keyboard_H_
