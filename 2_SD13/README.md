# Week 1-2 
## Assignment 1: Sequence of Numbers 

Design and implement a console application that randomly generates a series of 20 numbers (of type ```int```).

All number must be stored in an array.
After generating all 20 numbers, the program should calculate and display the following data:

- The lowest number in the array.
- The highest number in the array.
- The total (sum) of the numbers in the array.
- The average of the numbers in the array.
- The number of odd numbers in the array.

No cheating: the program should first fill the array with random numbers, and only then determine the requested data based on that array!

## Assignment 2: Arrays as Parameter 

Design and implement a function (for a console application) to which you can pass three integer arrays of the same size.

The function should change the values in the third array as follows: 

for each index where the first two arrays contain the same value, the third array should contain the value 1.
At any other index, the third array should contain the value 0.
For example: if you pass to the function 
- an array ```arr1```, being ```{4, 4, 9, 1, 3}```, 
- an array ```arr2```, being ```{4, 2, 9, 7, 3}``` 
- and an array ```arr3```, also of size 5, 

then the function should change the contents of array ```arr3``` to contain ```{1,0,1,0,1}``` (because the numbers at index 0, 2 and 4 are the same in arr1 and arr2, and the numbers at the index 1 and 3 are different).
Complete your console application in such a way that the functionality of your function can be demonstrated, and the results are displayed on the console.

## Assignment 3: Rolling Dice 

Design and implement a console application to simulate the rolling of two dice.

The application should use the random number generator once to roll the first die and again to roll the second die.
The sum of the two values should then be calculated.
With each die you can roll a value from 1 to 6, so the sum of the values will be from 2 to 12, with 7 being the most frequent sum and 2 and 12 the least frequent sums.

Your application should roll the dice 36,000 times, and count the number of times each sum appears in a one-dimensional array.
The 36 possible sums of two dice.
Display the results in a tabular format and determine whether the totals are reasonable (e.g., there are six ways to roll a 7, so approximately one-sixth of the rolls should be 7).

## Assignment 4: LED array reacting to button clicks with debouncing 

In Assignment 2-1 of SD12 you implemented a single pushbutton to make the LED array advance one LED each time the pushbutton was pressed.
Having an LED array already suggests you could use arrays here! 
The switching between LEDs can be done more efficiently if the LED pin numbers are stored in an array. 

## Assignment 5: Statistics

Add a function that returns a pointer to the maximum value of the data array:
```int *maximum(int *arr, int sz);``` If ``sz`` is ```0```, return ```NULL```.
Use this function in your main function to print the maximum value of the array.

Add a function that reverses the values of the data array:
```void reverse(int *arr, int sz);```
In the function, use two pointer variables (i.e. not integer indexes) to traverse the array elements.
Print the result to screen after executing this function.

## Assignment 6: Pascal’s triangle 

One of the most z number patterns in mathematics is Pascal's Triangle (named after Blaise Pascal, a famous French Mathematician and Philosopher).
To build the triangle, start with "1" at the top, then continue placing numbers below it in a triangular pattern.
Each number is the sum of the numbers directly above it.

In this assignment you will implement this triangle’s calculation in an efficient way.
Below, code is provided to compute Pascal’s triangle for a size provided by the user at runtime, using static arrays.
Study the code carefully!
``` c++
#include <iostream> 
using namespace std;
void printPascalTr(int size) 
{
   int pascalTr[100][100];
   // first and second rows are set to 1s 
   pascalTr[0][0] = 1;
   pascalTr[1][0] = 1;
   pascalTr[1][1] = 1;
   // compute the entries
   for (int row = 2; row < size; row++) 
   {
      // set the leftmost element to one
      pascalTr[row][0] = 1;
      // compute the middle elements of the triangle
      for (int col = 1; col < row; col++) 
      {
         pascalTr[row][col] = pascalTr[row - 1][col - 1] + pascalTr[row - 1][col];
      }
      // set the rightmost element to one
      pascalTr[row][row] = 1;
   }
   //display the Pascal Triangle 
   for (int row = 0; row < size; row++) 
   {
      for (int col = 0; col <= row; col++) 
      {
         cout << pascalTr[row][col] << "\t";
      }
      cout << "\n";
   }
}
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
```

Assignment: Change the code of the ```printPascalTr()``` function in such a way that it uses dynamic arrays (in two dimensions), making sure that memory is used more efficiently.

Assignment: The provided code does not use modularity in an optimal way yet.
Create a header and source file called ```Pascal.h``` and ```Pascal.cpp``` and isolate the functionality of creating the triangle and printing the triangle in two separate functions.

## Assignment 7: Voltmeter

In many projects an Arduino is used for measuring certain voltages (e.g. from sensors) using the analog input pins.
As you may have noticed earlier, when reading one of the potentiometers on your Arduino shield, the values you get from ```analogRead()``` are a bit noisy.
The values you get change a bit, even though the potentiometer is left at the same setting.
To get a more reliable measurement, we’re going to sample our analog input at a higher frequency and then average our measurements.

In this assignment, we choose a sample frequency of 100 Hz, which means we’ll measure the input 100 times per second (or once every 10 ms).
Then, we’ll display the average and peak of our measurements on the serial monitor twice per second.
While we’re at it, we’ll also convert the numbers we get from ```analogRead()``` to actual voltages.

1. creating a basic peak/average voltmeter.
Now design and implement a program that performs the following steps:
   - Every 10 ms, take a measurement from one of the analog input pins, and store this measurement in a (dynamic) array of sufficient length.
   - Every 500 ms, determine the average and peak (maximum) values from the array, convert these to a voltage, and display them in the serial monitor.
   Some requirements / hints for your implementation:
   - Don’t use magic numbers inside your code.
   Instead define a constant at the top of your program that you can then use in your code.
   - At the top of your program, define two variables of type const unsigned long for the sample time (use 10 ms) and the refresh time (use 500 ms).
   You can use these to take the next sample or refresh the display at the correct times.
   - Use a dynamic array for storing your samples.
   You can calculate the required size of this array by dividing the refresh time by the sample time.
   This way, the length of the array will adapt automatically to changes in your sample or refresh times.
   - Converting the values you get from ```analogRead()``` to actual voltages can be done by dividing by 1023 and then multiplying with the input range (in this case 5 V).

2. add a VU meter with LEDs In many applications, for example in sound engineering, it’s convenient to display the actual measurement using a number of LEDs.
We’re going to add this function to our voltmeter, using two green LEDs, one orange LED and a red LED.
Add a new (static) array at the top of your code, storing the numbers of the LED pins.
You could, for example, use pins 11, 12, 7 and 5 to use the green LED in the RGB LED and the green, orange and red LEDs next to the RGB LED.
Now, show your measurements using the four LEDs as follows:
   - If the measurement is 0, all LEDs are off;
   - If the measurement is > 0, the first green LED will be on;
   - If the measurement is > 25%, the second green LED will also be on;
   - If the measurement is > 50%, the orange LED will also be on;
   - If the measurement is > 75%, the red LED will also be on.
**Hint**: think about how to write efficient code for controlling the LEDs, using the indices of the array.
You can calculate the number of LEDs using the sizeof operator.

3. making your voltmeter more advanced in your current implementation, the amount of time over which the measurements are averaged equals the refresh time of the display.
For example, if we refresh our display every 500 ms, the average and peak values will be determined over the same period of 500 ms.
In real voltmeters, however, these times may be different and could depend on the settings of your voltmeter (e.g. AC or DC measurement).
Modify your code in such a way that, each time the display is refreshed, the average and peak values are determined over a number of samples that can be set separately (and do not have to be a nice multiple of your refresh time).

# Week 3-4

## Assignment 1: Cats and Dogs 

In this assignment we are going to use the string class for replacing cats with dogs.
We’ll start by making an application that asks the user to enter a line of text, and then outputs this text again.
Unfortunately, the usual ```cin >> ...``` statement will break at every space that is entered, so we cannot use that for reading a line of text.
We’ll have to use the ```getline()``` function from the string library instead.

So your initial code should look as follows:
``` c++
#include <iostream> 
#include <string>  

using namespace std;  
int main() {     
   string input;

   cout << "Please enter a line of text:\n";
   getline(cin, input); 

   cout << "\n";
   cout << input << "\n";      
}
```

Now we are going to change our program, using some of the methods from the string class, to replace the word “cat” with the word “dog” in any line of text that is entered.
Design and implement a program that replaces the word “cat” in any line of text with the word “dog” and displays the modified line of text.
If the word “cat” does not appear in the sentence, just display the entered line of text without any alterations.

**Hint**: the find method returns the position at which one string is found in another string.
If the string is not found, the find method returns −1.

**Optional**: can you improve your program such that all occurrences of the word “cat” in a sentence are replaced with the word “dog” (instead of just the first occurrence)?

**Optional**: can you change your program to replace the word “cat” with the word “rabbit”?

## Assignment 2: Arithmetic with Complex Numbers 

In this assignment we are going to create an application to help you with your Math homework.
Write a program that performs some arithmetic on any pair of complex numbers with the choice of adding, subtracting, multiplying and dividing the first number by the second one.

First ask the user for two complex numbers and next ask for one of the operators +, -, * or /.
Depending on the operator, compute the result of the operation.
Of course, your program should check if a valid operator is entered and for division by zero.
Also, after performing the calculation and outputting the result, the program should again start from the beginning.

**Hint**: first read the real and imaginary parts of a number separately (into two variables), and then assign these to the real and imaginary parts of a complex number object using the real and imag methods.
The output can be something like:

**Optional**: note that the complex number ```a+bj``` is represented as ```(a,b)```.
So, for example, the result ```(4,6)``` in the example above represents the complex number ```4+6j```.
Can you change your program in such a way that complex numbers are displayed in the common ```a+bj``` format?

**Optional**: can you also change your program in such a way that the user can enter the complex numbers in this format?

## Assignment 3: Classes on Arduino 

Arduino programs can also use classes, like for example the Serial class.
This class has different methods for communicating between the Arduino and your PC, like the ```print``` and ```println``` methods you have been using (for debugging) before.
We can, however, also use Serial communication for other applications than debugging.
Have a look at the Physical Pixel example at https://www.arduino.cc/en/Tutorial/PhysicalPixel.
Implement this program and try to control the LED from your PC.

**Optional**: try some more advanced LED control, e.g. the Dimmer and Read ASCII String examples.
We’ll get back to making our own classes on Arduino in week 5-6, when we’ll make a ```Button``` class for debouncing our buttons.

First create a ```Point``` header file that looks as follows:
``` c++
#pragma once 

class Point { 
   public:     
   double x;     
   double y; 
};  
```

In your program, first create a function called ```distance()``` with two ```Point``` objects as its parameters (you can use a class type as a parameter just like any basic type).
This function should calculate and return the distance between two points.

**Hint**: for two points, ```p``` and ```q```, the distance ```d``` is given by: ```d=sqrt(pow((x_p-x_q),2)+pow(y_p-y_q, 2));``` 
Finally create a ```main()``` function that asks the user two enter the x and y coordinates for two points, and then calculates and displays the distance between these points.
Obviously, you should pass two ```Point``` objects to your function (and not the separate x and y coordinates).

**Optional**: can you extend your ```Point``` class and ```distance()``` function to calculate the distance between two points in a three dimensional space? Call the additional dimension z.
Figure out how to calculate the distance between two points in a three dimensional space on your own.

**Even more optional**: now make two classes, one for 2D points and one for 3D points, and extend your ```distance()``` function such that it will work for both 2D and 3D points.

**Hint**: you will have to use function overloading to create two versions of your ```distance()``` function.

## Assignment 5: ```Car``` class 
In this assignment you will make a console application with a simple ```Car``` class.
The ```Car``` class holds two pieces of information: the speed of the car and the model of the car.
In your  program you will make one object of the ```Car``` class, set its model (e.g., Audi) and starting  speed (e.g., 25 km/h) and then change the value of the speed several times.
After your  program is finished, a possible result of your program could be something like:

In order to make this program, you should do the following: 
1. Create a new project.
2. Add a new class to your project (in a new/separate ```.h``` file) and call this class ```Car```.
3. Now you need to make it possible for your ```Car``` class to store its model and speed: 
   - Add a public data member (or field) to store the model (string).
   - Add a public data member to store the speed (int).
4. Create one object (for example, call the object ```myCar```) of type ```Car``` in your main  program.
5. Now you can set some initial information for ```myCar```: 
   - Set values for model and speed of ```myCar``` (e.g., model is “Audi” and speed is 25km/h).
   - Show these initial values in the console window.
6. Now you should change the value of the speed of ```myCar``` several times.
   - Make sure that after every change of the speed, you show the new  speed in the console window.
7. Now you can play around with your program.
Try to set different speed values in ```myCar```.
Also try to set different model values in  ```myCar``` (e.g., instead of an “Audi”, you can make a “Mercedes”, “Lamborghini”, etc.).

## Assignment 6: ```Car``` class for millionaires 

Your program from the previous assignment cannot be used for millionaires! Your program only works with one car, while the average millionaire typically has several cars.
So, create some more cars in the main program  (create several ```Car``` objects).

You can decide for yourself which models would be nice to have.
Make them all change speeds at different pace (drive them in parallel)! Don't forget to show  the information of all the cars after each change.
Of course, a millionaire could have a lot of cars, which might become a problem if all car objects are stored on the stack.
So, as is common practice, all objects should be created in the heap memory.

## Assignment 7: ```Car``` class with methods 
Your car program can be improved.
In the program you made for the previous assignment  you can directly change the speed value of the car:

- After driving 25 km/h you instantly switch to 50 km/h.
Is this realistic for a car?

- After driving 51 km/h you instantly switch to 5 km/h.
Is this realistic for a car? 

In this assignment, you will adjust your program in such a way that you can only change the speed in a controlled way.
The goal is to always change speed gradually, e.g., each time by adding or subtracting 10 km/h.

In order to achieve this you should extend your ```Car``` class as follows:

1. Make a method for increasing speed.
Add a method called ```accelerate()``` to the ```Car``` class.
In this method you should increase the speed by 10  km/h (add 10 to the current speed).
Place its declaration in the ```.h``` file and add a new ```.cpp``` file (with the same name) for its implementation.
2. Make a method for decreasing speed.
Add a method called ```brake()``` to the ```Car``` class.
In this method you should decrease the speed by 10 km/h (subtract 10 from the current speed).
Again, place its declaration in the ```.h``` file and its implementation in the ```.cpp``` file.
3. Use these methods in your main program for changing the  speed.
Now you have to change the main program in such a way that you use the methods ```accelerate()``` and ```brake()``` to change the speed instead of changing the data member speed directly.

**Note**: the output to the console windows should not be part of your ```accelerate()``` and ```brake()``` methods! This way we could reuse our classes and methods in an application with a graphical user interface (GUI) later on.

## Assignment 8: Advanced ```Car``` class (**Optional**) 
You can make your ```Car``` class more advanced in many ways: 

1. Adjust your program in such a way that, at the beginning of execution, the user should enter the model name.
2. Make it possible to store additional information in the ```Car``` class.
You are free to  choose which additional attributes are stored (e.g.
the color, license plate number, production year, type of fuel, or any other information you can think of).
3. Adjust your program in such a way that, at the beginning of the execution, the user  should also enter all additional attributes of the car.
Your program should show all  attributes of the car every time you show the current speed of the car.
4. Now the speed change for accelerating or braking is always 10 km/h (the step size).
In reality, this step size will be different for different cars: 
   - Fast cars (e.g., BMW) accelerate and brake faster than family cars (e.g., Fiat); 
   - Newer cars accelerate and brake faster than old or damaged cars.

   Adjust your program as follows: 
      - Add a new field called step for storing the size of the speed change step (e.g., 3 km/h or 10 km/h or some other value) 
      - Adjust methods ```accelerate()``` and ```brake()``` such that they use the new field step for increasing and decreasing the speed (instead of using 10 for each change) 
5. In your main program make two objects of type Car: 
   - One BMW with step 20 km/h
   - One Fiat with step value 5 km/h.
6. Test the two Car objects by calling methods ```accelerate()``` and ```brake()``` and  show the speed several times.

# Week 5-6 ## Assignment 1: ```Car``` class with constructor 

You created a ```Car``` class for millionaires, which allowed you to have an unlimited number of cars in your program.
One annoyance in this program, was that you had to set the model and speed for each car separately, leading to three lines of code for each new car, for example:  

```c++
    Car* myCar = new Car(); // create new Car object 
    myCar->model = "BMW"; // set model of myCar
    myCar->speed = 0; // set initial speed of myCar 
```

In this assignment we are going to extend our ```Car``` class with a constructor, so we will no longer need to set the model and initial speed separately.

To do this, you will need to: 
1. Add the declaration of a constructor to your ```Car``` class in your header file: 
   - A constructor is like a method with no return type, and with the exact same name as the name of your class.
   - Our constructor needs to have one parameter: a string for setting the model of our car. Make sure the parameter of your constructor does not have the same name as the model field in your class.
2. Implement the constructor.
The initial speed of your car should be set to 0 (zero).
3. Change your main program such that it no longer sets the model and initial speed separately, but uses the constructor instead.

If you added more fields to your ```Car``` class in assignment 8 of last week, make sure you also initialize those fields using the constructor, so you can create and initialize a new Car object with just one line of code in your main program.

## Assignment 2: ```Car``` class with private fields 

In the week 3-4 assignments you created a ```Car``` class with, amongst others, a field called speed (for the current speed of a car).
However, in your main program, it was possible to write things like:
- ```myCar->speed = -98;```
- ```myCar->speed = 698;```

This is, of course, not realistic behavior for a car.
Because the speed variable is public, you can assign any integer value to speed from your main program.

In this assignment, you will adjust your program in such a way that you can only change the speed of your car using the ```accelerate()``` and ```brake()``` methods.
In order to achieve this, you should do the following:
    
### A. Make it impossible to access variable speed from outside the ```Car``` class 

1. Instance variable speed was public.
Change this variable into a private one.
This is easy to do: just add a label “private:” to the top of your ```Car``` class and put the speed field below this label.
Usually, the private parts of a class come before its public parts.
2. Re-built your project.
You have errors! Every statement where you try to access the speed field (either for reading or writing) has an error.
In the Error List window at the bottom of your Visual Studio screen you have many error messages saying:
        ```'Car::speed': cannot access private member declared in class 'Car'```

This error message is telling you that, because the speed field is private, you cannot access this field: 
   - You cannot assign a new value with ```myCar->speed = 25;```
   - You cannot read its value with ```cout << ... << myCar->speed << ...;```


### B. Add a method to get the value of instance variable speed 
1. To be able to get the value of speed in our main program, we need to create a method for getting the speed value.
Add a (public) method to your ```Car``` class named ```getSpeed()``` with return type ```int```, and implement this property such that it returns the value of speed.
2. Now you have to change the main program in such a way that you use the ```getSpeed()``` method instead of the speed field for reading values:
   - using the speed field: ```cout << ... << myCar->speed << ...;```
   - using the ```getSpeed()``` method: ```cout << ...<< myCar->getSpeed()<< ...;```
3. If you run your application now (assuming you only used the ```accelerate()``` and ```brake()``` methods for changing the speed of your car) you should no longer get any errors.

### C.  Make sure only realistic speeds can be achieved 
Depending on the current implementation of your ```accelerate()``` and ```brake()``` methods, it may still be possible to get negative or unrealistically high speeds.
If you did not already do so, adapt your accelerate method such that the maximum speed of your car is limited to a realistic value (e.g.
260 km/h, or a separate (private) field for the maximum speed in your class).

### D. Round up your fields and methods 
In C++ it is customary to use private fields for all instance variables, even if there are no special rules you want to impose (like the maximum speed above).
So, make your program look like a professional C++ program by making your model field private as well, and adding a method for getting the model of your cars.
1. Make the model field private; 
2. Add a (public) ```getModel()``` method that can be used from outside the ```Car``` class to access the model field.
There is no need to add a method for changing the model of a car, because the model of a car does usually not change; 
3. Change the main program in such a way that you use the ```getModel()``` method instead of the model field for reading its value.

If you have any other fields in your ```Car``` class, make sure you make these private as well, and provide methods to get their value and to change their value if needed.


## Assignment 3: Driving the car 
The ```Car``` class you have created up to this point only tells something about the car, not the person owning or using it.
To implement this new feature, implement a new class named Person (in its own ```.h``` and ```.cpp``` files, of course) with two fields: name and age (what are their types?) Extend the ```Car``` class with two fields:

- a pointer to the owner (a Person*) 
- a pointer to the user(s) (also a Person*) 

Suppose you are a car lease company.
You have an arsenal of cars.
When you lease a car to someone, you assign an owner to the car and for insurances also the user(s).
Create a dynamic array for the car lease company and implement a function that prints an overview of all cars including the model, the owner’s name (if any) and age, and user name(s) (if any) and age.

**Remark**: take care of properly releasing the heap memory when the objects are deleted.

## Assignment 4: ```Car``` class refueled (**Optional**) 

Finalize your ```Car``` class by adding information about the fuel in the tank.
1. Add a private field fuel (of type double); 
2. Add a public method ```getFuel()``` to get the amount of fuel left in the tank; 
3. Add a public method ```refuel(double liters)``` which adds the value of parameter liters to the fuel field.
Make sure this method can only increase the amount of fuel in the tank, and limit the maximum amount of fuel in the tank to 50 liters; 
4. Add a public method ```drive(double kilometers)``` which uses fuel.
Every 100 kilometers, the car uses 10 liters of fuel.
Make sure you can only drive a positive number of kilometers, and the amount of fuel in the tank will never get negative; 
5. **Optional**: adjust methods ```accelerate()``` and ```brake()``` in the following way: every time one tries to accelerate or brake while the tank is empty (fuel is 0), the car automatically stops driving (speed is set to 0).

Test refueling in your main program!

**Optional**: if you have time left after completing the week 5-6 assignments, feel free to further extend your ```Car``` class as much as you’d like.
Add any properties and methods you can think of.
However, do make sure that you implement everything as you have learned: private fields, methods to access those fields, etc.

## Assignment 5: Debouncing class 

During the second quarter, we created a function for debouncing a button on Arduino.
A problem of this function was that it could only be used for one single button.
To solve this problem, we had to add a lot of pass-by-reference parameters to our function, which was not a very nice and clean solution.

Now, with what we have learned about classes, we can create a ```Button``` class with a ```debounce()``` method.
Because each object of a class has its own copy of the data structure of the class, there should be no problem using this class for debouncing multiple buttons; we could just create a Button object for each button we want to use.

To create this ```Button``` class, we are going to start from last quarter’s debounce function for a single button.
First locate your ```debounce.h``` and ```debounce.cpp``` files from last assignments.

Now, you should do the following: 
1. Create a new Arduino project; 
2. Add a new class to your Arduino project, named ```Button```; 
3. Add (private) fields to your ```Button``` class for those variables that should keep their value between calls of the ```debounce()``` function/method.
Note that these fields should not be made static! Also add a (private) field for the pin number of the button; 
4. Add a constructor to initialize all fields of the ```Button``` class.
The constructor should have one parameter for the pin number of the button.
All other fields should be initialized to a default value (i.e.
```0``` for ```lastDebounceTime``` and ```LOW``` for ```buttonState``` and ```lastButtonState```); 
5. Add a method called ```debounce()``` with no parameters, and return type ```int```.
This method should implement the debouncing function.

Finally, you should build a circuit containing a number of buttons and a number of LEDs.
Create a small program to demonstrate that your ```Button``` class can indeed be used for multiple buttons, e.g.
by turning on/off different LEDs with different buttons.

**Optional**: revisit some of the Arduino programs from last quarter (where you had to use multiple buttons) and modify your program to use your new ```Button``` class instead of the debouncing function with arrays.

## Assignment 6: Traffic light 
We are going to make a class for controlling a traffic light, simulated with three LEDs (green, orange and red).
Create a class named ```TrafficLight``` with the following members:
- A constructor;
- A data member to store if the traffic light is on or off (```bool```);
- A data member to store the current state / color of the traffic light;
- A data member to store, for each of the three colors, the length of the time interval the color should be active (array); i.e. how long each color should be on before going to the next color;
- A method to change to the next color (the transitions are from red to green, from green to orange and from orange to red again);
- A method to change the color of the traffic light automatically, controlled by a timer, using the previous method to change from one color to the next;  

Note that the class declaration must be located in a separate ```.h``` file with the implementation of its methods in the corresponding ```.cpp``` file.
Make sure the data members are private, with set and get methods to access the data members if needed (motivate why).


Next create a simple test program for Arduino, to test your ```TrafficLight``` class.

## Assignment 7: Cooperative traffic lights 
Use the ```TrafficLight``` class made in Assignment 6 to make two traffic lights work together.
This is why there are two traffic lights on your Arduino shield.
Make sure that if one of them has the color green, the other one must be red and once the color green changes to orange and becomes red finally, the other traffic light may become green.
(So they must be suitable for the two intersecting roads at a crossroads).

**Note**: this assignment is not trivial, so make a good flowchart before your start writing code!

**Optional**: add the ```Button``` class from assignment 5 to your project, and create two Button objects.

Each of these two buttons belongs to one of the roads of a crossroads.
Now change your program such that the traffic lights change which road has a green light automatically at a slow speed (e.g. changing roads once every 10 seconds), but when the button corresponding to one of the roads is pressed, the traffic light will change to that road much faster (e.g.
after 2 seconds).