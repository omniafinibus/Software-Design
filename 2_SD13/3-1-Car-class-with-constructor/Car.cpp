#include "Car.h"
#include <iostream>

car::car(std::string yourModel, int maxKmh)
{
	currentSpeed = 0;
	maxSpeed = maxKmh;
	model = yourModel;
}

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
	//std::cout << "Your " << model << " is going: " << currentSpeed << "km/h\n";
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
	//std::cout << "Your " << model << " is going: " << currentSpeed << "km/h\n";
}

void car::getSpeed()
{
	std::cout << "Your " << model << " is going " << currentSpeed << " km/h\n";
}

void car::getModel()
{
	std::cout << "The model of your car is " << model << "\n";
}

