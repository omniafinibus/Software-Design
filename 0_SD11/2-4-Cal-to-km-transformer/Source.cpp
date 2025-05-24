#include <iostream>

using namespace std;

int main()
{
	const int calBurrito = 357, calSalad = 185, calMilkshake = 388;
	const double calPerKm = 62.1371192237;
	double runDistance, totalCal;
	double amountBurrito, amountSalad, amountMilkshake;

	//ask amount of burritos, salads and milkshakes consumed
	cout << "How many burritos did you eat?\n";
	cin >> amountBurrito;

	cout << "How many salads did you eat?\n";
	cin >> amountSalad;

	cout << "How many milkshakes did you drink?\n";
	cin >> amountMilkshake;

	//calculate amount of calories eaten, and translate that too running distance too burn
	totalCal = amountBurrito * calBurrito + amountMilkshake * calMilkshake + amountSalad * calSalad;
	runDistance = totalCal / calPerKm;

	//inform user of total amount of calories eaten and how many km they need too run
	cout << "You have consumed " << totalCal << " Calories.\n";
	cout << "You need too run " << runDistance << "km too burn these Calories.\n";


}