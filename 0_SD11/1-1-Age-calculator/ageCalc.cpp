#include <iostream>

using namespace std;

int main()
{
	int curYear, yearOfBirth;
	int age;

	//ask current year
		cout << "What's the current year? \n";
		cin >> curYear;
	
	//ask birth year
		cout << "What's your year of birth? \n";
		cin >> yearOfBirth;

	//calculate age
		age = curYear - yearOfBirth;
	
	//show age
		cout << "You're " << age << " years old. \n";

		system("pause");
}