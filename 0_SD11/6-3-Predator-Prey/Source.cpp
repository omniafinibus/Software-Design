#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double preyBirth, preyDeath, predDeath, predBirth;
	int preySize, predSize, period;
	double finalPreySize, finalPredSize;
	//ask rate prey birth surplus(A)
	cout << "Rate prey birth exceeding deaths?\n";
	cin >> preyBirth;

	//ask rate of predation(B)
	cout << "Rate prey eaten?\n";
	cin >> preyDeath;

	//ask pred increase by food(C)
	cout << "Rate of predator deaths exceeding birth?\n";
	cin >> predDeath;

	//ask predator death(D)
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
	for (int i = 0; i <= period; i++) {
		int oldPreySize = preySize;
		preySize = preySize + preySize*preyDeath - preySize* predSize * preyBirth;
		predSize = predSize + predSize*predDeath - oldPreySize * predSize * predBirth;
	}

	//Show answers
	cout << "amount of predators after " << period << " years is " << predSize << "\n";
	cout << "amount of prey after " << period << " years is " << preySize << "\n";
}