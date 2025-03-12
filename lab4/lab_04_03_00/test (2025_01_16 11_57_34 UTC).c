#include <stdio.h>
#include "operation.h"
#include <string.h>
#include "inout.h"

int main() {
    char str[258] = "", words[256][16], result_str[256][16];
    fgets(str, 258, stdin);
	if (str[256] != '\0')
	{
		return 1;
	}
	if (str[strlen(str)] == '\n')
	{
		str[strlen(str)] = '\0';
	}
	int count_word = in(str, words);
	if (count_word == -1)
	{
		return 1;
	}
	int count_res_str = create_new_str(words, result_str, count_word);
	if (count_res_str == 0)
	{
		return 1;
	}
	delete_elems(result_str, count_res_str);
	print(result_str, count_res_str);
	return 0;
}