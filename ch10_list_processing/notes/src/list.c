#include "list.h"

int main(void) {
    LINK head = string_to_list("Hello, fuckwad!\n");
    print_list(head);
    printf("%d\n", count(head));
    free_list(head);
    return 0;
}

LINK string_to_list(char s[]) {
    LINK head = NULL, tail;
    int i;
    
    if (s[0] != '\0') {
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];
        tail = head;
        for (i = 1; s[i] != '\0'; ++i) {
            tail -> next = malloc(sizeof(ELEMENT));
            tail = tail -> next;
            tail -> d = s[i];
        }
        tail -> next = NULL;
    }
    return head;
}

int count(LINK head) {
    if (head == NULL)  
        return 0;
    return (1 + count(head->next));
}

void print_list(LINK head) {
    while (head) {
        printf("%c", head->d);
        head = head -> next;
    }
}

void free_list(LINK head) {
    while (head) {
        LINK next = head -> next;
        free(head);
        head = next;
    }
}
