#include <stdio.h>
#include <string.h>
#include <ctype.h>

int reg(char *str)
{
	int j = 0;
	int len = strlen(str);
	if (len < 15)
	{
		return -1;
	}
	while (str[j])
		{
			if (!isspace(str[j]))
			{
				break;
			}
			j++;
		}
	if ((str[j] != '+') && (str[j] != '('))
	{
		return -1;
	}
	if (str[j] == '+')
	{
		j++;
		while (str[j] != '(')
		{
			if (!isdigit(str[j]))
			{
				return -1;
			}
			j++;
		}
		if (j == 1)
		{
			return -1;
		}
		j++;
		int count = 0;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 3)
		{
			return -1;
		}
		if (str[j] != ')')
		{
			return -1;
		}
		j++;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		count = 0;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 3)
		{
			return -1;
		}
		count = 0;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 2)
		{
			return -1;
		}
		count = 0;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 2)
		{
			return -1;
		}
		while (str[j])
		{
			if (!isspace(str[j]))
			{
				return -1;
			}
			j++;
		}
		return 0;
	}
	else
	{
		j++;
		int count = 0;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 3)
		{
			return -1;
		}
		if (str[j] != ')')
		{
			return -1;
		}
		j++;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		count = 0;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 3)
		{
			return -1;
		}
		count = 0;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 2)
		{
			return -1;
		}
		count = 0;
		if (str[j] != '-')
		{
			return -1;
		}
		j++;
		while (isdigit(str[j]))
		{
			count++;
			j++;
		}
		if (count != 2)
		{
			return -1;
		}
		while (str[j])
		{
			if (!isspace(str[j]))
			{
				return -1;
			}
			j++;
		}
		return 0;
	}
}