#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Contact {
    char name[52];
    char phone[52];
};
int read_contacts(struct Contact contacts[], int *num_contacts) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        return -1;
    }
    
    *num_contacts = 0;
    while (fscanf(file, "%51s %51s", contacts[*num_contacts].name, contacts[*num_contacts].phone) == 2) {
        if (strlen(contacts[*num_contacts].name) > 50 || strlen(contacts[*num_contacts].phone) > 50) {
            printf("Very huge string");
            fclose(file);
            return -1;
        }
	for (size_t i = 0; i < strlen(contacts[*num_contacts].phone); i++) {
            if (!isdigit(contacts[*num_contacts].phone[i])) {
                printf("Invalid phone number\n");
                fclose(file);
                return -1;
            }
        }
        (*num_contacts)++;
    }
    
    fclose(file);
    return 0;
}

int print_contacts(int num_contacts, struct Contact contacts[])
{
	int a, b, c;
    int rc = scanf("%d %d %d", &a, &b, &c);
    if (rc != 3) {
        printf("Incorrect arguments\n");
        return 0;
    }
	int count = 0;
	char reg[4];
    reg[0] = '0' + a;
    reg[1] = '0' + b;
    reg[2] = '0' + c;
    reg[3] = '\0';
    
    for (int i = 0; i < num_contacts; i++) {
        if (strncmp(contacts[i].phone, reg, strlen(reg)) == 0) {
			count++;
            printf("%s\n", contacts[i].name);
        }
    }
	return count;
}
    