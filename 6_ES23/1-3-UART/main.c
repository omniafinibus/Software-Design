
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
#include "shell.h"
#include "string.h"

#define ADDR 0x0000

btn BTNL; //save angle to flash
btn BTNC; //decrease with 5 degrees
btn BTNR; //increase with 5 degrees

unsigned char angle = 0;
int shellAngle = 0;
long int readAngle = 0;
unsigned char saved = 1;
unsigned char changing = 0;
unsigned char recieving = 0;
unsigned char recievedMsg[50];
unsigned char getAngle[8];
unsigned char setAngle[8];
unsigned char transmitMsg[50];

int main() {    
    
    SPIFLASH_Init();
    init_btns();
    SPIFLASH_Read(ADDR, &angle, 1);
    servo_init(PB_FRQ, 1, angle);
    shell_init(PB_FRQ);
    sprintf(getAngle, "getangle"); 
    sprintf(setAngle, "setangle"); 
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
        
        //command decoder
        if(shellReadMessage(recievedMsg))
        {
            //clear string to recieve a new one
            memset(transmitMsg, 0, sizeof(transmitMsg));
            
            if(strncmp(recievedMsg, setAngle, 8) == 0)  //setangle
            {
                //read value from string
                readAngle = readInt(recievedMsg);
                //check if the value falls within range
                if(readAngle <= 45 && readAngle >= -45)
                {
                    saved = 0;
                    angle = (unsigned char)readAngle + 45;
                    servoSetPos(1, angle);
                    sprintf(transmitMsg, "\n\rservo set to %ld degrees\0", readAngle);
                    shellSendMessage(transmitMsg);
                }
                else
                {
                    sprintf(transmitMsg, "\n\rout of range\0");
                    shellSendMessage(transmitMsg);
                }
            }
            else if(strncmp(recievedMsg, getAngle, 8) == 0)  //getangle
            {
                shellAngle = (int) angle-45;
                sprintf(transmitMsg, "\n\rcurrent angle: %i degrees\0", shellAngle);
                shellSendMessage(transmitMsg);
            }
            else //anything else
            {
                sprintf(transmitMsg, "\n\rsyntax error\0");
                shellSendMessage(transmitMsg);
            }
            shellSendMessage("\n\rembc> \0");
        }
        
    }
    return true;
}