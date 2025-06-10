#pragma once

class complex
{
public:
	double real;
	double imag;

	double addComplex(double real1, double real2, double imag1, double imag2);

	double subComplex(double real1, double real2, double imag1, double imag2);

	double multComplex(double real1, double real2, double imag1, double imag2);

	double divComplex(double real1, double real2, double imag1, double imag2);
};