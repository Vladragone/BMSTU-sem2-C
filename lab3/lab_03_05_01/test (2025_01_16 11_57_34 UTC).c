#include <stdio.h>
#include "operation.h"
#include "inout.h"

int main(void)
{
	int matrix[10][10], mas_i[100], mas_j[100], mas[100], n, m, rc, chet;
	printf("Write sizes: ");
	rc = scanf("%d %d", &n, &m);
	if ((rc != 2) || (n <= 0) || (m <= 0) || (n > 10) || (m > 10))
	{
		printf("Input error!");
		return 1;
	}
	rc = matrix_input(matrix, n, m);
	if (rc == 1)
	{
		printf("Input error!");
		return 1;
	}
	chet = change_matrix(matrix, n, m, mas, mas_i, mas_j);
	if (chet == 0)
	{
		printf("No numbers");
		return 1;
	}
	cycle(mas, chet);
	insert_into_matrix(matrix, mas_i, mas_j, mas, chet);
	matrix_out(matrix, n, m);
	return 0;
}