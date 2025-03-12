#include <stdio.h>
#include <string.h>

int create_new_str(char words[256][16], char result_str[256][16], int count_word)
{
	int count = 0;
	char *last_word = words[count_word - 1];
	for (int i = count_word - 2; i > -1; i--)
	{
		if (strcmp(last_word, words[i]) != 0)
		{
			strcpy(result_str[count], words[i]);
			count++;
		}
	}
	return count;
}

void delete_elems(char result_str[256][16], int count_res_str)
{
	for (int i = 0; i < count_res_str; i++)
	{
		if (strlen(result_str[i]) == 1)
		{
			continue;
		}
		char first = result_str[i][0];
		char temp[16];
		int temp_index = 0;
		for (size_t j = 0; j < strlen(result_str[i]); j++)
		{
			if (j == 0 || result_str[i][j] != first)
			{
				temp[temp_index++] = result_str[i][j];
			}
		}
		temp[temp_index] = '\0';
		strcpy(result_str[i], temp);
	}
}
			