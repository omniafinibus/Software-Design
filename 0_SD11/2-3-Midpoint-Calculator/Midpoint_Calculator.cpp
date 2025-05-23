#include <iostream>

using namespace std;

int main()
{
	double x1, y1;
	double x2, y2;
	double xMid, yMid;
	char leftParen, comma, rightParen;

	//Ask for 2 points for which a midpoint is required
	cout << "Please enter the first point:  ";
	cin >> leftParen >> x1 >> comma >> y1 >> rightParen;

	cout << "Please enter the second point: ";
	cin >> leftParen >> x2 >> comma >> y2 >> rightParen;

	//Calculate midpoint
	xMid = (x1 + x2) / 2;
	yMid = (y1 + y2) / 2;

	//Display given points and midpoint
	cout << "Point 1:  " << leftParen << x1 << comma << y1 << rightParen << "\n";
	cout << "Point 2:  " << leftParen << x2 << comma << y2 << rightParen << "\n";
	cout << "Midpoint: " << leftParen << xMid << comma << yMid << rightParen << "\n";

	system("pause");
}