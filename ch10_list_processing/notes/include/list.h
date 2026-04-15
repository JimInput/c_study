#ifndef __LIST__
#define __LIST__

#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct linked_list {
    DATA d;
    struct linked_list *next;
};

typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

LINK string_to_list(char s[]);
int count(LINK head);
void print_list(LINK head);
void free_list(LINK head);


#endif
