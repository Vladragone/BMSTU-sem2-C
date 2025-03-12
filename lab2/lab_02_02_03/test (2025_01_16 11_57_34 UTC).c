#include <stdio.h>
#include <math.h>

int check(long long int n)
{
	long long int count = 0, sum = 0, nn = n, copy = n;
	if (n <= 0)
	{
		return 2;
	}
	while (nn != 0)
	{
		nn = nn / 10;
		sum += 1;
	}
	while (n != 0)
	{
		count = count + pow((n % 10), sum);
		n = n / 10;
	}
	if (count != copy)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
		
		
int main(void)
{
	long long int a[10], b[10], n, perem, len_b = 0;
	int rc, flag = 0;
	printf("Write size:\n ");
	rc = scanf("%lld", &n);
	if ((rc != 1) || (n <= 0) || (n > 10))
	{
		printf("Input error!");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("Write next elem: ");
		rc = scanf("%lld", &a[i]);
		if (rc != 1)
		{
			printf("Input error!");
			return 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		perem = check(a[i]);
		if (perem == 2)
		{
			if (flag == 0)
			{
				printf("Empty mas!");
				return 1;
			}
		}
		if (perem == 0)
		{
			flag = 1;
			b[len_b] = a[i];
			len_b++;
		}
		if (len_b == 0)
		{
			printf("Empty mas!");
			return 1;
		}
	}
	for (int i = 0; i < len_b; i++)
	{
		printf("%lld ", b[i]);
	}
	return 0;
}
