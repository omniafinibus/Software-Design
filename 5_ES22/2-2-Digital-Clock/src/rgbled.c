/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "rgbled.h"

/* Local variables */
uint32_t switchVal = 0;
char ledWidth = 0;

void init_RGB()
{
    //timer 3
    T3CON = 0x0020;         //turn timer 3 off and set prescalar to 4
    TMR3 = 0x0;             //clear timer register
    PR3 = PB_FRQ/(4*200);   //set the frequency to 200
    
	//calculate at which value of PR3 the LED should turn off
    switchVal = ((PR3+1)/100) * ledWidth;
       
    //Configure Output Compare Module 3
    OC3CON = 0x000E;	//turn OC3 off, use timer 3 and set to PWM mode without fault
    OC3R = switchVal;  //Set the PWM to low on calculated register value 
    OC3CONbits.ON = 1;  //Start the OC3 module

    //Configure Output Compare Module 4
    OC4CON = 0x000E;	//turn OC4 off, use timer 3 and set to PWM mode without fault
    OC4R = switchVal;   //Set the PWM to low on calculated register value
    OC4CONbits.ON = 1;  //Start the OC4 module

    //Configure Output Compare Module 5
    OC5CON = 0x000E;	//turn OC5 off, use timer 3 and set to PWM mode without fault
    OC5R = switchVal;   //Set the PWM to low on calculated register value 
    OC5CONbits.ON = 1;  //Start the OC5 module
    T3CONbits.ON = 1;   //turn timer 3 on
    
    //LEDs
    RPD2R = 0x0B;   	//Use OC3 for red LED
    RPD12R = 0x0B;  	//Use OC5 for green LED
    RPD3R = 0x0B;   	//Use OC4 for blue LED
	TRISDSET = 0x800C;	//set RGB leds as output
	ANSELDCLR = 0x000C;	//turn analog off for red and blue LED
	LATDCLR = 0x800C;	//turn LEDs off
}

void incBright(char step)
{
    if(ledWidth < 100)
    {
        ledWidth = ledWidth + step;
        switchVal = (PR3/100) * ledWidth;
        OC3RS = switchVal;  //update PWM
        OC4RS = switchVal;  //update PWM
        OC5RS = switchVal;  //update PWM
    }
}

void switchRGB(char onOff)
{
    ledWidth = 5;
    switchVal = (PR3/100) * ledWidth;
    OC3RS = (onOff*switchVal);  //update PWM
    OC4RS = (onOff*switchVal);  //update PWM
    OC5RS = (onOff*switchVal);  //update PWM
}