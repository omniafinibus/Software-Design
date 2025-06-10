#include <iostream>
#include "Car.h"

Person *owner1 = new Person("John Doe1", 21);
Person *owner2 = new Person("John Doe2", 22);
Person *owner3 = new Person("John Doe3", 23);
Person *owner4 = new Person("John Doe4", 24);
Person *owner5 = new Person("John Doe5", 25);
car *car1 = new car("Corola", 200);
car *car2 = new car("Corola", 200);
int main()
{
	car1->changeOwnership(owner2);
	car2->changeOwnership(owner1);

	car1->addUser(owner3);
	car1->addUser(owner4);
	car2->addUser(owner5);

	car1->showAllInfo();
	car2->showAllInfo();

	std::system("pause");
}