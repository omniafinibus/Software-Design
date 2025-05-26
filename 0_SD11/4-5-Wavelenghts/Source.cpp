#include <iostream>
#include <string>

using namespace std;

int main()
{
	int minIndex, midIndex, maxIndex;
	double wavelength;
	double wavelengthThreshold[] = {0, 1e-11, 1e-8, 4e-7, 7e-7, 1e-3, 1e-1};;
	string wavelengthNames[] = {"Gamma Rays", "X-Rays", "Ultraviolet", "Visible light", "Infrared", "Microwave", "Radio Waves"};
	int numberOfWavelengths = sizeof(wavelengthThreshold)/sizeof(double);

	cout << "Please enter a wavelength:\n";
	cin >> wavelength;

	minIndex = 0;
	midIndex = numberOfWavelengths / 2;
	maxIndex = numberOfWavelengths-1;

	// Divide and conquer approach
	for(int i = 0; i < numberOfWavelengths; i++) {
		cout << "min: " << minIndex;
		cout << " mid: " << midIndex;
		cout << " max: " << maxIndex << "\n";

		// See which limit needs to be updated
		if(wavelength >= wavelengthThreshold[midIndex]){
			minIndex = midIndex;
		}
		else{
			maxIndex = midIndex-1;
		}		
		
		if(maxIndex == minIndex){
			// Value found
			cout << "The wave is falls under the type " << wavelengthNames[minIndex] << "\n"; 
			break;
		}
		else{
			// Find the new midpoint (Rounding up)
			midIndex = minIndex + (maxIndex-minIndex)/2 + 1;
		}
	}
}