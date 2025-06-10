#include "audioPlayerLib.h"
#include <math.h>


const int buzzer = 10;
const int btnPin = A1;
const int volumePot = A0;

ledArray* volumeLEDs = new ledArray(13, 9, 8, 7, 6, 5, 3, 2);

AnalogButton* prevBtn = new AnalogButton();
AnalogButton* playPauseBtn = new AnalogButton();
AnalogButton* nextBtn = new AnalogButton();

songLib* classic90s = new songLib(buzzer);

int volume;
int prevVolume = 1;

unsigned long currentTime, playTime, pauseTime;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);

	//initialize LED array
	volumeLEDs->initialize();

	//initialize pins 
	pinMode(volumePot, INPUT);
	pinMode(btnPin, INPUT);
	pinMode(buzzer, OUTPUT);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	//check if serial communication is available
	if (Serial.available())
	{
		String command = Serial.readString();
		//if arduino recieves "next"
		if (command == "next")
		{
			//go to next song in playlist
			classic90s->nextSong();
		}

		//if arduino recieves "play"
		if (command == "play")
		{
			//play or pause song
			classic90s->playPause();
		}

		//if arduino recieves "prev"
		if (command == "prev")
		{
			//go to prev song or reset the song
			classic90s->previousSong();
		}

		//if arduino recieves "playlist"
		if (command == "playlist")
		{
			//switch playlist
			classic90s->switchPlaylist();
		}

		//if arduino recieves "loop"
		if (command == "loop")
		{
			//switch loop
			classic90s->switchRepeat();
		}

		//if arduino recieves command that starts with name
		if (command.startsWith("name"))
		{
			//play corresponding song
			classic90s->decodeString(command);
		}
		//if arduino recieves command that starts with S
		if (command.startsWith("S"))
		{
			//cut off S
			String speedValue = command.substring(1);
			//convert string to usable int and update it in the library
			classic90s->playbackSpeed(speedValue.toInt());
		}
	}

	//read current volume
	volume = analogRead(volumePot) / 127; //1023 divede by 8 options = 127

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

	//read analog buttons
	decodeAnalogBtns(btnPin, prevBtn, playPauseBtn, nextBtn);

	//check if the prev button has been pressed
	if (prevBtn->read())
	{
		//send command to gui
		Serial.print("prevAr\n");
		//go to prev song or reset the song
		classic90s->previousSong();
	}

	//check if the playPause button has been pressed
	if (playPauseBtn->read())
	{
		//send command to gui
		Serial.print("playAr\n");

		//pause or play current song
		classic90s->playPause();
	}

	//check if the next button has been pressed
	if (nextBtn->read())
	{
		//send command to gui
		Serial.print("nextAr\n");

		//go to next song
		classic90s->nextSong();
	}

	////update time of current song
	//classic90s->timer();

	//go to next note of song
	classic90s->nextNote();
}
