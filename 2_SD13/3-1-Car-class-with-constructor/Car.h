#pragma once

#include <iostream>
#include <string>
#include "Person.h"

class car
{
private:
	//fields
	std::string model;
	int currentSpeed;
	int maxSpeed;
	std::string *owner;
	std::string *user;

public:
	//methods

	//function:		constructor
	//parameters:	yourModel which model your car is
	//				maxKmh is max speed of your car in kmh
	car(std::string yourModel, int maxKmh);

	//function:		Changes the speed of your car
	//parameters:	newSpeed is the speed which is asked
	void changeSpeed(int newSpeed);

	//function:		Speeds up the car
	void accelerate();

	//function:		Slows down the car
	void slowDown();

	//function:		Get the speed of your car
	void getSpeed();

	//function:		Get the model of your car
	void getModel();
};