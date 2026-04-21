#ifndef __QUEUE_H__
#define __QUEUE_H__

/* A linked list implementation of a queue. */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define FULL 10000

typedef unsigned int data;

typedef struct elem {
    data d;
    struct elem *next;
} elem;

typedef struct queue {
    int cnt;
    elem *front;
    elem *rear;
} queue;

void initialize(queue *q);
void enqueue(data d, queue *q);
data dequeue(queue *q);
data front(const queue *q);
bool empty(const queue *q);
bool full(const queue *q);

#endif