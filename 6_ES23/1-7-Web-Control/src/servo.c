/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "servo.h"
#include "pwm.h"

/* Local variables */
#define maxPulseUs 2100
#define minPulseUs 900
#define pulseCycleMs 20
#define angleRange 90
#define servoTimer 2

int angleWidth[91];
unsigned char minAngle, maxAngle;

unsigned char servo_init(int fpb, int channel, unsigned char angle)
{
    int i = 0;
    //calculate width of each angle
    for(i; i<=angleRange; i++)
    {
        angleWidth[i] = ((maxPulseUs-minPulseUs)/angleRange)*i+minPulseUs;
    }
    maxAngle = angleRange;
    minAngle = 0;
    TRISAbits.TRISA15 = 0; //servo 1
    pwm_init(fpb, servoTimer, channel, 20);
    pwm_setWidth(servoTimer, channel, angleWidth[angle]);
    retrieveCallback(&servoPWMOn, &servoPWMoff);
    macro_enable_interrupts();
}

void servoSetPos(int channel, unsigned char angle)
{
    pwm_setWidth(servoTimer, channel, angleWidth[angle]);    
}

unsigned char updateAngle(char incr, unsigned char angle, unsigned char step)
{    
    unsigned char newAngle = angle;
    if(angle > maxAngle)
    {
        newAngle = maxAngle;
    }
    else if(angle < minAngle)
    {
        newAngle = minAngle;
    }
    
    if(incr == 1 && newAngle <= (maxAngle - step))
    {
        newAngle = newAngle + step;
    }
    else if(incr == 0 && newAngle >= (minAngle + step))
    {
        newAngle = newAngle - step;            
    }
    
    return(newAngle);
}

void servoPWMOn()
{
    LATAbits.LATA15 = 1;    //turn servo on
}

void servoPWMoff()
{
    LATAbits.LATA15 = 0;    //turn servo off
}