#include "swapValues.h"

//INTERGERS
//Value based swap
void swapVal(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

//Pointer based swap
void swapPoint(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// address based swap
void swapAddress(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//DOUBLES
//Value based swap
void swapVal(double a, double b)
{
	double temp = a;
	a = b;
	b = temp;
}

//Pointer based swap
void swapPoint(double* a, double* b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

// address based swap
void swapAddress(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}