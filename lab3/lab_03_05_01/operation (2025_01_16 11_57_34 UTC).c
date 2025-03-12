#include <stdio.h>
#include <stdlib.h>

int change_matrix(int matrix[10][10], int n, int m, int mas[100], int mas_i[100], int mas_j[100])
{
	int chet = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp = abs(matrix[i][j]), sum = 0;
			while (temp != 0)
			{
				sum += temp % 10;
				temp = temp / 10;
			}
			if (sum > 10)
			{
				mas_i[chet] = i;
				mas_j[chet] = j;
				mas[chet] = matrix[i][j];
				chet++;
			}
		}
	}
	return chet;
}

void cycle(int mas[100], int chet)
{
	for (int i = 0; i < 3; i++)
	{
		int temp = mas[0];
		for (int j = 0; j < (chet - 1); j++)
		{
			mas[j] = mas[j + 1];
		}
		mas[chet - 1] = temp;
	}
}