#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *n = malloc(sizeof(struct Node));

    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    n->data = x;
    n->next = NULL;

    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

void dequeue(void) {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void peek(void) {
    if (front == NULL)
        printf("Queue is empty\n");
    else
        printf("Front: %d\n", front->data);
}

void display(void) {
    struct Node *p = front;

    if (p == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

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

    while (front != NULL)
        dequeue();

    return 0;
}
