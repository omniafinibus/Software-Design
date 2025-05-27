#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double across, adjacent;
	double hypotenuse;

	//asks 2 sides
	cout << "Please enter the values of the shortest sides:\n";
	cin >> across >> adjacent;

	//calculates hypotenuse
	hypotenuse = sqrt(across * across + adjacent * adjacent);

	//shows hypotenuse
	cout << "The hypotenuse of your triangle is:" << hypotenuse << "\n";

	system("pause");
}