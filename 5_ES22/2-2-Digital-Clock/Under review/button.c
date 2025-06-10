
    //timer 5
    T5CONCLR = 0x8000;  //turn off timer 2 for setup and other settings
    T5CONSET = 0x0070;  //prescalar of 256
    TMR5 = 0x0;         //set timer value to 0
    PR5 = 0x0000;       //set the timer to 200Hz
    
    //timer interrupt
    IPC5SET = 0x001A;       //Set priority to 6 and sub-priority to 2
    IFS0CLR = 0x100000;     //Clear interrupt flag
    IEC0SET = 0x100000;     //Enable interrupt
    
    //Setup change notice interrupt
    CNCONFbits.ON = 1;      //turn f register change notification off
    CNPUFbits.CNPUF3 = 0;   //turn off pull up for pin F3
    CNPDFbits.CNPDF3 = 0;   //turn off pull down for pin F3
    CNENFbits.CNIEF3 = 1;   //set SW0 as input for change notice
    IFS1bits.CNFIF = 0;     //clear the interrupt flag
    IEC1bits.CNFIE = 1;     //enable change notice interrupt
    IPC6SET = 0x001D;       //set priority to 7 and sub priority to 1
    CNCONFbits.ON = 1;      //turn f register change notification on
    macro_enable_interrupts();  //Enable interrupts in the CPU


char btnCounter(btn *button, char btnPin, int waitTime)
{
    if(PR5 == 0)
    {
        PR5 = (PB_FRQ * waitTime) / (2 * 256 * 1000);   //set the timer to 200Hz
    }
    
    if(btnPin && !button->counter)
    {
        button->counter = 1;
        TMR5 = 0x0;         //set timer value to 0
        IEC0SET = 0x100000; //Enable interrupt
        interruptOut = 0;
        return(0);
    }
    else if(!btnPin)
    {
        IEC0CLR = 0x100000; //Disable interrupt
        button->counter = 0;
        return(0);
    }
    else if(interruptOut && btnPin)
    {
        interruptOut = 0;
        return(1);
    }
}

void __ISR(_TIMER_5_VECTOR, ipl6auto) Timer5ISR(void)
{
    interruptOut = 1;
    IFS0CLR = 0x100000; //Clear interrupt flag
    IEC0CLR = 0x100000; //Enable interrupt
}

void __ISR(_CHANGE_NOTICE_VECTOR, ipl7auto) ChangeNoticeHandler(void)
{
    //check which time mode the system is in
    switch(readCrntSettings())
    {
        //change to the next state
        case time:
            changeSettings(setTime);
            break;
        case setTime:
            changeSettings(setAlrm);
            break;
        case setAlrm:
            changeSettings(time);
            break;
        default:
            changeSettings(time);
            break;
    }
    
    IFS1bits.CNFIF = 0;         //clear the interrupt flag
}