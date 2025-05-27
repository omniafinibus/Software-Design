const int potPinL = A0;
const int potPinR = A1;

void setup() {

	Serial.begin(9600);

	//assign pin numbers
	const int potPinL = A0;
	const int potPinR = A1;

	//set pin type
	pinMode(potPinL, INPUT);
	pinMode(potPinR, INPUT);
}

void loop() {
	//read pot meters and assign them to the sides of a triangle
	double across = analogRead(potPinL);
	double adjacent = analogRead(potPinR);
	double hypotenuse;

	//limit available values between 0 and 225
	across = constrain(across, 0, 255);
	adjacent = constrain(adjacent, 0, 255);

	//calculate hypotenuse
	hypotenuse = sqrt(across * across + adjacent * adjacent);

	//show values of all sides
	Serial.print("across");
	Serial.println(across, DEC);
	Serial.print("adjacent");
	Serial.println(adjacent, DEC);
	Serial.print("hypotenuse");
	Serial.println(hypotenuse, DEC);
}