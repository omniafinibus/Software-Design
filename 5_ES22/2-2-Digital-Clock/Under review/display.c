char topStr[16];
char botStr[16];

char tempTopStr[16];
char tempBotStr[16];

int charsHidden = 0;

void init_display()
{
    //LCD
    LCD_Init();
    
	//timer 4
    T4CONCLR = 0x8000;      //Turn timer 4 off
    T4CONSET = 0x0070;      //Set prescaler to 256
    TMR4 = 0x0;             //Set timer to 0
    PR4 = 0xFFFF;           //Set register to max value
    
    //interrupts
    IPC4SET = 0x001B;           //Set priority to 6 and sub-priority to 3
    IFS0CLR = 0x10000;          //Clear interrupt flag
    macro_enable_interrupts();  //Enable interrupts in the CPU
    setBlinkFreq(4);            //set blinking frequency to 4
}

void displayTime(clk time, int alarmOn)
{
    //change integer values into a string
    sprintf(botStr, "time: %.2i:%.2i:%.2i  ", time.hour, time.minute, time.second);
    
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

void selectChar(int start, int length , int line)
{
    int i = start;
    
    IEC0CLR = 0x10000;  //disable interrupt
    
    //save top and bottom string in a temporary string to edit
    sprintf(tempBotStr, botStr);
    
    //check which line the characters are located on
    if(line = 0)
    {
        //clear the selected characters
        for(i = start; i < (start+length-1); i++)
        {
            tempTopStr[i] = ' ';
        }
    }
    else if (line = 1)
    {
        //clear the selected characters
        for(i = start; i < (start+length-1); i++)
        {
            tempBotStr[i] = ' ';            
        }
    }
    IEC0CLR = 0x10000;  //enable interrupt
}

void setBlinkFreq(int freq)
{
    IEC0CLR = 0x10000;          //turn interrupt off
    T4CONCLR = 0x8000;          //stop timer
    PR4 = (PB_FRQ*freq)/(2*256);//set PR4 to the value that is corresponds to the blink speed in ms
    TMR4 = 0x0;                 //clear timer 4
    T4CONCLR = 0x8000;          //turn interrupt on
}

void __ISR(_TIMER_4_VECTOR, ipl6auto) Timer4ISR(void) 
{
    if(charsHidden)
    {
        charsHidden = 0;
        LCD_WriteStringAtPos(botStr, 1, 0);
    }
    else
    {
        charsHidden = 1;
        LCD_WriteStringAtPos(tempBotStr, 1, 0);
    }
    IFS0CLR = 0x10000; //Clear the interrupt flag
}