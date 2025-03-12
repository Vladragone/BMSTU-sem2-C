#include <stdio.h>
#include <string.h>

int find_dif(char words1[256][16], char words2[256][16], char final_words[512][16], int word_count1, int word_count2)
{
	int count_find = 0, flag = 0;
	for (int i = 0; i < word_count1; i++)
	{
		char cur_word[256];
		strcpy(cur_word, words1[i]);
		flag = 1;
		for (int j = 0; j < word_count1; j++)
		{
			if (strcmp(cur_word, words1[j]) == 0 && i != j)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			continue;
		}
		for (int j = 0; j < word_count2; j++)
		{
			if (strcmp(cur_word, words2[j]) == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			strcpy(final_words[count_find], cur_word);
			count_find++;
		}
	}
	for (int i = 0; i < word_count2; i++)
	{
		char cur_word[256];
		strcpy(cur_word, words2[i]);
		flag = 1;
		for (int j = 0; j < word_count2; j++)
		{
			if (strcmp(cur_word, words2[j]) == 0 && i != j)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			continue;
		}
		for (int j = 0; j < word_count1; j++)
		{
			if (strcmp(cur_word, words1[j]) == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			strcpy(final_words[count_find], cur_word);
			count_find++;
		}
	}	
	return count_find;
}