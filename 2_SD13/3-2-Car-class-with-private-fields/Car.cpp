#include "Car.h"
#include <iostream>

car::car(std::string yourModel, int maxKmh)
{
	currentSpeed = 0;
	maxSpeed = maxKmh;
	model = yourModel;
	amountOfUsers = 0;
	user = new Person*[amountOfUsers];
}

car::~car()
{
	delete[] user;
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
	//show which model is going which speed
	std::cout << "Your " << model << " is going " << currentSpeed << " km/h\n";
}

void car::getModel()
{
	//show model
	std::cout << "The model of your car is " << model << "\n";
}

void car::changeOwnership(Person * ownerInfo)
{
	//updates the owner
	owner = ownerInfo;
}

void car::showAllInfo()
{
	//show what model & speed
	std::cout << "Model:		" << model << "\n";
	std::cout << "Max Speed:	" << maxSpeed << "kmh \n\n";

	//show owner info and info of all users
	owner->ownerInfo();
	for (int i = 0; i < amountOfUsers; i++)
	{
		user[i]->ownerInfo();
	}

}

void car::addUser(Person* newUser)
{
	//check which user the array is on
	int i = amountOfUsers;
	

	//change amount of users there are
	amountOfUsers++;

	//add this user
	user[i] = newUser;
}

