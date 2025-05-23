#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int random = 69;	//( ͡° ͜ʖ ͡°)
	int guess, difference;

	for (int i = 0; i <= 5; i++)
	{
		if (i <= 4)
		{
			cout << "Guess a random number?\n";
			cin >> guess;
			difference = abs(random - guess);
		}
		else if (i > 4)
		{
			cout << "You lose!\n";
			break;
		}

		if (difference >= 50)
		{
			cout << "Much, much higher or much, much lower\n\n";
		}
		else if (difference >= 30)
		{
			cout << "Much higher or much lower\n\n";
		}
		else if (difference >= 10)
		{
			cout << "Higher or lower\n\n";
		}
		else if (difference > 0)
		{
			cout << "Slightly higher or slightly lower\n\n";
		}
		else if (difference == 0)
		{
			cout << "WINNER WINNER, CHICKEN DINNER\n\n";
			break;
		}
	}


	system("pause");
}