 /* 
 * File:   swatch_clock.h
 * Author: Arjan Lemmens
 * Created on 12-12-2020
 */

#ifndef SWATCH_CLOCK_H
#define	SWATCH_CLOCK_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

typedef struct{
    int hour;
    int minute;
    int second;
}clk;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: init_clock*/
/* */
/* description: initializes timer 1 and interrupts*/
/* */
/* pre: none*/
/* */
/* post: none */
/* ================================================================= */
void init_clock();

/* ================================================================= */
/* function: changeTime*/
/* */
/* description: change time of the RTC*/
/* */
/* pre: hour - hours in hexadecimals*/
/*      minute - minutes in hexadecimals*/
/*      seconds - seconds in hexadecimals*/
/* */
/* post: none */
/* ================================================================= */
void incVal(int value);

/* ================================================================= */
/* function: showAlarm*/
/* */
/* description: show the alarm instead of the time*/
/* */
/* pre: onOff - turn the show alarm on or off*/
/* */
/* post: none */
/* ================================================================= */
void showAlrm(int onOff);

/* ================================================================= */
/* function: checkAlarm*/
/* */
/* description: check if the current time is equal to the alarm time*/
/* */
/* pre: on - set to 1 or 0 to turn the alarm off and on*/
/* */
/* post: none */
/* ================================================================= */
void checkAlrm(int on);

/* ================================================================= */
/* function: switchAlrm*/
/* */
/* description: turn the alarm on or off*/
/* */
/* pre: none*/
/* */
/* post: none*/
/* ================================================================= */
void switchAlrm();

/* ================================================================= */
/* function: stopRing*/
/* */
/* description: turn the alarm off*/
/* */
/* pre: none*/
/* */
/* post: none*/
/* ================================================================= */
void stopRing();

/* ================================================================= */
/* function: alrmRing*/
/* */
/* description: return if the alarm is ringing*/
/* */
/* pre: none*/
/* */
/* post: ringing - return status of the alarm in case its ringing*/
/* ================================================================= */
int alrmRing();

#endif	/* SWATCH_CLOCK_H */