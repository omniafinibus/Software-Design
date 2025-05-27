/*
 Name:		controlling_an_led.ino
 Created:	10-Nov-18 05:34:33 PM
 Author:	Arjan Lemmens
*/

const int ledPinRL = 5;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPinRL, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(ledPinRL, HIGH);
	delay(250);
	digitalWrite(ledPinRL, LOW);
	delay(250);
}
