#include <iostream>

using namespace std;

int main()
{
	int x, y, z;
	
	cout << "Enter a value for x: ";
		cin >> x;
	cout << "Enter a value for y: ";
		cin >> y;
		
	z = x - y;
	cout << "At the end: x = " << x - z << " y = " << y + z << "\n";

	system("pause");
}