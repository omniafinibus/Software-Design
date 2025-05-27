#include <iostream>
#include "badRange.h"

using namespace std;

int main()
{
	int lower, upper;
	int min = 50, max = 100;
	get_range(min, max, lower, upper);
	// print all numbers between lower and upper (including)
	for (int i = lower; i <= upper; i++)
	{
		cout << i << " ";
	}
	cout << '\n';
	system("pause");
}