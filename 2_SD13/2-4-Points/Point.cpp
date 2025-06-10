#include "Point.h"
#include <cmath>

using namespace std;

double distance(point *point1, point *point2)
{
	double answer;

	//calculate the distance between 2 points
	answer = sqrt(pow((point1->x - point2->x), 2) + pow((point1->y - point2->y), 2));

	//return the answer
	return answer;
}

double distance3D(point *point1, point *point2)
{
	double answer;

	//calculate the distance between 2 points
	answer = sqrt(pow((point1->x - point2->x), 2) + pow((point1->y - point2->y), 2) + pow((point1->z - point2->z), 2));

	//return the answer
	return answer;
}
