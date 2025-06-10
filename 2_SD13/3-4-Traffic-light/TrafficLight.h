#pragma once

class TrafficLight
{
private:
	bool trafficLightState;
	bool trafficLightStateMan;
	int currentColour;
	int *waitTime = new int[3];
	unsigned long currentMillis;
	unsigned long previousMillis;
	int greenLed, yellowLed, redLed;

public:
	//constructor
	//parameters:	green is pin of green LED
	//				yellow is pin of yellow LED
	//				red is pin of red LED
	TrafficLight(int green, int yellow, int red);

	////deconstructor
	//~TrafficLight();
	
	//function:		turn next light on
	void nextLight(int buttonState);

	//funcion:		turn on auto change
	void autoLight(int buttonState);

	////function:		turns on the lights
	//void turnOnLight();
};