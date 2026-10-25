#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void insert(int x, int pos) {
    struct Node *n, *p;
    int i;

    if (pos < 1)
        return;

    n = malloc(sizeof(struct Node));
    if (n == NULL)
        return;

    n->data = x;
    n->prev = n->next = NULL;

    if (pos == 1) {
        n->next = head;

        if (head != NULL)
            head->prev = n;

        head = n;
        return;
    }

    p = head;

    for (i = 1; p != NULL && i < pos - 1; i++)
        p = p->next;

    if (p == NULL) {
        free(n);
        printf("Invalid position\n");
        return;
    }

    n->next = p->next;
    n->prev = p;

    if (p->next != NULL)
        p->next->prev = n;

    p->next = n;
}

void deleteNode(int pos) {
    struct Node *p = head;
    int i;

    if (pos < 1)
        return;

    for (i = 1; p != NULL && i < pos; i++)
        p = p->next;

    if (p == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (p->prev != NULL)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next != NULL)
        p->next->prev = p->prev;

    free(p);
}

void display(void) {
    struct Node *p = head;

    while (p != NULL) {
        printf("%d <-> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
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

        if (ch == 1 || ch == 2 || ch == 3) {
            printf("Enter value: ");
            scanf("%d", &x);

            if (ch == 1)
                pos = 1;
            else if (ch == 2) {
                pos = 1;
                struct Node *p = head;
                while (p != NULL) {
                    pos++;
                    p = p->next;
                }
            } else {
                printf("Enter position: ");
                scanf("%d", &pos);
            }

            insert(x, pos);
        } else if (ch == 4 || ch == 5 || ch == 6) {
            if (ch == 4)
                pos = 1;
            else if (ch == 5) {
                pos = 0;
                struct Node *p = head;
                while (p != NULL) {
                    pos++;
                    p = p->next;
                }
            } else {
                printf("Enter position: ");
                scanf("%d", &pos);
            }

            deleteNode(pos);
        } else if (ch == 7) {
            display();
        }
    } while (ch != 0);

    return 0;
}
