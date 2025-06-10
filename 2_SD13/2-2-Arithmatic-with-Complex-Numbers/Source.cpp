#include <iostream>
#include "complexCalculations.h"

using namespace std;

complex *complex1 = new complex;
complex *complex2 = new complex;
complex *complexAnswer = new complex;

int real1, real2, imag1, imag2;
int realAnswer, imagAnswer;
char calcType;

int main()
{
	//ask for 2 complex numbers
	cout << "Please enter the real and imaginary part of the first complex number: ";
	cin >> complex1->real >> complex1->imag;

	cout << "Please enter the real and imaginary part of the second complex number: ";
	cin >> complex2->real >> complex2->imag;

	//ask for calculation
	cout << "Please enter what kind of calculation you want to do (+, -, *, /)";
	cin >> calcType;

	//check which calculation was requested
	switch (calcType) {

		//add 2 complex numbers with eachother
	case '+':
	{
		complexAnswer->addComplex(complex1->real, complex2->real, complex1->imag, complex2->imag);
		break;
	}
	//subtract 2 complex numbers
	case '-':
	{
		complexAnswer->subComplex(complex1->real, complex2->real, complex1->imag, complex2->imag);
		break;
	}

	//divide 2 complex numbers
	case '/':
	{
		complexAnswer->divComplex(complex1->real, complex2->real, complex1->imag, complex2->imag);
		break;
	}

	//multiply 2 complex numbers
	case '*':
	{
		complex1->multComplex(complex1->real, complex2->real, complex1->imag, complex2->imag);
		break;
	}
	}

	cout << "Your answer is: " << complexAnswer->real << "+" << complexAnswer->imag << "j\n";

	system("pause");
}