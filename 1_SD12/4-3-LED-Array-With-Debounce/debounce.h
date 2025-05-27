// Debounce.h

#ifndef _DEBOUNCE_h
#define _DEBOUNCE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
/*
	parameters:	a = buttonstate
*/
int debounce(int a);
#endif