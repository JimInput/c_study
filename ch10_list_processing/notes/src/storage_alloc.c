#include "list.h"

int main(void) {
    LINK head = malloc(sizeof(ELEMENT));
    head -> d = 'n';
    head -> next = malloc(sizeof(ELEMENT));
    head -> next -> d = 'e';
    head -> next -> next = malloc(sizeof(ELEMENT));
    head -> next -> next -> d = 'w';
    head -> next -> next -> next = NULL;

    printf("%ld\n", sizeof(ELEMENT));
    LINK head2 = head;

    while (head2) {
        printf("%c", head2->d);
        head2 = head2->next;
    }
    printf("\n");

    free(head->next->next);
    free(head->next);
    free(head);
    head = head2 = NULL;


}