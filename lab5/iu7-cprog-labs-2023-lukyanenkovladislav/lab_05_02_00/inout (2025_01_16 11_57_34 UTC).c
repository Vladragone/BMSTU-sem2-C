#include <stdio.h>
#include <math.h>

double in_med(FILE *file)
{
	double n = 0, el = 0, cur;
	while (!feof(file))
	{
		if (fscanf(file, "%lf", &cur) == 1)
		{
			el = el + cur;
			n++;
		}
		else
		{
			if (n < 1e-6)
			{
				printf("Empty file");
				return -2;
			}
			printf("Non-integer value found");
			return -1;
		}
	}
	double med = el / n;
	return med;
}

double in_closest(FILE *file, double med)
{
	double cur, closest = 0;
	double eps = 123;
	while (!feof(file))
	{
		fscanf(file, "%lf", &cur);
		if (fabs(eps - 123) < 1e-6)
		{
			closest = cur;
			eps = fabs(med - closest);
		}
		else
		{
			if (fabs(med - (cur)) < eps)
			{
				closest = cur;
				eps = fabs(med - closest);
			}
		}
	}
	return closest;
}
