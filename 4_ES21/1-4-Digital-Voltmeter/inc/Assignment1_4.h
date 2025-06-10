/* 
 * File:   ASSIGNMENT1_4_H
 * Author: Arjan Lemmens @ 23 Nov 2020
 */

#ifndef ASSIGNMENT1_4_H
#define	ASSIGNMENT1_4_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ================================================================= */
/* function: adc_init */
/* */
/* description: initialises the 10-bit A/D converter. */
/* */
/* pre: channels - 16-bit value, containing the analog inputs to be */
/*                 converted. Example: when only using AN2 and AN3, */
/*                 the channels variable should be 0b0000110 or 0x0006 */
/* */
/* post: none */
/* ================================================================= */
void adc_init(unsigned short int channels);

/* ================================================================= */
/* function: adc_getresult */
/* */
/* description: obtains the last 10-bit conversion result for a */
/* specific analogue input channel. */
/* */
/* pre: channel - the channel for which the result is required. */
/*                range: 0-15. */
/* */
/* post: return value - the 10-bit result of the last conversion for */
/*                      the specified channel. */
/* ================================================================= */
unsigned short int adc_getresult(unsigned char channel);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_4_H */