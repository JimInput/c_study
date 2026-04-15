#include "list.h"

LINK string_to_list(char s[]) {
    LINK head;

    if (s[0] == '\0')
        return NULL;
    else {
        head = malloc(sizeof(ELEMENT));
        head -> d = s[0];
        head -> next = string_to_list(s + 1);
        return head;
    }
}

LINK string_to_list_iter(char *s) {
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

void print_list(LINK head) {
    while (head) {
        printf("%c", head->d);
        head = head->next;
    }
}

void free_list(LINK head) {
    while (head) {
        LINK next = head -> next;
        free(head);
        head = next;
    }
}

int main(void) {
    char *s = "Hello, World!\n";

    LINK head = string_to_list_iter(s);

    print_list(head);

    free_list(head);

    return 0;
}