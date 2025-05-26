#include <iostream>

using namespace std;

int main()
{
	float answer;
	int num1, num2;
	char op;

	//ask for 2 values
	cout << "Please enter 2 integers: ";
	cin >> num1 >> num2;
	//ask for a op
	cout << "Please choose an op: +, -, * or /. \n";
	cin >> op;
	
	//calculate outcome
	switch (op)	{
	case '+':
		answer = num1 + num2;
		break;
	case '-':
		answer = num1 - num2;
		break;
	case '*':
		answer = num1 * num2;
		break;
	case '/':
		answer = (float)num1 / (float)num2;
		break;
	default:
		cout << "Error: operator not recognized";
		break;
	}
	
	cout << "The answer is " << answer << ".\n";
}