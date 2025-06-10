/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Your own custom made libraries */
#include "debounce.h"

uint64_t waitTime;

void init_debounce()
{   
//    *BTNU.readVal = PORTBbits.RB1;
//    *BTNL.readVal = PORTBbits.RB0;
//    *BTNC.readVal = PORTFbits.RF0;
//    *BTNR.readVal = PORTBbits.RB8;
//    *BTND.readVal = PORTAbits.RA15;
    TRISBbits.TRISB1 = 1; // RB1 (BTNU) configured as input
    ANSELBbits.ANSB1 = 0; // RB1 (BTNU) disabled analog
    TRISBbits.TRISB0 = 1; // RB1 (BTNL) configured as input
    ANSELBbits.ANSB0 = 0; // RB1 (BTNL) disabled analog
    TRISBbits.TRISB8 = 1; // RB8 (BTNR) configured as input
    ANSELBbits.ANSB8 = 0; // RB8 (BTNR) disabled analog
    TRISFbits.TRISF4 = 1; // RF0 (BTNC) configured as input
    TRISAbits.TRISA15 = 1; //RA15 (BTND) configured as input
    
    waitTime = (PB_FRQ * 20) / (2 * 1000); //calculate amount of oscillations need for requested time
    return;
}

int readBtn(button btnVal)
{    
    //check if button is released since the previous true
    if(btnVal.released)
    {
        //check if the button has been pressed at least once and has not been pressed before
        if(!btnVal.pressed)
        {
            if(PORTBbits.RB8)
            {
                btnVal.start = _CP0_GET_COUNT();
                btnVal.pressed = 1;
                return 0;
            }
            else
            {
                //wait for the next main loop
                return 0;
            }
        }
        else
        {
            //calculate how much time has passed since the button was pressed
            btnVal.difference = _CP0_GET_COUNT() - btnVal.start;

            //check if enough time has passed and the button has been released
            if(btnVal.difference > waitTime && !PORTBbits.RB8)
            {   
                //reset variables
                btnVal.difference = 0;
                btnVal.released = 1;
                btnVal.pressed = 0;
                
                return 1;
            }
            else
            {
                //wait for the next main loop
                return 0;
            }
        }
    }
    else
    {
        if(PORTBbits.RB8)
        {
            return 0;
        }
        else
        {
            btnVal.released = 1;
            return 0;
        }
    }
}