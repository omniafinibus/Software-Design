/*
 Name:		controlling-an-array-of-leds.ino
 Created:	10-Nov-18 05:58:36 PM
 Author:	Arjan Lemmens
*/
const int ledPinRL = 5;
const int ledPinRR = 6;
const int ledPinYL = 7;
const int ledPinYR = 8;
const int slow = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(ledPinRL, OUTPUT);
	pinMode(ledPinRR, OUTPUT);
	pinMode(ledPinYL, OUTPUT);
	pinMode(ledPinYR, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	digitalWrite(ledPinRL, HIGH);
	delay(slow);
	digitalWrite(ledPinRL, LOW);
	digitalWrite(ledPinRR, HIGH);
	delay(slow);
	digitalWrite(ledPinRR, LOW);
	digitalWrite(ledPinYL, HIGH);
	delay(slow);
	digitalWrite(ledPinYL, LOW);
	digitalWrite(ledPinYR, HIGH);
	delay(slow);
	digitalWrite(ledPinYR, LOW);
}
