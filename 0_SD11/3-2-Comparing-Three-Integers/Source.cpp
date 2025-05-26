#include <iostream>

using namespace std;

int main()
{
	int int1, int2, int3;

	//ask user for 3 integers
	cout << "Please enter 3 numbers: ";
	cin >> int1 >> int2 >> int3;

	//print out which is the largest or if they are equel
	if (int1 == int2 && int1 ==  int3){
		cout << "All numbers are equal.\n";
	}
	else {
		cout << max(max(int1, int2), int3) << " is the biggest number.\n";
	}
}