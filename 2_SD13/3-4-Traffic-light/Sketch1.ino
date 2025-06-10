#include "TrafficLight.h"
#include "debounce.h"

const int butPinTop = 2;
const int butPinBot = 4;

const int ledPinRR = 6;
const int ledPinYR = 8;
const int ledPinGR = 13;

int state;

Button topButton(butPinTop);
Button botButton(butPinBot);

TrafficLight leftLeds(ledPinGR, ledPinYR, ledPinRR);

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPinGR, OUTPUT);
	pinMode(ledPinRR, OUTPUT);
	pinMode(ledPinYR, OUTPUT);

	pinMode(butPinBot, INPUT);
	pinMode(butPinTop, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	leftLeds.autoLight(topButton.debounce());
	leftLeds.nextLight(botButton.debounce());
}
