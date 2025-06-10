#include <iostream>
#include <cstdlib>
#include <stdlib.h>     
#include <time.h>

using namespace std;

int arrayOfNumbers[20];
int currentNum = 0;
int max, min;
int amountOfOdd = 0;
int totalSum = 0;
int average;

int main()
{
	//initialize seed
	srand((unsigned)time(0));

	//generate and show 20 random numbers
	for (currentNum = 0; currentNum <= 19; currentNum++)
	{
		//assign random number to current array number
		arrayOfNumbers[currentNum] = rand();
		
		//show random number
		cout << "Number " << currentNum + 1 << " is: " << arrayOfNumbers[currentNum] << "\n";
		
	}

	//initialize max and min
	max = arrayOfNumbers[0];
	min = arrayOfNumbers[0];

	//calculate max, min and ammount of odd numbers
	for (currentNum = 0; currentNum <= 19; currentNum++)
	{
		//check if current number is odd
		if (arrayOfNumbers[currentNum] % 2 != 0)
		{
			amountOfOdd++;
		}

		//check if current number is bigger than previous number
		if (arrayOfNumbers[currentNum] > max)
		{
			max = arrayOfNumbers[currentNum];
		}

		//check if current number is smaller than previous number
		if (arrayOfNumbers[currentNum] < min)
		{
			min = arrayOfNumbers[currentNum];
		}
	}

	//calculate sum of array
	for (currentNum = 0; currentNum <= 19; currentNum++)
	{
		totalSum += arrayOfNumbers[currentNum];
	}

	//calculate average
	average = totalSum / currentNum;

	//show aske values
	cout << "The max value is: " << max << ".\n";
	cout << "The min value is: " << min << ".\n";
	cout << "The sum of all numbers is: " << totalSum << ".\n";
	cout << "The average of all numbers is: " << average << ".\n";

	system("pause");
}