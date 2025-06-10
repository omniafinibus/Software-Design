#include "TrafficLight.h"
#include <Arduino.h>

TrafficLight::TrafficLight(int green, int yellow, int red)
{
	//initialize variables
	trafficLightState = false;

	currentColour = 0;
	currentMillis = 0;
	previousMillis = millis();

	//initialize LEDS
	greenLed = green;
	yellowLed = yellow;
	redLed = red;

	////Calc array size
	//int sizeOfArray = sizeof waitTime / sizeof waitTime[0];

	//Set all times to 500 ms
	waitTime[0] = 500;
	waitTime[1] = 500;
	waitTime[2] = 500;

	redCheck = true;
}

//TrafficLight::~TrafficLight()
//{
//	//Delete timer array
//	delete[] waitTime;
//}

void TrafficLight::nextLight(int buttonState)
{
	//Check if button is pressed
	if (buttonState == 1)
	{
		//Turns off the auto traffic light
		trafficLightState = false;

		//Check which is the current LED and turns it on
		if (currentColour == 0)
		{
			//Turns on the required LED and turnes off the rest
			digitalWrite(greenLed, HIGH);
			digitalWrite(yellowLed, LOW);
			digitalWrite(redLed, LOW);

			//Go to next LED
			currentColour++;

			////Make sure the button is off to prevent loops
			//buttonState = false;
		}
		else if (currentColour == 1)
		{
			//Turns on the required LED and turnes off the rest
			digitalWrite(greenLed, LOW);
			digitalWrite(yellowLed, HIGH);
			digitalWrite(redLed, LOW);

			//Go to next LED
			currentColour++;

			////Make sure the button is off to prevent loops
			//buttonState = false;
		}
		else if (currentColour == 2)
		{
			//Turns on the required LED and turnes off the rest
			digitalWrite(greenLed, LOW);
			digitalWrite(yellowLed, LOW);
			digitalWrite(redLed, HIGH);

			//Go to next LED
			currentColour = 0;

			////Make sure the button is off to prevent loops
			//buttonState = false;
		}
	}
}

void TrafficLight::autoLightSwitch(int buttonState)
{
	//Changes button to switch
	if (buttonState == 1)
	{
		//Turns on or off the traffic light
		trafficLightState = !trafficLightState;

		//Starts the traffic light in the first LED
		if (trafficLightState == true)
		{
			currentColour = 0;
			digitalWrite(greenLed, HIGH);
		}
		else if (trafficLightState == false)
		{
			digitalWrite(greenLed, LOW);
			digitalWrite(yellowLed, LOW);
			digitalWrite(redLed, HIGH);
		}
	}

	//Reads and saves current millis
	currentMillis = millis();

	//Calculates how long ago since an update
	int difference = currentMillis - previousMillis;

	//Checks if the traffic light is on
	if (trafficLightState == true)
	{
		//Turns on the the next LED after the amount of time has passed
		if (difference >= waitTime[0] && currentColour == 0)
		{
			//Turns of current LED turns on next LED
			digitalWrite(greenLed, LOW);
			digitalWrite(yellowLed, HIGH);

			//Goes to next LED
			currentColour++;

			redCheck = false;

			//Updates time of last update
			previousMillis = millis();
		}
		else if (difference >= waitTime[1] && currentColour == 1)
		{
			//Turns of current LED turns on next LED
			digitalWrite(yellowLed, LOW);
			digitalWrite(redLed, HIGH);

			//Goes to next LED
			currentColour++;

			//Updates time of last update
			previousMillis = millis();
			redCheck = true;
		}
		else if (difference >= waitTime[2] && currentColour == 2)
		{
			//Turns of current LED turns on next LED
			digitalWrite(greenLed, HIGH);
			digitalWrite(redLed, LOW);

			//Goes to next LED
			currentColour = 0;

			//Updates time of last update
			previousMillis = millis();
			redCheck = false;
		}
	}
}

void TrafficLight::autoLight(int buttonState)
{
	//Reads and saves current millis
	currentMillis = millis();

	//Calculates how long ago since an update
	int difference = currentMillis - previousMillis;

	//Checks if the traffic light is on
	if (buttonState == true)
	{
		//Turns on the the next LED after the amount of time has passed
		if (difference >= waitTime[0] && currentColour == 0)
		{
			//Turns of current LED turns on next LED
			digitalWrite(greenLed, LOW);
			digitalWrite(yellowLed, HIGH);

			//Goes to next LED
			currentColour++;

			redCheck = false;

			//Updates time of last update
			previousMillis = millis();
		}
		else if (difference >= waitTime[1] && currentColour == 1)
		{
			//Turns of current LED turns on next LED
			digitalWrite(yellowLed, LOW);
			digitalWrite(redLed, HIGH);

			//Goes to next LED
			currentColour++;

			//Updates time of last update
			previousMillis = millis();
			redCheck = true;
		}
		else if (difference >= waitTime[2] && currentColour == 2)
		{
			//Turns of current LED turns on next LED
			digitalWrite(greenLed, HIGH);
			digitalWrite(redLed, LOW);

			//Goes to next LED
			currentColour = 0;

			//Updates time of last update
			previousMillis = millis();
			redCheck = false;
		}
	}
	else if (buttonState == false)
	{
		digitalWrite(greenLed, LOW);
		digitalWrite(yellowLed, LOW);
		digitalWrite(redLed, HIGH);
	}

}

bool TrafficLight::checkRed()
{
	return redCheck;
}

//void TrafficLight::turnOnLight()
//{
//	trafficLightState = !trafficLightState;
//	
//	if (trafficLightState == true)
//	{
//		currentColour = 0;
//	}
//}
