#include <iostream>
#include "Car.h"

using namespace std;

car *Viper = new car;
int newSpeed;
char confirmation;

int main()
{
	//initialize
	Viper->currentSpeed = 10;
	Viper->model = "dodge";

	//change speed
	do
	{
		//ask new speed
		cout << "How fast do you want to go?\n";
		cin >> newSpeed;

		//change speed of class
		Viper->changeSpeed(newSpeed);

		//ask user if they're done
		cout << "Want to change speed again? (y/n) \n";
		cin >> confirmation;

	} while (confirmation == 'y');

	system("pause");
}