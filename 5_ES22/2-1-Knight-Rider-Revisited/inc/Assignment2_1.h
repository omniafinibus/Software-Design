/* 
 * File:   ASSIGNMENT2_1_H
 * Author: Arjan Lemmens @ 20 Nov 2020
 */

#ifndef ASSIGNMENT2_1_H
#define	ASSIGNMENT2_1_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */
/* ================================================================= */
/* function: init_GPIO */
/* */
/* description: initialize required I/O for assignment*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_GPIO();

/* ================================================================= */
/* function: init_timers */
/* */
/* description: initialize required timers for assignment*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_timers();

/* ================================================================= */
/* function: updateComb */
/* */
/* description: save which last 3 buttons have been pressed*/
/* */
/* pre: oldString - the string that needs to be updated*/
/*      newChar - the character that needs to be added at the end*/
/* */
/* post: none */
/* ================================================================= */
short updateComb(short oldVal, short newVal);

/* ================================================================= */
/* function: tmrCtrl */
/* */
/* description: turns timer off and on and controls the time between interrupts*/
/* */
/* pre: tmrSwitch - turn the timer on (1) or off (0)*/
/*      ovfTime - time between interrupts in sec*/
/* */
/* post: none */
/* ================================================================= */
void tmrCtrl(uint64_t ovfTime);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT2_1_H */