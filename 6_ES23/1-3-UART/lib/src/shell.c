/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Personal libraries*/
#include "uart.h"
#include "config.h"
#include "shell.h"

/* Variables */
const unsigned int baudRate = 9600;
unsigned char localBuffer[50];
unsigned char crntChar = 0;
int newString = 0;

unsigned char shell_init(unsigned int fpb)
{
    UART_InitPoll(baudRate);
    
    if(TRISFbits.TRISF13 != 1 && TRISFbits.TRISF12 != 0)
    {
        return(0);
    }
    
    shellSendMessage("\fEMBC shell");
    shellSendMessage("\n\r==========");
    shellSendMessage("\n\rembc> ");
    return(1);
}

void shellSendMessage(unsigned char *message)
{
    UART_ClearBuffer();
    UART_PutString(message); // send string of characters
}

char shellReadMessage(unsigned char *buffer)
{
    unsigned char recievedChar;        
    
    if(UART_AvaliableRx())
    {
        recievedChar = UART_GetCharPoll();

        if(recievedChar == '\r')    //save the input string to the main program and open a new command line
        {
            newString = 1;
            crntChar = 0;
            strcpy(buffer, localBuffer);
            return(1);
        }
        else if(recievedChar == 0x7f && crntChar > 0)//clear last character when backspace is used  0x7f == backspace
        {
            localBuffer[crntChar] = 0;
            crntChar--;
        }         
        else if (crntChar < 50)     //save the new character to the correct address in the string
        {
            if(newString == 1)     //clear local buffer for the new string
            {
                int i;
                memset(localBuffer,0,sizeof(localBuffer));
                newString = 0;
            }
            
            localBuffer[crntChar] = recievedChar;
            crntChar++;
        }
        return(0);
    }
}

int readInt(char* str)
{
    int foundInt = 0;
    int index = 0;
    int neg = 0;
    int iter;
    
    for(iter = 0; iter < 48; iter++)
    {
        switch(str[iter])
        {
            case '-':
                neg = 1;
                break;
            case '0':
                foundInt = (foundInt*10);
                break;
            case '1':
                foundInt = (foundInt*10) + 1;
                break;
            case '2':
                foundInt = (foundInt*10) + 2;
                break;
            case '3':
                foundInt = (foundInt*10) + 3;
                break;
            case '4':
                foundInt = (foundInt*10) + 4;
                break;
            case '5':
                foundInt = (foundInt*10) + 5;
                break;
            case '6':
                foundInt = (foundInt*10) + 6;
                break;
            case '7':
                foundInt = (foundInt*10) + 7;
                break;
            case '8':
                foundInt = (foundInt*10) + 8;
                break;
            case '9':
                foundInt = (foundInt*10) + 9;
                break;
            case '\0':
                iter = 49;
                break;
        }
    }
    
    if(neg)
    {
        foundInt = (foundInt*-1);
    }
    
    return(foundInt);
}