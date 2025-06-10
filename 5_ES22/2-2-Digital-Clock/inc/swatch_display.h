/* 
 * File:   SWATCH_DISPLAY_H
 * Author: Arjan Lemmens @ 20 Dec 2020
 */

#ifndef SWATCH_DISPLAY_H
#define	SWATCH_DISPLAY_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: init_display */
/* */
/* description: initialize the display*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_display();

/* ================================================================= */
/* function: displayTime */
/* */
/* description: display the given time*/
/* */
/* pre: hour - hours that need to be displayed*/
/*      min - minutes that need to be displayed*/
/*      sec - seconds that need to be displayed*/
/*      alarmOn - status of the alarm if its on or off*/
/*      currentSetting - current setting of the alarm*/
/* */
/* post: none */
/* ================================================================= */
void displayTime(char hour, char min, char sec, char alarmOn);

/* ================================================================= */
/* function: displayAlarmStatus */
/* */
/* description: display the given time*/
/* */
/* pre: alarmOn - status of the alarm if its on or off*/
/* */
/* post: none */
/* ================================================================= */
void displayAlarmStatus(int alarmOn);

#endif	/* SWATCH_DISPLAY_H */