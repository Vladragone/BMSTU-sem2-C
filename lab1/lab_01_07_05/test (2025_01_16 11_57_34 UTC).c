#include <stdio.h>
#include <math.h>

double fx(double x)
{
	return 1 / sqrt(1 - pow(x, 2));
}

double sx(double x, long long int n)
{	
	double ret;
	int s_up = 1, s_down = 1;
	for (int i = 1; i <= n; i += 2)
		s_up *= i;
	for (int i = 2; i <= n; i += 2)
		s_down *= i;
	
	ret = (s_up * pow(x, n)) / s_down;
	return ret;
}

int main(void)
{
	double x, e, del, d, f, s = 0;
	int rc;
	printf("Write x and Eps: ");
	rc = scanf("%lf%lf", &x, &e);
	if (rc == 2)
	{
		if (fabs(x) >= 1 || ((e <= 0) || (e > 1)))
		{
			printf("Invalid out");
			return 1;
		}
		else
		{
			long long int chet = 0;
			double next;
			f = fx(x);
			next = sx(x, chet);
			while (next >= e)
			{
				s = s + next;
				chet = chet + 2;
				next = sx(x, chet);
			}
			del = fabs(f - s);
			d = fabs(f - s) / fabs(f);
		}
	}
	else
	{
		printf("Invalid out");
		return 1;
	}
	printf("%lf %lf %lf %lf", s, f, del, d);
	return 0;
}
