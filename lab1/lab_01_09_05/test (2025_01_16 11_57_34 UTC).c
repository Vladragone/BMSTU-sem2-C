#include <stdio.h>
#include <math.h>

double gx(double x)
{
	return exp(1/x);
}

int main(void)
{	
	double x, s = 1;
	int rc;
	long long int chet = 1;
	rc = scanf("%lf", &x);
	if (rc == 1)
	{
		if (x < 0)
		{
			printf("Invalid out");
			return 1;
		}
		while (x >= 0)
		{
			s = s * (x + 1);
			chet++;
			rc = scanf("%lf", &x);
			if (rc != 1)
			{
				printf("Invalid out");
				return 1;
			}
		}
	}
	else
	{
		printf("Invalid out");
		return 1;
	}
	printf("%lf",gx(s));
	while (1 == 1)
	{
		s = 1;
	}
	return 0;
}
	
	