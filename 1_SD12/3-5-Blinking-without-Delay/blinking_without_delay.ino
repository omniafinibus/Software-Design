/*
 Name:		_2.ino
 Created:	12/10/2018 5:41:22 PM
 Author:	A.Lemmens
*/

int offDelay;
int ran;
bool ledState;
unsigned long prevMillis = 0;
const int ledPinRGBR = 9;

void setup()
{
	Serial.begin(9600);

	//sets pinMode
	pinMode(ledPinRGBR, OUTPUT);

	//creates random seed
	randomSeed(analogRead(0));

	//Turn on the LED ass initilization
	digitalWrite(ledPinRGBR, HIGH);

}

void loop()
{
	unsigned long curMillis = millis();
	ledState = digitalRead(ledPinRGBR);

	//checks if the led is on 
	if (ledState)
	{
		//turns LED off after 100 milliseconds
		if (100 <= curMillis - prevMillis)
		{
			digitalWrite(ledPinRGBR, LOW);
			//updates time passed since last action 
			prevMillis = curMillis;
			//creates new value for off time
			ran = random(250, 4001);
		}
	}

	//turns LED onafter a random period
	else if (ran <= curMillis - prevMillis)
	{
		//updates time passed since last change
		prevMillis = curMillis;
		digitalWrite(ledPinRGBR, HIGH);
	}
}
