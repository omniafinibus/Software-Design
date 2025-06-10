#include "Car.h"
#include <iostream>

void car::changeSpeed(int newSpeed)
{
	//change speed
	currentSpeed = newSpeed;

	//show changes speed
	std::cout << "Your " << model << " is going: " << newSpeed << "km/h\n";
}

void car::accelerate()
{
	//check if max speed isnt achieved
	if (currentSpeed <= maxSpeed)
	{
		//change speed
		currentSpeed += 10;
	}
	else
	{
		std::cout << "Your " << model << " can't speed up any more.\n";
	}
	//Show changed speed
	std::cout << "Your " << model << " is going: " << currentSpeed << "km/h\n";
}

void car::slowDown()
{
	//check if your car isnt standing still
	if (currentSpeed >= 10)
	{
		//change speed
		currentSpeed -= 10;
	}
	else
	{
		std::cout << "Your " << model << " can't slow down any more.\n";
	}

	//Show changed speed
	std::cout << "Your " << model << " is going: " << currentSpeed << "km/h\n";
}

