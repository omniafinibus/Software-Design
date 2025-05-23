#include <iostream>

using namespace std;

int main()
{
	int x, y;
	
	cout << "Enter a value for x: ";
	cin >> x;
	cout << "Enter a value for y: ";
	cin >> y;
	
	swap(x, y);
	cout << "Swapped!\n";
	cout << "x: " << x << "\n";
	cout << "y: " << y << "\n";
}