/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Personal libraries*/
#include "config.h"
#include "buttons.h"
#include "timer.h"

/* Variables */

void init_btns()
{
    TRISBbits.TRISB1 = 1;   // RB1 (BTNU) configured as input
    ANSELBbits.ANSB1 = 0;   // RB1 (BTNU) disabled analog
    TRISBbits.TRISB0 = 1;   // RB1 (BTNL) configured as input
    ANSELBbits.ANSB0 = 0;   // RB1 (BTNL) disabled analog
    TRISFbits.TRISF4 = 1;   // RF0 (BTNC) configured as input 
    TRISBbits.TRISB8 = 1;   // RB8 (BTNR) configured as input
    ANSELBbits.ANSB8 = 0;   // RB8 (BTNR) disabled analog
//    TRISAbits.TRISA15 = 1; // RA15 (BTND) configured as input
    
    TRISFbits.TRISF3 = 1;   // RF3 (SW0) configured as input
    TRISFbits.TRISF5 = 1;   // RF5 (SW1) configured as input
    TRISFbits.TRISF4 = 1;   // RF4 (SW2) configured as input 
    TRISDbits.TRISD15 = 1;  // RD15 (SW3) configured as input
    TRISDbits.TRISD14 = 1;  // RD14 (SW4) configured as input
    TRISBbits.TRISB11 = 1;  // RB11 (SW5) configured as input
    ANSELBbits.ANSB11 = 0;  // RB11 (SW5) disabled analog
    TRISBbits.TRISB10 = 1;  // RB10 (SW6) configured as input
    ANSELBbits.ANSB10 = 0;  // RB10 (SW6) disabled analogBasys MX3? Board Reference Manual
    TRISBbits.TRISB9 = 1;   // RB9 (SW7) configured as input
    ANSELBbits.ANSB9 = 0;   // RB9 (SW7) disabled analog
    
    timer_init(PB_FRQ, 5, 1, 0, 6, 2);
    timer_init(PB_FRQ, 4, 1, 0, 6, 2);
}

char btnClick(btn *button, char btnPin)
{
    if(btnPin == 1 && !button->pressed)
    {
        button->counter++;    
        button->pressed = button->counter >> 4; //00010000 >> 4   = 00000001
        return button->pressed;
    }
    else if(button->pressed && !btnPin)
    {
        button->counter = 0;
        button->pressed = 0;
        return(0);
    }
    return(0);
}

char btnHold(btn *button, char btnPin)
{
    if(btnPin && button->counter < 16)
    {
        button->counter++;
        return(0);
    }
    else if(btnPin == 1 && button->counter >= 16)
    {
        return(1);
    }
    button->counter = 0;
    return(0);
}

char intervalClick(btn *button, char btnPin, int waitTime, int timer)
{
    if(button->intrptDone) //the interrupt has finished and the button has not been pressed before
    {
        button->intrptDone = 0;
        button->pressed = 0;
        timer_detachInterrupt(timer);
        return(1);
    }
    else if(btnPin && !button->pressed) //button has been pressed for the first time
    {
        button->pressed = 1;
        button->intrptDone = 0;
        if(timer == 5)
        {
            startStopWatch5(&button->intrptDone, waitTime);
        }
        else if (timer == 4)
        {
            startStopWatch4(&button->intrptDone, waitTime);
        }
    }
    else if(!btnPin) //button isn't pressed down or is bouncing
    {
        timer_detachInterrupt(timer);
        button->pressed = 0;
    }
    return(0);
}