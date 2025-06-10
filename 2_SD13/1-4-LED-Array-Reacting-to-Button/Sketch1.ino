/*
 Name:		Sketch1.ino
 Created:	2/7/2019 7:35:29 PM
 Author:	410513
*/

#include "debounce.h"

bool btnState;
int num;
int LEDArray[6] = { 6, 8, 13, 5, 7, 12 };
const int butPinMid = 3;

// the setup function runs once when you press reset or power the board
void setup() {
	for (num = 0; num < 6; num++)
	{
		pinMode(LEDArray[num], OUTPUT);
	}

	pinMode(butPinMid, INPUT);
	num = 0;
}

// the loop function runs over and over again until power down or reset
void loop() {	

	//debounce button
	btnState = debounce(butPinMid);

	//go to next number in array by pressing a button
	if (btnState)
	{
		//add 1 or reset number
		if (num >= 5)
		{ 
			num = 0;
		}
		else
		{
			num++;
		}
	}
	
	//go to next led in array
	digitalWrite(LEDArray[num], HIGH);

	if (num == 0)
	{
		digitalWrite(LEDArray[5], LOW);
	}
	else
	{
		digitalWrite(LEDArray[num - 1], LOW);
	}

}
