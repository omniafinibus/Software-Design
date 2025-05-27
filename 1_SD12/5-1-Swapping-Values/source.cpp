#include <iostream>
#include "swapValues.h"

using namespace std;

int main()
{
	int first, second;
	double firstDouble, secondDouble;

	cout << "Please enter 2 interger values: ";
	cin >> first >> second;

	//using intergers
	//Swapping values of A and B through integers
	cout << "\nSwapping through values.\n\n";
	cout << "The first value is: " << first << ".\n";
	cout << "The second value is: " << second << ".\n";

	swapVal(first, second);

	cout << "The new first value is: " << first << ".\n";
	cout << "The new second value is: " << second << ".\n";

	//Swapping values of A and B through pointers
	cout << "\nSwapping through pointers.\n\n";
	cout << "The first value is: " << first << ".\n";
	cout << "The second value is: " << second << ".\n";

	swapPoint(&first, &second);

	cout << "The new first value is: " << first << ".\n";
	cout << "The new second value is: " << second << ".\n";

	//Swapping values of A and B through addresses
	cout << "\nSwapping through address.\n\n";
	cout << "The first value is: " << first << ".\n";
	cout << "The second value is: " << second << ".\n";

	swapAddress(first, second);

	cout << "The new first value is: " << first << ".\n";
	cout << "The new second value is: " << second << ".\n";

	cout << "\nPlease enter 2 double values: ";
	cin >> firstDouble >> secondDouble;

	//using doubles
	//Swapping values of A and B through integers
	cout << "\nSwapping through values.\n\n";
	cout << "The first value is: " << firstDouble << ".\n";
	cout << "The second value is: " << secondDouble << ".\n";

	swapVal(firstDouble, secondDouble);

	cout << "The new first value is: " << firstDouble << ".\n";
	cout << "The new second value is: " << secondDouble << ".\n";

	//Swapping values of A and B through pointers
	cout << "\nSwapping through pointers.\n\n";
	cout << "The first value is: " << firstDouble << ".\n";
	cout << "The second value is: " << secondDouble << ".\n";

	swapPoint(&firstDouble, &secondDouble);

	cout << "The new first value is: " << firstDouble << ".\n";
	cout << "The new second value is: " << secondDouble << ".\n";

	//Swapping values of A and B through addresses
	cout << "\nSwapping through address.\n\n";
	cout << "The first value is: " << firstDouble << ".\n";
	cout << "The second value is: " << secondDouble << ".\n";

	swapAddress(firstDouble, secondDouble);

	cout << "The new first value is: " << firstDouble << ".\n";
	cout << "The new second value is: " << secondDouble << ".\n\n";

	system("pause");

	/*
		A)	Value:	 Swaps the interger value located on a different address, which means the original values dont change address or value.
			Pointer: Swaps the actual address of the values.
			Address: Swaps the actual address of the values.
		B)	The third one, because it more user friendly and while it still works.
		C)	Value:	 20 Bytes
			Pointer: 12 Bytes
			Address: 12 Bytes
			Total:	 44 Bytes
		D)	Value:	 40 Bytes
			Pointer: 24 Bytes
			Address: 24 Bytes
			Total:	 88 Bytes
	*/
}