#include <stdio.h>
#include <string.h>

int in(char *str, char words[256][16])
{
	int word_count = 0, word_length = 0, i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '-' || str[i] == '.' || str[i] == '!' || str[i] == '?' || str[i] == '\n' || str[i] == '\r')
		{
			if (word_length > 0)
			{
				words[word_count][word_length] = '\0';
				word_count++;
				word_length = 0;
			}
		}
		else
		{
			words[word_count][word_length] = str[i];
			word_length++;
			if (word_length > 16)
			{
				return -1;
			}
		}
		i++;
	}
	if (word_length > 0)
	{
		words[word_count][word_length] = '\0';
		word_count++;
	}
	if (word_count < 2)
	{
		return -1;
	}
	return word_count;
}

void print(char result_str[256][16], int count_res_str)
{
	char str[258];
	str[0] = '\0';
	strcat(str, "");
	for (int i = 0; i < count_res_str - 1; i++)
	{
		strcat(str, result_str[i]);
		strcat(str, " ");
	}
	strcat(str, result_str[count_res_str - 1]);
	printf("Result: %s\n", str);
}