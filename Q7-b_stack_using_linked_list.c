#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *n = malloc(sizeof(struct Node));

    if (n == NULL)
        return;

    n->data = x;
    n->next = top;
    top = n;
}

void pop(void) {
    struct Node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Popped: %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek(void) {
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top: %d\n", top->data);
}

void display(void) {
    struct Node *p = top;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

int main(void) {
    int ch, x;

    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (ch != 0);

    while (top != NULL)
        pop();

    return 0;
}
