#include <iostream>

using namespace std;

int main()
{
	int entered;
	int n, a = 0;

	//ask and check for an integer between 15 and 45
	do
	{
		cout << "Please enter an integer between 15 and 45:\n";
		cin >> entered;
	} while (entered < 10 || entered > 45);

	//use for loop to calculate value
	for (n = 1; a <= entered; n++)
	{
		a += n;
	}

	//print out calculations and value
	a -= n;
	n -= 2;
	cout << "1 + 2 + 3 + ... + " << n << " = " << entered << "\n";

	system("pause");
}