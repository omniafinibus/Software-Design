#include "complexCalculations.h"
#include <complex>
#include <iostream>



double complex::addComplex(double real1, double real2, double imag1, double imag2)
{
	double realAnswer, imagAnswer;

	realAnswer = real1 + real2;
	imagAnswer = imag1 + imag2;

	return realAnswer, imagAnswer;
}

double complex::subComplex(double real1, double real2, double imag1, double imag2)
{
	double realAnswer, imagAnswer;

	realAnswer = real1 - real2;
	imagAnswer = imag1 - imag2;
	return realAnswer, imagAnswer;
}

double complex::multComplex(double real1, double real2, double imag1, double imag2)
{
	double realAnswer, imagAnswer;

	realAnswer = (real1 * real2) - (imag1 * imag2);
	imagAnswer = (real1 * imag2) + (imag1 * real2);
	return realAnswer, imagAnswer;
}

double complex::divComplex(double real1, double real2, double imag1, double imag2)
{
	int zero = (real2 * real2) + (imag2 * imag2);
	double realAnswer, imagAnswer;

	if (zero == 0)
	{
		std::cout << "cant divide by zero";
	}
	else
	{
		realAnswer = ((real1 * real2) + (imag1 * imag2)) / zero;
		imagAnswer = ((imag1 * real2) - (real1 * imag2)) / zero;
	}
	return realAnswer, imagAnswer;
}
