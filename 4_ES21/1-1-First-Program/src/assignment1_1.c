/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Your own custom made libraries */
#include "ASSIGNMENT1_1.h"
#include "debounce.h"

/* Local variables */
int counter = 0;

int main(){
    //initialize components
    GPIO_init();
    debounce_init(0.05);
            
    while(1){
        
        if(readBtn('C'))        //increase counter
        {
            if(counter == 15)
            {
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        else if(readBtn('D'))   //decrease counter
        {
            if(counter == 0)
            {
                counter = 15;
            }
            else
            {
                counter--;
            }
        }
        
        //turn on corresponding LEDs
        switch(counter){
            case 0:
                LD0 = 0;
                LD1 = 0;
                LD2 = 0;
                LD3 = 0;
                break;
            
            case 1:
                LD0 = 0;
                LD1 = 0;
                LD2 = 0;
                LD3 = 1;
                break;
            
            case 2:
                LD0 = 0;
                LD1 = 0;
                LD2 = 1;
                LD3 = 0;
                break;
            
            case 3:
                LD0 = 0;
                LD1 = 0;
                LD2 = 1;
                LD3 = 1;
                break;
            
            case 4:
                LD0 = 0;
                LD1 = 1;
                LD2 = 0;
                LD3 = 0;
                break;
            
            case 5:
                LD0 = 0;
                LD1 = 1;
                LD2 = 0;
                LD3 = 1;
                break;
            
            case 6:
                LD0 = 0;
                LD1 = 1;
                LD2 = 1;
                LD3 = 0;
                break;
            
            case 7:
                LD0 = 0;
                LD1 = 1;
                LD2 = 1;
                LD3 = 1;
                break;
            
            case 8:
                LD0 = 1;
                LD1 = 0;
                LD2 = 0;
                LD3 = 0;
                break;
                
            case 9:
                LD0 = 1;
                LD1 = 0;
                LD2 = 0;
                LD3 = 1;
                break;
            
            case 10:
                LD0 = 1;
                LD1 = 0;
                LD2 = 1;
                LD3 = 0;
                break;
            
            case 11:
                LD0 = 1;
                LD1 = 0;
                LD2 = 1;
                LD3 = 1;
                break;
            
            case 12:
                LD0 = 1;
                LD1 = 1;
                LD2 = 0;
                LD3 = 0;
                break;
            
            case 13:
                LD0 = 1;
                LD1 = 1;
                LD2 = 0;
                LD3 = 1;
                break;
            
            case 14:
                LD0 = 1;
                LD1 = 1;
                LD2 = 1;
                LD3 = 0;
                break;
            
            case 15:
                LD0 = 1;
                LD1 = 1;
                LD2 = 1;
                LD3 = 1;
                break;
        }
    }
    return (0);
}

void GPIO_init(unsigned char led_val)
{
    
    TRISFbits.TRISF0 = 1;
    
    TRISA &= ~0xFF;
    
    LATA = (PORTA & ~0xFF) | (led_val & 0xFF );
}

void initLEDs()
{
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA7 = 0;
}