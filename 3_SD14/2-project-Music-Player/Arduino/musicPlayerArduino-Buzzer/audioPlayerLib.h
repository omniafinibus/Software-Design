#pragma once
#include <WString.h>
#include "pitches.h"

//Class:	8 controllable LED's
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

//Class:	debounce a given Boolean
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

//Class:	library of songs
class songLib {
	//fields
private:

	//song notes for fur elise
	int furEliseMelody[75] = { NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_GS4, NOTE_B4, NOTE_C5, NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_GS4, NOTE_B4, NOTE_C5, NOTE_E4, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_G4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_F4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_E4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_E5, NOTE_E5, NOTE_E6, NOTE_DS5 };
	//note duration in notes for fur elise
	int furEliseDuration[75] = {8, 8, 8, 8, 8, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 3, 8, 8, 8, 8, 8, 8 };

	//song notes for underworld from mario
	int underworldMelody[56] = { NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4, NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0 };
	//note duration in notes for underworld from mario
	int underworldDuration[56] = {12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18, 10, 10, 10, 10, 10, 10, 3, 3, 3 };

	//song notes
	int jamesBondMelody[99] = { NOTE_G4, NOTE_G4, 0, NOTE_G4, NOTE_G4, 0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_B3, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_CS4, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_B3, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_CS4, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_DS5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_DS5, NOTE_D5, NOTE_G4, NOTE_B4, NOTE_B4, NOTE_FS5, NOTE_F5, NOTE_B4, NOTE_D5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_DS6, NOTE_D6, 0 };
	//note duration in notes
	int jamesBondDurations[99] = {8, 8, 8, 2, 8, 8, 2, 16, 8, 16, 8, 8, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 16, 16, 8, 4, 8, 8, 8, 8, 2, 8, 8, 1, 8, 4, 8, 4, 8, 8, 8, 8, 4, 8, 4, 8, 4, 8, 4, 8, 3 };

	//song notes
	int marioThemeMelody[79] = { NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0, 0, NOTE_G6, 0, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0, NOTE_C7, NOTE_D7, NOTE_B6, 0, 0 };
	//note duration in notes
	int marioThemeDuration[79] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, };

	//song notes
	int piratesOfTheCaribbeanMelody[203] = { NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0, NOTE_A4, NOTE_G4, NOTE_A4, 0, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0, NOTE_A4, NOTE_G4, NOTE_A4, 0, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0, NOTE_C5, NOTE_A4, NOTE_B4, 0, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0, NOTE_A4, NOTE_G4, NOTE_A4, 0, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0, NOTE_A4, NOTE_G4, NOTE_A4, 0, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0, NOTE_D5, NOTE_E5, NOTE_A4, 0, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,NOTE_C5, NOTE_A4, NOTE_B4, 0, NOTE_E5, 0, 0, NOTE_F5, 0, 0, NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0, NOTE_D5, 0, 0, NOTE_C5, 0, 0, NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4, NOTE_E5, 0, 0, NOTE_F5, 0, 0, NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0, NOTE_D5, 0, 0, NOTE_C5, 0, 0, NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4 };
	//note duration in notes
	int piratesOfTheCaribbeanDuration[203] = { 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 4, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 2, 2, 4, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 4, 8, 4, 8, 8, 8, 4, 8, 8, 8, 8, 2, 2, 4, 8, 2, 4, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 2, 4, 8, 2, 4, 8, 2, 8, 8, 8, 8, 8, 1, 4, 8, 2, 4, 8, 2, 8, 8, 8, 8, 8, 8, 8, 8, 2, 4, 8, 2, 4, 8, 2, 8, 8, 8, 8, 8, 1 };

	//no tone
	int noSongMelody[1] = { 0 };
	//short duration
	int noSongDuration[1] = { 1000 };

	int** songsMelodies = new int*[6];
	int** songsNoteDura = new int*[6];
	int* amountOfNotes = new int[6];
	int* recommendedBar = new int[6];
	double speed;
	int currentSong, prevSong;
	bool playing, repeat, playlist;
	int currentNote;
	int audioPin;
	int savedNote, savedSong;
	unsigned long currentNoteTime;
	int lastPLayedSong;
	//unsigned long pauseTime, playTime, startTime, currentTime;

	//methods
public:

	//constructor
	//parameters: pin of the buzzer
	songLib(int buzzerPin);

	//funcion: play next note
	void nextNote();

	//function: go to previous song
	void previousSong();

	//function play or pause song
	void playPause();

	//function: go to next song
	void nextSong();

	//function: switch playlist boolean
	void switchPlaylist();

	//funciont: switch repeat boolean
	void switchRepeat();

	//function: change playback speed
	//parameters: amplifier = speed of song in percentage
	void playbackSpeed(int amplifier);

	////function: keep playtime
	//void timer();

	//funcion: decode string to corresponding song
	//parameters: string that is the name of a song in the playlist
	void decodeString(String songName);
};

//function:		decode analog read buttons to booleans
//parameters:	the booleans that need to be updated and pin number where the buttons are located
void decodeAnalogBtns(int buttonPin, AnalogButton * button1, AnalogButton * button2, AnalogButton * button3);