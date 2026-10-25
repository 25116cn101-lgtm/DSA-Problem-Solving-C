#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
}

void pop(void) {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

void peek(void) {
    if (top == -1)
        printf("Stack is empty\n");
    else
        printf("Top: %d\n", stack[top]);
}

void display(void) {
    int i;

    for (i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
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

    return 0;
}
