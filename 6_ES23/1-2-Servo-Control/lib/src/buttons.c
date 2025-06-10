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
    int16_t BREG = 0x0F03;
    int16_t DREG = 0xC000;
    int16_t FREG = 0x0039;
    //buttons and switches
    LATB = (LATB & !BREG) ^ BREG;   //SW5, SW6, SW7, BTNR, BTNU, BTNL
    ANSELB = ANSELB & !BREG;          
    LATD = (LATD & !DREG) ^ DREG;   //SW3, SW4
    LATF = (LATF & !FREG) ^ FREG;   //SW1, SW2, SW0, BTNC
    
    timer_init(PB_FRQ, 3, 1, 1, 6);
    timer_init(PB_FRQ, 4, 1, 1, 6);
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
        if(timer == 3)
        {
            startStopWatch3(&button->intrptDone, waitTime);
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