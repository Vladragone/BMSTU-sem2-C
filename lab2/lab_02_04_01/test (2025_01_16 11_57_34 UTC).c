#include <stdio.h>
#include <math.h>

void insertsort(long long int a[], int n)
{
	long long int next_elem, cur_pos;
	for (long long int i = 1; i < n; i++)
	{
		next_elem = a[i];
		cur_pos = i - 1;
		while ((cur_pos >= 0) && (a[cur_pos] > next_elem))
		{
			a[cur_pos + 1] = a[cur_pos];
			cur_pos--;
		}
		a[cur_pos + 1] = next_elem;
	}
}

int main(void)
{
	long long int n, flag = 0, a[10], rc;
	for (int i = 0; i < 11; i++)
	{
		printf("Write next elem: ");
		rc = scanf("%lld", &a[i]);
		if (rc != 1)
		{
			if (i == 0)
			{
				printf("Error!");
				return 1;
			}
			n = i;
			break;
		}
		if (i == 10)
		{
			printf("Error! Overflow!");
			flag = 1;
			n = 10;
		}
	}
	insertsort(a, n);
	if (flag == 1)
	{
		return 100;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%lld ", a[i]);
	}
	return 0;
}