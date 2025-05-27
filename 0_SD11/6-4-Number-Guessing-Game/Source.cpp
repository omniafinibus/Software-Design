#include <iostream>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	int guess, difference;

	srand(time(0));
	const int random = rand() % 100;
	cout << random << "\n\n";

	constexpr int thresholds[] = {0, 10, 30, 50};
	const string aboveThreshold[] = {
		"Slightly lower\n\n", 
		"Lower\n\n", 
		"Much lower\n\n", 
		"Much, much lower\n\n"
	};
	const string belowThreshold[] = {
		"Slightly higher\n\n", 
		"Higher\n\n", 
		"Much higher\n\n", 
		"Much, much higher\n\n"
	};
	
	constexpr int numberOfThresholds = sizeof(thresholds)/sizeof(int);
		
	for (int i = 0; i <= 5; i++)
	{
		if (i <= 4) {
			cout << "Guess a random number:\n";
			cin >> guess;
			difference = random - guess;
		}
		else {
			cout << "You lose!\n";
			break;
		}
		
		// Correct guess, exit the loop
		if (difference == 0) {
			cout << "You win!\n\n";
			break;
		}

		// Figure out how far off the guess was
		int minIndex = 0;
		int midIndex = numberOfThresholds / 2;
		int maxIndex = numberOfThresholds-1;
		for(int j = 0; j < numberOfThresholds; j++) {
			cout << "min " << minIndex << " mid " << midIndex << " max " << maxIndex << "\n";
			// See which limit needs to be updated
			if(abs(difference) < thresholds[midIndex]){
				maxIndex = midIndex-1;
			}
			else{
				minIndex = midIndex;
			}		
			
			// Correct message found
			if(maxIndex == minIndex){
				break;
			}
			else{
				// Find the new midpoint (Rounding up)
				midIndex = minIndex + (maxIndex-minIndex)/2 + 1;
			}
		}
				
		cout << ((difference < 0) ? aboveThreshold[minIndex] : belowThreshold[minIndex]);
	}
}