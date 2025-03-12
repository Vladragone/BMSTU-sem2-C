#include <stdio.h>

int count_lines(void) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        return -1;
    }
    
    int count = 0;
    char name[52], phone[52];
    
    while (fscanf(file, "%51s %51s", name, phone) == 2) {
        count++;
    }
    
    fclose(file);
    return count;
}