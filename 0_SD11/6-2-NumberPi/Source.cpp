#include <iostream>

using namespace std;

int main()
{
	double answer = 0;

	//calculate pi
	for (int i = 1; i <= 10000; i += 4) {
		answer += 1.0 / i;
		answer -= 1.0 / (i+2);
	}
	
	//show pi
	cout << answer * 4 << "\n";
}
