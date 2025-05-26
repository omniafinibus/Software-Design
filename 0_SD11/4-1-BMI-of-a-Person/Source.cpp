#include <iostream>

using namespace std;

int main()
{
	double height, weight, bmi;

	//ask user for weight and height
	cout << "Please enter your weight in kg: ";
	cin >> weight;

	cout << "Please enter your height in m: ";
	cin >> height;

	//calculate BMI
	bmi = weight / (height * height);
	
	//show results
	cout << "Your BMI is: " << bmi << ".\n";

	//check if doctorate advise is required
	cout << "Your BMI is ";
	if (bmi < 18.5) {
		cout << "extremely low, please contact your doctor for advice.\n";
	}
	else if (bmi < 25) {
		cout << "normal.\n";
	}
	else if (bmi < 30){
		cout << "higher than normal.\n";
	}
	else{
		cout << "extremely high, please contact your doctor for advice.\n";
	}

}