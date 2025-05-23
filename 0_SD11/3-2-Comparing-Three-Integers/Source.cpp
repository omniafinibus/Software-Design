#include <iostream>

using namespace std;

int main()
{
	int int1, int2, int3;

	//ask user for 3 integers
	cout << "Please enter 3 numbers: ";
	cin >> int1 >> int2 >> int3;

	//calculate the largest int or equel
	//print out which is the largest or if they are equel
	if (int1 == int2 == int3)
	cout << "All numbers are equel.\n";

	if (int1 > int2 && int1 > int3)
	cout << int1 << " is the biggest number.\n";

	if (int2 > int1 && int2 > int3)
	cout << int2 << " is the biggest number.\n";

	if (int3 > int1 && int3 > int2)
	cout << int3 << " is the biggest number.\n";
	
	system("pause");
}