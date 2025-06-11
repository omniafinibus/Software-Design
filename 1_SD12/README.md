# Week 1

## Assignment 1: Controlling an LED 

In this assignment you’ll learn how to digitally control an LED using the Arduino. 
 
Go to: http://arduino.cc/en/Tutorial/Blink, carefully read the page, and recreate this example.

Does the LED blink? 
Can you also change the program in such a way that the LED blinks faster or slower? 

## Assignment 2: Reacting to buttons 

Next to showing information (e.g. using the LED from the last example), we also want to be able to input information into our system. 
A simple form of input is a push button. 
In this assignment you’ll learn how a button can be used for (digital) input. 
 
Go to: http://arduino.cc/en/Tutorial/Button. Carefully read the page and recreate the example. 
 
If all went well, the LED should now be on if the button is pushed, and turned off again when the button is released. 
Can you change the program in such a way that the LED is on if the button is not pushed, and turns off when the button is pushed? 

Now change your code again, to make the pushbutton work as a toggle switch: when the button is pressed once, the LED should turn on (and stay on after you release the button), and when the button is pressed again the LED is turned off. 

Does this work reliably? 
Does the LED indeed toggle each time you push the button? 
Probably, the LED will sometimes toggle correctly, but sometimes not. We’ll get back to push buttons and how to solve this later. 

# Week 2

## Assignment 1: Controlling an array of LEDs 

Now that you figured out how to control a single LED, let’s setup an array of LEDs. 
Use at least 4 LEDs of the two traffic lights on your Arduino shield or just repeat the hardware setup, but now four times.  
 
Change the blinking program in such a way, that you get a running LED array.
Turn the first LED on for 0.1 s. 
Next, turn this LED off and turn the second LED on (again for 0.1 s). 
Again, turn this LED off and turn the third LED on, and so on. 
When the last LED is turned off, turn the first LED on again. Keep repeating this. 

Now change your program in such a way that you can change the speed of the chase lights by changing just one constant in your program. 
After you finished this assignment, you can continue with the next assignment, where you will reuse the hardware of this assignment. 
 
## Assignment 2: LED array reacting to button clicks  
In this assignment, we will extend the previous program by adding a pushbutton to have the LED array advance each time the pushbutton is pressed. 
So, if the first LED is on, the switch to the second LED occurs when the pushbutton is pressed. 
Similarly, the switch from the second LED to the third LED occurs when the pushbutton is pressed once more, and so on. 

Adapt your program, such that you can control the LED array by using the pushbutton. 
Each time the button is pressed, the array advances to the next LED. 
You are allowed to continue in the same project. 
Does your program work reliably?
The effect you notice is called the bouncing effect, which is present in every button or switch. 
On http://arduino.cc/en/Tutorial/Debounce you can find a tutorial which shows how to solve this problem (debouncing an input). 
Implement this solution in your program! 

**Hint**: first just run the debounce example from the Arduino website and try to figure out how this works.
Then combine your previous code with this code to make your LED array react to button presses reliably. 

# Week 3
## Assignment 1: Trigonometry  
Create a console application that, given the lengths of the two sides of a triangle adjacent to the right angle (Side 1 
and Side 2), computes the length of the hypotenuse of the triangle. 

If you are unsure how to solve the problem mathematically, do a web search for the Pythagorean Theorem. 

The algorithm you implement involves computing squares and the square root. Use the ```cmath``` library to perform these operations! 
 
**Optional**: Given three sides, two sides and one angle, or two angles and one side, you are able to calculate the three missing angles/sides using the cosine-and sine-rules. 
Create a program that allows the user to enter any three of the angles and/or sides, and then calculates the missing three. 
 
## Assignment 2: Trigonometry on Arduino (optional)  

(extension of Assignment 1) 
Use the two potentiometers on your Arduino shield or connect two potentiometers to the analog inputs of your Arduino (see week 1 slides for how to do this) and create a new Arduino project. 

In this project, implement the same algorithm as above, but now the inputs are not read from the console, but from the two analog inputs instead. 

The result of your calculations should be displayed on the Serial Monitor, showing the length of each of the three sides of the triangle on one line. 

## Assignment 3: Blinking with a random interval 
In Assignment 1-1, you implemented a blinking LED with a fixed time interval between turning the LED on and off. 
In this assignment, we are going to adapt this code to make the LED blink at random intervals. 

The LED should be on for 100 ms (0.1 s) and then off for a random interval in the range 0.25 to 4 seconds. 
Use the pseudo random number generator functions to generate a new random interval each time the LED turns off. 

**Note**: you are allowed to use the delay() function to make the LED blink. We’ll look at 
blinking an LED without using delays later. 

**Optional**: you will notice that it looks like the long intervals (1-3 seconds) occur more often than short intervals (< 1 second).
This is caused by the linear distribution of the chance for each possible time interval. 
Adapt your code to solve this problem. 

**Hint**: use the ```pow()``` function with base 2 and a random exponent between -2 and 2 to determine your time interval. 
 
## Assignment 4: Blinking without delay 
Until now, you have used the ```delay()``` function for making an LED blink.
However, if your program should do more than just make an LED blink, this won’t work anymore. 
Now, modify your program from Assignment 3 (you don’t need to create a new project for this), such that it no longer uses the delay() function anywhere in the code. 
Your program should keep cycling through the ```loop()``` function without any delays. Use the ```millis()``` function to measure time, and use this to determine when the LED should turn on or off. Do NOT create additional loops inside the ```loop()``` function to make your program wait! 

**Optional**: make two (or more) LEDs blink with different time intervals. 
Why would this not be possible if you were still using the ```delay()``` function? 

# Week 4

## Assignment 1: Calculator  
In a previous assignment you implemented a console application to perform arithmetic on any pair of numbers with the choice of adding, subtracting, multiplying and dividing. The user was asked for two numbers and one of the operators ```+```, ```-```, ```*``` or ```/```. 
Depending on the operator, the program computed the result of the operation. 
Optionally, you even changed the program in such a way that the user could provide expressions like ```8 * 3``` or ```6 / 5``` on one line. 

Re-implement your code incorporating modularity: 
- Create a separate header file (```arithmetic.h```) and source file (```arithmetic.cpp```) for defining and implementing the arithmetic operations. 
Create functions (each with two parameters) named add, subtract, multiply and divide. 

**Note**: do not forget to include comments for your functions, explaining what the function does, what its parameters are, and what its return value means! 

- Include the header file in your main source file, and use the functions you created to re-create the original functionality. 

## Assignment 2: Body fat of a person  
You implemented a program to compute the body fat of a person (with measurements in pounds and inches). 
In this assignment, we’ll create a modular and improved version of our program. 
There will be three main parts in our program: 
 
1. Conversion from kilograms to pounds and meters to inches: 
    - 1 kilogram = 2.20462262 pounds 
    - 1 meter = 39.3700787 inches 
2. The formulas to determine the body fat for a female:  
    - A1 = (body weight x 0.732) + 8.987  
    - A2 = wrist measurement (at fullest point) / 3.140  
    - A3 = waist measurement (at navel) x 0.157  
    - A4 = hip measurement (at fullest point) x 0.249  
    - A5 = forearm measurement (at fullest point) x 0.434  
    - B = A1 + A2 – A3 – A4 + A5  
    - Body fat = body weight – B  
    - Body fat percentage = body fat x 100 / body weight  
3. The formulas to determine the body fat for a male: 
    - A1 = (body weight x 1.082) + 94.42  
    - A2 = waist measurement x 4.15  
    - B = A1 – A2  
    - Body fat = body weight – B  
    - Body fat percentage = body fat x 100 / body weight  
 
The problem of this program was that for comparing the body fat of two persons, we had to implement the same code twice. 
We can now solve this by creating a modular version of our program: 
- Design and implement the unit conversion step. Define a header and source file with the name ```UnitConversion```, which contains functions to convert kilograms to pounds and meters to inches. 
- Design and implement the body fat computations for male and female (so, create two functions), in a separate header and source file named BodyFat. 
- Design and implement the main program that uses the functions declared in ```UnitConversion.h``` and ```BodyFat.h```, such that two arbitrary persons can compare their body fat.
 The program should determine who has the least body fat. 

## Assignment 3: LED array reacting to button clicks, with debounce

You implemented a program that used a pushbutton to have an LED array advance each time the pushbutton was pressed. 
Here you could clearly see the effect of the bouncing of a button and you implemented a debouncing algorithm to avoid this effect. 
In order to be able to re-use this code, we’ll move the debouncing implementation to its own module. 
 
- Add empty header (```.h```) and source (```.cpp```) file. 
- Create a ```debounce()``` function inside these files to implement the debouncing functionality. 
 
# Week 5

## Assignment 1: Swapping values 
Below are three examples of a function for swapping values: 

``` c++
    void swap_by_value(int a, int b)
    {
    int temp = a;
    a = b;
    b = temp;
    }

    int v = 5, w = 19;
    swap(v, w);
```

```c++
void swap_by_pointer(int* a, int* b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

int v = 5, w = 19;
swap(&v, &w);
```

```c++
void swap_by_reference(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}

int v = 5, w = 19;
swap(v, w);
```
 
 
In this assignment you are going to look into the differences between these functions. 

1. Create a separate ```.h``` and ```.cpp``` file, in which you implement these three functions (i.e. all three functions in one ```.cpp``` and one ```.h``` file) . 
Make sure you give each of your functions a recognizable name (e.g. ```swapValue()```, ```swapPointer()``` and ```swapReference()```). 
2. Create a main program that asks the user for two integer values, and applies 
each of the three functions to these two values. 
After each function, show the result to the user. 
    - What is the effect of each of the functions? 
    - Which function would you choose for swapping two values, and why? 
    - Given that integers and pointers each use 32 bits (4 bytes) of memory (in Win32 Applications). How much memory is needed for each of the three functions? You only need to count the memory for variables and pointers. 
3. Extend each of the functions such that they can also be used for doubles. You will need to use function overloading. 
Extend your main program to test your new functions. 
    - Given that doubles use 64 bits (8 bytes) of memory. 
    zow much memory is now needed for each of the three extended functions that work on doubles? 
 
## Assignment 2: Faulty function 
The following program displays all integers within a certain range, which can be provided by the user through the ```get_range()``` function: 
   
To get the desired range from the user, and make sure that lower cannot be below a certain minimum (50 in this example) and upper cannot be below a certain maximum (100 in this example), the function below is used. 
 
This function intends to ask the user for a range of integers, between min and max. The values for min and max are provided by the program that calls this function (see above), while the values for lower and upper, that are entered by the user, are further used in the main program (e.g. as the lower and upper bounds for a loop). 

``` c++
int main() 
{ 
    int lower, upper; 
    int min = 50, max = 100; 
  
    get_range(min, max, lower, upper); 
  
    // print all numbers between lower and upper (including) 
    for (int i = lower; i <= upper; i++) 
    { 
        cout << i << " "; 
    } 
  
    cout << '\n'; 
  
} 
```
 
Unfortunately, the function does not behave as expected! 
 
- What is the problem with this function? 
- Modify the function such that it works, using pass by reference with pointers. 
- Modify the function such that it works, using pass by reference with reference parameters. 
  
```c++
/* (Faulty function) 
 * 
 * get_range 
 * Asks the user for a range of integers. 
 * The lower value must be greater than or equal to min, 
 * and the upper value must be less than or equal to max. 
 * min is a parameter containing the lowest acceptable lower value. 
 * max is a parameter containing the highest acceptable upper value. 
 * lower is assigned the lower limit of the range 
 * upper is assigned the upper limit of the range 
 */ 
void get_range(int min, int max, int lower, int upper) 
{ 
    cout << "Please enter a data range within the bounds "; 
    cout << min << "..." << max << ": "; 
 
    do // Loop until acceptable values are provided 
    { 
        cin >> lower >> upper; 
        if (lower < min) 
            cout << lower << " is too low, please try again.\n"; 
        if (upper > max) 
            cout << upper << " is too high, please try again.\n"; 
    } while ((lower < min) || (upper > max)); 
} 
```