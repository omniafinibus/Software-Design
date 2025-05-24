#include <iostream>

using namespace std;

int main()
{
	int enterNum, remain;

	//ask a number
	cout << "This program will check if your number is an odd or even number.\n";
	cout << "Please enter a number: ";
	cin >> enterNum;

	//calculate the remainder after deviding by 2
	cout << "The number is " << (enterNum % 2 ? "odd\n" : "even\n");
}