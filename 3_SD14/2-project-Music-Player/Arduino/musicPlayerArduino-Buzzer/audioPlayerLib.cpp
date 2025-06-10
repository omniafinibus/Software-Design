#include "audioPlayerLib.h"
#include "pitches.h"
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

void decodeAnalogBtns(int buttonPin, AnalogButton* button1, AnalogButton* button2, AnalogButton* button3)
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

songLib::songLib(int buzzerPin)
{
	repeat = false;
	playing = false;
	playlist = false;

	savedNote = 0;
	savedSong = 0;

	currentSong = 5;
	prevSong = 0;
	currentNote = 0;
	audioPin = buzzerPin;

	lastPLayedSong = 0;
	currentNoteTime = 0;

	speed = 1;

	//save the array in an array
	songsMelodies[0] = furEliseMelody;
	songsNoteDura[0] = furEliseDuration;

	//check how many notes are in the melody array
	amountOfNotes[0] = sizeof(furEliseDuration) / sizeof(furEliseDuration[0]);
	//bar speed (number found after testing)
	recommendedBar[0] = 1500;

	//save the array in an array
	songsMelodies[1] = underworldMelody;
	songsNoteDura[1] = underworldDuration;

	//check how many notes are in the melody array
	amountOfNotes[1] = sizeof(underworldDuration) / sizeof(underworldDuration[0]);
	//bar speed (number found after testing)
	recommendedBar[1] = 1500;

	//save the array in an array
	songsMelodies[2] = jamesBondMelody;
	songsNoteDura[2] = jamesBondDurations;

	//check how many notes are in the melody array
	amountOfNotes[2] = sizeof(jamesBondDurations) / sizeof(jamesBondDurations[0]);
	//bar speed (number found after testing)
	recommendedBar[2] = 900;

	//save the array in an array
	songsMelodies[3] = marioThemeMelody;
	songsNoteDura[3] = marioThemeDuration;

	//check how many notes are in the melody array
	amountOfNotes[3] = sizeof(marioThemeDuration) / sizeof(marioThemeDuration[0]);
	//bar speed (number found after testing)
	recommendedBar[3] = 1000;

	//save the array in an array
	songsMelodies[4] = piratesOfTheCaribbeanMelody;
	songsNoteDura[4] = piratesOfTheCaribbeanDuration;

	//check how many notes are in the melody array
	amountOfNotes[4] = sizeof(piratesOfTheCaribbeanDuration) / sizeof(piratesOfTheCaribbeanDuration[0]);
	//bar speed (number found after testing)
	recommendedBar[4] = 750;

	//save the array in an array
	songsMelodies[5] = noSongMelody;
	songsNoteDura[5] = noSongDuration;

	//check how many notes there are in the melody array
	amountOfNotes[5] = sizeof(noSongDuration) / sizeof(noSongDuration[0]);
	//bar speed (as fast as possible)
	recommendedBar[5] = 10000;
}

void songLib::nextNote()
{
	//save last played song so when play is pressed it goes back to that song
	if (currentSong != 5)
	{
		lastPLayedSong = currentSong;
	}
	//make 2 arrays to assign
	int *frequency = new int[amountOfNotes[currentSong]];
	int *duration = new int[amountOfNotes[currentSong]];

	//save which song is currently in use
	frequency = songsMelodies[currentSong];
	duration = songsNoteDura[currentSong];

	int noteTime = (recommendedBar[currentSong] / duration[currentNote]) / speed;
	/*delay(bar);*/
	//make the sound of the current song
	tone(audioPin, frequency[currentNote], noteTime);

	//go to next note after "bar"
	if (millis() - currentNoteTime > noteTime)
	{
		//update currentNoteTime
		currentNoteTime = millis();
		currentNote++;
		
		//pause between notes, otherwise you wont hear stops
		noTone(audioPin);
	}

	//check if its the end of the song
	if (currentNote >= amountOfNotes[currentSong])
	{
		if (playlist)
		{
			Serial.print("nextAr\n");
			//if playlist is on go to next song
			nextSong();
		}
		else if (repeat)
		{
			//if loop is on restart the song
			currentNote = 0;
		}
		else
		{
			//switch to noSong
			currentNote = 0;
			currentSong = 5;
		}
	}
}

void songLib::previousSong()
{
	//decrease current song int
	if (currentSong > 0)
	{
		currentSong--;
	}
	//if pause go to prev song base on last song
	else if (currentSong == 5)
	{
		playing = true;
		if (savedSong < 4)
		{
			savedSong--;
		}
		else
		{
			savedSong = 0;
		}

		currentSong = savedSong;
	}
	//go back to the end of the song array
	else
	{
		currentSong = 4;
	}
	//start next song from the beginning
	currentNote = 0;

	//update saved song when chaging song
	savedSong = currentSong;
}

void songLib::playPause()
{
	//pause
	if (playing)
	{
		//saved current note and song to save where you paused
		savedNote = currentNote;
		savedSong = currentSong;

		//set current note and song to noSong
		currentNote = 0;
		currentSong = 5;

		//update playing boolaen
		playing = false;
	}
	//play
	else
	{
		//set current song and note to saved note and saved song
		currentNote = savedNote;
		currentSong = savedSong;

		//update playing boolaen
		playing = true;
	}

}

void songLib::nextSong()
{
	//increase current song int
	if (currentSong < 4)
	{
		currentSong++;
	}
	//if pause go to next song base on last song
	else if (currentSong == 5)
	{
		playing = true;
		if (savedSong < 4)
		{
			savedSong++;
		}
		else
		{
			savedSong = 0;
		}
		
		currentSong = savedSong;
	}
	//go back to the start of the song array
	else
	{
		currentSong = 0;
	}
	//start next song from the beginning
	currentNote = 0;

	//update saved song when chaging song 
	savedSong = currentSong;
}

void songLib::switchPlaylist()
{
	//check which state playlist is currently in and switch to the other
	if (playlist)
	{
		playlist = false;
	}
	else
	{
		playlist = true;
	}
}

void songLib::switchRepeat()
{
	//check which state repeat is currently in and switch to the other
	if (repeat)
	{
		repeat = false;
	}
	else
	{
		repeat = true;
	}
}

void songLib::playbackSpeed(int amplifier)
{
	//change percentage to multiplier
	speed = amplifier * 0.01;
}

void songLib::decodeString(String songName)
{
	//check which song needs to be played
	if (songName == "nameFurElise")
	{
		//update current song to fur elise
		currentSong = 0;
	}
	else if (songName == "nameUnderWorld")
	{
		//update current song to underworld
		currentSong = 1;
	}
	else if (songName == "nameJamesBond")
	{
		//update current song to James Bond
		currentSong = 2;
	}
	else if (songName == "nameMarioTheme")
	{
		//update current song to the mario theme song
		currentSong = 3;
	}
	else if (songName == "namePirOfTheCar")
	{
		//update current song to the pirates of the caribbean theme song
		currentSong = 4;
	}
	else
	{
		//play fur elise as a default
		currentSong = 0;
	}
	//play from the start
	currentNote = 0;
}