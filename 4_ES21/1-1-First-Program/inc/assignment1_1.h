/* 
 * File:   assignment1_1.h
 * Author: Boyan Nikolov
 * Editor: Arjan Lemmens
 * Created on 2 July 2017, 16:52
 */

#ifndef ASSIGNMENT1_1_H
#define	ASSIGNMENT1_1_H

/* ------------------------------------------------------------ */
/*						Configuration Bits		                */
/* ------------------------------------------------------------ */

// Device Config Bits in  DEVCFG1:	
#pragma config FNOSC =      FRCPLL
#pragma config FSOSCEN =    OFF
#pragma config POSCMOD =	XT
#pragma config OSCIOFNC =	ON
#pragma config FPBDIV =     DIV_2

// Device Config Bits in  DEVCFG2:	
#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

#pragma config JTAGEN =     OFF     
#pragma config FWDTEN =     OFF  


/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

#define LD0     LATAbits.LATA0
#define LD1     LATAbits.LATA1
#define LD2     LATAbits.LATA2
#define LD3     LATAbits.LATA3
#define LD4     LATAbits.LATA4
#define LD5     LATAbits.LATA5
#define LD6     LATAbits.LATA6
#define LD7     LATAbits.LATA7

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */
void GPIO_init();

void initLEDs();

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* ASSIGNMENT1_1_H */

