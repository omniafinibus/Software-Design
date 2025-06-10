
/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#include "srf.h"
#include "i2c.h"

#define ADDR 0x0000

btn BTNL; //save angle to flash
btn BTNC; //decrease with 5 degrees
btn BTNR; //increase with 5 degrees

unsigned char angle = 0;
unsigned char saved = 1;
unsigned char recievedMsg[50];
unsigned char transmitMsg[50];

cmd getAngle, setAngle, getDistance;

char data1[2] = {0x00, 0x51};
char data2[1] = {0x02};
char result[2];

int main() {
//    I2C_Init(400000);
    
    SPIFLASH_Init();
    SPIFLASH_Read(ADDR, &angle, 1);
    servo_init(PB_FRQ, 1, angle);
    shell_init(PB_FRQ);
    srf_init(40000);
    init_btns();
    macro_enable_interrupts();
        
    setupCmd("getangle", &getAngle);
    setupCmd("setangle", &setAngle);
    setupCmd("getdistance", &getDistance);
    
    while(true)
    {
//        I2C_Write(0x70, data1, 2, 1);
//        I2C_Write(0x70, data2, 1, 0);
//        I2C_Read(0x70, result, 2);
//    }
        if (saved == 0)
        {
            SPIFLASH_Erase4k(ADDR);
            SPIFLASH_ProgramPage(ADDR, &angle, 1);
            saved = 1;
        }
        
        if(intervalClick(&BTNR, readR, 1, 4) && !BTNC.pressed)
        {
            angle = updateAngle(1, angle, 2);
            servoSetPos(1, angle);
            saved = 0;
        }
       
        if(intervalClick(&BTNC, readC, 1, 5) && !BTNR.pressed)
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
            
            if(strncmp(recievedMsg, setAngle.name, setAngle.length) == 0)  //setangle
            {
                //read value from string
                setAngle.value = readInt(recievedMsg);
                //check if the value falls within range
                if(setAngle.value <= 45 && setAngle.value >= -45)
                {
                    saved = 0;
                    angle = (unsigned char)setAngle.value + 45;
                    servoSetPos(1, angle);
                    sprintf(transmitMsg, "\n\rservo set to %ld degrees\0", setAngle.value);
                    shellSendMessage(transmitMsg);
                }
                else
                {
                    sprintf(transmitMsg, "\n\rout of range\0");
                    shellSendMessage(transmitMsg);
                }
            }
            else if(strncmp(recievedMsg, getAngle.name, getAngle.length) == 0)  //getangle
            {
                getAngle.value = (int)angle-45;
                sprintf(transmitMsg, "\n\rcurrent angle: %i degrees\0", getAngle.value);
                shellSendMessage(transmitMsg);
            }
            else if(strncmp(recievedMsg, getDistance.name, getDistance.length) == 0)  //getdistance
            {
                getDistance.value = (int)srf_range();
                sprintf(transmitMsg, "\n\rmeasured distance is %i cm\0", getDistance.value);
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