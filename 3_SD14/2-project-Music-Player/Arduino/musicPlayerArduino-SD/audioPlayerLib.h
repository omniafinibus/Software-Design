#pragma once

//Class:		8 LED's
class ledArray
{
	//fields
private:

	int ledArrayPins[8];

	//methods
public:

	//use:			save pin intergers to the array
	//parameters:	int led1 - led8 are the pins of the use LEDs
	ledArray(int led1, int led2, int led3, int led4, int led5, int led6, int led7, int led8);

	//use:			Initialize all selected pins to outputs and save intergers to class's fields
	void initialize();

	//use:			Turn off all LEDs
	void turnAllOff();

	//use:			Turns on required LEDs until required LED
	//parameters:	int representing LED, led1 = 1, led2 = 2 etc
	void turnOnUpTo(int requiredLED);
};

/*
	Class:		debounce a given Boolean
	Returns:	Debounced button state.
*/
class AnalogButton
{
	//fields
private:

	int buttonState;
	int lastButtonState;
	bool analogButton;
	unsigned long lastDebounceTime;
	unsigned long debounceDelay;
	unsigned long lastClickTime;
	unsigned long lastTimeDiff;

	//methods
public:

	//constructor
	AnalogButton();

	//function: update boolean to debounce
	void updateBool(bool newState);

	//function:	debounce button
	bool read();
};

//function:		decode analog read buttons to booleans
//parameters:	the booleans that need to be updated and pin number where the buttons are located
void decodeAnalogBtns(int buttonPin, AnalogButton * button1, AnalogButton * button2, AnalogButton * button3);