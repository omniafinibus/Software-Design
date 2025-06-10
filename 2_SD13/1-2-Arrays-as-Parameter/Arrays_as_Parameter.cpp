#include <iostream>
#include "parityChecker.h"

using namespace std;

const int num = 5;
int maxSize;
int currentNum;

int main()
{
	////ask amount of indexes
	//cout << "How many numbers do you want checked? ";
	//cin >> num;

	//create arrays
	int array1[num];
	int array2[num];
	int array3[num];

	//assign a number to each index
	for (currentNum = 0; currentNum <= num; currentNum++)
	{
		//ask for first array value
		cout << "Please give a value for array1[" << currentNum << "]: ";
		cin >> array1[currentNum];

		//ask for second array value
		cout << "Please give a value for array2[" << currentNum << "]: ";
		cin >> array2[currentNum];
	}

	//calculate size of array 1
	int sizeOf1 = sizeof(array1) / sizeof(array1[0]);

	//calculate size of array 2
	int sizeOf2 = sizeof(array2) / sizeof(array2[0]);

	//check which is bigger
	if (sizeOf1 > sizeOf2)
	{
		//assign array 1 as size of
		maxSize = sizeOf1;
	}
	else
	{
		//assign array 2 as size of
		maxSize = sizeOf2;
	}


	//check parities
	checkPairs(array1, array2, array3, maxSize);

	//show numbers in arrays
	for (currentNum = 0; currentNum <= num; currentNum++)
	{
		cout << "array3[" << currentNum << "] = " << array3[currentNum] << "\n";
	}

	system("pause");
}