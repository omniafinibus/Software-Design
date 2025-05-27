#include "BodyFat.h"
#include <cmath>

double male(double a, double b)
{
	double A1, A2, B, bodyFat, fatPercent;

	//Calculations for Fatpercentage
	A1 = (b * 1.082) + 94.42;
	A2 = a * 4.15;
	B = A1 - A2;
	bodyFat = b - B;
	fatPercent = bodyFat * 100 / b;

	return fatPercent;
}

double female(double a, double b, double c, double d, double e)
{
	double A1, A2, A3, A4, A5, B, bodyFat, fatPercent;

	//Calculations for Fatpercentage
	A1 = (e * 0.732) + 8.987;
	A2 = a / 3.140;
	A3 = b * 0.157;
	A4 = c * 0.249;
	A5 = d * 0.434;
	B = A1 + A2 - A3 - A4 + A5;
	bodyFat = e - B;
	fatPercent = bodyFat * 100 / e;

	return fatPercent;
}