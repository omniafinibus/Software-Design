#include <iostream>

using namespace std;

int getAmountOfCoins(int* total, int coinSize) {
	int numOfCoins = (int) *total/coinSize;
	*total -= numOfCoins*coinSize;
	return numOfCoins;
}

int main()
{
	int amount, cents;
	char separator;
	int amountInCents;

	//ask for amount of euros and cents separately
	cout << "Amount of money: "; 
	cin >> amount >> separator >> cents;
	amountInCents = (int) amount*100 + cents;

	int size[] = {200, 100, 50, 20, 10, 5, 2, 1};
	
	//display amount of minimum coins
	for(int i; i < 8; i++){
		cout << (float) size[i]/100 << " euro coins: ";
		cout << getAmountOfCoins(&amountInCents, size[i]); 
		cout << "\n";
	}
}