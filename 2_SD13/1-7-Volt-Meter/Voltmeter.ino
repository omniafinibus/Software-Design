/*
 Name:		Voltmeter.ino
 Created:	2/12/2019 7:56:39 PM
 Author:	410513
*/

#include "arduinoLibrary.h"

const int ledPinRL = 5;
const int ledPinYL = 7;
const int ledPinGL = 12;
const int ledPinRGBG = 10;
const int readingPin = A0;

const unsigned long readTime = 10;
const unsigned long refreshTime = 500;

unsigned long currentMillis;
unsigned long timeSinceMeas = 0;
int index = 0;

unsigned long size = refreshTime / readTime;
int *measurements = new int[size];

int max;
double average;

// the setup function runs once when you press reset or power the board
void setup() {
	//setup pins
	pinMode(ledPinGL, OUTPUT);
	pinMode(ledPinRL, OUTPUT);
	pinMode(ledPinYL, OUTPUT);
	pinMode(ledPinRGBG, OUTPUT);
	pinMode(readingPin, INPUT);
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {

	//measure for requested amount
	for (index = 0; index < size; index++)
	{
		//wait for requestd amount
		currentMillis = millis();
		if (currentMillis - timeSinceMeas >= readTime)
		{
			measurements[index] = ((double)analogRead(readingPin) / 1023) * 5;
		}
		timeSinceMeas = millis();
	}
	//reset timer
	timeSinceMeas = 0;
	
	//calc max and average
	average = findAverage(measurements, size);
	max = findMax(measurements, size);

	//show results
	Serial.print("Max voltage is: ");
	Serial.print(max);
	Serial.print("V");
	Serial.print("\t");

	Serial.print("Average voltage is: ");
	Serial.print(average);
	Serial.print("V");
	Serial.print("\t");

	////delete array
	//delete[] measurements;
}