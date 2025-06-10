/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "audio.h"

/* Local variables */
int resolution = 0;
int PWMStep[41];
char currentStep = 0;

void init_audio()
{
    //calculate the resolution
    resolution = 41;
    
    //define all values of PWM width to create a sine wave
    int i;
    for(i = 0; i < resolution; i++)
    {
        PWMStep[i] = (100*sin((2*M_PI*i)/resolution));
    }
    
    //initialize speaker
    TRISBbits.TRISB14 = 0;
    ANSELBbits.ANSB14 = 0;
    
    //initialize timer 2
    T2CON = 0x0020;             //turn timer 2 off and set pre-scalar to 1
    TMR2 = 0x0;                 //set timer value to 0
    PR2 = PB_FRQ/(4*200*resolution); //set the timer to 200Hz
    
    //initialize OC1
    OC1CONbits.ON = 0;          //turn off OC1
    RPB14R = 0x0C;              //connect OC1 to audio pin
    OC1RS = (PR2+1)/2;          //set OC register to 50%
    OC1CON = 0x8006;            //turn OC1 on, use timer 2 as source and turn on PWM without fault pin
    
    //initialize interrupts
    IPC2SET = 0x001D;           //Set priority to 7 and sub-priority to 1
    IFS0bits.T2IF = 0;          //Clear interrupt flag
    IEC0bits.T2IE = 1;          //Turn interrupt on
    macro_enable_interrupts();  //Enable interrupts in the CPU
}

void changeFreq(int freq)
{
    //set the timer to the correct frequency for audio
    T2CONbits.ON = 0;  //turn off timer 2
    PR2 = PB_FRQ/(2*4*freq*41);
    T2CONbits.ON = 1;  //turn timer 2 on
}

void switchAudio(char onOff)
{
    TMR2 = 0x0;
    T2CONbits.ON = onOff;
}

void __ISR(_TIMER_2_VECTOR, ipl7auto) Timer2Handler(void) 
{
    //check if PWM step is at the end of the array
    if(currentStep == (resolution-1))
    {
        currentStep = 0;
    }
    else 
    {
        currentStep++;
    }
    
    //update PWM width
    OC1RS = (PR2*PWMStep[currentStep])/100;
    
    //Clear the interrupt flag
    IFS0bits.T2IF = 0;
}