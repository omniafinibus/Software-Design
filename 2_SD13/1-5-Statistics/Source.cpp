#include <iostream>
#include "MyStatistics.h"
#include <cstdlib>

using namespace std;

int main()
{
	//// METHOD I: declare a large array and keep track of the indices that
	//// actually get a value.

	// declare storage array
	int sz = 5;
	int * arrayOfNumbers = new int[sz];
	int * p = arrayOfNumbers;
	//int number;
	int index = 0; 

	//// input
	//do
	//{
	//	// user input
	//	cout << "Please provide next number: ";
	//	cin >> number;

	//	// store number
	//	if (number >= 0)
	//	{
	//		*p = number;
	//		p++;
	//		index++;
	//	}
	//} while (number >= 0);

	//// compute statistics
	//int min = findMin(arrayOfNumbers, index);
	//int max = findMax(arrayOfNumbers, index); 
	//long sum = findSum(arrayOfNumbers, index);
	//double average = findAverage(arrayOfNumbers, index);

	//// display results
	//cout << "Maximum value = " << max << " and minimum value = " << min << ".\n";
	//cout << "Sum = " << sum << " and average = " << average << ".\n";

	//cout << "\n";

	//// delete dynamic array
	//delete[] arrayOfNumbers;
	//	
	// METHOD II: use dynamic arrays by first asking how many entries the 
	// array has

	// declare storage array
	int numOfElements;
	cout << "Please provide number of elements: ";
	cin >> numOfElements;
	int * pArrayOfNumbers = new int[numOfElements];
	int numValue;
	
	// input
	for (int *q = pArrayOfNumbers; q < pArrayOfNumbers + numOfElements; q++)
	{
		// user input
		cout << "Please provide next number: ";
		cin >> numValue;

		// store number
		*q = numValue;
	}

	// compute statistics
	int min2 = findMin(pArrayOfNumbers, pArrayOfNumbers + numOfElements);
	int max2 = findMax(pArrayOfNumbers, pArrayOfNumbers + numOfElements);
	long sum2 = findSum(pArrayOfNumbers, pArrayOfNumbers + numOfElements);
	double average2 = findAverage(pArrayOfNumbers, pArrayOfNumbers + numOfElements);
	int* maxVal = &pArrayOfNumbers[0];
	maxVal = maximum(pArrayOfNumbers, sz);

	// display results
	cout << "Maximum value = " << max2 << " and minimum value = " << min2 << ".\n";
	cout << "Sum = " << sum2 << " and average = " << average2 << ".\n";
	cout << *maxVal << " ";
	cout << &pArrayOfNumbers[0] << " ";
	cout << &pArrayOfNumbers[1] << " ";
	cout << &pArrayOfNumbers[2] << "\n";

	//flip array around
	flipArray(arrayOfNumbers, index);

	//show the flipped array
	for (int num = 0; num < index; num++)
	{
		cout << arrayOfNumbers[num] << "\n";
	}
	

	system("pause");

	// delete dynamic array
	delete[] pArrayOfNumbers;
}