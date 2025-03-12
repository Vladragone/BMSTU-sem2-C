#include <stdio.h>

void change_matrix(int mas[10], int matrix[10][10], int n, int m)
{
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = (i + 1); j < n; j++)
		{
			if (mas[i] < mas[j])
			{
				int temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
				for (int k = 0; k < m; k++)
				{
					int temp = matrix[i][k];
					matrix[i][k] = matrix[j][k];
					matrix[j][k] = temp;
				}
			}
		}
	}
}