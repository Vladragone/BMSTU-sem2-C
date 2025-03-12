#ifndef INOUT_H
#define INOUT_H

struct Contact {
    char name[52];
    char phone[52];
};
int read_contacts(struct Contact contacts[], int *num_contacts);
int print_contacts(int num_contacts, struct Contact contacts[]);

#endif