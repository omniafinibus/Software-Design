#include <iostream>

using namespace std;

int main()
{
	int maxVal;
	int sum = 0;

	//ask for an integer greater than 10 
	//check if its greater than 10
	do
	{
		cout << "Please enter an integer larger or equel to 10:\n";
		cin >> maxVal;
	} while (maxVal < 10);

	//calculate the sum of all integers up to that value
	for (int add = 1; add <= maxVal; add++)
	{
		sum += add;
	}

	//display sum
	cout << "Sum is " << sum << ".\n";
	system("pause");
}