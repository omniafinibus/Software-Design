#include "MyStatistics.h"

long findSum(int * arrayOfNums, int sz)
{
	// declare and initialize sum
	long sum = 0;

	// Update sum with all entries of the array
	for (int i = 0; i < sz; i++)
	{
		sum += arrayOfNums[i];
	}

	// return sum
	return sum;
}

double findAverage(int * arrayOfNums, int sz)
{
	// compute the sum
	long total = findSum(arrayOfNums, sz);

	// compute the average
	double average = (double)total / (double)sz;

	// return average
	return average;
}

int findMax(int * arrayOfNums, int sz)
{
	// set the first element of the array as the maximum value
	int max = arrayOfNums[0];

	if (sz == 0)
	{
		max = 0;
	}

	for (int i = 1; i < sz; i++)
	{
		// check if array element is larger
		if (arrayOfNums[i] > max)
		{
			max = arrayOfNums[i];
		}
	}

	// return maximum
	return max;
}

int findMin(int * arrayOfNums, int sz)
{
	// set the first element of the array as the minimum value
	int min = arrayOfNums[0];

	for (int i = 1; i < sz; i++)
	{
		// check if array element is larger
		if (arrayOfNums[i] < min)
		{
			min = arrayOfNums[i];
		}
	}

	// return minimum
	return min;
}

long findSum(int * begin, int * end)
{
	// declare and initialize sum
	long sum = 0;

	// Update sum with all entries of the array
	for (int* c = begin; c < end; c++)
	{
		sum += *c;
	}

	// return sum
	return sum;
}

double findAverage(int * begin, int * end)
{
	// compute the sum
	long total = findSum(begin, end);

	// compute the average
	double average = (double)total / (double)(end - begin);

	// return average
	return average;
}

int findMax(int * begin, int * end)
{
	// set the first element of the array as the maximum value
	int max = *begin;

	for (int * c = begin + 1; c < end; c++)
	{
		// check if array element is larger
		if (*c > max)
		{
			max = *c;
		}
	}

	// return maximum
	return max;
}

int findMin(int * begin, int * end)
{
	// set the first element of the array as the minimum value
	int min = *begin;

	for (int * c = begin + 1; c < end; c++)
	{
		// check if array element is larger
		if (*c < min)
		{
			min = *c;
		}
	}

	// return minimum
	return min;
}

void flipArray(int * begin, int end)
{
	//int *array2 = new int[end];

	for (int i = 0; i < end / 2; i++)
	{
		int temp = begin[i];
		begin[i] = begin[end - i - 1];
		begin[end - i - 1] = temp;
	}
	////make a copy of the array
	//for (int num = 0; num < end; num++)
	//{
	//	array2[num] = begin[num];
	//}

	////flip array
	//for (int num = 0; num < end; num++)
	//{
	//	begin[num] = array2[end - num];
	//}

	//delete[] array2;
}

int * maximum(int * arr, int sz)
{
	int * max = nullptr;
	if (sz > 0)
	{
		// set the first element of the array as the maximum valuu
		max = arr;

		for (int cur = 1; cur < sz; cur++)
		{
			// check if array element is larger
			if (arr[cur] > *max)
			{
				max = arr + cur;
			}
		}
	}
	// return maximum
	return max;
}