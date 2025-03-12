#include <stdio.h>
#include "operation.h"
#include "inout.h"

int main()
{
	int matrix[10][10], n, m, rc;
	printf("Write sizes: ");
	rc = scanf("%d %d", &n, &m);
	if ((rc != 2) || (n != m) || (n > 10) || (n <= 0))
	{
		printf("Input error!");
		return 1;
	}
	change_matrix(matrix, n);
	matrix_out(matrix, n);
	return 0;
}
