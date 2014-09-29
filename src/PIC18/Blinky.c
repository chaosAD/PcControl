/* 
 * File:   Blinky.c
 * Author: Tze-Ven Poh
 *
 * Created on January 1, 2005, 7:57 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\\18c.h"
#ifndef __18CXX
# include "usart.h"
#endif // __18CXX

#pragma config OSC = INTIO67, PWRT = ON, WDT = OFF, DEBUG = ON, LVP = OFF

void shortDelay() {
    unsigned long i;
    for(i = 0; i < 100; i++);
}

void configureLED() {
    TRISCbits.RC0 = 0;
}

void setLED() {
    PORTCbits.RC0 = 1;
}

void resetLED() {
    PORTCbits.RC0 = 0;
}

/*
 * 
 */
int main(int argc, char** argv) {
    configureLED();
//    configureUSART();
    OSCCONbits.IRCF = 7;
//    OpenUSART(, );
    while(1) {
        WriteUSART(0x6a);
        // wait till all bits are transmitted
        // ...
        shortDelay();       // Delay for 100 cycles
    }
/*
    while(1) {
        setLED();
        shortDelay();
        resetLED();
        shortDelay();
    }
 */
    return (EXIT_SUCCESS);
}

