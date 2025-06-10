/* 
 * File:   debounce.h
 * Author: Arjan Lemmens @ 20 Nov 2020
 */

#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define PB_FRQ 40000000

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
int readBtn(char button);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* DEBOUNCE_H */