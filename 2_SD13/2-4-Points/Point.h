#pragma once

class point
{
public:
	double x;
	double y;
	double z;

};


//function:		calculates the distance between 2 points
//parameters:	x1 and y1 are coördoninates of first point
//				x2 and y2 are coördoninates of second point
//return:		distance between 2 points
double distance(point *point1, point *point2);

//function:		calculates the distance between 2 points in 3 dimensions
//parameters:	x1, y1 and z1 are coördoninates of first point
//				x2, y2 and z2 are coördoninates of second point
//return:		distance between 3 points
double distance3D(point *point1, point *point2);