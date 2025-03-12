#include <stdio.h>
#include <math.h>

void reverse(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            int temp = arr[i];
            int reversed = 0;
            while (temp > 0)
            {
                reversed = (reversed * 10) + (temp % 10);
                temp /= 10;
            }
            for (int j = size - 1; j > i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i + 1] = reversed;
            i++;
            size++;
        }
    }
}
int main(void)
{
    int plus = 0, a[20], rc, n;
    printf("Write size:\n ");
    rc = scanf("%d", &n);
    if ((rc != 1) || (n <= 0) || (n > 10))
    {
        printf("Input error!");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Write next elem: ");
        rc = scanf("%d", &a[i]);
        if (rc != 1)
        {
            printf("Input error!");
            return 1;
        }
        if (a[i] > 0)
        {
            plus++;
        }
    }
    reverse(a, n);
    n = n + plus;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}