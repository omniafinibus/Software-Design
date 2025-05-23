#include <iostream>

using namespace std;

int main()
{
	double preyBirth, preyDeath, predDeath, predBirth;
	int preySize, predSize, period;
	double finalPreySize, finalPredSize;
	//preyn=amount of prey
	//ask rate preybirth surplus(A)
	cout << "Rate prey birth exceeding deaths?\n";
	cin >> preyBirth;

	//ask rate of predation(B)
	cout << "Rate prey eaten?\n";
	cin >> preyDeath;

	//ask pred increase by food(C)
	cout << "Rate of predator deaths exceeding birth?\n";
	cin >> predDeath;

	//ask predetor death(D)
	cout << "Rate of predator births?\n";
	cin >> predBirth;

	//ask initial population size of prey
	cout << "Initial amount of prey?\n";
	cin >> preySize;

	//ask initial population size of pred
	cout << "Inital amount of Pred?\n";
	cin >> predSize;

	//ask period in years
	cout << "In how many years?\n";
	cin >> period;

	//preyn+1=preyn*(1+A-B*predn)
	//predn+1=predn*(1-C+D*preyn)
	for (int i = 0; i <= period; i++)
	{
		int oldPreySize = preySize;
		preySize = preySize * (1 + preyBirth - preyDeath * predSize);
		predSize = predSize * (1 - predDeath + predBirth * oldPreySize);
	}

	//Show answers
	cout << "amount of predators after " << period << " years is " << predSize << "\n";
	cout << "amount of prey after " << period << " years is " << predSize << "\n";

	system("pause");
}