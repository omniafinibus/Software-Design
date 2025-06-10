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
unsigned char servo_init(int fpb, int channel, unsigned char angle);

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
void servoSetPos(int channel, unsigned char angle);

/* ========================================================================== */
/* function: updateAngle(increase, angle); */
/* */
/* description: check if the current angle is compatible with the servo. */
/* */
/* pre: angle - the new angle*/
/* */
/* post: none */
/* ========================================================================== */
unsigned char updateAngle(char incr, unsigned char angle, unsigned char step);

/* ========================================================================== */
/* function: servoPWMOn(); */
/* */
/* description: turn the servo pin off */
/* */
/* pre: none*/
/* */
/* post: none */
/* ========================================================================== */
void servoPWMOn();

/* ========================================================================== */
/* function: servoPWMoff(); */
/* */
/* description: turn the servo pin on */
/* */
/* pre: none*/
/* */
/* post: none */
/* ========================================================================== */
void servoPWMoff();

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SERVO_H */