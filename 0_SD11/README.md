# Software Design Quarter 1 Year 1
This course was an introductory course to `C++` programming.
For background the book Fundamentals of C++ was used: http://python.cs.southern.edu/cppbook/progcpp.pdf


## Week 1 - The Basics
### Assignment 1.1: Hello Application
Write a console application, which shows, for instance, your name, your country and some more information about you.
Note: you do not need to ask for the information before displaying it.

**Goal:**: Learn basic syntax and how to write to an output stream.

### Assignment 1.2: My Age
Write a C++ program using a variable to store the age of a person. The output of the program could look like the example below: 
I am 20 years old.

**Goal:**: Understand variables, specifically strings.
### Assignment 1.3: My Data
Write a C++ program to prompt a user to input his/her age, height and weight, and then the output will be shown as in the example below:

`Your name is Arjan, your age is 25, and your pin is 9000`

**Goal:**: Learn how to read user input.
### Assignment 1.4: My Initials
Write a C++ program which shows your initials. For example, if your name would be Mary Poppins, then the output of the program would look like: `M.P.`
- Implement this program for your own set of initials.

**Goal:**: Learn about data handling in relation to strings.
### Assignment 1.5: Code debugging
Suppose x, y, and z are int variables and x = 2, y = 5 and z = 6. What is the output of each of the following statements?
- `cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';`
- `cout << "x + y = " << x + y << '\n';`
- `cout << "Sum of " << x << " and " << z << " is " << x + z << '\n';`
- `cout << "z / x = " << z / x << '\n';`
- `cout << "2 times " << x << " = " << 2 * x << '\n';`

For each statement, first think of what will be printed to the screen. After that verify your answer by putting the statement into the main function of a program (that also assigns the values to x, y and z).

**Goal:** Understand integer mathematics.

### Assignment 1.6: Exchange the content of 2 variables
Write a C/C++ program to exchange the content of two integer variables (x and y).
The program first reads the initial values of x and y. 
Then your code must swap the content of the 2 variables and at the end the program should display the new values of both x and y. 
Think about the design of your code first, before you implement!

No cheating allowed: you must really swap the content of the variables!

**Goal:**: Understand data handling.

### Assignment 1.7: Code implementation
Consider the following program segment
```
//include statement(s)

int main()
{
    //variable declaration
    
    //executable statements
    
    //return statement
    
}
```
- Write C++ statements that include the iostream header.
- Write a C++ statement that allows you to use cin and cout without the prefix std::.
- Write C++ statements that declare the variables: num1, num2, num3 and average of type int.
- Write C++ statements that store 125 into num1, 28 into num2, and -25 into num3.
- Write a C++ statement that calculates the average of num1, num2 and num3, and stores this into
- rage.
- Write C++ statements that output the values of num1, num2, num3, and average.
- Compile and run your program.

**Goal:** Get used to creating your own C++ code.

## Week 2 - Growing project complexity and floating point values
### Assignment 2.1: Circle calculations (modified exercise 4.24 from the
book)
Write a program that asks the user to enter the radius of a circle as an integer value. 
Your program should display the circle’s diameter, circumference and area using the floating-point value 3.14159 for π. 
Hint: Remember to use a named constant for π (of type double).
Given the radius (r) that the user enters, use the following formulas:
- diameter = 2*r
- circumference = 2*r*π
- area = π*r*r

**Goal:** Introduction to float and double variables

### Assignment 2.2: Total earned EC for all SD courses
Write a C++ program to calculate the total earned EC’s for SD courses for one Engineering student. 
In total, there are four SD courses in the first year: SD11, SD12, SD21 and SD22. 
For each of them a student can earn either 1.5 EC (passed) or 0 EC (failed). 
Ask the user to enter the number of earned EC’s (0 or 1.5) for each of the four SD courses, and calculate and show the total of earned EC’s. 
Draw a flowchart for this application.

**Goal:** Get familiar with drawing flowcharts before diving into programming

### Assignment 2.3: Midpoints (Exercise 4.25 from the book)
In mathematics, the midpoint between the two points (𝒙𝟏, 𝒚𝟏) and (𝒙𝟐, 𝒚𝟐) is computed by the
formula
((x1+x2)/2 , (y1+y2)/2)
Write a C++ program that asks for two mathematical points from the user and computes and computes and displays their midpoint.
The user literally enters ”(0,0)” and ”(1,1)” with the parentheses and commas. 
To see how to do this, suppose you want to allow a user to enter the point (2.3,9), assigning the x component of the point to a variable named x and the y component to a variable named y. 
You can add the following code fragment to your program to achieve the desired effect:
```
double x, y;
char leftParen, comma, rightParen;
cin >> leftParen >> x >> comma >> y >> rightParen;
```
If the user literally types (2.3,9), the cin statement will assign the ( character to the variable
leftParen. It will then assign 2.3 to the variable x. 
It assigns the , character to the variable named comma, the value 9 to the y variable, and the ) character to the rightParen variable.
The leftParen, comma, and rightParen variables are just placeholders for the user’s input and are not used elsewhere within the program. 
In reality, the user can type in other characters in place of the parentheses and comma as long as the numbers are in the proper location relative to the characters; for example, the user could enter *2.3:9#, and the program would still interpret this as the point (2.3,9). We’ll learn ways to prevent this later in the course.

**Goal:** Learn about more complex user inputs

### Assignment 2.4: Calories of food (Exercise 4.26 from the book)
The table below lists the Calorie contents of several types of food. 
| Food | Calories |
| ------------- | ------------- |
| Bean Burrito | 357 |
| Salad w/ Dressing | 187 |
| Milkshake | 388 |

Running or walking burns approx. 100 Calories per mile. 
Write a C++ program that requests three values from the user: the number of bean burritos, salads, and shakes consumed (in that order). 
The program should then display the number of miles that must be run or walked to burn off the Calories in the amount of food the user had.
Observe that the result is a floating-point value, so you should use floating-point arithmetic to compute the answers for this problem.

**Goal:** Get more experience with floating point calculations

### Assignment 2.5: Minimize the coins
Write a program that first asks the user for two (positive) integer values. 
The first one is the number of euros, the second one is the number of cents.
The program must determine a set of coins with a value equal to the value of the amount
entered, with the restriction that the number of coins must be minimized!
First think about how you solve this problem and only then start implementing!
You must display the amount of coins at the end. Two possible results of your program are
displayed below. What is the difference between these two examples?
Optional: could you change your program such that the total amount of money is read in a single line, similar to the method that we used in Assignment 2.3?

**Goal:** Get used to more complex code

## Week 3 - Basic data analysis
### Assignment 3.1 Odd or even
A program asks the user to enter one integer, and then determines and displays whether the number is odd or even.
Use the remainder operator: an even number is dividable by 2, so any multiple of 2 leaves a remainder of 0 when divided by 2.

**Goal:** Understand basic operations and conditional logic.

### Assignment 3.2: Comparing three integers
A program asks the user to enter three integer values (e.g. 56, 30 and 45).
Your program should compare these three integers, and display the value of the largest 
(e.g. “The maximum value is 56.”).
If all three numbers are equal, the program should display the message “All numbers are equal.”.
Again, first provide the flow chart of the program and then implement the code!

**Goal:** Practice using conditional statements and comparisons.


### Assignment 3.3: Duplicates (Exercise 5.20 from the book)
A program requests three integer values from the user.
It then displays one of two things: if any of the values entered are duplicates, it displays “DUPLICATES”; otherwise, it displays “ALL UNIQUE”.
First provide the flow chart of the program and then implement the code.

**Goal:** Practice checking for duplicates and logical conditions.


### Assignment 3.4: Arithmetic with 2 numbers
The goal is to write a program that performs some arithmetic on any pair of numbers with the choice of adding, subtracting, multiplying and dividing the first number by the second one.
First ask the user for two numbers and next ask for one of the operators +, −, * or /.
Depending on the operator the user enters, compute and display the result of the operation.

**Goal:** Practice using operators and user input for operations.

## Week 4 - 
### Assignment 4.1: Body mass index
Body mass index (BMI) is calculated based on the following formula:
```
BMI = weight / (height^2) 
```
Design and write a program that asks the user to enter the weight and height. 
Your program should calculate and display the BMI. 
Also show the following explanation so that the user can evaluate his/her BMI:
| Type | Range |
|------|-------|
|Underweight | less than 18.5 |
|Normal | between 18.5 and 24.9 |
|Overweight | between 25 and 29.9 |
|Obese | 30 or greater |

If the BMI value indicates the person is obese, issue the following warning “Your BMI is extremely high.
Please contact your doctor because your health is in danger!”.

**Goal:** Practice input/output, mathematical operations, and conditional checks to calculate and interpret BMI

### Assignment 4.2: Body fat of a person
Another way to determine how healthy someone is, is by measuring his/her body fat percentage.
The formulas to determine the body fat for female and male are as follows:
Body fat formula for women:
```
A1 = (body weight x 0.732) + 8.987
A2 = wrist measurement (at fullest point) / 3.140
A3 = waist measurement (at naval) x 0.157
A4 = hip measurement (at fullest point) x 0.249
A5 = forearm measurement (at fullest point) x 0.434
B = A1 + A2 – A3 – A4 + A5
Body fat = body weight – B
Body fat percentage = body fat x 100 / body weight
```
Body fat formula for men:
```
A1 = (body weight x 1.082) + 94.42
A2 = waist measurement x 4.15
B = A1 – A2
Body fat = body weight – B
Body fat percentage = body fat x 100 / body weight
Note: weights in pounds, measurements in inches.
```
Design and write a program to calculate the body fat of a person.

**Goal:** Using multiple variables, scientific notation for unit conversions, and conditional logic.

### Assignment 4.3: Body fat of a person
Extend assignment 4.2 such that two arbitrary persons can compare their body fat such that the program determines who has the least body fat.

**Goal:** Organizing code with functions or data structures to compare results.

### Assignment 4.4: Days of the month
Design and implement a program that asks the user to enter a month (1 for January, 2 for February,and so on) and then prints the number of days in the month. For February, print “28 or 29 days”.
Do not use a separate if/else branch for each month!

**Goal:** Using arrays or switch-case to avoid repetitive if-else logic

### Assignment 4.5: Wavelengths
Design and write a program that prompts the user for a wavelength value and prints a description of the
corresponding part of the electromagnetic spectrum, as given in the table below.
Type Wavelength (m) Frequency (Hz)

| Type | Wavelength (m) | Frequency (Hz) |
| ------------- | ------------- | ------------- |
| Radio Waves   | > 10^-1                | < 3 x 10^9 |
| Microwave     | 10^-3 to 10^-1         | 3 x 10^9 to 3 x 10^11 |
| Infrared      | 7 x 10^-7 to 10^-3     | 3 x 10^11 to 4 x 10^14 |
| Visible light | 4 x 10^-7 to 7 x 10^-7 | 4 x 10^14 to 7.5 x 10^14 |
| Ultraviolet   | 10^-8 to 4 x 10^-7     | 7.5 x 10^14 to 3 x 10^16 |
| X-rays        | 10^-11 to 10^-8        | 3 x 10^16 to 3 x 10^19 |
| Gamma rays    | < 10^-11               | > 3 x 10^19 |


Hint: you can make use of scientific notation also in C++, saving you a lot of counting and typing zeroes

for this exercise. Have a look at Chapter 3 from the book to figure out how to do this!

**Goal:** Using floating-point arithmetic with scientific notation, comparison operators, and constants to categorize data into predefined ranges