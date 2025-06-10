/* ================================================================= */
/* function: init_RTC*/
/* */
/* description: initializes RTC*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_RTC();

void init_RTC()
{
    //RTCC
    RTCCONCLR = 0x8000;     //turn RTCC off
    RTCTIME = 0x00000000;   //RTCC time (0xHHMMSS--)
    RTCDATE = 0x00000000;   //RTCC date (0xYYMMDD--)
    RTCCONSET = 0x8000;     //turn RTCC 
    
    //alarm
    RTCALRMCLR = 0x8000;    //turn alarm off
    RTCALRMSET = 0x0605;    //set alarm mask to daily and repeat it 5 times
    ALRMTIME = 0x00000000;  //alarm time (0xHHMMSS--)
}

/* ================================================================= */
/* function: changeTimeRTC*/
/* */
/* description: change time of the RTC*/
/* */
/* pre: hour - hours in hexadecimals*/
/*      minute - minutes in hexadecimals*/
/*      seconds - seconds in hexadecimals*/
/* */
/* post: none */
/* ================================================================= */
void changeTimeRTC(char hour, char minute, char second);

void changeTimeRTC(char hour, char minute, char second)
{
    RTCCONCLR = 0x8000;                                         //turn RTCC off
    RTCTIME = (hour << 24) ^ (minute << 16) ^ (second << 8);    //set the RTC to the correct time
    RTCCONSET = 0x8000;                                         //turn RTCC on
}

/* ================================================================= */
/* function: changeAlarmRTC*/
/* */
/* description: change time when the alarm sounds*/
/* */
/* pre: hour - hours in hexadecimals*/
/*      minute - minutes in hexadecimals*/
/*      seconds - seconds in hexadecimals*/
/* */
/* post: none */
/* ================================================================= */
void changeAlarmRTC(char hour, char minute, char second, char turnOn);

void changeAlarmRTC(char hour, char minute, char second, char turnOn)
{
    RTCALRMCLR = 0x8000;                                        //turn alarm off
    ALRMTIME = (hour << 24) ^ (minute << 16) ^ (second << 8);   //change time
    RTCALRMSET = turnOn << 15;                                  //turn alarm on if necessary
}