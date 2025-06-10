/*
 Name:		musicPlayerArduino.ino
 Created:	5/16/2019 9:42:48 PM
 Author:	A.Lemmens
*/

#include "audioPlayerLib.h"

const int sckSD = 13;
const int misoSD = 12;
const int mosiSD = 11;
const int csSD = 4;

AnalogButton* playBtn = new AnalogButton();
AnalogButton* nextBtn = new AnalogButton();
AnalogButton* prevBtn = new AnalogButton();

const int recieveLED = 0;
const int transmitLED = 1;

const int speakerPin = 10;
const int volumePot = A0;

ledArray* volumeLEDs = new ledArray(13, 9, 8, 7, 6, 5, 3, 2);

const int btns = A1;

int speed;
bool playingBool;
unsigned long currentTime;

int volume;
int prevVolume = 1;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(57600);

	volumeLEDs->initialize();

	pinMode(speakerPin, OUTPUT);
	pinMode(volumePot, INPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
	//decodes buttons to 
	decodeAnalogBtns(btns, prevBtn, playBtn, nextBtn);

	//check if any button has been pressed or updated through serial data
	if (prevBtn->read() == true)
	{
		//check if song has been playing for longer than 5 seconds
		if (currentTime > 5000)
		{
			//reset current song
			
		}
		else
		{
			//go to previous song
		}
	}
	else if (playBtn->read() == true)
	{
		//pause or play the song
	}
	else if (nextBtn->read() == true)
	{
		//go to next song
	}

		//check if serial data is available
		if (Serial.available())
		{
			String commands = Serial.readString();
			//turn on booleans corresponding with acquired serial data

			if (commands == "play")
			{
				//turn on play boolean
				playBtn->updateBool(HIGH);
			}
			else if (commands == "next")
			{
				//turn on next boolean
				nextBtn->updateBool(HIGH);
			}
			else if (commands == "prev")
			{
				//turn on prevBtn boolean
				prevBtn->updateBool(HIGH);
			}
			else if (commands == "playlist")
			{
				//switch playlist on or off
			}
			//check if command starts with a capital S
			else if (commands.startsWith("S"))
			{
				//save the characters after S to a substring
				String valueString = commands.substring(1);

				//convert string to usable interger
				speed = valueString.toInt();
			}
		}

	//read potmeter and change to int to increase stability
	volume = analogRead(volumePot) / 146;

	//if the volume changes it turns on the amount of LEDs corresponding to the volume
	if (volume != prevVolume)
	{
		//update prevVolume
		prevVolume = volume;

		//turn all LEDs off first
		volumeLEDs->turnAllOff();

		//turn required LEDs on
		volumeLEDs->turnOnUpTo(volume);
	}
}