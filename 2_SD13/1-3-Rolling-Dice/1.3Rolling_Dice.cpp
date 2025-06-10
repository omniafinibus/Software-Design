#include <iostream>
#include <cstdlib>
#include <stdlib.h>   
#include <time.h>  

using namespace std;

int num;
int* diceArray = new int[36000];
int role1, role2;
int counter[11];

int main()
{
	//calc size
	long sz1 = 36000;
	//sizeof(diceArray) / sizeof(diceArray[0]);
	int sz2 = sizeof(counter) / sizeof(counter[0]);
	
	//Generate seed for the random generator
	srand(time(NULL));

	//Generate 36000 different dice pairs
	for (num = 0; num < sz1; num++)
	{

		//Generate 2 random numbers between 1 and 6
		role1 = rand() % 6 + 1;
		role2 = rand() % 6 + 1;

		//Add them together and assign them to a array index
		diceArray[num] = role1 + role2;
	}

	//initialize array
	for (num = 0; num < sz2; num++)
	{
		counter[num] = 0;
	}

	//Chech which how many 2's, 3's. 4's etc. there are
	for (num = 0; num < sz1; num++)
	{
		counter[diceArray[num] - 2]++;
	}

	//show statistics
	for (num = 0; num < sz2; num++)
	{
		cout << "There are: " << counter[num] << " " << num + 2 << "'s. \n";
	}
	
	system("pause");


	//delete Array
	delete[] diceArray;
}