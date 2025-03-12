#include <stdio.h>

void change_matrix(int matrix[10][10], int n)
{
	int start = 0; 
	int end = n - 1;
	while (start < end)
	{
		for (int j = 0; j < (n / 2); j++)
		{
			for (int i = start; i <= end; i++)
			{
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n - j - 1];
				matrix[i][n - j - 1] = temp;
			}
			start++;
			end--;
		}
		if (start >= end)
		{
			break;
		}
	}
}