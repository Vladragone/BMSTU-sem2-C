#include <stdio.h>
#include "operation.h"
#include "inout.h"

int main(void)
{
	int matrix[10][10], n, m, rc;
	printf("Write sizes: ");
	rc = scanf("%d %d", &n, &m);
	if ((rc != 2) || (n <= 0) || (n > 10) || (n != m))
	{
		printf("Input error!");
		return 1;
	}
	rc = matrix_input(matrix, n);
	if (rc == 1)
	{
		printf("Input error!");
		return 1;
	}
	change_matrix(matrix, n);
	matrix_out(matrix, n);
	return 0;
}