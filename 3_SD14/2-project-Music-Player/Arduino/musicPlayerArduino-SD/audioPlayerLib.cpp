#include "audioPlayerLib.h"
#include <Arduino.h>

ledArray::ledArray(int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8)
{
	//assign pin integers to the array 
	ledArrayPins[0] = led1;
	ledArrayPins[1] = led2;
	ledArrayPins[2] = led3;
	ledArrayPins[3] = led4;
	ledArrayPins[4] = led5;
	ledArrayPins[5] = led6;
	ledArrayPins[6] = led7;
	ledArrayPins[7] = led8;
}

void ledArray::initialize()
{
	//set all LED pins as an output
	pinMode(ledArrayPins[0], OUTPUT);
	pinMode(ledArrayPins[1], OUTPUT);
	pinMode(ledArrayPins[2], OUTPUT);
	pinMode(ledArrayPins[3], OUTPUT);
	pinMode(ledArrayPins[4], OUTPUT);
	pinMode(ledArrayPins[5], OUTPUT);
	pinMode(ledArrayPins[6], OUTPUT);
	pinMode(ledArrayPins[7], OUTPUT);
}

void ledArray::turnAllOff()
{
	//turn off all LEDs
	for (int i = 0; i < 8; i++)
	{
		digitalWrite(ledArrayPins[i], LOW);
	}
}

void ledArray::turnOnUpTo(int requiredLED)
{
	//turn on leds up to "requiredLED"
	for (int i = 0; i <= requiredLED; i++)
	{
		digitalWrite(ledArrayPins[i], HIGH);
	}
}

AnalogButton::AnalogButton()
{
	//initial values of fields
	buttonState = LOW;
	lastButtonState = LOW;
	lastDebounceTime = 0;
	debounceDelay = 50;
	lastClickTime = 0;
	lastTimeDiff = 0;
}

void AnalogButton::updateBool(bool newState)
{
	//update state of the boolean 
	analogButton = newState;
}

bool AnalogButton::read()
{
	bool result = LOW;	// value to be returned after executing the function

	// read the state of the switch into a local variable:
	int reading = analogButton;

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// if the switch changed, due to noise or pressing:
	if (reading != lastButtonState)
	{
		// reset the debouncing timer
		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than
		// the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (reading != buttonState)
		{
			buttonState = reading;

			// only toggle the LED if the new button state is HIGH
			if (buttonState == HIGH)
			{
				result = HIGH;
			}
		}
	}

	// save the reading.  Next time through the function,
	// it'll be the lastButtonState:
	lastButtonState = reading;
	analogButton = false;
	return result;
}

void decodeAnalogBtns(int buttonPin, AnalogButton * button1, AnalogButton * button2, AnalogButton * button3)
{
	//read the value of the analog pin which is connected to the buttons
	int buttonValue = analogRead(buttonPin);

	if (buttonValue > 450 && buttonValue < 500)
	{
		//turn on the boolean assign to the first button
		button1->updateBool(HIGH);
	}
	else if (buttonValue > 600 && buttonValue < 700)
	{
		//turn on the boolean assign to the second button
		button2->updateBool(HIGH);
	}
	else if (buttonValue > 900)
	{
		//turn on the boolean assign to the third button
		button3->updateBool(HIGH);
	}
}