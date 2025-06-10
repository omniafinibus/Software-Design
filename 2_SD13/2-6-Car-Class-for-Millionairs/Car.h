#pragma once

#include <iostream>
#include <string>

class car
{
public:
	//fields
	std::string model;
	int currentSpeed;
	int maxSpeed;

	//methods

	//function:		Changes the speed of your car
	//parameters:	newSpeed is the speed which is asked
	void changeSpeed(int newSpeed);

	//function:		Speeds up the car
	void accelerate();

	//function:		Slows down the car
	void slowDown();
};