#include <iostream>

using namespace std;

int main()
{
	double s11, s12, s21, s22;
	double totEc;

	//Ask for EC points for S11 to S22
	cout << "How many EC points did you get for SD1,1: \n";
	cin >> s11;
	cout << "How many EC points did you get for SD1,2: \n";
	cin >> s12;
	cout << "How many EC points did you get for SD2,1: \n";
	cin >> s21;
	cout << "How many EC points did you get for SD2,2; \n";
	cin >> s22;

	//Calculate totale EC
	totEc = s11 + s12 + s21 + s22;

	//Display EC's per S and total EC's
	cout << "Your total amount of EC's= " << totEc << ". \n";



}