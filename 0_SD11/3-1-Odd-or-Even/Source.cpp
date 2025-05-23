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
	remain = enterNum % 2;

	//check if the remainder is equel to 1 or 0
	if (remain == 1)
		cout << "The number is odd.\n";

	if (remain == 0)
		cout << "The number is even.\n";

	system("pause");
	//inform user of outcome
}