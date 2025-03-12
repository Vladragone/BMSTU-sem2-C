#include <stdio.h>
#include "inout.h"

#define NOT_ENOUGH_ELEMS 1
#define SUCCESS 0

int main(void)
{
	int num1 = 0, num2 = 0;
	int rc = process(stdin, &num1, &num2);
	if (rc == -1)
	{
		printf("Invalid input");
		return NOT_ENOUGH_ELEMS;
	}
	printf("%d %d", num1, num2);
	return SUCCESS;
}
	