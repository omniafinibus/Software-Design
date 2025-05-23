#include <iostream>

using namespace std;

int main()
{
	int answer;
	int num1, num2;
	char operat;

	//ask for 2 values
	cout << "Please enter 2 values with the required operator in between: ";	//cout << "Please enter 2 values: "
	cin >> num1 >> operat >> num2;												//cin >> num1  >> num2;

	//ask for a operator
	//cout << "Please choose an operator: +, -, * or /. \n";
	//
	
	cin >> operat;
	
	//calculate outcome
	if (operat == '+')
	answer = num1 + num2;

	else if (operat == '-')
	answer = num1 - num2;

	else if (operat == '*')
	answer = num1 * num2;
	
	else if (operat == '/')
	answer = num1 / num2;
	
	cout << "The answer is " << answer << ".\n";
	//show answer
	

	system("pause");
}