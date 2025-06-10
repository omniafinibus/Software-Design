/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Personal libraries*/
#include "config.h"
#include "swatch_clock.h"

/* Local variables */
clk crntTime;
clk alrmTime;

char alrmStatus = 0;
char alrmRinging = 0;
char editAlrm = 0;

void init_clock()
{    
    //clock object
    crntTime.hour = 0;
    crntTime.minute = 0;
    crntTime.second = 0;
    
    alrmTime.hour = 0;
    alrmTime.minute = 0;
    alrmTime.second = 0;
    alrmRinging = 0;
    alrmStatus = 0;
                
    //timer 1
    T1CON = 0x0030;             //Turn timer 1 off and set prescalar to 256
    TMR1 = 0x0;                 //Set timer to 0
    PR1 = PB_FRQ/256;           //Set register to 62500 for a 1 sec interrupt
    T1CONbits.ON = 1;           //Turn timer 1 on
    
    //interrupts
    IPC1SET = 0x001F;           //Set priority to 7 and sub-priority to 3
    IFS0bits.T1IF = 0;          //Clear interrupt flag
    IEC0bits.T1IE = 1;          //Enable interrupt
    macro_enable_interrupts();  //Enable interrupts in the CPU
}

void incVal(int value)
{
    switch(value)
    {
        case 0:
            if (crntTime.hour<23)
            {
                crntTime.hour++;
            }
            else
            {
                crntTime.hour = 0;
            }
        break;
        case 1:
            if (crntTime.minute<59)
            {
                crntTime.minute++;
            }
            else
            {
                crntTime.minute = 0;
            }
            break;
        case 2:
            if (alrmTime.hour<23)
            {
                alrmTime.hour++;
            }
            else
            {
                alrmTime.hour = 0;
            }
            break;
        case 3:
            if (alrmTime.minute<59)
            {
                alrmTime.minute++;
            }
            else
            {
                alrmTime.minute = 0;
            }
            break;
    }
}

void showAlrm(int onOff)
{
    editAlrm = onOff;
    if(onOff)
    {
        displayTime(alrmTime.hour, alrmTime.minute, alrmTime.second, alrmStatus);
    }
    else
    {
        displayTime(crntTime.hour, crntTime.minute, crntTime.second, alrmStatus);
    }
}

void checkAlrm(int on)
{
    if(on && alrmTime.hour == crntTime.hour && alrmTime.minute == crntTime.minute && !alrmRinging)
    {
        alrmRinging = 1;
    }
}

void switchAlrm()
{
    alrmStatus = !alrmStatus;
}

void stopRing()
{
    alrmRinging = 0;
}

int alrmRing()
{
    return(alrmRinging);
}

void __ISR(_TIMER_1_VECTOR, ipl7auto) Timer1Handler(void) 
{
    if(crntTime.second<59)
    {
        crntTime.second++;
        if(alrmRinging)
        {
            incBright(5);  //increase the brightness by 5 with white light
        }
    }
    else if (crntTime.minute<59)
    {
        crntTime.second = 0;
        crntTime.minute++;
        checkAlrm(alrmStatus);
    }
    else if (crntTime.hour<23)
    {
        crntTime.second = 0;
        crntTime.minute = 0;
        crntTime.hour++;
        checkAlrm(alrmStatus);
    }
    else 
    {
        crntTime.second = 0;
        crntTime.minute = 0;
        crntTime.hour = 0;
        checkAlrm(alrmStatus);
    }
    
    if(!editAlrm)
    {
        displayTime(crntTime.hour, crntTime.minute, crntTime.second, alrmStatus);
    }
    
    IFS0bits.T1IF = 0; //Clear the interrupt flag
}