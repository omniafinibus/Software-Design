#include <iostream>

using namespace std;

int main()
{
	char sex;
	double wristMeas, waistMeas, hipMeas, armMeas, weight;
	double bodyFat, fatPercent;
	double A1, A2, A3, A4, A5, B;
	double person1, person2;

	//ask users gender
	cout << "Please enter your sex at birth: type M for male and F for female.\n";
	cin >> sex;


	if (sex == 'F')
	{
		//ask user for measurements and weight
		cout << "Please measure your wrist at the fullest point and enter the diameter in inches:\n";
		cin >> wristMeas;

		cout << "Please measure your waist at the naval and enter the diameter in inches:\n";
		cin >> waistMeas;

		cout << "Please measure your hip at the fullest point and enter the diameter in inches:\n";
		cin >> hipMeas;

		cout << "Please measure your forearm at the fullest point and enter the diameter in inches:\n";
		cin >> armMeas;

		cout << "Please enter your weight in pounds:\n";
		cin >> weight;

		//calulate body fat percentage
		A1 = (weight * 0.732) + 8.987;
		A2 = wristMeas / 3.140;
		A3 = waistMeas * 0.249;
		A4 = hipMeas * 0.249;
		A5 = armMeas * 0.434;
		B = A1 + A2 - A3 - A4 + A5;
		bodyFat = weight - B;
		fatPercent = bodyFat * 100 / weight;

		//display body fat percentage
		cout << "Your body fat percentage = " << fatPercent << ".\n";
	}

	else if (sex == 'M')
	{
		//ask user for measurements and weight
		cout << "Please measure your waist at the naval and enter the diameter in inches:\n";
		cin >> waistMeas;

		cout << "Please enter your weight in pounds:\n";
		cin >> weight;

		//calulate body fat percentage
		A1 = (weight * 1.082) + 94.42;
		A2 = waistMeas * 4.15;
		B = A1 - A2;
		bodyFat = weight - B;
		fatPercent = bodyFat * 100 / weight;

		//display body fat percentage
		cout << "Your body fat percentage = " << fatPercent << ".\n";
	}
	person1 = fatPercent;

	//ask users gender
	cout << "Please enter your sex at birth: type M for male and F for female.\n";
	cin >> sex;


	if (sex == 'F')
	{
		//ask user for measurements and weight
		cout << "Please measure your wrist at the fullest point and enter the diameter in inches:\n";
		cin >> wristMeas;

		cout << "Please measure your waist at the naval and enter the diameter in inches:\n";
		cin >> waistMeas;

		cout << "Please measure your hip at the fullest point and enter the diameter in inches:\n";
		cin >> hipMeas;

		cout << "Please measure your forearm at the fullest point and enter the diameter in inches:\n";
		cin >> armMeas;

		cout << "Please enter your weight in pounds:\n";
		cin >> weight;

		//calulate body fat percentage
		A1 = (weight * 0.732) + 8.987;
		A2 = wristMeas / 3.140;
		A3 = waistMeas * 0.249;
		A4 = hipMeas * 0.249;
		A5 = armMeas * 0.434;
		B = A1 + A2 - A3 - A4 + A5;
		bodyFat = weight - B;
		fatPercent = bodyFat * 100 / weight;

		//display body fat percentage
		cout << "Your body fat percentage = " << fatPercent << ".\n";
	}

	else if (sex == 'M')
	{
		//ask user for measurements and weight
		cout << "Please measure your waist at the naval and enter the diameter in inches:\n";
		cin >> waistMeas;

		cout << "Please enter your weight in pounds:\n";
		cin >> weight;

		//calulate body fat percentage
		A1 = (weight * 1.082) + 94.42;
		A2 = waistMeas * 4.15;
		B = A1 - A2;
		bodyFat = weight - B;
		fatPercent = bodyFat * 100 / weight;

		//display body fat percentage
		cout << "Your body fat percentage = " << fatPercent << ".\n";
	}
	person2 = fatPercent;

	if (person1 < person2)
	{
		cout << "The first entry has the lowest fat percentage at" << person1 << "%\n";
	}
	else if (person1 > person2)
	{
		cout << "The second entry has the lowest fat percentage at" << person2 << "%\n";
	}

	system("pause");
}