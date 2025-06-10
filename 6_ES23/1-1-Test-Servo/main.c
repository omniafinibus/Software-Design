/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "pragma.h"
#include "servo.h"
#include "buttons.h"

btn BTNC; //decrease with 5 degrees
btn BTNR; //increase with 5 degrees
char angle1 = 0;

int main() {    

    servo_init(PB_FRQ, 1, angle1);
    init_btns();
    
    while(true) {
        
        if(btnClick(&BTNR, readR) && !btnHold(&BTNC, readC))
        {
            angle1 = updateAngle(1, angle1);
            servoSetPos(1, angle1);
        }
        else if (btnClick(&BTNC, readC) && !btnHold(&BTNR, readR))
        {
            angle1 = updateAngle(0, angle1);
            servoSetPos(1, angle1);
        }
    }
    
    return true;
}