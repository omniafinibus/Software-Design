#include "Car.h"
#include <iostream>

void car::changeSpeed(int newSpeed)
{	
	//change speed
	currentSpeed = newSpeed;

	//show changes speed
	std::cout << "Your new speed is: " << newSpeed << "km/h\n";
}
