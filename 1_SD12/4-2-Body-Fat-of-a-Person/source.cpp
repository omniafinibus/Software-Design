#include <iostream>
#include "unitConversion.h"
#include "BodyFat.h"

using namespace std;

int main()
{
	char sex;
	double wristMeas, waistMeas, hipMeas, armMeas, weight;
	double fatPercent;

	//asks gender
	cout << "Please enter your sex: ";
	cin >> sex;

	//checks which calculations are applicable
	if (sex == 'F' || sex == 'f')
	{
		//ask user for measurements and weight
		cout << "Please measure your wrist at the fullest point and enter the diameter in cm:\n";
		cin >> wristMeas;

		cout << "Please measure your waist at the naval and enter the diameter in cm:\n";
		cin >> waistMeas;

		cout << "Please measure your hip at the fullest point and enter the diameter in cm:\n";
		cin >> hipMeas;

		cout << "Please measure your forearm at the fullest point and enter the diameter in cm:\n";
		cin >> armMeas;

		cout << "Please enter your weight in kg:\n";
		cin >> weight;

		//converts all data into usable values
		wristMeas = conLengthInch(wristMeas);
		waistMeas = conLengthInch(waistMeas);
		hipMeas = conLengthInch(hipMeas);
		armMeas = conLengthInch(armMeas);
		weight = conWeightLbs(weight);
		fatPercent = female(wristMeas, waistMeas, hipMeas, armMeas, weight);

		// Displays fat percentage
		cout << "Your fat percentage is: " << fatPercent << "%\n";
	}
	else if (sex == 'm' || sex == 'M')
	{
		//ask user for measurements and weight
		cout << "Please measure your waist at the naval and enter the diameter in cm:\n";
		cin >> waistMeas;

		cout << "Please enter your weight in kg:\n";
		cin >> weight;

		//converts all data into usable values
		waistMeas = conLengthInch(waistMeas);
		weight = conWeightLbs(weight);
		fatPercent = male(waistMeas, weight);

		//shows fat percentage
		cout << "Your fat percentage is: " << fatPercent << "%/n";
	}

	system("pause");
}