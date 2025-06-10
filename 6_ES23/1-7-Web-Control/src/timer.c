#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"

#define ERROR -1

void (*pwmSwitchTimer) (char);
volatile char * stopWatchStatus5;
volatile char * stopWatchStatus4;
volatile int stopWatchDelay5 = 0;
volatile int stopWatchDelay4 = 0;
volatile int counter5 = 0;
volatile int counter4 = 0;
int clk;
int prd1, prd2, prd3, prd4, prd5;

int timer_init(int freq, int channel, int periodMs, int interruptEnabled, int interruptPriority, int subPriority) {    
    clk = freq;
    
    int prescaler = getPrescaler(channel, periodMs);
    int prescalerCode = getPrescalerCode(channel, prescaler);
    int period = getPeriod(channel, periodMs, prescaler);
    
    savePeriod(channel, period);
    setupTimer(channel, period, prescalerCode);
    
    if (interruptEnabled) {
        timer_attachInterrupt(channel, interruptPriority, subPriority);
    }
    
    return prescaler != ERROR && prescalerCode != ERROR;
}

int timer_initRaw(int freq, int channel, int period, int prescaler, int interruptEnabled, int interruptPriority, int subPriority) {    
    clk = freq;
    
    setupTimer(channel, period, prescaler);
    
    if (interruptEnabled) {
        timer_attachInterrupt(channel, interruptPriority, subPriority);
    }
    
    return prescaler != ERROR && prescaler != ERROR;
}

void timer_attachInterrupt(int channel, int priority, int sub) {
    switch(channel) {
        case 1:
            IPC1bits.T1IP = priority;
            IPC1bits.T1IS = sub;
            IFS0bits.T1IF = 0;
            IEC0bits.T1IE = 1;
            break;
            
        case 2:
            IPC2bits.T2IP = priority;
            IPC2bits.T2IS = sub;
            IFS0bits.T2IF = 0;
            IEC0bits.T2IE = 1;
            break;
            
        case 3:
            IPC3bits.T3IP = priority;
            IPC3bits.T3IS = sub;
            IFS0bits.T3IF = 0;
            IEC0bits.T3IE = 1;
            break;
            
        case 4:
            IPC4bits.T4IP = priority;
            IPC4bits.T4IS = sub;
            IFS0bits.T4IF = 0;
            IEC0bits.T4IE = 1;
            break;
            
        case 5:
            IPC5bits.T5IP = priority;
            IPC5bits.T5IS = sub;
            IFS0bits.T5IF = 0;
            IEC0bits.T5IE = 1;
            break;
            
        default: 
            break;
    }
}

void timer_detachInterrupt(int channel) {
    switch(channel) {
        case 1:
            IEC0bits.T1IE = 0;
            break;
            
        case 2:
            IEC0bits.T2IE = 0;
            break;
            
        case 3:
            IEC0bits.T3IE = 0;
            break;
            
        case 4:
            IEC0bits.T4IE = 0;
            break;
            
        case 5:
            IEC0bits.T5IE = 0;
            break;
            
        default: 
            break;
    }
}

int timer_stop(int channel) {
    switch(channel) {
        case 1:
            T1CONbits.ON = 0;
            break;
            
        case 2:
            T2CONbits.ON = 0;
            break;
            
        case 3:
            T3CONbits.ON = 0;
            break;
            
        case 4:
            T4CONbits.ON = 0;
            break;
            
        case 5:
            T5CONbits.ON = 0;
            break;
            
        default:
            break;
    }
    
    return channel > 0 && channel < 6;
}

void timer_reset(int channel) {
    switch(channel) {
        case 1:
            TMR1 = 0;
            break;
            
        case 2:
            TMR2 = 0;
            break;
            
        case 3:
            TMR3 = 0;
            break;
            
        case 4:
            TMR4 = 0;
            break;
            
        case 5:
            TMR5 = 0;
            break;
            
        default:
            break;
    }
}

int timer_getPeriod(int channel) {
    switch(channel) {
        case 1:
            return prd1;
            break;
            
        case 2:
            return prd2;
            break;
            
        case 3:
            return prd3;
            break;
            
        case 4:
            return prd4;
            break;
            
        case 5:
            return prd5;
            break;
            
        default: 
            return 0;
            break;
    }
}

void setupTimer(int channel, int period, int prescalerCode) {
    switch(channel) {
        case 1:
            PR1 = period;
            TMR1 = 0;
            T1CONbits.TCKPS = prescalerCode;
            T1CONbits.TGATE = 0;
            T1CONbits.TCS = 0;
            T1CONbits.ON = 1;
            break;
            
        case 2:
            PR2 = period;
            TMR2 = 0;
            T2CONbits.TCKPS = prescalerCode;
            T2CONbits.TGATE = 0;
            T2CONbits.TCS = 0;
            T2CONbits.ON = 1;
            break;
            
        case 3:
            PR3 = period;
            TMR3 = 0;
            T3CONbits.TCKPS = prescalerCode;
            T3CONbits.TGATE = 0;
            T3CONbits.TCS = 0;
            T3CONbits.ON = 1;
            break;
            
        case 4:
            PR4 = period;
            TMR4 = 0;
            T4CONbits.TCKPS = prescalerCode;
            T4CONbits.TGATE = 0;
            T4CONbits.TCS = 0;
            T4CONbits.ON = 1;
            break;
            
        case 5:
            PR5 = period;
            TMR5 = 0;
            T5CONbits.TCKPS = prescalerCode;
            T5CONbits.TGATE = 0;
            T5CONbits.TCS = 0;
            T5CONbits.ON = 1;
            break;
            
        default: 
            break;
    }
}

int getPrescaler(int channel, int periodMs) {
    double cyclesPerMs = clk / 1000;
    double requiredCycles = cyclesPerMs * periodMs;
    
    if (requiredCycles < 65536) {
        return 1;
    } else if (requiredCycles < 65536 * 8) {
        return 8;
    } else if (requiredCycles < 65536 * 64) {
        return 64;
    } else if (requiredCycles < 65536 * 256) {
        return 256;
    }
    
    return ERROR;
}

int getPrescalerCode(int channel, int prescaler) {
    switch(prescaler) {
        case 1:
            return 0;
            
        case 8:
            if (channel == 1) {
                return 1;
            } else {
                return 3;
            }
            
        case 64:
            if (channel == 1) {
                return 2;
            } else {
                return 6;
            }
            
        case 256:
            if (channel == 1) {
                return 3;
            } else {
                return 7;
            }
            
        default:
            break;
    }
    
    return ERROR;
}

int getPeriod(int channel, int periodMs, int prescaler) {
    double cyclesPerMs = clk / 1000;
    double requiredCycles = cyclesPerMs * periodMs;
    
    return requiredCycles / prescaler;
}

void savePeriod(int channel, int period) {
    switch(channel) {
        case 1:
            prd1 = period;
            break;
            
        case 2:
            prd2 = period;
            break;
            
        case 3:
            prd3 = period;
            break;
            
        case 4:
            prd4 = period;
            break;
            
        case 5:
            prd5 = period;
            break;
            
        default: 
            break;
    }
}

void callbackAddressTimerISR(void (*functionAddress)(char))
{
    pwmSwitchTimer= functionAddress;    
}

void startStopWatch5(volatile char * status, int delayInSec)
{
    //reset timer
    timer_reset(5);
    //connect interrupt
    timer_attachInterrupt(5, 6, 2);
    //attach flag address
    stopWatchStatus5 = status;
    //setup counter
    stopWatchDelay5 = delayInSec;
    counter5 = 0;    
}

void startStopWatch4(volatile char * status, int delayInSec)
{
    //reset timer
    timer_reset(4);
    //connect interrupt
    timer_attachInterrupt(4, 6, 2);
    //attach flag address
    stopWatchStatus4 = status;
    //setup counter
    stopWatchDelay4 = delayInSec;
    counter4 = 0;    
}

void __ISR(_TIMER_2_VECTOR, ipl7auto) Timer2Handler(void) 
{
    (*pwmSwitchTimer) (1);
    IFS0bits.T2IF = 0;      //turn timer 2 interrupt flag off
}

void __ISR(_TIMER_5_VECTOR, ipl6auto) Timer5Handler(void) 
{
    if(counter5 == stopWatchDelay5)
    {
        *stopWatchStatus5 = 1;        
    }
    else if(counter5 < stopWatchDelay5)
    {
        counter5++;
        *stopWatchStatus5 = 0;
    }
    IFS0bits.T5IF = 0;      //turn timer 2 interrupt flag off
}

void __ISR(_TIMER_4_VECTOR, ipl6auto) Timer4Handler(void) 
{
    if(counter4 == stopWatchDelay4)
    {
        *stopWatchStatus4 = 1;        
    }
    else if(counter4 < stopWatchDelay4)
    {
        counter4++;
        *stopWatchStatus4 = 0;
    }
    IFS0bits.T4IF = 0;      //turn timer 2 interrupt flag off
}