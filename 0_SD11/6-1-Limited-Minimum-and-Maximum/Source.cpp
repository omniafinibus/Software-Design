#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int entry, amount;
	vector<int> vEntries;

	//ask for amount of entries
	cout << "How many entries are there total?\n";
	cin >> amount;

	for (size_t i = 0; i < amount; i++) {
		//ask for value
		cout << "Enter the amount of sold products for agent nr " << i << ": ";
		cin >> entry;
		vEntries.push_back(entry);
	}

	//print out the winner and loser. 
	cout << "The winner sold " << *max_element(vEntries.begin(), vEntries.end()) << " products!\n";
	cout << "The loser sold " << *min_element(vEntries.begin(), vEntries.end()) << " products!\n";
}