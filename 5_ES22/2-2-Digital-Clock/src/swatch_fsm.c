/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Personal libraries*/
#include "config.h"
#include "swatch_fsm.h"

/* Local Variables*/
settingState Setting = time;
char topStr[16];
char alarmSetting = 0;

char nextMajStng()
{    
    switch(Setting)
    {
        case time:
            Setting = setTime;
            alarmSetting = 0;
            sprintf(topStr, "change time    ");
            break;
        case setTime:
            Setting = setAlrm;
            alarmSetting = 1;
            sprintf(topStr, "change alarm   ");
            break;
        case setTimeHour:
            Setting = setAlrm;
            alarmSetting = 1;
            sprintf(topStr, "change alarm   ");
            break;
        case setTimeMin:
            Setting = setAlrm;
            alarmSetting = 1;
            sprintf(topStr, "change alarm   ");
            break;
        case setAlrm:
            Setting = time;
            alarmSetting = 0;
            sprintf(topStr, "show time      ");
            break;
        case setAlrmHour:
            Setting = time;
            alarmSetting = 0;
            sprintf(topStr, "show time      ");
            break;
        case setAlrmMin:
            Setting = time;
            alarmSetting = 0;
            sprintf(topStr, "show time      ");
            break;
    }
    
    LCD_WriteStringAtPos(topStr, 0, 0);
    return(alarmSetting); //return if the current setting is an alarm setting or not
}

void nextMinStng()
{
    switch(Setting)
    {
        case time:
            Setting = time;
            break;
        case setTime:
            Setting = setTimeHour;
            sprintf(topStr, "change time  HH");
            break;
        case setTimeHour:
            Setting = setTimeMin;
            sprintf(topStr, "change time  MM");
            break;
        case setTimeMin:
            Setting = setTimeHour;
            sprintf(topStr, "change time  HH");
            break;
        case setAlrm:
            Setting = setAlrmHour;
            sprintf(topStr, "change alarm HH");
            break;
        case setAlrmHour:
            Setting = setAlrmMin;
            sprintf(topStr, "change alarm MM");
            break;
        case setAlrmMin:
            Setting = setAlrmHour;
            sprintf(topStr, "change alarm HH");
            break;
    }
    
    LCD_WriteStringAtPos(topStr, 0, 0);
}

settingState readCrntStng()
{
    return Setting;
}