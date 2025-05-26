#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> vLongMonths = {1, 3, 5, 7, 8, 10, 12};
	vector<int> vShortMonths = {4, 6, 9, 11};
	int month;
	int amountDays;

	//ask for month
	cout << "Which month would you like to know the amount of days from?\n";
	cout << "Type 1 for January, 2 for February, 3 for March etc.\n";
	cin >> month; 
	
	//check which category amount days is
	if (month == 2)	{
		// Check if the year is a leap year
		int year;
		cout << "In which year?.\n";
		cin >> year;
		// February is 29 days long every 4 years unless the year is devisable by 100 and not 400
		if (year % 4 || ((year/100) % 4)) {
			amountDays = 28;
		}
		else {
			amountDays = 29;
		}
	}
	else if (find(vLongMonths.begin(), vLongMonths.end(), month) != vLongMonths.end()) {
		amountDays = 31;
	}
	else if (find(vShortMonths.begin(), vShortMonths.end(), month) != vShortMonths.end()) {
		amountDays = 30;
	}
	else {
		amountDays = -1;
	}
	
	cout << "The number of days in this month is: " << amountDays << ".\n";
}