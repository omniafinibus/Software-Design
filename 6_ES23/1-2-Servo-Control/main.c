
/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "pragma.h"
#include "timer.h"
#include "oc.h"
#include "pwm.h"
#include "servo.h"
#include "buttons.h"
#include "spiflash.h"

#define ADDR 0x0000

btn BTNL; //save angle to flash
btn BTNC; //decrease with 5 degrees
btn BTNR; //increase with 5 degrees

unsigned char angle = 0;
unsigned char saved = 1;
unsigned char changing = 0;

int main() {    
    
    SPIFLASH_Init();
    init_btns();
    SPIFLASH_Read(ADDR, &angle, 1);
    servo_init(PB_FRQ, 1, angle);
    macro_enable_interrupts();  //Enable interrupts in the CPU
    
    while(true) {
        if (saved == 0)
        {
            saved = 1;
            SPIFLASH_Erase4k(ADDR);
            SPIFLASH_ProgramPage(ADDR, &angle, 1);
        }
        
        if(intervalClick(&BTNR, readR, 1, 4) && !BTNC.pressed)
        {
            angle = updateAngle(1, angle, 2);
            servoSetPos(1, angle);
            saved = 0;
        }
       
        if(intervalClick(&BTNC, readC, 1, 3) && !BTNR.pressed)
        {
            angle = updateAngle(0, angle, 2);
            servoSetPos(1, angle);
            saved = 0;
        }
    }
    return true;
}