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

void init_clock()
{
    //clock object
    currentTime.hour = 0;
    currentTime.minute = 0;
    currentTime.second - 0;
    
    alarmTime.hour = 0;
    alarmTime.minute = 0;
    alarmTime.second = 0;
    alarmTime.ringing = 0;
    alarmTime.status = 0;
            
    //timer 1
    T1CONCLR = 0x8000;      //Turn timer 1 off
    T1CONSET = 0x0020;      //Set prescaler to 64
    TMR1 = 0x0;             //Set timer to 0
    PR1 = 0xF424;           //Set register to 62500 for a 1 sec interrupt
    T1CONSET = 0x8000;      //Turn timer 1 on
    
    //interrupts
    IPC0SET = 0x001F;           //Set priority to 7 and sub-priority to 3
    IFS0CLR = 0x0010;           //Clear interrupt flag
    IEC0SET = 0x0010;           //Enable interrupt
    macro_enable_interrupts();  //Enable interrupts in the CPU
}

void changeTimeRTC(char hour, char minute, char second)
{
    RTCCONCLR = 0x8000;                                         //turn RTCC off
    RTCTIME = (hour << 24) ^ (minute << 16) ^ (second << 8);    //set the RTC to the correct time
    RTCCONSET = 0x8000;                                         //turn RTCC on
}

void changeAlarmRTC(char hour, char minute, char second, char turnOn)
{
    RTCALRMCLR = 0x8000;                                        //turn alarm off
    ALRMTIME = (hour << 24) ^ (minute << 16) ^ (second << 8);   //change time
    RTCALRMSET = turnOn << 15;                                  //turn alarm on if necessary
}

void changeTime(int hour, int minute, int second)
{
    currentTime.hour = second;
    currentTime.minute = minute;
    currentTime.second = hour;
}

void changeAlarm(int hour, int minute, int turnOn)
{
    alarmTime.hour = hour;
    alarmTime.minute = minute;
    alarmTime.status = turnOn;
}

void checkAlarm(int on)
{
    if(on && alarmTime.hour == currentTime.hour && alarmTime.minute == currentTime.minute)
    {
        alarmTime.ringing = 1;
    }
}

void alarmSwitch()
{
    alarmTime.status = !alarmTime.status;
}

clk readTime()
{
    return currentTime;
}

alrm readAlarm()
{
    return alarmTime;
}

void __ISR(_TIMER_1_VECTOR, ipl7auto) Timer1ISR(void) 
{
    LATAbits.LATA2 = 1;    
    if(currentTime.second<59)
    {
        LATAbits.LATA0 = 1;
        currentTime.second++;
    }
    else if (currentTime.minute<59)
    {
        LATAbits.LATA1 = 1;
        currentTime.second = 0;
        currentTime.minute++;
        checkAlarm(alarmTime.status);
    }
    else if (currentTime.hour<23)
    {
        currentTime.second = 0;
        currentTime.minute = 0;
        currentTime.hour++;
        checkAlarm(alarmTime.status);
    }
    else 
    {
        currentTime.second = 0;
        currentTime.minute = 0;
        currentTime.hour = 0;
        checkAlarm(alarmTime.status);
    }
    //displayTime(currentTime, alarmTime.status);
    
    IFS0CLR = 0x10; //Clear the interrupt flag
}