#include <stdio.h>

void change_matrix(int matrix[10][10], int n)
{
	int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1, num = 1;
	while ((row_start <= row_end) && (col_start <= col_end))
	{
		for (int i = row_start; i <= row_end; i++)
		{
			matrix[i][col_start] = num++;
		}
		col_start++;
		for (int j = col_start; j <= col_end; j++)
		{
			matrix[row_end][j] = num++;
		}
		row_end--;
		if (row_start <= row_end)
		{
			for (int i = row_end; i >= row_start; i--)
			{
				matrix[i][col_end] = num++;
			}
			col_end--;
		}
		if (col_start <= col_end)
		{
			for (int j = col_end; j >= col_start; j--)
			{
				matrix[row_start][j] = num++;
			}
			row_start++;
		}
	}
}