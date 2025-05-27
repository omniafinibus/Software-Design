#pragma once

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
void get_range(int min, int max, int& lower, int& upper);