/* 
 * File:   buttons.h
 * Author: Arjan Lemmens
 * Created on 06-12-2020
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define readU PORTBbits.RB1
#define readL PORTBbits.RB0
#define readC PORTFbits.RF0
#define readR PORTBbits.RB8
#define readD PORTAbits.RA15

#define read0 PORTFbits.RF3
#define read1 PORTFbits.RF5
#define read2 PORTFbits.RF4
#define read3 PORTDbits.RD15
#define read4 PORTDbits.RD14
#define read5 PORTBbits.RB11
#define read6 PORTBbits.RB10
#define read7 PORTBbits.RB9

typedef struct
{
    char pressed;
    char counter;
}btn;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: init_btns */
/* */
/* description: initializes all buttons on the BASYS MX3*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_btns();

/* ================================================================= */
/* function: btnClick */
/* */
/* description: read button or switch as a button*/
/* */
/* pre: button - switch or button that needs to be debounced*/
/*      btnPin - pin that needs to be read*/
/* */
/* post: the button state once the button is held down */
/* ================================================================= */
char btnClick(btn *button, char btnPin);

/* ================================================================= */
/* function: btnHold */
/* */
/* description: switch or button that needs to be debounced*/
/* */
/* pre: button - button that needs to be debounced*/
/*      btnPin - pin that needs to be read*/
/* */
/* post: the button state as long as its held down */
/* ================================================================= */
char btnHold(btn *button, char btnPin);

/* ================================================================= */
/* function: btnCounter */
/* */
/* description: switch or button that needs to be debounced*/
/* */
/* pre: button - button that needs to be debounced*/
/*      btnPin - pin of the button*/
/*      waitTime - time the button needs to be held down for a positive return*/
/* */
/* post: the button state as long as its held down */
/* ================================================================= */
char btnCounter(btn *button, char btnPin, int waitTime);

#endif	/* BUTTONS_H */