
int resolution = 0;
int PWMStep[41];
char currentStep = 0;

void init_audio()
{
    //calculate the resolution
    resolution = 41;
    
    //define all values of PWM width to create a sine wave
    int i;
    for(i = 0; i < resolution; i++)
    {
        PWMStep[i] = (100*sin((2*M_PI*i)/resolution));
    }
    
    //initialize speaker
    TRISBbits.TRISB14 = 0;
    ANSELBbits.ANSB14 = 0;
    
    //initialize timer 2
    T2CONCLR = 0x8000;          //turn off timer 2 for setup and other settings
    T2CONSET = 0x0070;          //prescalar of 256
    TMR2 = 0x0;                 //set timer value to 0
    PR2 = PB_FRQ/(2*4*200*resolution); //set the timer to 200Hz
    OC1RS = (PR2+1)/2;          //set OC register to 50%
    
    //initialize OC1
    OC1CONCLR = 0x8000;         //turn off OC1
    RPB14R = 0x0C;              //connect OC1 to audio pin
    OC1CONSET = 0x0006;         //turn of fault pin and turn on PWM mode
    OC1CONCLR = 0x0008;         //use timer 2 as clock source
    
    //initialize interrupts
    IPC2SET = 0x001E;           //Set priority to 7 and sub-priority to 2
    IFS0CLR = 0x0100;           //Clear interrupt flag
    IEC0SET = 0x0100;           //Enable interrupt
    macro_enable_interrupts();  //Enable interrupts in the CPU
}

void changeFreq(int freq)
{
    //set the timer to the correct freq for audio
    T2CONCLR = 0x8000;  //turn off timer 2
    PR2 = PB_FRQ/(2*4*freq*41);
    T2CONSET = 0x8000;  //turn timer 2 on    
}

void __ISR(_TIMER_2_VECTOR, ipl7auto) Timer2ISR(void) 
{
    //check if PWM step is at the end of the array
    if(currentStep >= (resolution-1))
    {
        currentStep = 0;
    }
    else 
    {
        currentStep++;
    }
    
    //update PWM width
    OC1RS = (PR2+1)/PWMStep[currentStep];
    
    //Clear the interrupt flag
    IFS2CLR = 0x100;
}