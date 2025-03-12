#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int next_number(long long int n)
{ 
	int c = 0;
	while (n / 10 != 0)
	{
		c++;
		n = n / 10;
	}
	
	return c;
}	

int main(void)
{
	long long int n;
	int first, rc, i;
	printf("Write number: ");
	rc = scanf("%lli", &n);
	if (rc == 1)
	{
		if (n < 0)
		{
			n = llabs(n);
			printf("-");
		}
		i = next_number(n);
		while (i >= 0)
		{
			first = n / (pow(10, i));
			first = first % 10;
			printf("%d", first);
			i--;
		}
	}
	else
	{
		printf("Invalid out");
		while (1 == 1)
		{
			n = 1;
		}
		return 1;
	}
	while (1 == 1)
		{
			n = 1;
		}
	return 0;
}
		
	