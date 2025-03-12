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
	if (word_count == 0)
	{
		return -1;
	}
	return word_count;
}

void out(char final_words[512][16], int count)
{
	printf("Result: ");
	for (int i = 0; i < count; i++)
	{
		printf("%s ", final_words[i]);
	}
}