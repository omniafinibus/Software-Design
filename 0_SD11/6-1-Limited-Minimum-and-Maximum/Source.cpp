#include <iostream>

using namespace std;

int main()
{
	int ent, amount;
	int entMax, entMin;

	//ask for amount of enteries
	cout << "How many entries are there total?\n";
	cin >> amount;

	//ask for amount sold in a loop of ent.
	//primer
	cout << "Enter the amount of sold products for agent nr 1: ";
	cin >> entMax;
	entMin = entMax;

	//loop
	for (int i = 2; i <= amount; i++)
	{
		//ask for value
		cout << "Enter the amount of sold products for agent nr " << i << ": ";
		cin >> ent;

		//check if the entered value is bigger or smaller then the previous one
		if (ent > entMax)
		{
			entMax = ent;
		}
		else if (ent < entMax)
		{
			entMin = ent;
		}
	}

	//print out the winner and loser. 
	cout << "The winner sold " << entMax << " products!\n";
	cout << "The loser sold " << entMin << " products!\n";

	system("pause");
}