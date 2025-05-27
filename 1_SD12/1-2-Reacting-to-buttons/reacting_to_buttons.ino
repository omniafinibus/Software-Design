/*
 Name:		reacting_to_buttons.ino
 Created:	10-Nov-18 05:51:19 PM
 Author:	Arjan Lemmens
*/
const int ledPinRL = 5;
const int butPinBot = 4;
int buttonState;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPinRL, OUTPUT);
	pinMode(butPinBot, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	buttonState = digitalRead(butPinBot);
	digitalWrite(ledPinRL, buttonState);
}
