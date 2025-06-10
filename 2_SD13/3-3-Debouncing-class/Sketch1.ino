/*
 Name:		Sketch1.ino
 Created:	3/13/2019 9:05:57 PM
 Author:	410513
*/

#include "debounce.h"

//LED pins
const int ledPinRR = 6;
const int ledPinYR = 8;
const int ledPinGR = 13;

//Button pins
const int butPinTop = 2;
const int butPinMid = 3;
const int butPinBot = 4;

//buttonClasses
Button topButton(butPinTop);
Button midButton(butPinMid);
Button botButton(butPinBot);

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPinRR, OUTPUT);
	pinMode(ledPinYR, OUTPUT);
	pinMode(ledPinGR, OUTPUT);

	pinMode(butPinTop, INPUT);
	pinMode(butPinMid, INPUT);
	pinMode(butPinBot, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	topButton.debounce();
	midButton.debounce();
	botButton.debounce();

	digitalWrite(ledPinRR, digitalRead(butPinTop));
	digitalWrite(ledPinYR, digitalRead(butPinMid));
	digitalWrite(ledPinGR, digitalRead(butPinBot));
}
