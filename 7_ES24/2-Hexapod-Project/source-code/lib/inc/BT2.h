/* 
 * File:   BT2.h
 * Author: Arjan Lemmens
 * Created on 03-05-2022
 */

#ifndef BT2_H
#define	BT2_H

#include <stdbool.h>

#define START_RECEIVED      1
#define DATA_REC_NOT_START  2
#define NOT_FOR_THIS_DEVICE 3
#define FOR_THIS_DEVICE     4
#define SOURCE_ADDR_REC     5
#define REC_FUNC_AND_LENGTH 6
#define SAVING_DATA_TO_BUF  7
#define CHECKSUM_WRONG      8
#define CHECKSUM_CORRECT    9
#define NO_CRLF_RECEIVED    10
#define PACKAGE_RECEIVED    11
#define bufferSize          50

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/*
 * function: bluetooth_Initialize(void)
 * 
 * pre: none 
 * 
 * post: none 
 * 
 * description: initialize the bluetooth module and required libraries
 */
void bluetooth_Initialize(void);

/* 
 * function:  bluetooth_EnableCommandMode(void)
 * 
 * pre: None
 * 
 * post: boolean- If command port has correctly opened
 * 
 * description: Opens the Bluetooth module too commands
 */ 
bool bluetooth_EnableCommandMode(void);

/* 
 * function:  bluetooth_DisableCommandMode(void)
 * 
 * pre: None
 * 
 * post: boolean- If command port has correctly closed 
 * 
 * description: Closes the Bluetooth module to commands
 */ 
bool bluetooth_DisableCommandMode(void);

/* ==========================================================================
 * function:  bluetooth_SetCommand(char * command, char * value)
 *
 * pre: command - command which needs the be sent (check RN-42 documentation)
 *      value   - Value to append command (check RN-42 documentation)
 *   
 * post: boolean- If command port has correctly opened and closed 
 *
 * description: Sends specified commands to Bluetooth module to change functionality
 */
bool bluetooth_SetCommand(uint8_t * command, uint8_t functionLength , uint8_t * value, uint8_t dataLength);

/* 
 * function:  bluetooth_GetCommand(char * command)
 * 
 * pre: command - command which needs the be sent (check RN-42 documentation
 * 
 * post: boolean- If command port has correctly opened and closed 
 * 
 * description: Sends specified commands to Bluetooth module which will return      
 *              the value over UART for the specified command
 */ 
bool bluetooth_GetCommand(uint8_t * command);

void bluetooth_TransmitPackage(uint8_t function ,uint8_t *data, uint8_t length);

uint8_t bluetooth_ReceivePackage(uint8_t * buffer);

/* 
 * function:  bluetooth_ClearBuffer(void)
 * 
 * pre: None
 * 
 * post: None
 * 
 * description: Clears the internally used buffers
 */ 
void bluetooth_ClearBuffer(void);

///* 
// * function:  bluetooth_ReceivedChar(void)
// * 
// * pre: None
// * 
// * post: char   - returns the last received character from the UART buffer
// * 
// * description: Read the last received character
// */ 
//void bluetooth_ToggleEcho(void);
//
///* 
// * function:  bluetooth_GetDipValues(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Get the current dip switch values
// */ 
//void bluetooth_GetDipValues(void);
//
///* 
// * function:  bluetooth_Disconnect(void)
// * 
// * pre: None
// * 
// * post: bool - returns if the module has correctly disconnected the  
// *              current connection
// * 
// * description: Disconnect the current connection
// */ 
//bool bluetooth_Disconnect(void);
//
///* 
// * function:  bluetooth_ConnectToKnown(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Connect to the stored remote address
// */ 
//void bluetooth_ConnectToKnown(void);
//
///* 
// * function:  bluetooth_ConnectToKnownFast(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Connect to the stored remote address in fast mode
// */ 
//void bluetooth_ConnectToKnownFast(void);
//
///* 
// * function:  bluetooth_ConnectToLastFast(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Connect to the last acquired address from inquiry in fast mode
// */ 
//void bluetooth_ConnectToLastFast(void);
//
///* 
// * function:  bluetooth_ReceivedChar(void)
// * 
// * pre: None
// * 
// * post: char   - returns the last received character from the UART buffer
// * 
// * description: Read the last received character
// */ 
//void bluetooth_ConnectToAddressTimer(char * address, uint8_t duration);
//
///* 
// * function:  bluetooth_ConnectToAddress(char * address)
// * 
// * pre: None
// * 
// * post: address - 12 hexadecimal value for the Bluetooth address to connect to
// * 
// * description: Connect to a specified bluetooth address
// */ 
//void bluetooth_ConnectToAddress(char * address);
//
///* 
// * function:  bluetooth_ConnectToAddressFast(char * address)
// * 
// * pre: None
// * 
// * post: address - 12 hexadecimal value for the Bluetooth address to connect to
// * 
// * description: Connect to a specified bluetooth address in fast mode
// */ 
//void bluetooth_ConnectToAddressFast(char * address);
//
///* 
// * function:  bluetooth_StartFastMode(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Start fast mode, this means the module wont respond to "$$$"
// */ 
//void bluetooth_StartFastMode(void);
//
///* 
// * function:  bluetooth_InquiryTimer(uint8_t duration)
// * 
// * pre: duration -  How long the inquiry will last in 0.25 * duration seconds
// * 
// * post: None
// * 
// * description: Inquires about all active Bluetooth devices for specified 
// *              amount of time
// */ 
//void bluetooth_InquiryTimer(uint8_t duration);
//
///* 
// * function:  bluetooth_InquiryTimerWithCOD(uint8_t duration, char * COD)
// * 
// * pre: duration -  How long the inquiry will last in 0.25 * duration seconds
// *      COD -       first 4 hexadecimal values of Bluetooth devices
// * 
// * post: None
// * 
// * description: Inquires about all active Bluetooth devices which start with 
// *              the 4 entered hexadecimal values, for specified amount of time
// */ 
//void bluetooth_InquiryTimerWithCOD(uint8_t duration, char * COD);
//
///* 
// * function:  bluetooth_InquiryTimerNoEcho(uint8_t duration, char * COD)
// * 
// * pre: duration -  How long the inquiry will last in 0.25 * duration seconds
// *      COD -       first 4 hexadecimal values of Bluetooth devices
// * 
// * post: None
// * 
// * description: Inquires about all active Bluetooth devices for specified 
// *              amount of time, without relaying the found devices
// */ 
//void bluetooth_InquiryTimerNoEcho(uint8_t duration, char * COD);
//
///* 
// * function:  bluetooth_InquiryWithRSSI(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Inquires about all active Bluetooth devices and relays the  
// *              measured RSSI 
// */ 
//void bluetooth_InquiryWithRSSI(void);
//
///* 
// * function:  bluetooth_InquiryFor1F00(uint8_t duration)
// * 
// * pre: duration -  How long the inquiry will last in 0.25 * duration seconds
// * 
// * post: None
// * 
// * description: Inquires about all devices which have an address that 
// *              starts with 0x1F00 (factory set COD)
// */ 
//void bluetooth_InquiryFor1F00(uint8_t duration);
//
///* 
// * function: bluetooth_InquiryFor55AA(uint8_t duration)
// * 
// * pre: duration - how long the inquiry will continue
// * 
// * post: None
// * 
// * description: Device Scan Inquiry, Fixed COD (0x0055AA) to Find Instant Cable Pairs
// */ 
//void bluetooth_InquiryFor55AA(uint8_t duration);
//
///* 
// * function:  bluetooth_HidePinCode(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Hides the Device?s Pin Code.
// */ 
//void bluetooth_HidePinCode(void);
//
///* 
// * function:  bluetooth_TestConnection(char * buffer)
// * 
// * pre: buffer - buffer to save the value of RSSI too
// * 
// * post: bool - If the device was connected 
// * 
// * description: Toggle Link Quality Readings
// */ 
//bool bluetooth_TestConnection(char * buffer);
//
///* 
// * function: bluetooth_ModemSignalStatus(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Check which status the modum is in
// */ 
//void bluetooth_ModemSignalStatus(void);
//
///* 
// * function:  bluetooth_DisplaySettings(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Start sending current set settings of the module to the     
// *              MCU over UART
// */ 
//void bluetooth_DisplaySettings(void);
//
///* 
// * function:  bluetooth_QuietModeUndiscoverable(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: puts the device into quiet mode, which means it is temporarily 
// *              not discoverable or connectable.
// */ 
//void bluetooth_QuietModeUndiscoverable(void);
//
///* 
// * function: bluetooth_QuietMode(uint8_t value)
// * 
// * pre: value - The type of quiet mode which is required (check RN-42 documentation)
// * 
// * post: None
// * 
// * description: puts the device into quiet mode, which means it is temporarily 
// *              not discoverable or connectable.
// */ 
//void bluetooth_QuietMode(uint8_t value);
//
///* 
// * function: bluetooth_ForceReboot(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Reboot the module
// */ 
//void bluetooth_ForceReboot(void);
//
///* 
// * function: bluetooth_PassDataSwitch(bool mode)
// * 
// * pre: mode - the new mode to set too
// * 
// * post: None
// * 
// * description: Pass Received Data (from UART or Bluetooth) while in Command Mode
// */ 
//void bluetooth_PassDataSwitch(bool mode);
//
///* 
// * function: bluetooth_TempUARTSettings(uint32_t newBaud, char parity)
// * 
// * pre: newBaud - new baudrate
// *      parity  - new parity setting (Check RN-42 documentation)
// * 
// * post: None
// * 
// * description: temporarily set new UARt settings (will lost on reboot)
// */ 
//void bluetooth_TempUARTSettings(uint32_t newBaud, char parity);
//
///* 
// * function:  bluetooth_DisplayFirmware(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Makes the Bluetooth module start sending the firmware version
// */ 
//void bluetooth_DisplayFirmware(void);
//
///* 
// * function:  bluetooth_LoudMode(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Make the device discoverable and connectable
// */ 
//void bluetooth_LoudMode(void);
//
///* 
// * function:  bluetooth_DeepSleep(void)
// * 
// * pre: None
// * 
// * post: None
// * 
// * description: Enter Bluetooth module into the deep sleep state
// */ 
//void bluetooth_DeepSleep(void);

#endif	/* BT2_H */