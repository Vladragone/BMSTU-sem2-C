#include <stdio.h>

int get_number_by_pos(FILE *file, int pos)
{
	int elem;
	fseek(file, pos * sizeof(int), SEEK_SET);
	fread(&elem, sizeof(int), 1, file);
	fclose(file);
	return elem;
}

void put_number_by_pos(FILE *file, int pos, int elem)
{
	fseek(file, pos * sizeof(int), SEEK_SET);
	fwrite(&elem, sizeof(int), 1, file);
}

void sort_numbers(FILE *file, int elems_num)
{
	int swapped;
	do
	{
		swapped = 0;
		for (int i = 0; i < elems_num - 1; i++)
		{
			int cur_num = 0, next_num = 0;
			fseek(file, i * sizeof(int), SEEK_SET);
			fread(&cur_num, sizeof(int), 1, file);
			fseek(file, (i + 1) * sizeof(int), SEEK_SET);
			fread(&next_num, sizeof(int), 1, file);
			if (cur_num > next_num)
			{
				put_number_by_pos(file, i, next_num);
				put_number_by_pos(file, i + 1, cur_num);
				swapped = 1;
			}
		}
	}
	while (swapped);
}

