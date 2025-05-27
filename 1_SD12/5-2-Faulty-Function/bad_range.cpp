#include "badRange.h"
#include <iostream>

using namespace std;

void get_range(int min, int max, int& lower, int& upper)
{
	cout << "Please enter a data range within the bounds ";
	cout << min << "..." << max << ": ";
	do // Loop until acceptable values are provided
	{
		cin >> lower >> upper;
		if (lower < min)
			cout << lower << " is too low, please try again.\n";
		if (upper > max)
			cout << upper << " is too high, please try again.\n";
	} while ((lower < min) || (upper > max));
}