#include <xc.h>
#include <stdlib.h>
#include <sys/attribs.h>
#include <stdio.h>
#include "i2c.h"
#include "timer.h"
#include "srf.h"

#define srfAddress 0x70
char startData[2] = {0x00, 0x51};
char readData[1] = {0x02};
unsigned char recievedData[2];

void srf_init(int freq) {
    I2C_Init(freq);
}

unsigned char srf_range()
{
    srf_startRanging();
    srf_getDistance();
    return(recievedData[1]);
}
 
unsigned char srf_startRanging()
{
    I2C_Write(srfAddress, startData, 2, 1);
    delay();
    return 1;
}
 
unsigned char srf_getDistance() 
{
    I2C_Write(srfAddress, readData, 1, 0);
    delay();
    I2C_Read(srfAddress, recievedData, 2);
    delay();
    return(recievedData[1]);
}

void delay()
{
    _CP0_SET_COUNT(0);
    while(_CP0_GET_COUNT() < 20000000){}
}