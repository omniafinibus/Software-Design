#include <iostream>
#include "arithmetic.h"

using namespace std;

int main()
{
	double a, b, answer;
	char type;

	cout << "please enter your formula: ";
	cin >> a >> type >> b;
	switch (type) {
	case '+':	answer = add(a, b);
		break;

	case '-':	answer = subtract(a, b);
		break;

	case '*':	answer = multiply(a, b);
		break;

	case '/':	answer = divide(a, b);
		break;
	}

	cout << a << type << b << "=" << answer << "\n";
	system("pause");
}