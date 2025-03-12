#include <stdio.h>
#include "operation.h"
#include <string.h>

int main()
{
	char str1[258] = "";
	fgets(str1, 258, stdin);
	if (str1[256] != '\0')
	{
		return 1;
	}
	if (str1[strlen(str1)] == '\n')
	{
		str1[strlen(str1)] = '\0';
	}
	int rc = reg(str1);
	if (rc == -1)
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES");
		return 0;
	}
}