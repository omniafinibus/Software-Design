/*
 Name:		LED_array_reacting_to_button_clicks.ino
 Created:	14-Nov-18 02:16:15 PM
 Author:	Arjan Lemmens
*/

//Assign LED's and button to a pin
const int ledPinRR = 6;
const int ledPinYR = 8;
const int ledPinGR = 13;
const int ledPinRL = 5;
const int ledPinYL = 7;
const int ledPinGL = 12;
const int butPinMid = 3;

//give the counter a initial value
int counter = 1;
int buttonPress;

//intialize debouncing
int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;

int reading;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
	//Assign integers as output or input
	pinMode(ledPinRL, OUTPUT);
	pinMode(ledPinRR, OUTPUT);
	pinMode(ledPinYL, OUTPUT);
	pinMode(ledPinYR, OUTPUT);
	pinMode(ledPinGR, OUTPUT);
	pinMode(ledPinGL, OUTPUT);
	pinMode(butPinMid, INPUT);

	//Sets initial LED states
	//digitalWrite(ledPinRL, ledState);
	//digitalWrite(ledPinYL, ledState);
	//digitalWrite(ledPinYR, ledState);
	//digitalWrite(ledPinRR, ledState);
	//digitalWrite(ledPinGR, ledState);
	//digitalWrite(ledPinGL, ledState);
}

void loop()
{
	//check state of button
	reading = digitalRead(butPinMid);

	// If the switch changed, due to noise or pressing:
	if (reading != lastButtonState) {
		// reset the debouncing timer
		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > debounceDelay) {
		// whatever the reading is at, it's been there for longer than the debounce
		// delay, so take it as the actual current state:

		// if the button state has changed:
		if (reading != buttonState) {
			buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (buttonPress == HIGH)
			{
				//Turns on LED next in line
				if (counter == 1)
				{
					digitalWrite(ledPinRL, ledState);
					digitalWrite(ledPinGR, LOW);
				}

				if (counter == 2)
				{
					digitalWrite(ledPinYL, ledState);
					digitalWrite(ledPinRL, LOW);
				}
				if (counter == 3)
				{
					digitalWrite(ledPinGL, ledState);
					digitalWrite(ledPinYL, LOW);
				}

				if (counter == 4)
				{
					digitalWrite(ledPinRR, ledState);
					digitalWrite(ledPinGL, LOW);
				}
				if (counter == 5)
				{
					digitalWrite(ledPinYR, ledState);
					digitalWrite(ledPinRR, LOW);
				}
				if (counter == 6)
				{
					digitalWrite(ledPinGR, ledState);
					digitalWrite(ledPinYR, LOW);
				}
			}
			else if (buttonPress == LOW)
			{
				//Add a button press to the amount of presses
				if (counter < 6)
				{
					counter++;
				}
				//resets amount of presses when it reaches max value
				else
				{
					counter -= 5;
				}
			}
		}
	}

	buttonPress = digitalRead(butPinMid);
	//check if button is pressed and how many times it has been pushed

	lastButtonState = reading;
}