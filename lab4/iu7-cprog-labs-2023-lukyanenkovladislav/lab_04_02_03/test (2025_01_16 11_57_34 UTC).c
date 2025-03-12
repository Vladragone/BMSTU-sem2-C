#include <stdio.h>
#include "inout.h"
#include "operation.h"
#include <string.h>

int main()
{
	char str1[258] = "", words1[256][16], str2[258] = "", words2[256][16], final_words[512][16];
	fgets(str1, 258, stdin);
	if (str1[256] != '\0')
	{
		return 1;
	}
	fgets(str2, 258, stdin);
	if (str2[256] != '\0')
	{
		return 1;
	}
	if (str1[strlen(str1)] == '\n')
	{
		str1[strlen(str1)] = '\0';
	}
	if (str2[strlen(str2)] == '\n')
	{
		str2[strlen(str2)] = '\0';
	}
	int word_count1 = in(str1, words1);
	int word_count2 = in(str2, words2);
	if (word_count1 == -1 || word_count2 == -1)
	{
		return 1;
	}
	int count = find_dif(words1, words2, final_words, word_count1, word_count2);
	if (count == 0)
	{
		return 1;
	}
	out(final_words, count);
	return 0;
}