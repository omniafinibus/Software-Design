#include <iostream>

using namespace std;

int main()
{
	int twoEuro, oneEuro, fiftyCents, twentyCents, tenCents, fiveCents, twoCents, oneCents;
	//if these variables are double, i doesn't work?

	double amountEuroInCent, amountEuro, amountCents;
	int amountOneInCent, amountTwoInCent;
	int hundredCentTotal, fiftyCentTotal, twentyCentTotal, tenCentTotal, fiveCentTotal, twoCentTotal, oneCentTotal;
	int remainder;

	//ask for amount of euros and eurocents seperatly
	cout << "Amount of euros: ";
	cin >> amountEuro;

	cout << "Amount of eurocents: ";
	cin >> amountCents;

	//calculate amount of 2,1,0.50,0.20 etc coins there are
	amountTwoInCent = amountCents / 200;
	amountOneInCent = amountCents / 100;

	twoEuro = amountEuro / 2 + amountTwoInCent;

	oneEuro	= (amountOneInCent + amountEuro) - twoEuro * 2;
	hundredCentTotal = amountOneInCent * 100;

	remainder = amountCents - hundredCentTotal;

	fiftyCents = remainder / 50;
	remainder = remainder % 50;

	twentyCents = remainder / 20;
	remainder %= 20;
	twentyCentTotal = twentyCents * 20;

	tenCents = (amountCents - hundredCentTotal - fiftyCentTotal - twentyCentTotal) / 10;
	tenCentTotal = tenCents * 10;

	fiveCents = (amountCents - hundredCentTotal - fiftyCentTotal - twentyCentTotal - tenCentTotal) / 5;
	fiveCentTotal = fiveCents * 5;

	twoCents = (amountCents - hundredCentTotal - fiftyCentTotal - twentyCentTotal - tenCentTotal - fiveCentTotal) / 2;
	twoCentTotal = twoCents * 2;

	oneCents = (amountCents - hundredCentTotal - fiftyCentTotal - twentyCentTotal - tenCentTotal  - fiveCentTotal - twoCentTotal) / 1;

	//display amount of minimum coins
	cout << "2 euro coins:		" << (int) twoEuro << "\n";
	cout << "1 euro coins:		" << (int) oneEuro << "\n";
	cout << "50 eurocent coins:	" << (int) fiftyCents << "\n";
	cout << "20 eurocent coins:	" << (int) twentyCents << "\n";
	cout << "10 eurocent coins:	" << (int) tenCents << "\n";
	cout << "5 eurocent coins:	" << (int) fiveCents << "\n";
	cout << "2 eurocent coins:	" << (int) twoCents << "\n";
	cout << "1 eurocent coins:	" << (int) oneCents << "\n";

	system("pause");
	
}