/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include <assignment1_7.h>
#include <lcd.h>
#include <pragma.h>

/* Local variables */
uint32_t sampleStart = 0;
uint32_t screenRefresh = 0;
uint32_t screenDif = 0;

float screenFreq = 2;

float an2Meas = 0;
float an3Meas = 0;
float refVolt = 3.3;
float binVal = 1023;

char topStr[20];
char botStr[20];

int main()
{  
	//initialization of required components
    adc_init(0x0006);
    LCD_Init();
    
    while(1)
    {
        screenDif = (PB_FRQ/2)*(1/screenFreq);
        if(_CP0_GET_COUNT()-screenRefresh>screenDif)
        {
           screenRefresh = _CP0_GET_COUNT();                //Save the time when the screen refreshed
           an2Meas = refVolt * (adc_getresult(2) / binVal); //Measure voltage on AN2
           an3Meas = refVolt * (adc_getresult(3) / binVal); //Measure voltage on AN3
           sprintf(topStr, "Ch. AN2: %.3f V", an2Meas);     //Save measurement into string
           sprintf(botStr, "Ch. AN3: %.3f V", an3Meas);     //Save measurement into string
           LCD_WriteStringAtPos(topStr, 0, 0);              //Update LCD
           LCD_WriteStringAtPos(botStr, 1, 0);              //Update LCD
        }
    }
    
    return(0);
}

void adc_init(unsigned short int channels)
{
    AD1CON1 = 0x0000;   //Clear CON1 and turn of ADC
    AD1CON2 = 0x0000;   //Don't use input scan
    AD1CON3 = 0x0003;   //ADC clk period = 8 PB clk periods = 1000 ns
    AD1CHS = channels;  //Connect specified channels to SHA as input
    tris_ADC_AN2 = 1;   //Set AN2 as input
    ansel_ADC_AN2 = 1;  //Set AN2 to analog
    tris_ADC_AN3 = 1;   //Set AN3 as input
    ansel_ADC_AN3 = 1;  //Set AN3 to analog
    AD1CON1 = 0x8000;       //Turn ADC on
    
//    AD1PCFGSET = channels;  //Set required pins to digital
//    AD1PCFGINV = 0x00FF;    //Set required pins to analog
}

unsigned short int adc_getresult(unsigned char channel)
{
    uint32_t sampleWait = (PB_FRQ / 2)*(2e-7);
    
    AD1CHS = channel << 16; 
    AD1CON1bits.DONE = 0;   //Clear done bit
    AD1CON1bits.SAMP = 1;   //Start sampling
    
    while(AD1CON1bits.DONE == 0)
    {
        if(_CP0_GET_COUNT()-sampleStart>sampleWait && AD1CON1bits.SAMP == 1)
        {
            AD1CON1bits.SAMP = 0; // conversion starts when SAMP bit is cleared
        }
    }
    
    return ADC1BUF0;
}