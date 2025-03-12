#include <stdio.h>
#include <math.h>

double geomterical(double count, int n, int a[])
{
	double elem_am = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			count = count * a[i];
			elem_am++;
		}
	}
	if (elem_am == 0)
	{
		return -1;
	}
	count = pow(count, (1 / elem_am));
	return count;
}

int main(void)
{
	double count = 1;
	int a[10], rc, n;
	printf("Write size:\n ");
	rc = scanf("%d", &n);
	if ((rc != 1) || (n <= 0) || (n > 10))
	{
		printf("Input error!");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("Write next elem: ");
		rc = scanf("%d", &a[i]);
		if (rc != 1)
		{
			printf("Input error!");
			return 1;
		}
	}
	count = geomterical(count, n, a);
	if (count == -1.000000)
	{
		printf("No one pos elems");
		return 1;
	}
	printf("%lf", count);
	return 0;
}

		