#include <stdio.h>
#include "inout.h"
#include "find_mon.h"
int main(void)
{
	int mas[10], matrix[10][10], n, m, rc;
	printf("Write sizes: ");
	rc = scanf("%d %d", &n, &m);
	if ((rc != 2) || (n <= 0) || (m <= 0) || (n > 10) || (m > 10))
	{
		printf("Input error!");
		return 1;
	}
	rc = matrix_input(matrix, n, m);
	if (rc == 1)
	{
		printf("Input error!");
		return 1;
	}
	if (m == 1)
	{
		for (int i = 0; i < n; i++)
		{
			mas[i] = 0;
		}
	}
	else
	{
		check_mon(mas, matrix, n, m);
	}
	mas_out(mas, n);
	return 0;
}
	