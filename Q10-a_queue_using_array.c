#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    queue[++rear] = x;
}

void dequeue(void) {
    if (front > rear) {
        printf("Queue Underflow\n");
        front = 0;
        rear = -1;
        return;
    }

    printf("Deleted: %d\n", queue[front++]);

    if (front > rear) {
        front = 0;
        rear = -1;
    }
}

void peek(void) {
    if (rear == -1)
        printf("Queue is empty\n");
    else
        printf("Front: %d\n", queue[front]);
}

void display(void) {
    int i;

    if (rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main(void) {
    int ch, x;

    do {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
