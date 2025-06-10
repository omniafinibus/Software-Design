#include <iostream>
#include "Point.h"

point *point1 = new point;
point *point2 = new point;
int dimension;
double distanceAnswer;

int main()
{
	//ask values
	std::cout << "Please enter the X coördinates of the first point\n";
	std::cin >> point1->x;
	std::cout << "Please enter the Y coördinates of the first point\n";
	std::cin >> point1->y;

	std::cout << "\n";
	std::cout << "Please enter the X coördinates of the second point\n";
	std::cin >> point2->x;
	std::cout << "Please enter the Y coördinates of the second point\n";
	std::cin >> point2->y;

	std::cout << "\n";
	std::cout << "In how many dimensions do you want the distance to be calculated?\n";
	std::cin >> dimension;

	if (dimension == 2)
	{
		//calculate distance
		distanceAnswer = distance(point1, point2);
	}
	else if (dimension == 3)
	{
		//ask z coördinates
		std::cout << "\n";
		std::cout << "Please enter the Z coördinates of the first point\n";
		std::cin >> point1->z;
		std::cout << "Please enter the Z coördinates of the second point\n";
		std::cin >> point2->z;


		//calulate distance
		distanceAnswer = distance3D(point1, point2);
	}
	else
	{
		std::cout << "\n";
		std::cout << "Wrong amount of dimensions, calculating for 2 dimensional.\n";
		distanceAnswer = distance(point1, point2);
	}

	//show results
	std::cout << "\n";
	std::cout << "The distance between the 2 points is " << distanceAnswer << "\n";

	system("pause");
}