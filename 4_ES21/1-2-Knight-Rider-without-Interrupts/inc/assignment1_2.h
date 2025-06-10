/* 
 * File:   assignment1_2.h
 * Author: Boyan Nikolov @ 3 July 2017
 * Editor: Joachim Lazaroms @ 7 oct 2017
 * Editor: Arjan Lemmens @ 20 Nov 2020
 */

#ifndef ASSIGNMENT1_2_H
#define	ASSIGNMENT1_2_H

/* ------------------------------------------------------------ */
/*						Configuration Bits		                */
/* ------------------------------------------------------------ */

// Device Config Bits in  DEVCFG1:	
#pragma config FNOSC    = FRCPLL
#pragma config FSOSCEN  = OFF
#pragma config POSCMOD  = XT
#pragma config OSCIOFNC = ON
#pragma config FPBDIV   = DIV_2

// Device Config Bits in  DEVCFG2:	
#pragma config FPLLIDIV = DIV_2
#pragma config FPLLMUL  = MUL_20
#pragma config FPLLODIV = DIV_1

#pragma config JTAGEN   = OFF     
#pragma config FWDTEN   = OFF  


/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */


#define LD0     LATAbits.LATA0
#define LD1     LATAbits.LATA1
#define LD2     LATAbits.LATA2
#define LD3     LATAbits.LATA3
#define LD4     LATAbits.LATA4
#define LD5     LATAbits.LATA5
#define LD6     LATAbits.LATA6
#define LD7     LATAbits.LATA7

typedef enum
{
    S0,
    S1,
    S2,
    S3,
    Yes,
    S4,
    S5,
    S6,
    Bye,
    S7,
    S8,
    S9,
    Turbo,
    S10,
    S11,
    Swoosh,
    S12
}state;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: chooseNextState */
/* */
/* description: change the current state into the one corresponding to the button pressed*/
/* */
/* pre: stateIfBtnR - the next state if BTNR is pressed*/
/*      stateIfBtnD - the next state if BTND is pressed*/
/* post: none */
/* ================================================================= */
void chooseNextState(state stateIfBtnR, state stateIfBtnD);

/* ================================================================= */
/* function: GPIO_init */
/* */
/* description: Initialize required IO pins*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void GPIO_init();

/* ================================================================= */
/* function: swooshSwoosh */
/* */
/* description: "Swoosh" the LEDs from left to right and back with a specific interval*/
/* */
/* pre: ledDelay - Amount of time in seconds that 1 LED is on for*/
/* */
/* post: none */
/* ================================================================= */
void swooshSwoosh(float ledDelay);

/* ================================================================= */
/* function: counter */
/* */
/* description: Counts from 0 up to the maximum value after which it will count down until 0 etc.*/
/* */
/* pre: maxVal - maximum value the counter counts up to before it goes back down (starts counting from 0)*/
/* */
/* post: none */
/* ================================================================= */
void counter(int maxVal);

/* ================================================================= */
/* function: controlLeds */
/* */
/* description: Turn all LEDs on or off*/
/* */
/* pre: ledValue - state that the LEDs take over (1 for on, 0 for off)*/
/* */
/* post: none */
/* ================================================================= */
void controlLeds(int ledValue);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_2_H */

