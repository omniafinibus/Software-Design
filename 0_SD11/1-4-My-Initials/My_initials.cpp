#include <iostream>

using namespace std;

int main()
{
	string name = "Arjan Lemmens";
	int nameLength = name.length();
	int position = -1;

	cout << "My name is " << name << "\n";
	cout << "My initials are: ";

	do{
		cout << name.c_str()[++position] << ". ";
		position = name.find(" ", position);
	} while(position != string::npos && position < nameLength);

	cout << "\n";
}