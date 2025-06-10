
/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Your own custom made libraries */
#include "BT2.h"
#include "pragma.h"
#include "lcd.h"
#include "shell.h"
#include "srf.h"
#include "led.h"
#include "lib/inc/sequencer.h"
#include "uartjb.h"

/* Definitions */
#define FLASH_ADDR 0x0000
#define BAUDRATE 9600

/* Variables */
int DHCP = 0;
unsigned char IP_address[4];
unsigned char variableMsg[50];
unsigned char BTCommand[bufferSize];
unsigned char srf_data[3] = { 1, 1, 0 };
int interval = 0;

int main() {
    //LCD_Init();
    //LED_Init();
    //srf_init(PB_FRQ);
    bluetooth_Initialize();
    shell_init(PB_FRQ, BAUDRATE);
    
    UARTJB_PutString("\r\nConnected");;
    
    while(true)
    {
        switch(bluetooth_ReceivePackage(BTCommand)) {
        case START_RECEIVED:
                shellSendMessage("\n\r(>?.?<)\t\tPackage received\0"); 
            break;
        case DATA_REC_NOT_START:
                shellSendMessage(BTCommand);
            break;
        case NOT_FOR_THIS_DEVICE:
                shellSendMessage("\n\r( ._.)\t\tWrong address\0"); 
            break;
        case FOR_THIS_DEVICE:
                shellSendMessage("\n\r(/ >w<)/\tIt's for you!\0"); 
            break;
        case REC_FUNC_AND_LENGTH:
                shellSendMessage("\n\r( .-.)\t\tRemoving tape\0"); 
            break;
        case SOURCE_ADDR_REC:
                shellSendMessage("\n\r( '-')\t\tIt's from: \0");
                shellSendMessage(BTCommand);
            break;
        case SAVING_DATA_TO_BUF:
                shellSendMessage("\n\r( .-.)\t\tDigging through package\0"); 
            break;
        case CHECKSUM_WRONG:
                shellSendMessage("\n\r( ;-;)\t\tIt was broken during transit\0"); 
            break;
        case CHECKSUM_CORRECT:
                shellSendMessage("\n\r( ='o'= )\tIt looks intact\0"); 
            break;
        case NO_CRLF_RECEIVED:
                shellSendMessage("\n\r( ;-;)\t\tNope, it was broken during transit\0"); 
            break;
        case PACKAGE_RECEIVED:
            shellSendMessage("\n\r(^O^)\t\tYou've got mail: ");
            shellSendMessage(BTCommand);
            shellSendMessage("\n\r> \0");
            break;
        default:
            //shellSendMessage(BTCommand);
            break;
        }
        
        
        switch(readRecievedCommand()) {
            case 0:     //starting Hexapod
                shellSendMessage("\n\rStarting...\0"); 
                //sequencer_wake();
                shellSendMessage("\n\r> \0");
                break;
                
            case 1:     //stopping Hexapod
                shellSendMessage("\n\rStopping...\0");
                //sequencer_sleep();
                shellSendMessage("\n\r> \0");
                break;
                
            case 2:     //Test
                UARTJB_PutString("\n\r");
                bluetooth_TransmitPackage(15 ,"Succes", 6);
                shellSendMessage("\n\rSending test command...\0");
                //sequencer_sleep();
                shellSendMessage("\n\r> \0");
                break;
                
            case 3:     //Switching DHCP on or off
                if (DHCP == 0) {
                    shellSendMessage("\n\rTurning DHCP on\0");
                    DHCP = 1;
                }
                else {
                    shellSendMessage("\n\rTurning DHCP off\0");
                    DHCP = 0;
                }
                shellSendMessage("\n\r> \0");
                break;
                
            case 4:     //clear command prompt
                shellSendMessage("\fHexapod V1\0");
                shellSendMessage("\n\r==========\0");
                shellSendMessage("\n\r> \0");
                break;
                
            case 5:     //change IP address
                
                break;
                
            case 255:
                shellSendMessage("\n\rerror 255: Command not recognized\0");
                shellSendMessage("\n\r> \0");
                break;
                
            default :
                break;                    
        }
    }
}