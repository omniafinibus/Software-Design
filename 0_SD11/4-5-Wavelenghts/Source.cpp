#include <iostream>

using namespace std;

int main()
{
	int wave;
	int usable;

	//ask the user for a wavelength
	cout << "Please enter a wavelength:\n";
	cout << "If the wavelength is bigger than 1e-1, enter 1.\n";
	cout << "If the wavelenght is smaller than 1e-1 and bigger than 1e-3, enter 2.\n";
	cout << "If the wavelenght is smaller than 1e-3 and bigger than 7e-7, enter 3.\n";
	cout << "If the wavelenght is smaller than 7e-1 and bigger than 4e-7, enter 4.\n";
	cout << "If the wavelenght is smaller than 4e-7 and bigger than 1e-8, enter 5.\n";
	cout << "If the wavelenght is smaller than 1e-8 and bigger than 1e-11, enter 6.\n";
	cout << "If the wavelenght is smaller than 1e-11, enter 7.\n";
	cin >> wave;

	//workaround for maximum wavelength
	/*if (wave >= 1e-1)
	{
		usable = 1;
	}
	else if (wave >= 1e-3)
	{
		usable = 2;
	}
	else if (wave >= 7e-7)
	{
		usable = 3;
	}
	else if (wave >= 4e-7)
	{
		usable = 4;
	}
	else if (wave >= 1e-8)
	{
		usable = 5;
	}
	else if (wave >= 1e-11)
	{
		usable = 6;
	}
	else if (wave < 1e-11)
	{
		usable = 7;
	}*/

	//use a switch thingymajig to find the corresponding name and then print out this name
	switch (wave)
	{
	case 1:
		cout << "These are of the Radiowave variaty. \n";
		break;
	case 2:	cout << "These are of the Microwave variaty. \n";
		break;
	case 3:	cout << "These are of the Infrared variaty. \n";
		break;
	case 4:	cout << "These are of the Visible light variaty. \n";
		break;
	case 5:	cout << "These are of the Ultraviolet variaty. \n";
		break;
	case 6:	cout << "These are of the X-Ray variaty. \n";
		break;
	case 7:	cout << "These are of the Gamma ray variaty. \n";
		break;
	}

	system("pause");
}