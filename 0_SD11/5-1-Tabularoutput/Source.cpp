#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int amount;

	//ask for positive int value
	do {
		cout << "Please enter a positive value:\n";
		cin >> amount;
	} while (amount < 0);


	//calculate and print out N N*N N*N*N N*N*N*N
	cout << "N\tN*N\tN*N*N\tN*N*N*N\n";
	for ( int N = 1; N <= amount; N++) {
		cout << pow(N, 1) << "\t" << pow(N, 2) << "\t" << pow(N, 3) << "\t" << pow(N, 4) << "\n";
	}
}