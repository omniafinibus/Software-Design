#pragma once

#include <iostream>
#include <string>

class car
{
public:
	//fields
	std::string model;
	int currentSpeed;

	//methods

	//function:		Changes the speed of your car
	//parameters:	newSpeed is the speed which is asked
	//returns:		the new speed
	void changeSpeed(int newSpeed);

};