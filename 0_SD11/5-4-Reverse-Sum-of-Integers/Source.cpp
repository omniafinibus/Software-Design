#include <iostream>

using namespace std;

int main()
{
	int entered;
	int add = 0;
	int total = 0;

	//ask and check for an integer above 15
	do
	{
		cout << "Please enter an integer greater than 15:\n";
		cin >> entered;
	} while (entered < 15);

	//use for loop to calculate value
	
	do {
		total += ++add; 		
	} while(total < entered);

	cout << "1 + 2 + 3 + ... + " << add - 1 << " = " << total - add << "\n";

	cout << total - add << " is less than " << entered << "\n";
	
	cout << "1 + 2 + 3 + ... + " << add << " = " << total<< "\n";

	cout << total << " is greater or equal to " << entered << "\n";
}