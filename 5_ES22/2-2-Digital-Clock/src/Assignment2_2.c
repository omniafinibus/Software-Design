/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "audio.h"
#include "buttons.h"
#include "lcd.h"
#include "pragma.h"
#include "rgbled.h"
#include "swatch_clock.h"
#include "swatch_display.h"
#include "swatch_fsm.h"

/* Local variables */
btn BTNU;
btn BTNC;
btn BTNR;
btn BTND;

int main()
{
	//initialization of required componentsS
    TRISA &= ~0xFF;
    LATA = 0x0;   
    init_display();
    init_clock();
    init_audio();
    init_RGB();
    init_btns();
    
    while(1)
    {
        if(alrmRing())
        {
            //turn LEDs on
            switchRGB(1);
            //turn audio on
            switchAudio(1);
        }
        
        if(btnClick(&BTND, readD))
        {
            stopRing();
            //turn LEDs off
            switchRGB(0);
            //turn audio off
            switchAudio(0);
        }
        
        if(btnCounter(&BTNC, readC, 2000))
        {
            nextMinStng();
        }
        
        if(btnClick(&BTNU, readU))
        {
            switchAlrm();
            displayAlarmStatus(1);
        }
                
        if(btnClick(&BTNR, readR))
        {
            switch(readCrntStng())
            {
                case setTimeHour:
                    incVal(0);  //increase the hours of time
                    showAlrm(0);//display the alarm time
                    break;
                case setTimeMin:
                    incVal(1);  //increase the minutes of time
                    showAlrm(0);//display the alarm time
                    break;
                case setAlrmHour:
                    incVal(2);  //increase the hours of alarm
                    showAlrm(1);//display the alarm time
                    break;
                case setAlrmMin:
                    incVal(3);  //increase the minutes of alarm
                    showAlrm(1);//display the alarm time
                    break;
            }
        }
    }
    return(0);
}