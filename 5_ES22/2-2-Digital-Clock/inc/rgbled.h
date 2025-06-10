/* 
 * File:   rgbled.h
 * Author: Arjan Lemmens
 *
 * Created on 10-12-2020
 */

#ifndef RGBLED_H
#define	RGBLED_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: init_RGB */
/* */
/* description: initialize RGB values */
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_RGB();

/* ================================================================= */
/* function: incBright */
/* */
/* description: slowely increase brightness */
/* */
/* pre: red -   how much red there is in the mix*/
/*      green - how much red there is in the mix*/
/*      blue -  how much red there is in the mix*/
/*      step -  step size with which the brightness increases*/
/* */
/* post: none */
/* ================================================================= */
void incBright(char step);

/* ================================================================= */
/* function: switchRGB */
/* */
/* description: turn RGB on or off */
/* */
/* pre: onOff - turn the rgb on or off*/
/* */
/* post: none */
/* ================================================================= */
void switchRGB(char onOff);

#endif	/* RGBLED_H */

