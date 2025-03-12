#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "inout.h"

#define SUCCESS 0
#define OPEN_ERROR 1
#define ARGUMENT_ERROR 2
#define EMPTY_ERROR 3
#define NUM_ERROR 4
#define NON_INTEGER_ERROR 5

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		return ARGUMENT_ERROR;
	}
	char *key = argv[1];
	char *file_name = argv[2];
	if (key[0] == 'c')
	{
		if (argc != 4)
		{
			return ARGUMENT_ERROR;
		}
		FILE *file = fopen(file_name, "wb");
		if (file == NULL)
		{
			return OPEN_ERROR;
		}
		srand(time(NULL));
		int num = atoi(argv[3]);
		if (num < 1)
		{
			return NUM_ERROR;
		}
		
		for (int i = 0; i < num; i++)
		{
			int random_number = rand() % 1000;
			put_number_by_pos(file, i, random_number);
		}
		fclose(file);
	}
	else if (key[0] == 'p')
	{
		if (argc != 3)
		{
			return ARGUMENT_ERROR;
		}
		FILE *file = fopen(file_name, "rb+");
		if (file == NULL)
		{
			return OPEN_ERROR;
		}
		int number, check = 0;
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		if (size % sizeof(int) != 0)
		{
			return NON_INTEGER_ERROR;
		}
		fseek(file, 0, SEEK_SET);
		while (fread(&number, sizeof(int), 1, file))
		{
			check++;
			printf("%d\n", number);
		}
		if (check == 0)
		{
			return EMPTY_ERROR;
		}
		fclose(file);
	}
	else if (key[0] == 's')
	{
		if (argc != 3)
		{
			return ARGUMENT_ERROR;
		}
		FILE *file = fopen(file_name, "rb+");
		if (file == NULL)
		{
			return OPEN_ERROR;
		}
		int number, elems_num = 0;
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		if (size % sizeof(int) != 0)
		{
			return NON_INTEGER_ERROR;
		}
		fseek(file, 0, SEEK_SET);
		while (fread(&number, sizeof(int), 1, file))
		{
			elems_num++;
		}
		if (elems_num == 0)
		{
			return EMPTY_ERROR;
		}
		sort_numbers(file, elems_num);
		fclose(file);
	}
	else
	{
		return ARGUMENT_ERROR;
	}
	return SUCCESS;
}