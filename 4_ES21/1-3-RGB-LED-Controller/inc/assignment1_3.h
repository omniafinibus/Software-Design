/* 
 * File:   ASSIGNMENT1_3_H
 * Author: Arjan Lemmens @ 20 Nov 2020
 */

#ifndef ASSIGNMENT1_3_H
#define	ASSIGNMENT1_3_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

typedef enum
{
    S0,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6
}state;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: rgbled_init */
/* */
/* description: initialises the RGB LED connected to OC3 (R), OC5 (G)*/
/*              and OC4 (B) at a given width each. The repetition */
/*              frequency of the PWM signals can be set using the */
/*              freq argument. */
/* */
/* pre: freq ? repetition frequency of the PWM signals in Hz./ 
/*             The range of frequencies is 100 Hz ? 2 kHz. */
/*      width ? default width of the 3 channels in %. */
/* */
/* post: none */
/* ================================================================= */
void rgbled_init(unsigned int freq, unsigned int width);

/* ================================================================= */
/* function: rgbled_setpwmwidths */
/* */
/* description: sets the PWM widths for each of the channels of the */
/*              RGB LED. */
/* */
/* pre: rwidth ? width of the R channel in %. */
/*      gwidth ? width of the G channel in %. */
/*      bwidth ? width of the B channel in %. */
/* */
/* post: none */
/* ================================================================= */
void rgbled_setpwmwidths(unsigned int rwidth, unsigned int gwidth, unsigned int bwidth);

/* ================================================================= */
/* function: counter */
/* */
/* description: Counts from 0 up to the maximum value after which */
/*              it will count down until 0.*/
/* */
/* pre: maxVal - maximum value the counter counts up to before it */
/*               goes back down (starts counting from 0)*/
/*      intervalSize - amount which is added to the counter per step*/
/* */   
/* post: returns a 1 when the counter is done */
/* ================================================================= */
int counter(float maxVal, float intervalSize);

/* ================================================================= */
/* function: ledProtocol */
/* */
/* description: Controls all LEDs*/
/* */
/* pre: redLED - choose if the red LED will turn on*/
/*      grnLED - choose if the green LED will turn on*/
/*      bluLED - choose if the blue LED will turn on*/
/*      nextState - the state next state after protocol is done*/
/* */   
/* post: the next state */
/* ================================================================= */
state ledProtocol(int redLED, int grnLED, int bluLED, state nextState);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_3_H */