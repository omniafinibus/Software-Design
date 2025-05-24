#include <iostream>

using namespace std;

int main()
{
	double radius;
	double area, diameter, circum;
	const double pi = 3.14159;
	
	//ask user for radius
	cout << "What is the radius of your circle in m?\n";
	cin >> radius;

	//use radius too calculate area, diameter and circumference
	diameter = 2.0 * radius;
	area = pi * radius * radius;
	circum = 2.0 * radius * pi;

	//display area, diameter and circumference
	cout << "The diameter= " << diameter << "m, the area= " << area << "m and the circumference= " << circum << "m.\n";
}