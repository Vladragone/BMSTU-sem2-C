#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define SUCCESS 0
#define ARGUMENT_ERROR 53
#define OPEN_ERROR 2
#define VALUE_ERROR 3
#define EMPTY_ERROR 4
#define SORT_ERROR 5

typedef struct product
{
	char name[32];
	char creator[17];
	unsigned int price;
	unsigned int amount;
} product;

int compare_products(const void *a, const void *b)
{
	const product *product_a = (const product *)a;
	const product *product_b = (const product *)b;
	if (product_a->price != product_b->price)
	{
		return product_b->price - product_a->price;
	}
	else
	{
		return product_b->amount - product_a->amount;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("Argument error");
		return ARGUMENT_ERROR;
	}
	char key[3];
	strcpy(key, argv[1]);
	if (strcmp(key, "st") != 0 && strcmp(key, "at") != 0)
	{
		printf("Argument error");
		return ARGUMENT_ERROR;
	}
	char *file_name = argv[2];
	FILE *file = fopen(file_name, "r");
	if (file == NULL)
	{
		printf("Open error");
		return OPEN_ERROR;
	}
	product products[1000];
	int count = 0;
	int rc;
	while (fgets(products[count].name, 32, file))
	{
		for (size_t i = 0; i < 32; i++)
		{
			if (products[count].name[i] == '\n')
			{
				products[count].name[i] = '\0';
				break;
			}
			if (products[count].name[i] == '\0')
			{
				printf("Str error");
				fclose(file);
				return VALUE_ERROR;
			}
		}
		fgets(products[count].creator, 17, file);
		for (size_t i = 0; i < 17; i++)
		{
			if (products[count].creator[i] == '\n')
			{
				products[count].creator[i] = '\0';
				break;
			}
			if (products[count].creator[i] == '\0')
			{
				printf("Str error");
				fclose(file);
				return VALUE_ERROR;
			}
		}
		rc = fscanf(file, "%u\n%u\n", &products[count].price, &products[count].amount);
		if (rc != 2)
		{
			fclose(file);
			return VALUE_ERROR;
		}
		count++;
	}
	fclose(file);
	if (strcmp(key, "st") == 0)
	{
		if (argc != 4)
		{
			printf("Argument error");
			return ARGUMENT_ERROR;
		}
		if (count == 0)
		{
			printf("Empty file");
			return EMPTY_ERROR;
		}
		char *file_name_write = argv[3];
		FILE *file_write = fopen(file_name_write, "w");
		if (file_write == NULL)
		{
			printf("Open error");
			return OPEN_ERROR;
		}
		qsort(products, count, sizeof(product), compare_products);
		for (int i = 0; i < count; i++)
		{
			fprintf(file_write, "%s\n%s\n%u\n%u\n", products[i].name, products[i].creator, products[i].price, products[i].amount);
		}
		fclose(file_write);
	}
	else if (strcmp(key, "at") == 0)
	{
		if (argc != 3)
		{
			printf("Argument error");
			return ARGUMENT_ERROR;
		}
		FILE *file = fopen(file_name, "w");
		if (file == NULL)
		{
			printf("Open error");
			return OPEN_ERROR;
		}
		product new;
		rc = scanf("%s", new.name);
		if (rc != 1 || strlen(new.name) > 30)
		{
			fclose(file);
			printf("Long names or not unsigned values");
			return VALUE_ERROR;
		}
		rc = scanf("%s", new.creator);
		if (rc != 1 || strlen(new.creator) > 15)
		{
			fclose(file);
			printf("Long names or not unsigned values");
			return VALUE_ERROR;
		}
		rc = scanf("%u", &new.price);
		if (rc != 1 || new.price == 0)
		{
			fclose(file);
			printf("Long names or not unsigned values");
			return VALUE_ERROR;
		}
		rc = scanf("%u", &new.amount);
		if (rc != 1 || new.amount == 0)
		{
			fclose(file);
			printf("Long names or not unsigned values");
			return VALUE_ERROR;
		}
		int in = count;
		unsigned int prev_price = products[0].price, prev_amount = products[0].amount;
		for (int i = 0; i < count; i++)
		{
			if (prev_price < products[i].price)
			{
				printf("Sort Error");
				fclose(file);
				return SORT_ERROR;
			}
			if (prev_price == products[i].price)
			{
				if (prev_amount < products[i].amount)
				{
					printf("Sort Error");
					fclose(file);
					return SORT_ERROR;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			if (products[i].price < new.price)
			{
				in = i;
				break;
			}
			if (products[i].price == new.price)
			{
				if (products[i].amount < new.amount)
				{
					in = i;
					break;
				}
			}
		}
		for (int i = count; i > in; i--)
		{
			products[i] = products[i - 1];
		}
		products[in] = new;
		count++;
		for (int i = 0; i < count; i++)
		{
			fprintf(file, "%s\n%s\n%u\n%u\n", products[i].name, products[i].creator, products[i].price, products[i].amount);
		}
		fclose(file);
	}
	else
	{
		printf("Argument error");
		return ARGUMENT_ERROR;
	}
	return SUCCESS;
}
