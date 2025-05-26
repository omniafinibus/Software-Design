#include <iostream>

using namespace std;

int main()
{
	char sex;
	double waistMeas, weight;
	double bodyFat, fatPercent;
	double B;

	//ask users gender
	cout << "Please enter your sex at birth: type M for male and F for female.\n";
	cin >> sex;

	//ask user for measurements and weight
	cout << "Please measure your waist at the naval and enter the diameter in inches:\n";
	cin >> waistMeas;

	cout << "Please enter your weight in pounds:\n";
	cin >> weight;
	
	if (sex == 'F' || sex == 'f') {
		double wristMeas, hipMeas, armMeas;
		double A1, A2, A3, A4, A5;

		//ask user for measurements and weight
		cout << "Please measure your wrist at the fullest point and enter the diameter in inches:\n";
		cin >> wristMeas;
	
		cout << "Please measure your hip at the fullest point and enter the diameter in inches:\n";
		cin >> hipMeas;

		cout << "Please measure your forearm at the fullest point and enter the diameter in inches:\n";
		cin >> armMeas;
		
		//calculate body fat percentage
		A1 = (weight * 0.732) + 8.987;
		A2 = wristMeas / 3.140;
		A3 = waistMeas * 0.249;
		A4 = hipMeas * 0.249;
		A5 = armMeas * 0.434;
		B = A1 + A2 - A3 - A4 + A5;
	}

	else if (sex == 'M' || sex == 'm') {
		double A1, A2;
		A1 = (weight * 1.082) + 94.42;
		A2 = waistMeas * 4.15;
		B = A1 - A2;
	}
	
	bodyFat = weight - B;
	fatPercent = bodyFat * 100 / weight;

	//display body fat percentage
	cout << "Your body fat percentage = " << fatPercent << ".\n";
}

