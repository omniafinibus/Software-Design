#include <iostream> 
#include "pascal.h"

using namespace std;

int main()
{
   // Ask user for the size of the Pascal triangle
   int size; 
   cout << "Enter Pascal triangle size: ";
   cin >> size;
	
   // Print the triangle
   printPascalTr(size);

   system("PAUSE");
}

/*
	Answer: 1. You cant go over the set max.
			2. You're creating unused data addresses.
			3. The triangle isn't saved on the heap which causes it to have a lower maximum.
			4. If the user isn't using the max, the program wont run optimally.
*/