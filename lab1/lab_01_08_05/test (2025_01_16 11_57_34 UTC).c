#include <stdio.h>

int main()
{
    unsigned int num, enc_num = 0;
    int i, rc;
    rc = scanf("%u", &num);
	if (sizeof(num) != 4)
	{
		printf("Error:not 4 bytes");
		return 1;
	}
	if (rc != 1)
	{
		printf("Error:incorrect input");
		return 1;
	}
    for (i = 0; i < 32; i += 2)
	{
        unsigned int even_mask = 1 << i;
        unsigned int odd_mask = 1 << (i + 1);
        unsigned int even_bit = num & even_mask;
        unsigned int odd_bit = num & odd_mask;
        enc_num |= even_bit << 1;
        enc_num |= odd_bit >> 1;
    }
    printf("Result:");
	for(int i = 31; i >= 0; i--)
	{
        if ((enc_num >> i) & 1)
		{
            printf("1");
		}
        else
		{
            printf("0");
		}
    }
	while (1 == 1)
	{
		rc = 1;
	}
    return 0;
}