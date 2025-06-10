/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "servo.h"

/* Local variables */
const int maxPulseUs = 2100;
const int minPulseUs = 900;
const int pulseCycleMs = 20;
const int angleRange = 90;
const int servoTimer = 2;
char minAngle, maxAngle;

unsigned char servo_init(int fpb, int channel, int angle)
{
    maxAngle = angleRange/2;
    minAngle = maxAngle - angleRange;
    TRISAbits.TRISA15 = 0; //servo 1
    unsigned int initWidth = ((maxPulseUs-minPulseUs)/angleRange)*angle+((maxPulseUs+minPulseUs)/2);
    pwm_init(fpb, servoTimer, channel, 20);
    pwm_setWidth(servoTimer, channel, initWidth);
    macro_enable_interrupts();
}

void servoSetPos(int channel, int angle)
{
    unsigned int newWidth = ((maxPulseUs-minPulseUs)/angleRange)*angle+((maxPulseUs+minPulseUs)/2);
    pwm_setWidth(servoTimer, channel, newWidth);
}

char updateAngle(char incr, char angle)
{    
    char newAngle = angle;
    if(angle > maxAngle)
    {
        newAngle = 45;
    }
    else if(angle < minAngle)
    {
        newAngle = -45;
    }
    
    if(angle < (maxAngle - 5) || angle > (minAngle + 5))
    {
        if(incr == 1)
        {
            newAngle = newAngle + 5;
        }
        else if(incr == 0)
        {
            newAngle = newAngle - 5 ;            
        }
    }
    return(newAngle);
}

//OC1 Interrupt
void __ISR(_OUTPUT_COMPARE_1_VECTOR, ipl7auto) OC1Handler(void)
{
    LATAbits.LATA15 = 0;    //turn servo off
    IFS0bits.OC1IF = 0;     //turn output compare 1 interrupt flag off
}

//Timer 2 interrupt 
void __ISR(_TIMER_2_VECTOR, ipl7auto) Timer2Handler(void) 
{
    LATAbits.LATA15 = 1;    //turn servo on
    IFS0bits.T2IF = 0;      //turn timer 2 interrupt flag off
}