#include <stdio.h>

int matrix_input(int matrix[10][10], int n)
{
	int rc, flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Write elem ");
			rc = scanf("%d", &matrix[i][j]);
			if (rc != 1)
			{
				flag = 1;
			}
		}
	}
	return flag;
}

void matrix_out(int matrix[10][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}