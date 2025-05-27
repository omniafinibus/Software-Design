// Test program to test the funtionality of the Arduino shield for the course General Electronic Skills (GES)
// Components:
//   * RGB led (1x, common cathode) to PWM pins 9, 10, 11 (in the order R, G, B)
//   * 2 x Green LEDs to pins 12 and 13
//   * 2 x Yellow / orange LEDs to pins 7 and 8
//   * 2 x Red Leds to pins 5 and 6
//   * 3 x pushbuttons (pull-down) at pins 2, 3, 4
//   * 2 x POT meters to PIN A0 and A1
// References to layout: keep USB port to your left, such that the traffic lights are natural

// constants
const int greenLedPinLeft = 12;                     // green led traffic light left
const int greenLedPinRight = 13;                    // green led traffic light right
const int yellowLedPinLeft = 7;                     // yellow led traffic light left
const int yellowLedPinRight = 8;                    // yellow led traffic light right
const int redLedPinLeft = 5;                        // red led traffic light left
const int redLedPinRight = 6;                       // red led traffic light right

const int rgbLedPinRed = 9;                         // rgb led red
const int rgbLedPinGreen = 10;                      // rgb led green
const int rgbLedPinBlue = 11;                       // rgb led blue

const int buttonPinBottom = 4;                      // button bottom
const int buttonPinMiddle = 3;                      // button middle
const int buttonPinTop = 2;                         // button top

const int potPinLeft = A0;							// potentiometer left
const int potPinRight = A1;							// potentiometer right

const unsigned long debounceDelay = 50;             // fixed debounce delay for pushbuttons

// variables 
bool leftTrafficLightState = false;                 // indicator for top pushbutton (false is off)
bool rightTrafficLightState = false;                // indicator for middle pushbutton 
bool rgbLedState = false;							// indicator for bottom pushbutton

int nrTrafficLightLeft = 2;                         // state counter for left traffic light
int nrTrafficLightRight = 2;                        // state counter for right traffic light
int nrRgbLed = 5;                                   // state counter for rgb led

unsigned long previousMillisTrafficLightLeft = 0;   // indicator when last time left traffic light was updated
unsigned long previousMillisTrafficLightRight = 0;  // indicator when last time right traffic light was updated
unsigned long previousMillisRgbLight = 0;           // indicator when last time rgb led was updated 

int btnStateTop = LOW;                              // current reading from the top pushbutton
int lastBtnStateTop = LOW;                          // previous reading from the top pushbutton
unsigned long lastDebounceTimeBtnTop = 0;           // last time the top pushbutton was toggled

int btnStateMiddle = LOW;                           // current reading from the middle pushbutton
int lastbtnStateMiddle = LOW;                       // previous reading from the middle pushbutton
unsigned long lastDebounceTimeBtnMiddle = 0;        // last time the middle pushbutton was toggled

int btnStateBottom = LOW;                           // current reading from the bottom pushbutton
int lastbtnStateBottom = LOW;                       // previous reading from the bottom pushbutton
unsigned long lastDebounceTimeBtnBottom = 0;        // last time the bottom pushbutton was toggled


void setup()
{
	// rgb led
	pinMode(rgbLedPinRed, OUTPUT);
	pinMode(rgbLedPinGreen, OUTPUT);
	pinMode(rgbLedPinBlue, OUTPUT);

	// traffic lights
	pinMode(greenLedPinLeft, OUTPUT);
	pinMode(greenLedPinRight, OUTPUT);
	pinMode(yellowLedPinLeft, OUTPUT);
	pinMode(yellowLedPinRight, OUTPUT);
	pinMode(redLedPinLeft, OUTPUT);
	pinMode(redLedPinRight, OUTPUT);

	// pushbuttons
	pinMode(buttonPinBottom, INPUT);
	pinMode(buttonPinMiddle, INPUT);
	pinMode(buttonPinTop, INPUT);

	// potentiometers
	pinMode(potPinLeft, INPUT);
	pinMode(potPinRight, INPUT);

	// check LEDs traffic light
	const int delayTime = 250;
	digitalWrite(greenLedPinLeft, HIGH);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, LOW);
	digitalWrite(yellowLedPinLeft, HIGH);
	delay(delayTime);
	digitalWrite(yellowLedPinLeft, LOW);
	digitalWrite(redLedPinLeft, HIGH);
	delay(delayTime);
	digitalWrite(redLedPinLeft, LOW);
	digitalWrite(greenLedPinRight, HIGH);
	delay(delayTime);
	digitalWrite(greenLedPinRight, LOW);
	digitalWrite(yellowLedPinRight, HIGH);
	delay(delayTime);
	digitalWrite(yellowLedPinRight, LOW);
	digitalWrite(redLedPinRight, HIGH);
	delay(delayTime);
	digitalWrite(redLedPinRight, LOW);

	// check rgb LED
	digitalWrite(rgbLedPinRed, HIGH);
	delay(delayTime);
	digitalWrite(rgbLedPinRed, LOW);
	digitalWrite(rgbLedPinGreen, HIGH);
	delay(delayTime);
	digitalWrite(rgbLedPinGreen, LOW);
	digitalWrite(rgbLedPinBlue, HIGH);
	delay(delayTime);
	digitalWrite(rgbLedPinBlue, LOW);

	// last check with leds flashing
	digitalWrite(greenLedPinLeft, HIGH);
	digitalWrite(greenLedPinRight, HIGH);
	digitalWrite(yellowLedPinLeft, HIGH);
	digitalWrite(yellowLedPinRight, HIGH);
	digitalWrite(redLedPinLeft, HIGH);
	digitalWrite(redLedPinRight, HIGH);
	digitalWrite(rgbLedPinRed, HIGH);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, LOW);
	digitalWrite(greenLedPinRight, LOW);
	digitalWrite(yellowLedPinLeft, LOW);
	digitalWrite(yellowLedPinRight, LOW);
	digitalWrite(redLedPinLeft, LOW);
	digitalWrite(redLedPinRight, LOW);
	digitalWrite(rgbLedPinRed, LOW);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, HIGH);
	digitalWrite(greenLedPinRight, HIGH);
	digitalWrite(yellowLedPinLeft, HIGH);
	digitalWrite(yellowLedPinRight, HIGH);
	digitalWrite(redLedPinLeft, HIGH);
	digitalWrite(redLedPinRight, HIGH);
	digitalWrite(rgbLedPinGreen, HIGH);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, LOW);
	digitalWrite(greenLedPinRight, LOW);
	digitalWrite(yellowLedPinLeft, LOW);
	digitalWrite(yellowLedPinRight, LOW);
	digitalWrite(redLedPinLeft, LOW);
	digitalWrite(redLedPinRight, LOW);
	digitalWrite(rgbLedPinGreen, LOW);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, HIGH);
	digitalWrite(greenLedPinRight, HIGH);
	digitalWrite(yellowLedPinLeft, HIGH);
	digitalWrite(yellowLedPinRight, HIGH);
	digitalWrite(redLedPinLeft, HIGH);
	digitalWrite(redLedPinRight, HIGH);
	digitalWrite(rgbLedPinBlue, HIGH);
	delay(delayTime);
	digitalWrite(greenLedPinLeft, LOW);
	digitalWrite(greenLedPinRight, LOW);
	digitalWrite(yellowLedPinLeft, LOW);
	digitalWrite(yellowLedPinRight, LOW);
	digitalWrite(redLedPinLeft, LOW);
	digitalWrite(redLedPinRight, LOW);
	digitalWrite(rgbLedPinBlue, LOW);
	Serial.begin(9600);
}

void loop()
{
	// local variables
	int readingBtnTop;		// reading top button
	int readingBtnMiddle;	// reading of middle button
	int readingBtnBottom;	// reading of bottom button
	int potValLeft;			// value of left potentiometer
	int potValRight;		// value of right potentionmeter


	// debounce the three pushbuttons

	// read the state of the button into a local variable:
	readingBtnTop = digitalRead(buttonPinTop);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// if the switch changed, due to noise or pressing:
	if (readingBtnTop != lastBtnStateTop)
	{
		// reset the debouncing timer
		lastDebounceTimeBtnTop = millis();
	}

	if ((millis() - lastDebounceTimeBtnTop) > debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than
		// the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (readingBtnTop != btnStateTop)
		{
			btnStateTop = readingBtnTop;

			// only toggle the LED if the new button state is HIGH
			if (btnStateTop == LOW)
			{
				// if rgb led is on, stop it
				rgbLedState = false;
				// toggle
				leftTrafficLightState = !leftTrafficLightState;
			}
		}
	}

	// save the reading.  Next time through the function,
	// it'll be the lastButtonState:
	lastBtnStateTop = readingBtnTop;


	// read the state of the button into a local variable:
	readingBtnMiddle = digitalRead(buttonPinMiddle);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// if the switch changed, due to noise or pressing:
	if (readingBtnMiddle != lastbtnStateMiddle)
	{
		// reset the debouncing timer
		lastDebounceTimeBtnMiddle = millis();
	}

	if ((millis() - lastDebounceTimeBtnMiddle) > debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than
		// the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (readingBtnMiddle != btnStateMiddle)
		{
			btnStateMiddle = readingBtnMiddle;

			// only toggle the LED if the new button state is HIGH
			if (btnStateMiddle == LOW)
			{
				// if rgb led is on, stop it
				rgbLedState = false;
				// toggle
				rightTrafficLightState = !rightTrafficLightState;
			}
		}
	}

	// save the reading.  Next time through the function,
	// it'll be the lastButtonState:
	lastbtnStateMiddle = readingBtnMiddle;


	// read the state of the button into a local variable:
	readingBtnBottom = digitalRead(buttonPinBottom);

	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:

	// if the switch changed, due to noise or pressing:
	if (readingBtnBottom != lastbtnStateBottom)
	{
		// reset the debouncing timer
		lastDebounceTimeBtnBottom = millis();
	}

	if ((millis() - lastDebounceTimeBtnBottom) > debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than
		// the debounce delay, so take it as the actual current state:

		// if the button state has changed:
		if (readingBtnBottom != btnStateBottom)
		{
			btnStateBottom = readingBtnBottom;

			// only toggle the LED if the new button state is HIGH
			if (btnStateBottom == LOW)
			{
				// if traffic light are on, stop them
				leftTrafficLightState = false;
				rightTrafficLightState = false;
				// toggle
				rgbLedState = !rgbLedState;
			}
		}
	}

	// save the reading.  Next time through the function,
	// it'll be the lastButtonState:
	lastbtnStateBottom = readingBtnBottom;


	// read potentionmeters
	potValLeft = analogRead(potPinLeft);
	potValRight = analogRead(potPinRight);


	if (leftTrafficLightState)
	{
		int valSpeed = (int)((900.0 / 1024.0) * potValLeft + 100);

		// check to see if it's time to blink the LED; that is, if the difference
		// between the current time and last time you blinked the LED is bigger than
		// the interval at which you want to blink the LED.
		unsigned long currentMillis = millis();

		if (currentMillis - previousMillisTrafficLightLeft >= valSpeed)
		{
			// save the last time you blinked the LED
			previousMillisTrafficLightLeft = currentMillis;

			switch (nrTrafficLightLeft)
			{
			case 0: // yellow
				digitalWrite(greenLedPinLeft, LOW);
				digitalWrite(yellowLedPinLeft, HIGH);
				break;
			case 1: // red
				digitalWrite(yellowLedPinLeft, LOW);
				digitalWrite(redLedPinLeft, HIGH);
				break;
			case 2: // green
				digitalWrite(redLedPinLeft, LOW);
				digitalWrite(greenLedPinLeft, HIGH);
				break;
			default:
				break;
			}

			// update counter
			nrTrafficLightLeft = (nrTrafficLightLeft + 1) % 3;
		}
	}
	else
	{
		// reset counter
		nrTrafficLightLeft = 2;

		// turn off traffic light
		digitalWrite(greenLedPinLeft, LOW);
		digitalWrite(yellowLedPinLeft, LOW);
		digitalWrite(redLedPinLeft, LOW);
	}


	if (rightTrafficLightState)
	{
		int valSpeed = (int)((900.0 / 1024.0) * potValRight + 100);

		// check to see if it's time to blink the LED; that is, if the difference
		// between the current time and last time you blinked the LED is bigger than
		// the interval at which you want to blink the LED.
		unsigned long currentMillis = millis();

		if (currentMillis - previousMillisTrafficLightRight >= valSpeed)
		{
			// save the last time you blinked the LED
			previousMillisTrafficLightRight = currentMillis;

			switch (nrTrafficLightRight)
			{
			case 0: // yellow
				digitalWrite(greenLedPinRight, LOW);
				digitalWrite(yellowLedPinRight, HIGH);
				break;
			case 1: // red
				digitalWrite(yellowLedPinRight, LOW);
				digitalWrite(redLedPinRight, HIGH);
				break;
			case 2: // green
				digitalWrite(redLedPinRight, LOW);
				digitalWrite(greenLedPinRight, HIGH);
				break;
			default:
				break;
			}

			// update traffic light
			nrTrafficLightRight = (nrTrafficLightRight + 1) % 3;
		}
	}
	else
	{
		// reset counter
		nrTrafficLightRight = 2;

		// turn off traffic light
		digitalWrite(greenLedPinRight, LOW);
		digitalWrite(yellowLedPinRight, LOW);
		digitalWrite(redLedPinRight, LOW);
	}


	if (rgbLedState)
	{
		int valIntensity = potValLeft / 4;
		int valSpeed = (int)((900.0 / 1024.0) * potValRight + 100);

		// check to see if it's time to blink the LED; that is, if the difference
		// between the current time and last time you blinked the LED is bigger than
		// the interval at which you want to blink the LED.
		unsigned long currentMillis = millis();

		if (currentMillis - previousMillisRgbLight >= valSpeed)
		{
			// save the last time you blinked the LED
			previousMillisRgbLight = currentMillis;

			switch (nrRgbLed)
			{
			case 0: // green
				analogWrite(rgbLedPinRed, 0);
				analogWrite(rgbLedPinGreen, valIntensity);
				break;
			case 1: // blue
				analogWrite(rgbLedPinGreen, 0);
				analogWrite(rgbLedPinBlue, valIntensity);
				break;
			case 2: // red
				analogWrite(rgbLedPinBlue, 0);
				analogWrite(rgbLedPinRed, valIntensity);
				break;
			case 3: // cyan
				analogWrite(rgbLedPinRed, 0);
				analogWrite(rgbLedPinGreen, valIntensity);
				analogWrite(rgbLedPinBlue, valIntensity);
				break;
			case 4: // purple
				analogWrite(rgbLedPinGreen, 0);
				analogWrite(rgbLedPinRed, valIntensity);
				break;
			case 5: // orange
				analogWrite(rgbLedPinBlue, 0);
				analogWrite(rgbLedPinGreen, valIntensity);
				break;
			default:
				break;
			}

			// update counter
			nrRgbLed = (nrRgbLed + 1) % 6;
		}
	}
	else
	{
		// reset counter
		nrRgbLed = 5;

		// turn off rgb led
		analogWrite(rgbLedPinRed, 0);
		analogWrite(rgbLedPinGreen, 0);
		analogWrite(rgbLedPinBlue, 0);
	}
	Serial.write("Red Left");
	Serial.write(redLedPinLeft);
	Serial.print("\t");
	Serial.write("Red Right");
	Serial.write(redLedPinRight);
	Serial.print("\t");
	Serial.write("Yellow Left");
	Serial.write(yellowLedPinLeft);
	Serial.print("\t");
	Serial.write("Yellow Right");
	Serial.write(yellowLedPinRight);
	Serial.print("\t");
	Serial.write("Green Left");
	Serial.write(greenLedPinLeft);
	Serial.print("\t");
	Serial.write("Green Right");
	Serial.write(greenLedPinRight);
	Serial.print("\t");

	Serial.write("Blue RGB");
	Serial.write(rgbLedPinBlue);
	Serial.print("\t");
	Serial.write("Green RGB");
	Serial.write(rgbLedPinGreen);
	Serial.print("\t");
	Serial.write("Red RGB");
	Serial.write(rgbLedPinRed);
	Serial.print("\t");

	Serial.write("Left Pot");
	Serial.write(potPinLeft);
	Serial.print("\t");
	Serial.write("Right Pot");
	Serial.write(potPinRight);
	Serial.print("\t");

	Serial.write("Button Bottom");
	Serial.write(buttonPinBottom);
	Serial.print("\t");
	Serial.write("Button Middle");
	Serial.write(buttonPinMiddle);
	Serial.print("\t");
	Serial.write("Button Top");
	Serial.write(buttonPinTop);
	Serial.print("\t");
}