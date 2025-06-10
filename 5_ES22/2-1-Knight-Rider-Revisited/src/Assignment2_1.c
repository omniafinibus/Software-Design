/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "Assignment2_1.h"
#include <config.h>
#include <pragma.h>
#include <lcd.h>
#include "debounce.h"

/* Local variables */
short btnComb = 0x0000;
char rising = 0;

int main()
{  
	//initialization for required components
    init_GPIO();
    LCD_Init();
    init_debounce();
    
    LCD_WriteStringAtPos("Embedded Systems", 0, 0);
    LCD_WriteStringAtPos(" KITT activated ", 1, 0);
    
    while(1)
    {
        if(readBtn('R'))
        {
            btnComb = updateComb(btnComb, 0x000F);
        }
        
        if(readBtn('D'))
        {
            btnComb = updateComb(btnComb, 0x000D);
        }

        switch (btnComb)
        {
            case 0x0FFF: //yes
                LCD_WriteStringAtPos("  Yes Micheal?  ", 1, 0); //Update LCD
                LATA = 0xFF;                                    //Turn on LEDs
                btnComb = 0x1000;                               //Reset button combination to nothing and turn system on
                break;
            case 0x1DFD: //swoosh
                LCD_WriteStringAtPos(" Swoosh Swoosh! ", 1, 0); //Update screen
                LATA = 0x01;                                    //Turn on first LED
                rising = 0;                                     //Turn off rising
                tmrCtrl(350);                               //Start timer to interrupt every 350 ms
                btnComb = 0x1000;                               //Reset button combination to nothing and turn system on
                break;
            case 0x1DDF: //turbo
                LCD_WriteStringAtPos("  TURBO SWOOSH  ", 1, 0); //Update screen
                LATA = 0x01;                                    //Turn on first LED
                rising = 0;                                     //Turn off rising
                tmrCtrl(175);                              //Start timer to interrupt every 175 ms
                btnComb = 0x1000;                               //Reset button combination to nothing and turn system on
                break;
            case 0x1FFF: //bye
                LCD_WriteStringAtPos("  Bye Micheal   ", 1, 0); //Update LCD
                LATA = 0x00;                                    //Turn off LEDs
                T1CONCLR= 0x8000;                               //turn timer off
                btnComb = 0x0000;                               //Reset button combination to nothing and turn system off
                break;
            default:
                break;
        }
    }
    return(0);
}

void init_GPIO()
{
    //initialize LEDs
    TRISA &= ~0xFF;
    LATA = 0x00;
    
    //initialize timers
    T1CON = 0x0030;  //Set prescaler to 256 to give a minimum freq of 65535/(PB_FRQ/2*256) = 838,8 ms = 1.19Hz
    TMR1 = 0x0;         //Set timer to 0
    PR1 = 0xFFFF;       //Use max value for register
    
    //initialize interrupts
    IPC1SET = 0x001F;           //Set priority to 7 and sub-priority to 3
    IFS0CLR = 0x0010;           //Clear interrupt flag
    IEC0SET = 0x0010;           //Enable interrupt
    macro_enable_interrupts();  //Enable interrupts in the CPU
}

void __ISR(_TIMER_1_VECTOR, ipl7auto) Timer1ISR(void) 
{
    if((PORTA & 0xFF) == 0x01 || (PORTA & 0xFF) == 0x80)
    {
        rising = !rising;
    }
    
    if(rising)
    {
        LATA = ((PORTA & 0xFF) << 1) | PORTA & ~0xFF;
    }
    else
    {
        LATA = (PORTA & 0xFF) >> 1;
    }    
    
    IFS0CLR = 0x10; //Clear the interrupt flag
}

short updateComb(short oldVal, short newVal)
{
    short sysState = oldVal & 0x1000;   //Save if the system is on or off
    oldVal <<= 4;                       //Move the previous pressed buttons to the lefts
    oldVal &= 0x0FFF;                   //Remove the oldest button from history
    oldVal ^= newVal;                   //Add the new button to the button combination
    oldVal ^= sysState;                 //Add the system state to the register
} 

void tmrCtrl(uint64_t ovfTime)
{
    T1CONCLR= 0x8000;               //Stop timer
    PR1 = (PB_FRQ*ovfTime)/(2*256*1000); //Amount of cycles it takes for an interrupt to occur every ovfTime amount of ms
    TMR1 = 0x0;                     //Reset timer
    T1CONSET= 0x8000;               //start timer
}