#include <iostream>

using namespace std;

int main()
{
	int month;
	int amountDays;

	//ask for month
	cout << "Which month would you like to know the amount of days from?\n";
	cout << "Type 1 for Januari, 2 for Februari, 3 for March etc.\n";
	cin >> month; 
	
	//check which category amount days is
	if (month == 2)
	{
		amountDays = 2829;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 9 || month == 11)
	{
		amountDays = 31;
	}
	else if (month == 4 || month == 6 || month == 8 || month == 10 || month == 12)
	{
		amountDays == 30;
	}

	//use switch too see which month is necessary
	//output amount of days in a months
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:

		cout << "The number of days in this month is: 31.\n";
		break;
	case 30:
		cout << "The number of days in this month is: 30.\n";
		break;
	case 2829:
		cout << "The number of days in this month is: 28 or 29.\n";
		break;
	default:
		cout << "You have entered a unusable number.\n";
	}

	system("pause");
}