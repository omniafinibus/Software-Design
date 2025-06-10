#include "TrafficLight.h"
#include "debounce.h"

const int butPinTop = 2;
const int butPinBot = 4;

const int ledPinRR = 6;
const int ledPinYR = 8;
const int ledPinGR = 13;

const int ledPinRL = 5;
const int ledPinYL = 7;
const int ledPinGL = 12;

int state;

Button topButton(butPinTop);
Button botButton(butPinBot);

TrafficLight rightLeds(ledPinGR, ledPinYR, ledPinRR);
TrafficLight leftLeds(ledPinGL, ledPinYL, ledPinRL);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);

	pinMode(ledPinGR, OUTPUT);
	pinMode(ledPinRR, OUTPUT);
	pinMode(ledPinYR, OUTPUT);

	pinMode(ledPinGL, OUTPUT);
	pinMode(ledPinRL, OUTPUT);
	pinMode(ledPinYL, OUTPUT);

	pinMode(butPinBot, INPUT);
	pinMode(butPinTop, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	if (rightLeds.checkRed() == true)
	{
		leftLeds.autoLight(true);
		rightLeds.autoLight(false);
	}
	
	if (leftLeds.checkRed() == true)
	{
		leftLeds.autoLight(false);
		rightLeds.autoLight(true);
	}
}
