#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

#define N 255
#define M 6

int main(void)
{
	char str1[M][N] = {"Hello", "555123555", " ", "5 5 5 1 2 3 5 5   5", ".,/123/.,"};
	char str2[M][N] = {"ell", "512", "3 5 5", "321", ".,", "5123"};
	char sym[M] = {'5', '1', '3', '2', 'o', '7'};
	int count_correct = 0, count_all = 0;
	for (int i = 0; i < M; i++)
	{
		if (my_strpbrk(str1[i], str2[i]) == strpbrk(str1[i], str2[i]))
		{
			count_correct += 1;
		}
		count_all += 1;
	}
	for (int i = 0; i < M; i++)
	{
		if (my_strspn(str1[i], str2[i]) == strspn(str1[i], str2[i]))
		{
			count_correct += 1;
		}
		count_all += 1;
	}
	for (int i = 0; i < M; i++)
	{
		if (my_strcspn(str1[i], str2[i]) == strcspn(str1[i], str2[i]))
		{
			count_correct += 1;
		}
		count_all += 1;
	}
	for (int i = 0; i < M; i++)
	{
		if (my_strchr(str1[i], sym[i]) == strchr(str1[i], sym[i]))
		{
			count_correct += 1;
		}
		count_all += 1;
	}
	for (int i = 0; i < M; i++)
	{
		if (my_strrchr(str1[i], sym[i]) == strrchr(str1[i], sym[i]))
		{
			count_correct += 1;
		}
		count_all += 1;
	}
	if (count_correct == count_all)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}