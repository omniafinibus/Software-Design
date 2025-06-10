#include "parityChecker.h"
#include <iostream>

using namespace std;

void checkPairs(const int * array1, const int * array2, int * array3, int maxSize)
{
	int num;

	//check if amount of times it checked the pairs
	for (num = 0; num <= maxSize; num++)
	{


		//check if current array indexes are equal
		if (array1[num] == array2[num])
		{
			//array3 of current index is 1
			array3[num] = 1;
		}
		else
		{
			//array3 of current index is 0
			array3[num] = 0;
		}
	}
}