/*
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
	int i = 0;
	int j = 1;
	int k = 2;
	int total = 2;
	while (i < 4000000)
	{
		i = j + k;
		if (i%2==0)
		{
			total += i;
		}
		j = k;
		k = i;
	}

	printf("%d", total);
}
