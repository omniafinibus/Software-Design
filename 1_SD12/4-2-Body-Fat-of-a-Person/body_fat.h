#pragma once

/*
	This function calculates the body fat of a male.
	parameters:	a is waist Measurements in centimeters
				b is weigt in kilograms.
	returns:	returns the body fat of a person in percentages		
*/
double male(double a, double b);

/*
	This function calculates the body fat of a female
	parameters:	a = wrist circumference measurements in centimeters
				b = waist circumference measurements in centimeters
				c = hip circumference measurements in centimeters
				d = arm circumference measurements in centimeters
				e = weight in kilograms
	returns:	returns the body fat of a person in centimeters
*/
double female(double a, double b, double c, double d, double e);