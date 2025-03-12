#include <stdio.h>
#include <math.h>

int main(void)
{
	int a[10], n, rc;
	int *s = a;
	int *p = a;
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
		rc = scanf("%d", &*p);
		p++;
		if (rc != 1)
		{
			printf("Input error!");
			return 1;
		}
	}
	int *e = a + n - 1;
	int max_sum = *s + *e;
	while (s <= e)
	{
		int sum = *s + *e;
		if (sum > max_sum)
		{
			max_sum = sum;
		}
		s++;
		e--;
	}
	printf("%d", max_sum);
	return 0;
}