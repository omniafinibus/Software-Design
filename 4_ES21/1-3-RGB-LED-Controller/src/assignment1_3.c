/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <config.h>
#include <sys/attribs.h>
#include <xc.h>

/* Your own custom made libraries */
#include <assignment1_6.h>
#include <config.h>
#include <debounce.h>
#include <pragma.h>

/* Local variables */
int switchVal = 0;
int counterVal = 0;
int counterRising = 1;

uint32_t timeOfCount = 0;
int counterDone = 0;

state currentRGBSetup = S0;

int main()
{  
    rgbled_init(200, 50);

    while(1)
    {
        switch (currentRGBSetup)
        {
            case S0:
                currentRGBSetup = ledProtocol(0, 0, 1, S1);
                break;
            case S1:
                currentRGBSetup = ledProtocol(0, 1, 1, S2);                
                break;
            case S2:
                currentRGBSetup = ledProtocol(0, 1, 0, S3);
                break;
            case S3:
                currentRGBSetup = ledProtocol(1, 1, 0, S4);
                break;
            case S4:
                currentRGBSetup = ledProtocol(1, 0, 0, S5);
                break;
            case S5:
                currentRGBSetup = ledProtocol(1, 0, 1, S6);
                break;
            case S6 :
                currentRGBSetup = ledProtocol(1, 1, 1, S0);
                break;
        }
    }
    
    return(0);
}

void rgbled_init(unsigned int freq, unsigned int width)
{
    //turn on timer 2 and set the prescaler to 2
    T2CONbits.ON = 0;           //Turn off timer 2 while doing setup
    T2CONbits.TCKPS = 1;        //Set prescaler to 2 (001)
    TMR2 = 0x0;                 //Set timer 2 to 0
    PR2 = (PB_FRQ/2) / freq;    //calculate size of PR2 to create an overflow every 1/freq
    T2CONbits.ON = 1;           //Start timer 2
    
    //calculate at which value of PR2 the LED should turn off
    switchVal = ((PR2+1)/100) * width;
       
    //Configure Output Compare Module 3
    OC3CONbits.ON = 0;      //Turn off OC3 while doing setup
    OC3CONbits.OCM = 6;     //PWM mode on OC3; Fault pin is disabled
    OC3CONbits.OCTSEL = 0;  //Timer2 is the clock source for this Output Compare module
    OC3RS = switchVal;      //Set the PWM to low on calculated register value 
    OC3CONbits.ON = 1;      //Start the OC3 module

    //Configure Output Compare Module 4
    OC4CONbits.ON = 0;      //Turn off OC4 while doing setup
    OC4CONbits.OCM = 6;     //PWM mode on OC4; Fault pin is disabled
    OC4CONbits.OCTSEL = 0;  //Timer2 is the clock source for this Output Compare module
    OC4RS = switchVal;      //Set the PWM to low on calculated register value 
    OC4CONbits.ON = 1;      //Start the OC4 module

    //Configure Output Compare Module 5 
    OC5CONbits.ON = 0;      //Turn off OC5 while doing setup
    OC5CONbits.OCM = 6;     //PWM mode on OC5; Fault pin is disabled
    OC5CONbits.OCTSEL = 0;  //Timer2 is the clock source for this Output Compare module
    OC5RS = switchVal;      //Set the PWM to low on calculated register value 
    OC5CONbits.ON = 1;      //Start the OC5 module  
    
    //Configure red LED
    rp_LED8_R = 0x0B;   //Use OC3
    tris_LED8_R = 0;    //Set LED as output
    ansel_LED8_R = 0;   //Disable analog
    lat_LED8_R = 0;     //Turn LED off   
    
    //Configure green LED
    rp_LED8_G = 0x0B;   //Use OC5
    tris_LED8_G = 0;    //Set LED as output
    lat_LED8_G = 0;     //Turn LED off   
    
    //Configure blue LED
    rp_LED8_B = 0x0B;   //Use OC4
    tris_LED8_B = 0;    //Set LED as output
    ansel_LED8_B = 0;   //Disable analog
    lat_LED8_B = 0;     //Turn LED off   
}

void rgbled_setpwmwidths(unsigned int rwidth, unsigned int gwidth, unsigned int bwidth)
{
    rwidth = ((PR2+1)/100) * rwidth;
    OC3RS = rwidth;     //Set the PWM to low on calculated register value 
    gwidth = ((PR2+1)/100) * gwidth;
    OC5RS = gwidth;     //Set the PWM to low on calculated register value 
    bwidth = ((PR2+1)/100) * bwidth;
    OC4RS = bwidth;     //Set the PWM to low on calculated register value 
}

int counter(float maxVal, float intervalSize)
{
    if (counterVal >= maxVal)
    {
        counterRising = 0;
        counterVal = counterVal - intervalSize;
    }
    else if(counterRising)
    {
        counterVal = counterVal + intervalSize;
    }
    else if(!counterRising && counterVal == 0)
    {
        return (1);
    }
    else
    {
        counterVal = counterVal - intervalSize;
    }
    return(0);
}

state ledProtocol(int redLED, int grnLED, int bluLED, state nextState)
{
    //Calculate amount off time between steps to acquire specified rise and fall time
    uint32_t waitTime = (PB_FRQ/2)*(0.1);
    int counterDone = 0;
    int red, green, blue;
    
    while(!counterDone)
    {        if(_CP0_GET_COUNT() - timeOfCount>waitTime)
        {
            //Update last count time
            timeOfCount = _CP0_GET_COUNT();
            
            //Increase/Decrease width and check if the counter is done
            counterDone = counter(100, 1);
            
            //Calculate if the LED is needed by multiplying with "Boolean"
            red = counterVal * redLED;
            green = counterVal * grnLED;
            blue = counterVal * bluLED;
            
            //Update widths
            rgbled_setpwmwidths(red ,green ,blue);
        }
    }
    
    counterRising = 1;
    return nextState;
}