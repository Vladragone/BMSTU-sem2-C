#include <stdio.h>

int process(FILE *file, int *num1, int *num2)
{
	int elem, chet = 0, flag1 = 1, flag2 = 1;
	while (fscanf(file, "%d", &elem) == 1)
	{
		if (flag1 == 1)
		{
			*num1 = elem;
			flag1 = 0;
		}
		else if (flag2 == 1)
		{
			if (elem > *num1)
			{
				*num2 = *num1;
				*num1 = elem;
			}
			else
			{
				*num2 = elem;
			}
			flag2 = 0;
		}
		else
		{
			if (elem > *num1)
			{
				*num2 = *num1;
				*num1 = elem;
			}
			else if (elem > *num2)
			{
				*num2 = elem;
			}
		}
		chet++;
	}
	if (chet < 2)
	{
		return -1;
	}
	return 0;
}
