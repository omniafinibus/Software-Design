#pragma once

#include <iostream>
#include <string>


class Person
{
//fields
private:
	std::string ownerName;
	int ownerAge;
	
//methods
public:

	//function:		constructor
	//parameters:	owner = name of owner
	//				userAmount = amount of users
	//				ageOwner = age of owner;
	Person(std::string owner, int ageOwner);

	//function:		show owner info
	void ownerInfo();
};