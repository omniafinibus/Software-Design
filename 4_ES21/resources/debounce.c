/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Your own custom made libraries */
#include "debounce.h"

uint32_t waitTime;

int btnVal;
int btnPressed[5];
int btnReleased[5];
uint32_t startTimer[5];
uint32_t timeDifference[5];
int i;

void debounce_init(float sec)
{
    //initialize all buttons
    for(i=0; i<5; i++)
    {
        btnPressed[i] = 0;
        btnReleased[i] = 1;
        startTimer[i] = 0;
        timeDifference[i] = 0;
    }
    
    TRISBbits.TRISB1 = 1; // RB1 (BTNU) configured as input
    ANSELBbits.ANSB1 = 0; // RB1 (BTNU) disabled analog
    TRISBbits.TRISB0 = 1; // RB1 (BTNL) configured as input
    ANSELBbits.ANSB0 = 0; // RB1 (BTNL) disabled analog
    TRISFbits.TRISF4 = 1; // RF0 (BTNC) configured as input
    TRISBbits.TRISB8 = 1; // RB8 (BTNR) configured as input
    ANSELBbits.ANSB8 = 0; // RB8 (BTNR) disabled analog
    TRISAbits.TRISA15 = 1; // RA15 (BTND) configured as input
    waitTime = (PB_FRQ / 2)*(sec); //calculate amount of oscillations need for requested time
    return;
}

int readBtn(char button)
{
    int buttonInt;
    //read requested button state
    switch(button)
    {
        case 'U':
            btnVal = PORTBbits.RB1;
            buttonInt = 0;
        break;
            
        case 'L':
            btnVal = PORTBbits.RB0;
            buttonInt = 1;
        break;
            
        case 'C':
            btnVal = PORTFbits.RF0;
            buttonInt = 2;
        break;
            
        case 'R':
            btnVal = PORTBbits.RB8;
            buttonInt = 3;
        break;
            
        case 'D':
            btnVal = PORTAbits.RA15; 
            buttonInt = 4;
        break;
    }
    
    //check if button is released since the previous true
    if(btnReleased[buttonInt])
    {
        //check if the button has been pressed at least once and has not been pressed before
        if(!btnPressed[buttonInt])
        {
            if(btnVal)
            {
                startTimer[buttonInt]=_CP0_GET_COUNT();
                btnPressed[buttonInt]=1;
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
            timeDifference[buttonInt]=_CP0_GET_COUNT()-startTimer[buttonInt];

            //check if enough time has passed and the button has been released
            if(timeDifference[buttonInt]>waitTime && !btnVal)
            {   
                //reset variables
                timeDifference[buttonInt]=0;
                btnReleased[buttonInt]=1;
                btnPressed[buttonInt]=0;
                
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
        if(btnVal)
        {
            return 0;
        }
        else
        {
            btnReleased[buttonInt]=1;
            return 0;
        }
    }
}