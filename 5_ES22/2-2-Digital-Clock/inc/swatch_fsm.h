/* 
 * File:   SWATCH_FSM_H
 * Author: Arjan Lemmens @ 20 Dec 2020
 */

#ifndef SWATCH_FSM_H
#define	SWATCH_FSM_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

typedef enum
{
    time,
    setTime,
    setTimeHour,
    setTimeMin,
    setAlrm,
    setAlrmHour,
    setAlrmMin
}settingState;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: nextMajStng*/
/* */
/* description: go to the next major setting (time, setTime, setAlarm)*/
/* */
/* pre: none*/
/* */
/* post: currentSetting - return if the current setting is an alarm setting or not */
/* ================================================================= */
char nextMajStng();

/* ================================================================= */
/* function: nextMinStng*/
/* */
/* description: go to the next minor setting (change hour/min)*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void nextMinStng();

/* ================================================================= */
/* function: readCrntStng */
/* */
/* description: reads the current setting*/
/* */
/* pre: none*/
/* */
/* post: none*/
/* ================================================================= */
settingState readCrntStng();

#endif	/* SWATCH_FSM_H */