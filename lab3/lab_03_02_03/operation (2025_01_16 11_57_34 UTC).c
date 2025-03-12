#include <stdio.h>
#include <stdlib.h>

void change_matrix(int mas[10], int matrix[10][10], int n, int m, int num)
{
	int a;
	for (int i = 0; i < m; i++)
	{
		mas[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (mas[j] == 0)
			{
				continue;
			}
			a = abs(matrix[i][j]);
			while (a >= 0)
			{
				if (a == num)
				{
					mas[j] = 0;
					break;
				}
				else if ((a % 10) == num)
				{
					mas[j] = 0;
					break;
				}
				a = a / 10;
				if (a == 0)
				{
					break;
				}
			}
		}
	}
}