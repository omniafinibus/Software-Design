/* 
 * File:   shell.h
 * Author: Arjan Lemmens
 * Created on 04-03-2021
 */

#ifndef SHELL_H
#define	SHELL_H

/* ------------------------------------------------------------ */
/*						Definitions      		                */
/* ------------------------------------------------------------ */

typedef struct
{
    char name[50];
    int length;
    int value;
}cmd;

/* ------------------------------------------------------------ */
/*						Function prototypes		                */
/* ------------------------------------------------------------ */

/* Global functions */

/* Private functions */

/* ========================================================================== */
/* function: setupCmd(cmdName, cmdLength, cmdValue); */
/* */
/* description: initialises the shell module. */
/* */
/* pre: cmdName - string to which shell responds */
/*      cmdAddress - address of the command that needs to be setup*/
/* */   
/* post: none*/
/* ========================================================================== */
void setupCmd(char* cmdName, cmd * cmdAddress);

/* ========================================================================== */
/* function: shell_init( fpb ); */
/* */
/* description: initialises the shell module. */
/* */
/* pre: fpb - peripheral bus clock frequency in Hz */
/* */
/* post: return value - 0 if initialisation failed */
/* 1 if initialisation succeeded */
/* ========================================================================== */
unsigned char shell_init(unsigned int fpb);

/* ========================================================================== */
/* function: shellSendMessage( message ); */
/* */
/* description: transmits a message, stored as a string in the message */
/* variable, to the terminal. The message will be terminated */
/* with a newline: "\n\r". */
/* */
/* pre: message - pointer to the first element of the string to be */
/* transmitted to the terminal */
/* */
/* post: return value - 0 if transmission failed */
/* 1 if transmission was successful */
/* ========================================================================== */
void shellSendMessage(unsigned char *message);

/* ========================================================================== */
/* function: shellReadMessage(); */
/* */
/* description: reads incoming message and responds to it */
/* */
/* pre: buffer - address of the buffer to save too */
/* */
/* post: new string - returns a 1 if the buffer has been updated else its 0*/
/* ========================================================================== */
char shellReadMessage(unsigned char *buffer);

/* ========================================================================== */
/* function: readInt(); */
/* */
/* description: finds all integers in string */
/* */
/* pre: str - address of the string to check */
/* */
/* post: integer value in string*/
/* ========================================================================== */
int readInt(char* str);

#endif	/* SHELL_H */