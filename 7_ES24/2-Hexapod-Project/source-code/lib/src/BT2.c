/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>
#include <config.h>

/* Personal libraries*/
#include "utils.h"
#include "uartjb.h"
#include "pmods.h"
#include "config.h"
#include "BT2.h"

/* Definitions */
#define FUNC_WAKE           0x11
#define FUNC_SLEEP          0x21
#define FUNC_SCAN           0x31
#define FUNC_FORWARD        0x41
#define FUNC_FORWARD_FAST   0x51
#define FUNC_BACKWARD       0x61
#define FUNC_BACKWARD_FAST  0x71
#define FUNC_RIGHT          0x81
#define FUNC_LEFT           0x91
#define FUNC_DIST_DATA      0xA3
#define FUNC_AUTONOMOUS     0xF1

#define START_BYTE          0x41 //0xFE changed to 0x41 ('A') for test
#define SERVER_ADDRESS      0x30
#define HEXAPOD_ADDRESS     0x20
#define BROADCAST_ADDRESS   0x42 //0x00 changed to 0x42 ('B') for test
#define baudRate            9600


#define WAITING_FOR_START   0
#define WAITING_FOR_DEST    1
#define WAITING_FOR_SOURCE  2
#define DECODE_FUNC_LEN     3
#define SAVING_DATA         4
#define CONTROL_CHECKSUM    5
#define WAITING_FOR_END     6

/* Variables */
uint8_t bluetooth_buffer[bufferSize];
uint8_t rx_buffer[bufferSize];
uint8_t tx_buffer[bufferSize];
uint8_t rx_buf_poll[bufferSize];
uint8_t receiver_state, function, length, current_byte;
uint16_t checksum;

void bluetooth_Initialize() {
    UARTJB_InitPoll(baudRate);  //Init uart
    receiver_state = WAITING_FOR_START;
    function = 0x00;
    length = 0;
    current_byte = 0x00;
    checksum = 0x0000;
}

bool bluetooth_EnableCommandMode(void) {
    bluetooth_ClearBuffer(); //Prepare buffers
    UARTJB_PutString("$$$"); //Send data
    UARTJB_GetStringPoll(rx_buffer); //Read response
    
    //If Bluetooth module responded with CMD it is in command mode
    if(memcmp(rx_buffer, "CMD", 3) == 0) { return 1; }
    else { return 0; }
}

bool bluetooth_DisableCommandMode(void) {
    bluetooth_ClearBuffer(); //Prepare buffers
    UARTJB_PutString("---<cr>"); //Send data 
    UARTJB_GetStringPoll(rx_buffer); //Read response
    
    //If response is END it has successfully exited command mode
    if(memcmp(rx_buffer, "END", 3) == 0) { return 1; }
    else { return 0; }
}

//bool bluetooth_SetCommand(uint8_t * command, uint8_t functionLength , uint8_t * value, uint8_t dataLength) {
//    uint8_t interval;
//    bluetooth_ClearBuffer(); //Prepare buffers
//    
//    for (interval = 0; interval < functionLength; interval++) {
//        tx_buffer[interval] = command[interval];
//    }
//    
//    tx_buffer[functionLength] = ',';
//    
//    for (interval = 0; interval < dataLength; interval++) {
//        tx_buffer[interval] = value[interval];
//    }
//    
//    if (bluetooth_EnableCommandMode()) {
//        UARTJB_PutString(tx_buffer);
//        if(bluetooth_DisableCommandMode()) { return 1; }
//        else{ return 0; }
//    }
//    else { return 0; }
//}
//
//bool bluetooth_GetCommand(uint8_t * command) {
//    bluetooth_ClearBuffer(); //Prepare buffers
//    if ( bluetooth_EnableCommandMode() ) {
//        sprintf(tx_buffer, "%s\n",command);
//        UARTJB_PutString(tx_buffer);
//        if( bluetooth_DisableCommandMode() ) { return 1; }
//        else{ return 0; }
//    }
//    else { return 0; }
//}

void bluetooth_TransmitPackage(uint8_t function ,uint8_t *data, uint8_t length) {
    uint8_t interval;
    uint16_t sum = 0;
    uint8_t msb, lsb;
    bluetooth_ClearBuffer();
    tx_buffer[0] = START_BYTE;
    tx_buffer[1] = SERVER_ADDRESS;
    tx_buffer[2] = HEXAPOD_ADDRESS;
    msb = (function & 0x0F) << 4;
    lsb = length & 0x0F;
    tx_buffer[3] = msb + lsb;
    
    //Add all data bytes up
    for (interval = 0; interval < length; interval++) {
        tx_buffer[(interval+4)] = data[interval];
        sum = data[interval] + sum; 
    }
    
    tx_buffer[(length+4)] = (uint8_t)(sum & 0x00FF); //get 8 LSB of sum
    
    UARTJB_PutString(tx_buffer);
}

uint8_t bluetooth_ReceivePackage(uint8_t * buffer) {
    bool dataRec = 0;
    
    dataRec = UARTJB_GetStringPoll(rx_buf_poll);
    if (dataRec > 0) {
        switch (receiver_state) {
            case WAITING_FOR_START:
                if (rx_buf_poll[0] == START_BYTE) { 
                    function = 0x00;
                    length = 0;
                    current_byte = 0;
                    checksum = 0x0000;
                    receiver_state = WAITING_FOR_DEST; 
                    return START_RECEIVED;
                }
                else {
                    buffer[0] = rx_buf_poll[0];
                    return DATA_REC_NOT_START;
                }
                break;
            case WAITING_FOR_DEST:
                if (rx_buf_poll[0] == 0x20 || rx_buf_poll[0] == 0x00 ) { 
                    receiver_state = WAITING_FOR_SOURCE;
                    return FOR_THIS_DEVICE;
                }
                else { 
                    receiver_state = WAITING_FOR_START; 
                    return NOT_FOR_THIS_DEVICE;
                }
                break;
            case WAITING_FOR_SOURCE:    
                buffer[0] = rx_buf_poll[0];
                receiver_state = DECODE_FUNC_LEN; 
                return SOURCE_ADDR_REC;
            case DECODE_FUNC_LEN:
                function = (rx_buf_poll[0] & 0xF0) >> 4;
                buffer[0] = function;
                length = rx_buf_poll[0] & 0x0F;
                receiver_state = SAVING_DATA;
                return REC_FUNC_AND_LENGTH;
                break;
            case SAVING_DATA:
                if(current_byte < length) {
                    //save data and update checksum and current_byte
                    buffer[current_byte + 1] = rx_buf_poll[0];
                    checksum = checksum + rx_buf_poll[0];
                    current_byte++;
                    return SAVING_DATA_TO_BUF;
                }
                else if (current_byte == length){
                    //check if check sum is correct, otherwise flush the buffer and restart
                    if(rx_buf_poll[0] == (checksum & 0x00FF)) {  
                        receiver_state = WAITING_FOR_END; 
                        return CHECKSUM_CORRECT; 
                    }
                    else { 
                        uint8_t interval;
                        for(interval = 0; interval < (length + 1); interval++) {
                            buffer[interval] = '\0';
                        }
                        receiver_state = WAITING_FOR_START; 
                        return CHECKSUM_WRONG; 
                    }
                }
                else { receiver_state = WAITING_FOR_END; }
                break;
            case WAITING_FOR_END:
                if(rx_buf_poll[0] == 0x0D) {
                    receiver_state = WAITING_FOR_START; 
                    return PACKAGE_RECEIVED; 
                }
                else {
                    receiver_state = WAITING_FOR_START; 
                    return NO_CRLF_RECEIVED; 
                }
                break;
            default:
                return 0;
                break;
        }
    }
}

void bluetooth_ClearBuffer(void) {
    uint8_t interval, length;
    length = strlen(tx_buffer);
    for(interval = 0; interval < length; interval++) {
        tx_buffer[interval];
    }
    
    length = strlen(rx_buffer);
    for(interval = 0; interval < length; interval++) {
        rx_buffer[interval];
    }
    
    length = strlen(bluetooth_buffer);
    for(interval = 0; interval < length; interval++) {
        bluetooth_buffer[interval];
    }
}

/*
void bluetooth_ToggleEcho(void) {
    bluetooth_EnableCommandMode();
    UARTJB_PutString("+\n");
    bluetooth_DisableCommandMode();
}

void bluetooth_GetDipValues(void) {
    bluetooth_EnableCommandMode();
    UARTJB_PutString("&\n");
    bluetooth_DisableCommandMode();
}

bool bluetooth_Disconnect(void) {
    bluetooth_EnableCommandMode();
    UARTJB_PutString("K\n");
    
    //wait for response
    //while(!UARTJB_AvaliableRx()) { ; }
    
    //Read response
    UARTJB_GetString(rx_buffer, 4);
    
    //If Bluetooth module responded with CMD it is in command mode
    if(memcmp(rx_buffer, "KILL", 4) == 0) { 
        bluetooth_ClearBuffer();
        connected = 0;
        bluetooth_DisableCommandMode();
        return 1;
    }
    else { 
        bluetooth_ClearBuffer();
        bluetooth_DisableCommandMode();
        return 0;
    }
}

void bluetooth_ConnectToKnown(void) {
    bluetooth_EnableCommandMode();
    UARTJB_PutString("C\n");
    connected = 1;
    bluetooth_DisableCommandMode();
}

void bluetooth_ConnectToKnownFast(void) {
    UARTJB_PutString("CFR");
    connected = 1;
}

void bluetooth_ConnectToLastFast(void) {
    UARTJB_PutString("CFI");
    connected = 1;
}

void bluetooth_ConnectToAddressTimer(char * address, uint8_t duration) {
    if (strlen(address) == 12) {
        sprintf(tx_buffer, "CT,%s%u\0", address, duration);
        UARTJB_PutString(tx_buffer);
        bluetooth_ClearBuffer();
        connected = 1;
    }
}

void bluetooth_ConnectToAddress(char * address) {
    if (strlen(address) == 12) {
        sprintf(tx_buffer, "C,%s\0", address);
        UARTJB_PutString(tx_buffer);
        bluetooth_ClearBuffer();
        connected = 1;
    }
}

void bluetooth_ConnectToAddressFast(char * address) {
    if (strlen(address) == 12) {
        sprintf(tx_buffer, "CF,%s\0", address);
        UARTJB_PutString(tx_buffer);
        bluetooth_ClearBuffer();
        connected = 1;
    }
}

void bluetooth_StartFastMode(void) {
    UARTJB_PutString("F,1");
}

void bluetooth_InquiryTimer(uint8_t duration) {
    uint8_t limited;
    
    if(duration > 48) { limited = 48; }
    else { limited = duration; }
    sprintf(tx_buffer, "I,%u", limited);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
    
}

void bluetooth_InquiryTimerWithCOD(uint8_t duration, char * COD) {
    uint8_t limited;
    
    if(duration > 48) { limited = 48; }
    else { limited = duration; }
    
    if(strlen(COD) == 6) { 
        sprintf(tx_buffer, "I,%u,%s", limited, COD); 
        UARTJB_PutString(tx_buffer);
        bluetooth_ClearBuffer();
    }    
}

void bluetooth_InquiryTimerNoEcho(uint8_t duration, char * COD) {
    uint8_t limited;
    
    if(duration > 48) { limited = 48; }
    else { limited = duration; }
    
    if(strlen(COD) == 6) { sprintf(tx_buffer, "I,%u%s", limited, COD); }
}

void bluetooth_InquiryWithRSSI(void) {
    UARTJB_PutString("IQ");
}

void bluetooth_InquiryFor1F00(uint8_t duration) {
    sprintf(tx_buffer, "IS%u", duration);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
}

void bluetooth_InquiryFor55AA(uint8_t duration) {
    sprintf(tx_buffer, "IR%u", duration);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
}

void bluetooth_HidePinCode(void) {
    UARTJB_PutString('J');
}

bool bluetooth_TestConnection(char * buffer) {
    //Send data
    UARTJB_PutChar('L');
    
    //wait for response
    //while(!UARTJB_AvaliableRx()) { ; }
    
    //Read response
    UARTJB_GetString(buffer, 14);
    
    //If response is END it has successfully exited command mode
    if(memcmp(buffer, "NOT Connected!", 14) == 0) { 
        connected = 0;
        return 0;
    }
    else { 
        return 1;    
    }
} 

void bluetooth_ModemSignalStatus(void) {
    UARTJB_PutChar('M');
}

void bluetooth_DisplaySettings(void) {
    UARTJB_PutChar('O');
}

void bluetooth_QuietModeUndiscoverable(void) {
    UARTJB_PutChar('Q');
}

void bluetooth_QuietMode(uint8_t value) {
    sprintf(tx_buffer, "Q,%u", value);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
}

void bluetooth_ForceReboot(void) {
    UARTJB_PutString("R,1");
}

void bluetooth_PassDataSwitch(bool mode) {
    sprintf(tx_buffer, "T,%i", mode);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
}

void bluetooth_TempUARTSettings(uint32_t newBaud, char parity) {
    char baudString[4];
    switch(newBaud) {
        case 1200:
            sprintf(baudString, "%u", newBaud);
            break;
        case 2400:
            sprintf(baudString, "%u", newBaud);
            break;
        case 4800:
            sprintf(baudString, "%u", newBaud);
            break;
        case 9600:
            sprintf(baudString, "%u", newBaud);
            break;
        case 19200:
            sprintf(baudString, "192K");
            break;
        case 38400:
            sprintf(baudString, "384K");
            break;
        case 57600:
            sprintf(baudString, "576K");
            break;
        case 115200:
            sprintf(baudString, "115K");
            break;
        case 230400:
            sprintf(baudString, "230K");
            break;
        case 460800:
            sprintf(baudString, "460K");
            break;
        case 921000:
            sprintf(baudString, "921K");
            break;
        default:
            sprintf(baudString, "115K");
    }
    sprintf(tx_buffer, "U,%s,%c", baudRate,parity);
    UARTJB_PutString(tx_buffer);
    bluetooth_ClearBuffer();
}

void bluetooth_DisplayFirmware(void) {
    UARTJB_PutChar('V');
}

void bluetooth_LoudMode(void) {
    UARTJB_PutChar('W');
}

void bluetooth_DeepSleep(void) {
    UARTJB_PutChar('Z');
}
*/