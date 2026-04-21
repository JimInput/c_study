#include "queue.h"

void initialize(queue *q) {
    q->cnt = 0;
    q->front = NULL;
    q->rear = NULL;
}

data dequeue(queue *q) {
    elem *p = q->front;
    data  d = p->d;
    q->front = p->next;
    q->cnt--;
    free(p);
    return d;
}

void enqueue(data d, queue *q) {
    elem *p = malloc(sizeof(elem));
    p->d = d;
    p->next = NULL;
    if (!empty(q)) {
        q->rear->next = p;
        q->rear = p;
    } else
        q->front = q->rear = p;
    q->cnt++;
}

data front(const queue *q) { return q->front->d; }

bool empty(const queue *q) { return q->cnt == EMPTY; }

bool full(const queue *q) { return q->cnt == FULL; }
