/* 
 * File:   debounceV2.h
 * Author: Arjan Lemmens @ 4 DEC 2020
 */

#ifndef DEBOUNCEV2_H
#define	DEBOUNCEV2_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define PB_FRQ 40000000
typedef Button{
   int released;
   int pressed;
   int readVal;
   uint64_t difference;
   uint64_t start;
};

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: debounce_init */
/* */
/* description: initialize debouncer for Basys MX3*/
/* */
/* pre: sec - Amount of time the debouncer waits in seconds until it read the button*/
/* */
/* post: none */
/* ================================================================= */
void init_debounce();

/* ================================================================= */
/* function: readBtn*/
/* */
/* description: */
/* */
/* pre: button - Character for to choose which button is read*/
/* U for BTNU, L for BTNL, C for BTNC, R for BTNR, D for BTND*/
/* */
/* post: state of the button (acts as a button not a switch)*/
/* ================================================================= */
int readBtn(Button btnVal);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* DEBOUNCEV2_H */