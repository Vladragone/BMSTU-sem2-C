#include <stdio.h>
#include "operation.h"
#include "inout.h"

int main(void)
{
	int matrix[10][10], mas[10], n, m, rc;
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
	for (int i = 0; i < n; i++)
	{
		int cur_min = matrix[i][0];
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] < cur_min)
			{
				cur_min = matrix[i][j];
			}
		}
		mas[i] = cur_min;
	}
	change_matrix(mas, matrix, n, m);
	matrix_out(matrix, n, m);
	return 0;
}