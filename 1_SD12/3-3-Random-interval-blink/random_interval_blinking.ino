int offDelay;
const int ledPinRGBR = 9;

void setup() {
	Serial.begin(9600);

	//sets pinMode
	pinMode(ledPinRGBR, OUTPUT);

	//creates random seed
	randomSeed(analogRead(0));
}

void loop() {
	//sets offDelay to a value from 250 to 4000
	offDelay = random(250, 4001);

	//turns on LED for 0.1 secend
	digitalWrite(ledPinRGBR, HIGH);
	delay(100);

	//turns LED off for a random period
	digitalWrite(ledPinRGBR, LOW);
	delay(offDelay);
}
