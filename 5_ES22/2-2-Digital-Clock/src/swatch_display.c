/* Generic C libraries */
#include <stdlib.h>
#include <stdio.h>

/* XC32 libraries */
#include <sys/attribs.h>
#include <xc.h>

/* Personal libraries*/
#include "lcd.h"
#include "config.h"
#include "swatch_display.h"

/* Local variables */
char topStr[16];
char botStr[16];

char tempTopStr[16];
char tempBotStr[16];

int charsHidden = 0;

void init_display()
{
    LCD_Init();
    LCD_WriteStringAtPos("show time      ", 0, 0);
}

void displayTime(char hour, char min, char sec, char alarmOn)
{
    //change integer values into a string
    sprintf(botStr, "time: %.2i:%.2i:%.2i  ", hour, min, sec);
    
    //check if the alarm is on
    if(alarmOn)
    {
        botStr[15] = 'A';
    }
    else
    {
        botStr[15] = ' ';
    }
   
    //display time
    LCD_WriteStringAtPos(botStr, 1, 0);
}

void displayAlarmStatus(int alarmOn)
{
    //change integer values into a string and add display alarm status
    if(alarmOn)
    {
        botStr[15] = 'A';
    }
    else
    {
        botStr[15] = ' ';
    }
   
    //display time
    LCD_WriteStringAtPos(botStr, 1, 0);
}