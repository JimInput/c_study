#include <stdio.h>
#include <stdbool.h>

#define MAX_LEN 100
#define EMPTY -1
#define FULL (MAX_LEN - 1)

typedef char data;

typedef struct deque {
    data d[MAX_LEN];
    int front, end;
} deque;

void reset(deque *q);
void add_to_front(deque *q, data d);
void add_to_rear(deque *q, data d);
data take_from_front(deque *q);
data take_from_rear(deque *q);
bool empty(const deque *q);
bool full(const deque *q);
void print_deque(const deque *q);

int main(void) {
    int i;
    data c = 'a';
    deque d;
    reset(&d);
    
    for (i = 0; i < 26; ++i) {
        add_to_front(&d, c++);
    }
    c = 'A';
    for (i = 0; i < 26; ++i) {
        add_to_rear(&d, c++);
    }

    print_deque(&d);

    return 0;
}

void reset(deque *q) {
    q->front = MAX_LEN / 2;
    q->end = MAX_LEN / 2 - 1;
}

void add_to_front(deque *q, data d) {
    q -> front--;
    q -> d[q -> front] = d;
}

void add_to_rear(deque *q, data d) {
    q -> end++;
    q -> d[q -> end] = d;
}

data take_from_front(deque *q) {
    return q -> d[q -> front++];
}

data take_from_rear(deque *q) {
    return q -> d[q -> end--];
}

bool empty(const deque *q) {
    return q->end - q->front == EMPTY;
}

bool full(const deque *q) {
    return q->front < 0 || q->end >= MAX_LEN;
}

void print_deque(const deque *q) {
    int front = q->front;
    while (front <= q->end) {
        printf("%c ", q->d[front]);
        front++;
    }
    printf("\n");
}
