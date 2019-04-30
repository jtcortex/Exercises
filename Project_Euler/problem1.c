/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <stdlib.h>

int j = 0;
int k = 0;

void main()
/* 
 * Starting at 3, loop through all values and perform module operation to determine divisibility by 3 or 5. Take summation of values.
 */
{
	for(int i = 3; i < 1000; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			j += i;
		}
	}

	printf("%d", j);
}
