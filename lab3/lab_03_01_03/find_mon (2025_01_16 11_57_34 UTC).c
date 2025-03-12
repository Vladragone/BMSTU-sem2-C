#include <stdio.h>

void check_mon(int mas[10], int matrix [10][10], int n, int m)
{
	int flag_up, flag_down;
	for (int i = 0; i < n; i++)
	{
		flag_up = 1;
		flag_down = 1;
		for (int j = 0; j < (m - 1); j++)
		{
			if (matrix[i][j] > matrix[i][j + 1])
			{
				flag_up = 0;
			}
			if (matrix[i][j] < matrix[i][j + 1])
			{
				flag_down = 0;
			}
			if ((flag_up == 0) && (flag_down == 0))
			{
				break;
			}	
		}
		if ((flag_up == 1) || (flag_down == 1))
		{
			mas[i] = 1;
		}
		else
		{
			mas[i] = 0;
		}
	}
}