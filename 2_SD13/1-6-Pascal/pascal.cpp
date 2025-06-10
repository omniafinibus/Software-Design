#include "pascal.h"
#include <iostream>

using namespace std;

void printPascalTr(int size)

{
	int rowCount, colCount;

	//assign amount of rows and columns
	rowCount = size;
	colCount = size;

	//create 2D dynamic Array
	int** pascalTr = new int*[rowCount];
	for (int col = 0; col < rowCount; col++)
	{
		pascalTr[col] = new int[col + 1];
	}

	// first and second rows are set to 1s    
	pascalTr[0][0] = 1;
	pascalTr[1][0] = 1;
	pascalTr[1][1] = 1;

	// compute the entries
	for (int row = 2; row < size; row++)
	{
		// set the leftmost element to one
		pascalTr[row][0] = 1;

		// compute the middle elements of the triangle
		for (int col = 1; col < row; col++)
		{
			pascalTr[row][col] = pascalTr[row - 1][col - 1] + pascalTr[row - 1][col];
		}

		// set the rightmost element to one
		pascalTr[row][row] = 1;
	}

	//display the Pascal Triangle 
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col <= row; col++)
		{
			cout << pascalTr[row][col] << "\t";
		}
		cout << "\n";
	}

	//delete 2D array
	for (int col = 0; col < rowCount; col++)
	{
		delete[] pascalTr[col];
	}
	delete[] pascalTr;
}