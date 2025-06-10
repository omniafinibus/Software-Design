/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include <debounce.h>
#include <lcd.h>
#include <utils.h>
#include "debounce.h"

/* Local variables */
int counterVal = 0;
int counterRising = 1;
uint32 timeLedOn = 0;

int swooshing = 0;
float ledDelayInSec = 0;

state currentState = S0;

int main() {
    GPIO_init();
    LCD_Init();
    debounce_init(0.02);

    LCD_WriteStringAtPos("Embedded Systems", 0, 0);
    LCD_WriteStringAtPos(" KITT activated ", 1, 0);

    while (1) {
        if (swooshing) {
            swooshSwoosh(ledDelayInSec);
        }
        switch (currentState) {
            case S0:
                chooseNextState(S2, S1);
                break;
            case S1:
                chooseNextState(S2, S1);
                break;
            case S2:
                chooseNextState(S3, S1);
                break;
            case S3:
                chooseNextState(Yes, S1);
                break;
            case Yes:
                LCD_WriteStringAtPos("  Yes Micheal?  ", 1, 0);
                controlLeds(1);
                swooshing = 0;
                currentState = S4;
            case S4:
                chooseNextState(S5, S8);
                break;
            case S5:
                chooseNextState(S6, S8);
                break;
            case S6:
                chooseNextState(Bye, S8);
                break;
            case Bye:
                LCD_WriteStringAtPos("  Bye Micheal   ", 1, 0);
                controlLeds(0);
                swooshing = 0;
                currentState = S7;
                break;
            case S7:
                chooseNextState(S2, S1);
                break;
            case S8:
                chooseNextState(S11, S9);
                break;
            case S9:
                chooseNextState(Turbo, S8);
                break;
            case Turbo:
                LCD_WriteStringAtPos("  Turbo Swoosh  ", 1, 0);
                controlLeds(0);
                swooshing = 1;
                ledDelayInSec = 0.175;
                currentState = S10;
                break;
            case S10:
                chooseNextState(S5, S8);
                break;
            case S11:
                chooseNextState(S6, Swoosh);
                break;
            case Swoosh:
                LCD_WriteStringAtPos(" Swoosh Swoosh! ", 1, 0);
                controlLeds(0);
                swooshing = 1;
                ledDelayInSec = 0.35;
                currentState = S12;
                break;
            case S12:
                chooseNextState(S6, S8);
                break;
            default:
                currentState = S0;
                break;
        }
    }
    return (0);
}

void GPIO_init() {

    TRISFbits.TRISF0 = 1;

    TRISA &= ~0xFF;

    LATA = 0x0;
}

void chooseNextState(state stateIfBtnR, state stateIfBtnD) {
    if (readBtn('R')) {
        currentState = stateIfBtnR;
    } else if (readBtn('D')) {
        currentState = stateIfBtnD;
    }
    return;
}

void swooshSwoosh(float ledDelay) {
    //calculate amount of oscillations is equal to requested waiting time
    uint64_t ledWaitTime = (PB_FRQ / 2)*(ledDelay);

    if ((_CP0_GET_COUNT() - timeLedOn) > ledWaitTime) {
        //save new start time
        timeLedOn = _CP0_GET_COUNT();

        //increase or decrease counter
        counter(7);
    }

    //turn on corresping LED
    switch (counterVal) {
        case 0:
            LD1 = 0;
            LD0 = 1;
            break;
        case 1:
            LD0 = 0;
            LD1 = 1;
            LD2 = 0;
            break;
        case 2:
            LD1 = 0;
            LD2 = 1;
            LD3 = 0;
            break;
        case 3:
            LD2 = 0;
            LD3 = 1;
            LD4 = 0;
            break;
        case 4:
            LD3 = 0;
            LD4 = 1;
            LD5 = 0;
            break;
        case 5:
            LD4 = 0;
            LD5 = 1;
            LD6 = 0;
            break;
        case 6:
            LD5 = 0;
            LD6 = 1;
            LD7 = 0;
            break;
        case 7:
            LD6 = 0;
            LD7 = 1;
            break;
        default:
            LD0 = 1;
            LD1 = 0;
            LD2 = 1;
            LD3 = 0;
            LD4 = 1;
            LD5 = 0;
            LD6 = 1;
            LD7 = 0;
            break;
    }
    return;
}

void counter(int maxVal) {
    if (counterVal == 0) {
        counterRising = 1;
        counterVal++;
    } else if (counterVal == maxVal) {
        counterRising = 0;
        counterVal--;
    } else {
        if (counterRising) {
            counterVal++;
        } else {
            counterVal--;
        }
    }
}

void controlLeds(int ledValue) {
    LD0 = ledValue;
    LD1 = ledValue;
    LD2 = ledValue;
    LD3 = ledValue;
    LD4 = ledValue;
    LD5 = ledValue;
    LD6 = ledValue;
    LD7 = ledValue;
}

unsigned char shift_led(unsigned char *val, unsigned char dir) {
    if (dir) {
        *val = val << 1;
    } else {
        *val = val >> 1;
    }
    return (*val & 0x81);
}

void la() {
    unsigned char dir = 0;
    unsigned char val = 1;
    dir = dir ^ shift_led(val, dir);

}