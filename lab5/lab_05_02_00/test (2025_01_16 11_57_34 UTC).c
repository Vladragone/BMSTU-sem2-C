#include <stdio.h>
#include "inout.h"

#define ARGUMENTS_ERROR 1
#define OPEN_ERROR 2
#define NONINTEGER_ERROR 3
#define EMPTY_ERROR 4
#define SUCCESS 0

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error with arguments");
		return ARGUMENTS_ERROR;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error while opening");
		return OPEN_ERROR;
	}
	double med = in_med(file);
	fclose(file);
	if (med + 1 < 1e-6)
	{
		return NONINTEGER_ERROR;
	}
	if (med + 2 < 1e-6)
	{
		return EMPTY_ERROR;
	}
	file = fopen(argv[1], "r");
	fseek(file, 0, SEEK_SET);
	double elem = in_closest(file, med);
	fclose(file);
	printf("%lf", elem);
	return SUCCESS;
}