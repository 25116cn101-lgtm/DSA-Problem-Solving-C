#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *last = NULL;

int length(void) {
    int n = 0;
    struct Node *p;

    if (last == NULL)
        return 0;

    p = last->next;

    do {
        n++;
        p = p->next;
    } while (p != last->next);

    return n;
}

void insert(int x, int pos) {
    struct Node *n, *p;
    int i, len = length();

    if (pos < 1 || pos > len + 1) {
        printf("Invalid position\n");
        return;
    }

    n = malloc(sizeof(struct Node));
    if (n == NULL)
        return;

    n->data = x;

    if (last == NULL) {
        n->next = n;
        last = n;
        return;
    }

    if (pos == 1) {
        n->next = last->next;
        last->next = n;
        return;
    }

    p = last->next;

    for (i = 1; i < pos - 1; i++)
        p = p->next;

    n->next = p->next;
    p->next = n;

    if (p == last)
        last = n;
}

void deleteNode(int pos) {
    struct Node *p, *temp;
    int i, len = length();

    if (pos < 1 || pos > len) {
        printf("Invalid position\n");
        return;
    }

    p = last->next;

    if (len == 1) {
        free(last);
        last = NULL;
        return;
    }

    if (pos == 1) {
        temp = last->next;
        last->next = temp->next;
        free(temp);
        return;
    }

    for (i = 1; i < pos - 1; i++)
        p = p->next;

    temp = p->next;
    p->next = temp->next;

    if (temp == last)
        last = p;

    free(temp);
}

void display(void) {
    struct Node *p;

    if (last == NULL) {
        printf("Empty list\n");
        return;
    }

    p = last->next;

    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);

    printf("(back to head)\n");
}

int main(void) {
    int ch, x, pos;

    do {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Insert Position");
        printf("\n4.Delete Beginning");
        printf("\n5.Delete End");
        printf("\n6.Delete Position");
        printf("\n7.Display");
        printf("\n0.Exit\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x, 1);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insert(x, length() + 1);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &x, &pos);
                insert(x, pos);
                break;

            case 4:
                deleteNode(1);
                break;

            case 5:
                deleteNode(length());
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteNode(pos);
                break;

            case 7:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
