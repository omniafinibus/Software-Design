#include <xc.h>
#include <sys/attribs.h>
#include "config.h"
#include "servo.h"

#define TMR_TIME    0.02 // 20 ms 

unsigned int sPR2 = 0;
/* ------------------------------------------------------------ */
/***	SRV_Init
**
**	Parameters:
**		
**
**	Return Value:
**		
**
**	Description:
**		This function initializes the hardware involved in the SRV module: 
**      The Servo 1 PWM and Servo 2 PWM pins are configured as digital out and mapped to OC5 and OC4. 
**      The OC5 and OC4 module of PIC32 are configured with a period of 20 ms given by Timer2.
**          
*/
void servo_init(int freq) {
    servo_configurePins();
    servo_configureOCs(freq);
}

void servo_setAngle(int angle, int servo) {
    int width = servo_angleToWidth(angle);
    
    if (servo == 1) {
        servo_setPulseMicroseconds1(width);
    } else if (servo == 2) {
        servo_setPulseMicroseconds2(width);
    }
}

int servo_angleToWidth(int angle) {
    return (int) ((2000 / (double) 180) * (angle + 90) + 500);
}

/* ------------------------------------------------------------ */
/***	SRV_ConfigureOCs
**
**	Parameters:
**		
**
**	Return Value:
**		
**
**	Description:
**		This function configures the output compares and timer involved in the SRV module.
**      The OC5 and OC4 module of PIC32 are configured with a period of 20 ms given by Timer2.
**      This is a low-level function called by SRV_Init(), so user should avoid calling it directly.
**          
*/
void servo_configureOCs(int freq) {
    T3CONbits.TCKPS = 4;                // 1:16 prescale value
    T3CONbits.TGATE = 0;                // not gated input (the default)
    T3CONbits.TCS = 0;                  // PCBLK input (the default)
    T3CONbits.ON = 1;                   // turn on Timer2
    
    //sPR2 = (int)(((float)(TMR_TIME * freq) / 16) + 0.5);
    sPR2 = 60000;
    PR2 = sPR2;
    OC5RS = (unsigned short) 0.1*PR2;

    // Configure Output Compare Module 2
    OC5CONbits.ON = 0;       // Turn off OC5 while doing setup.
    OC5CONbits.OCM = 6;      // PWM mode on OC5; Fault pin is disabled
    OC5CONbits.OCTSEL = 1;   // Timer3 is the clock source for this Output Compare module
    OC5CONbits.ON = 1;       // Start the OC5 module

    // Configure Output Compare Module 3
    OC4CONbits.ON = 0;       // Turn off OC4 while doing setup.
    OC4CONbits.OCM = 6;      // PWM mode on OC4; Fault pin is disabled
    OC4CONbits.OCTSEL = 1;   // Timer3 is the clock source for this Output Compare module
    OC4CONbits.ON = 1;       // Start the OC4 module
}

/* ------------------------------------------------------------ */
/***	SRV_ConfigurePins
**
**	Parameters:
**		
**
**	Return Value:
**		
**
**	Description:
**		This function configures the digital pins involved in the SRV module:
**      The servo 1 and servo 2 pins are defined as digital out and mapped to OC5 and OC4. 
**      The function uses pin related definitions from config.h file.
**      This is a low-level function called by SRV_Init(), so user should avoid calling it directly.
**          
*/
void servo_configurePins() {
    tris_SRV_S0PWM = 0;
    tris_SRV_S1PWM = 0;
    
    // disable analog (set pins as digital))
    ansel_SRV_S0PWM = 0;
    
    // remap pins to OCs
    rp_SRV_S0PWM = 0x0B; // 1011 = OC5
    rp_SRV_S1PWM = 0x0B; // 1011 = OC4    
}

/* ------------------------------------------------------------ */
/***	SRV_SetPulseMicroseconds1
**
**	Parameters:
**		unsigned short usVal - the pulse width in microseconds
**                              
**	Return Value:
**		
**
**	Description:
**		This function configures the output compare 5 (corresponding to servo 1) 
**      according to the specified pulse width.
**          
*/
void servo_setPulseMicroseconds1(unsigned short usVal) {
    //float fVal = ((float)(sPR2 + 1) * (float)usVal)/ (TMR_TIME * 1000000);
    ///OC5RS = (unsigned short)fVal; 
    OC5RS = (unsigned short) 0.1*PR2;
}

/* ------------------------------------------------------------ */
/***	SRV_SetPulseMicroseconds2
**
**	Parameters:
**		unsigned short usVal - the pulse width in microseconds
**                              
**	Return Value:
**		
**
**	Description:
**		This function configures the output compare 4 (corresponding to servo 2) 
**      according to the specified pulse width.
**          
*/
void servo_setPulseMicroseconds2(unsigned short usVal) {
    float fVal = ((float)(sPR2 + 1) * (float)usVal)/ (TMR_TIME * 1000000);
    OC4RS = (unsigned short)fVal; 
}

/* ------------------------------------------------------------ */
/***	SRV_Close
**
**	Parameters:
** 
**
**	Return Value:
**      
**
**	Description:
**		This functions releases the hardware involved in the SRV library: 
**      it turns off the OC5, OC4 and Timer 2 modules.
**      
**          
*/
void servo_close() {
    OC5CONbits.ON = 0;       // Stop the OC2 module
    OC4CONbits.ON = 0;       // Stop the OC3 module   
    T2CONbits.ON = 0;        // turn off Timer2
}
/* *****************************************************************************
 End of File
 */
