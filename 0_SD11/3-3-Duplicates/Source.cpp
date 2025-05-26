#include <iostream>

using namespace std;

int main()
{
	int int1, int2, int3;
	//ask for 3 values
	cout << "Please enter 3 values: ";
	cin >> int1 >> int2 >> int3;

	//check if it has a duplicate or if they are all 
	if (int1 == int2 || int3 == int2 || int1 == int3) {
		cout << "DUPLICATES\n";
	}
	else if (int1 != int2 != int3) {
		cout << "UNIQUE\n";
	}
	else {
		cout << "ERROR";
	}
}