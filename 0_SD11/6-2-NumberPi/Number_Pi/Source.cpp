#include <iostream>

using namespace std;

int main()
{
	double noemer = 3;
	double fraction, answer = 1;

	//calculate pi
	for (int i = 0; i <= 9999; i++)
	{
		fraction = 1 / noemer;
		answer -= fraction;
		noemer += 2;
		fraction = 1 / noemer;
		answer += fraction;
		noemer += 2;
	}

	//show pi
	answer = answer * 4;
	cout << answer << "\n";
	system("pause");
}
