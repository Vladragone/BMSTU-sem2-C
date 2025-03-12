#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "operation.h"
#include "inout.h"

int main(void) {
    int size = count_lines();
    if (size == -1) {
        return 1;
    }
    
    struct Contact contacts[size];
    int num_contacts;
    
    int rc = read_contacts(contacts, &num_contacts);
    if (rc == -1) {
        return -1;
    }
    
    printf("Write 3 numbers: ");
    rc = print_contacts(num_contacts, contacts);
	if (rc == 0)
	{
		printf("No numbers with this start");
		return 1;
	}
    return 0;
}
