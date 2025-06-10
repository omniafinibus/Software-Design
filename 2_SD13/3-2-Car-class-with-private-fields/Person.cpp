#include "Person.h"
#include <iostream>

Person::Person(std::string owner, int ageOwner)
{
	ownerName = owner;
	ownerAge = ageOwner;
}

void Person::ownerInfo()
{
	//show owner's age and name
	std::cout << "Owner:	" << ownerName << "\n";
	std::cout << "Age:	" << ownerAge << "\n\n";
}