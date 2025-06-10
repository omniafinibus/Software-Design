#pragma once

#include <iostream>
#include <string>
#include "Person.h"

class car
{
private:
	//fields
	//car info
	std::string model;
	int currentSpeed;
	int maxSpeed;

	//owner & user info
	Person *owner;
	int amountOfUsers;
	Person** user;
	
public:
	//methods

	//function:		constructor
	//parameters:	yourModel which model your car is
	//				maxKmh is max speed of your car in kmh
	car(std::string yourModel, int maxKmh);

	//functionL		deconstructor
	~car();

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

	//function:		Change owner and or user
	//parameter:	newOwner is class of new owner info
	void changeOwnership(Person *newOwner);

	//function:		Show info on car
	void showAllInfo();

	//function:		add a user
	//parameters:	newUser = user you want to add
	void addUser(Person * newUser);

};