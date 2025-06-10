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

/* Definitions */
#define NUM_OF_CMDS 8
#define STR_LEN 50
#define NUM_OF_IP_ELEMENTS 4

/* Variables */
unsigned char localBuffer[STR_LEN];
unsigned char crntChar = 0;
int newString = 0;

unsigned char recievedMsg[STR_LEN];
unsigned char transmitMsg[STR_LEN];
unsigned char rcvdCmd = 255;
cmd commands[NUM_OF_CMDS];
char cmdNames[NUM_OF_CMDS][20] = {"start", "stop", "test", "toggleDHCP", "clear", "changeIP", "connect", "getStatus"};

void setupCmd(char* cmdName, cmd* cmdAddress)
{
    int i;
    cmdAddress->length = strlen(cmdName);
    for(i=0; i<cmdAddress->length; i++)
    {
        cmdAddress->name[i] = cmdName[i];
    }
    cmdAddress->value = 0;
}

unsigned char shell_init(unsigned int fpb, int baudrate)
{
    UART_InitPoll(baudrate);
    
    if(TRISFbits.TRISF13 != 1 && TRISFbits.TRISF12 != 0)
    {
        return(0);
    }
    
    //Assign command string to each command
    int i;
    for(i=0; i < NUM_OF_CMDS; i++){
        setupCmd(cmdNames[i], &commands[i]);
    }
    shellSendMessage("\fHexapod V1\0");
    shellSendMessage("\n\r==========\0");
    shellSendMessage("\n\r> \0");
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
        //clear string to receive a new one
        memset(buffer, '\0', sizeof(buffer));
        
        recievedChar = UART_GetCharPoll();
        UART_PutChar((char)recievedChar);
        if (recievedChar == 0x0D)
        {
            newString = 1;
            crntChar = 0;
            strcpy(buffer, localBuffer);
            memset(localBuffer,'\0',sizeof(localBuffer));
            return(1);
        }
        else if(recievedChar == 0x7f && crntChar > 0)//clear last character when backspace is used  
        {
            localBuffer[crntChar] = 0;
            crntChar--;
        }         
        else if (crntChar < STR_LEN)     //save the new character to the correct address in the string
        {
            if(newString == 1)     //clear local buffer for the new string
            {
                int i;
                memset(localBuffer,'\0',sizeof(localBuffer));
                newString = 0;
            }
            
            localBuffer[crntChar] = recievedChar;
            crntChar++;
        }
        return(0);
    }
}

unsigned char readRecievedCommand()
{
    if (shellReadMessage(recievedMsg)) {
        //compare the received data to known commands
        int i;
        for (i=0; i < NUM_OF_CMDS; i++) {
            if(strncmp(recievedMsg, commands[i].name, commands[i].length) == 0) {
                rcvdCmd = i;
                break;
            }
            else {
                rcvdCmd = 255;
            }
        }
        return(rcvdCmd);
    }
    else {
        rcvdCmd = 255;
        return(254);
    }
}

int readInt(char* str)
{
    int foundInt = 0;
    int neg = 0;
    int iter;
    
    for(iter = 0; iter < STR_LEN-1; iter++)
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
                iter = STR_LEN;
                break;
        }
    }
    
    if(neg)
    {
        foundInt = (foundInt*-1);
    }
    
    return(foundInt);
}

void readIP(unsigned char* IPAddress)
{
    unsigned char foundVal = 0;
    int index = 0;
    int iter;
    
    for (iter = 0; iter < STR_LEN-1; iter++) {  //Convert all digits to integer
        switch (recievedMsg[iter]) {
            case '0':
                foundVal = (foundVal*10);
                break;
            case '1':
                foundVal = (foundVal*10) + 1;
                break;
            case '2':
                foundVal = (foundVal*10) + 2;
                break;
            case '3':
                foundVal = (foundVal*10) + 3;
                break;
            case '4':
                foundVal = (foundVal*10) + 4;
                break;
            case '5':
                foundVal = (foundVal*10) + 5;
                break;
            case '6':
                foundVal = (foundVal*10) + 6;
                break;
            case '7':
                foundVal = (foundVal*10) + 7;
                break;
            case '8':
                foundVal = (foundVal*10) + 8;
                break;
            case '9':
                foundVal = (foundVal*10) + 9;
                break;
            case '.':   //When a . is read, save the current integer to the IP array and go to the next element
                if (index < NUM_OF_IP_ELEMENTS-1) {
                    IPAddress[index] = foundVal;
                    index++;
                    foundVal = 0;
                }
                else {
                    IPAddress[NUM_OF_IP_ELEMENTS-1] = foundVal;
                    iter = STR_LEN;
                }
                break;
            case '\0':  //when a space is found save the last read integer to IP array and stop looking for integers
                IPAddress[NUM_OF_IP_ELEMENTS-1] = foundVal;
                iter = STR_LEN;
                break;
            default:
                IPAddress[NUM_OF_IP_ELEMENTS-1] = foundVal;
                iter = STR_LEN;
                break;
        }
    }
}