#pragma once

// purpose: compute the sum of all array elements
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the sum
long findSum(int * arrayOfNums, int sz);

// purpose: compute the average of all array elements
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the average
double findAverage(int * arrayOfNums, int sz);

// purpose: find the maximum value of all array elements
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the maximum value
int findMax(int * arrayOfNums, int sz);

// purpose: find the minimum value of all array elements
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the minimum value
int findMin(int * arrayOfNums, int sz);

// purpose: compute the sum of all array elements using array ranges
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the sum
long findSum(int * begin, int * end);

// purpose: compute the average of all array elements using array ranges
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the average
double findAverage(int * begin, int * end);

// purpose: find the maximum value of all array elements using array ranges
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the maximum value
int findMax(int * begin, int * end);

// purpose: find the minimum value of all array elements using array ranges
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//             sz is the number of entries in the arrayOfNums
// output: the minimum value
int findMin(int * begin, int * end);

// purpose: flip the array around
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//			   sz is the number of entries in the arrayOfNums
// output: flipped array
void flipArray(int * begin, int end);


// purpose: find the address of max on the given array
// parameters: arrayOfNums is the array of numbers to compute the statistics for
//			   sz is the number of entries in the arrayOfNums
// output: find address of max
int *maximum(int *arr, int sz);