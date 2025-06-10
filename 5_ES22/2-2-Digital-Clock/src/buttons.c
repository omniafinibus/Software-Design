/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Personal libraries*/
#include "config.h"
#include "buttons.h"
#include "swatch_fsm.h"

/* Variables */
volatile char intrptDone = 0;
volatile btn CNswitch;
volatile int counter = 0;

void init_btns()
{
    int16_t AREG = 0x8000;
    int16_t BREG = 0x0F03;
    int16_t DREG = 0xC000;
    int16_t FREG = 0x0039;
    //buttons and switches
    LATA = (LATA & !AREG) ^ AREG;   //BTND
    LATB = (LATB & !BREG) ^ BREG;   //SW5, SW6, SW7, BTNR, BTNU, BTNL
    ANSELB = ANSELB & !BREG;          
    LATD = (LATD & !DREG) ^ DREG;   //SW3, SW4
    LATF = (LATF & !FREG) ^ FREG;   //SW1, SW2, SW0, BTNC
        
    //timer 4
    T4CON = 0x0070;        //turn timer 2 off and set prescalar to 256
    TMR4 = 0x0;            //clear timer register
    PR4 = PB_FRQ/256;      //timer will interrupt every second
    T4CONbits.ON = 1;      //start timer
    
    //interrupt for timer 4
    IPC4SET = 0x001B;      //set priority to 6 and sub-priority to 3
    IFS0bits.T4IF = 0;     //clear interrupt flag
    
    //interrupt for F3
    CNCONFbits.ON = 0;      //turn f register change notification off
    CNENFbits.CNIEF3 = 1;   //set SW0 as input for change notice
    CNSTATFbits.CNSTATF3 = PORTFbits.RF3;
    IFS1bits.CNFIF = 0;     //clear the interrupt flag
    IEC1bits.CNFIE = 1;     //enable change notice interrupt
    IPC8 = 0x1C00;          //set priority to 7 and sub priority to 0
    CNCONFbits.ON = 1;      //turn f register change notification on

    macro_enable_interrupts();  //Enable interrupts in the CPU
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

char btnCounter(btn *button, char btnPin, int waitTime)
{
    if(btnPin && !button->counter) //button has been pressed for the first time
    {
        button->counter = 1;
        PR4 = (PB_FRQ*waitTime)/(1000*256); //calculate how long the interrupt needs to be delayed
        TMR4 = 0x0;
        IEC0bits.T4IE = 1;  //enable interrupt
        intrptDone = 0;
    }
    else if(!btnPin) //button isn't pressed down or is bouncing
    {
        IEC0bits.T4IE = 0;  //disable interrupt
        button->counter = 0;
        button->pressed = 0;
    }
    else if(intrptDone && !button->pressed) //the interrupt has finished and the button has not been pressed before
    {
        button->pressed = 1;    //prevent the function to output more than once
        return(1);
    }
    return(0);
}

void __ISR(_TIMER_4_VECTOR, ipl6auto) Timer4Handler(void)
{
    intrptDone = 1;     //notify function that the interrupt occurred
    IFS0bits.T4IF = 0;  //clear interrupt flag
}

void __ISR(_CHANGE_NOTICE_VECTOR, ipl7auto) ChangeNoticeHandler(void)
{
    showAlrm(nextMajStng());                //go to the next major setting
//    CNSTATFbits.CNSTATF3 = PORTFbits.RF3;   //update current STAT value (otherwise interrupt loops)
    PORTF;                                      
    IFS1bits.CNFIF = 0;                     //clear interrupt flag
}