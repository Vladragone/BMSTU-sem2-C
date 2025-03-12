#include <stdio.h>
#include "operation.h"
#include "inout.h"

int main(void)
{
	int matrix[10][10], mas[10], n, m, num, rc;
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
	printf("Write number: ");
	rc = scanf("%d", &num);
	if ((rc != 1) || (num < 0) || (num > 9))
	{
		printf("Input error!");
		return 1;
	}
	change_matrix(mas, matrix, n, m, num);
	for (int i = 0; i < m; i++)
	{
		if (mas[i] == 1)
		{
			break;
		}
		if ((i + 1) == m)
		{
			printf("Empty mas");
			return 1;
		}
	}
	int chet = 0;
	for (int i = 0; i < m; i++)
	{
		if (mas[i] == 1)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[j][chet] = matrix[j][i];
			}
			chet++;
		}
	}
	m = chet;
	matrix_out(matrix, n, m);
	return 0;
}
