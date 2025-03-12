#include <stdio.h>
#include <string.h>

char *my_strpbrk(const char *str, const char *sym)
{
	int len_str = strlen(str), len_sym = strlen(sym);
	for (int i = 0; i < len_str; i++)
	{
		for (int j = 0; j < len_sym; j++)
		{
			if (str[i] == sym[j])
			{
				return (char *) &str[i];
			}
		}   
	}
	return NULL;
}

size_t my_strspn(const char *str, const char *sym)
{
	int len_str = strlen(str), len_sym = strlen(sym);
	size_t count = 0;
	for (int i = 0; i < len_str; i++)
	{
		int flag = 0;
		for (int j = 0; j < len_sym; j++)
		{
			if (str[i] == sym[j])
			{
				flag = 1;
				count++;
				break;
			}
		}   
		if (flag == 0)
		{
			return count;
		}
	}
    return count;
}

size_t my_strcspn(const char *str, const char *sym)
{
	int len_str = strlen(str), len_sym = strlen(sym);
	size_t count = 0;
	for (int i = 0; i < len_str; i++)
	{
		int flag = 0;
		for (int j = 0; j < len_sym; j++)
		{
			if (str[i] == sym[j])
			{
				flag = 1;
				break;
			}
		}   
		if (flag == 1)
		{
			return count;
		}
		count++;	
	}
    return count;
}

const char *my_strchr(const char *str, int ch)
{
	int len_str = strlen(str);
	int i = 0;
	for (i = 0; i < len_str; i++)
	{
		if (str[i] == ch)
		{
			return &str[i];
		}
	}
	if (ch == '\0')
	{
		return &str[i];
	}
	return NULL;
}

const char *my_strrchr(const char *str, int ch)
{
	int len_str = strlen(str);
	for (int i = len_str; i > -1; i--)
	{
		if (str[i] == ch)
		{
			return &str[i];
		}
	}
	if (str[0] == ch)
		return &str[0];
	return NULL;
}