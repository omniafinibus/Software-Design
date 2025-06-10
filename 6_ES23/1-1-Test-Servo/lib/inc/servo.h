/* 
 * File:   SERVO_H
 * Author: Arjan Lemmens @ 19 Feb 2021
 */

#ifndef SERVO_H
#define	SERVO_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ========================================================================== */
/* function: servo_init(fpb, channel, angle); */
/* */
/* description: initialises a servo channel. */
/* */
/* pre: fpb - peripheral bus clock frequency in Hz */
/* channel - number of the servo channel to initialise */
/* (range 0...1) */
/* angle - servo opening angle in degrees (range -45...45) */
/* */
/* post: return value - 0 if initialisation failed, 1 if succeeded */
/* ========================================================================== */
unsigned char servo_init(int fpb, int channel, int angle);

/* ========================================================================== */
/* function: servoSetPos( fpb, channel, angle ); */
/* */
/* description: changes the opening angle for a servo channel. */
/* */
/* pre: channel - number of the servo channel to set the position for */
/* (range 1...5) */
/* angle - servo opening angle in degrees (range -45...45) */
/* */
/* post: none */
/* ========================================================================== */
void servoSetPos(int channel, int angle);

/* ========================================================================== */
/* function: updateAngle(increase, angle); */
/* */
/* description: check if the current angle is compatible with the servo. */
/* */
/* pre: incr - boolean value if the angle check should increase or decrease*/
/*      angle- the current angle*/
/* */
/* post: newAngle - 0 if the original angle is out of range otherwise the increase/decrease */
/* ========================================================================== */
char updateAngle(char incr, char angle);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */