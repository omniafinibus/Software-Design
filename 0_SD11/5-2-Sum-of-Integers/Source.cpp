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
	int add = 0;
	do {
		sum += ++add;
	} while (add < maxVal);

	//display sum
	cout << "Sum is " << sum << ".\n";

}