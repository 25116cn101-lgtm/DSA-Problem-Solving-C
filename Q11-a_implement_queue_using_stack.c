#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int in[MAX], out[MAX];
    int topIn, topOut;
} MyQueue;

MyQueue* myQueueCreate(void) {
    MyQueue *q = malloc(sizeof(MyQueue));

    if (q == NULL)
        return NULL;

    q->topIn = q->topOut = -1;
    return q;
}

void transfer(MyQueue *q) {
    while (q->topIn != -1)
        q->out[++q->topOut] = q->in[q->topIn--];
}

void myQueuePush(MyQueue *q, int x) {
    if (q->topIn < MAX - 1)
        q->in[++q->topIn] = x;
}

int myQueuePop(MyQueue *q) {
    if (q->topOut == -1)
        transfer(q);

    if (q->topOut == -1)
        return -1;

    return q->out[q->topOut--];
}

int myQueuePeek(MyQueue *q) {
    if (q->topOut == -1)
        transfer(q);

    if (q->topOut == -1)
        return -1;

    return q->out[q->topOut];
}

int myQueueEmpty(MyQueue *q) {
    return q->topIn == -1 && q->topOut == -1;
}

void myQueueFree(MyQueue *q) {
    free(q);
}

int main(void) {
    MyQueue *q = myQueueCreate();

    if (q == NULL)
        return 1;

    myQueuePush(q, 10);
    myQueuePush(q, 20);
    myQueuePush(q, 30);

    printf("Front: %d\n", myQueuePeek(q));
    printf("Removed: %d\n", myQueuePop(q));
    printf("Front: %d\n", myQueuePeek(q));
    printf("Empty: %d\n", myQueueEmpty(q));

    myQueueFree(q);
    return 0;
}
