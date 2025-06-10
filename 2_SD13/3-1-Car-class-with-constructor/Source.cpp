#include <iostream>
#include "Car.h"

car *Viper = new car("Dodge Viper", 330);
car *ModelS = new car("Tesla ModelS", 250);
char newSpeed;
char confirmation;
std::string model;

int main()
{
	//change speed of each model
	do {

		//ask which model the user wants to change speed of
		std::cout << "which model do you want to change speed of?\n";
		std::cin >> model;

		//ask if the user wants to speed up or slow down
		std::cout << "Do you want to speed up of slow down? (+/-)\n";
		std::cin >> newSpeed;

		//check which option is asked
		if (model == "viper")
		{
			//check which option is asked
			if (newSpeed == '+')
			{
				Viper->accelerate();
			}
			else if (newSpeed == '-')
			{
				Viper->slowDown();
			}
			else
			{
				std::cout << "error\n";
			}
			Viper->getSpeed();
		}
		else if (model == "modelS")
		{
			//check which option is asked
			if (newSpeed == '+')
			{
				ModelS->accelerate();
			}
			else if (newSpeed == '-')
			{
				ModelS->slowDown();
			}
			else
			{
				std::cout << "error\n";
			}
			ModelS->getSpeed();
		}
		else
		{
			std::cout << "error\n";
		}

		//ask user if they're done
		std::cout << "Want to change speed again? (y/n) \n";
		std::cin >> confirmation;

	} while (confirmation == 'y');

	std::system("pause");
}

/*
//change speed
do
{
	//ask which model the user wants to change speed of
	std::cout << "which model do you want to change speed of?\n";
	std::cin >> model;

	if (model == "viper")
	{
		//ask new speed
		std::cout << "How fast do you want to go?\n";
		std::cin >> newSpeed;

		//change speed of class
		Viper->changeSpeed(newSpeed);

	}
	else if (model == "modelS")
	{
		//ask new speed
		std::cout << "How fast do you want to go?\n";
		std::cin >> newSpeed;

		//change speed of class
		ModelS->changeSpeed(newSpeed);
	}

	//ask user if they're done
	std::cout << "Want to change speed again? (y/n) \n";
	std::cin >> confirmation;

} while (confirmation == 'y');
*/