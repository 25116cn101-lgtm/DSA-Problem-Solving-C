#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
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

    if (pos == 1) {
        n->next = head;
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
    p->next = n;
}

void deleteNode(int pos) {
    struct Node *p, *temp;
    int i;

    if (pos < 1 || head == NULL)
        return;

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    p = head;

    for (i = 1; p->next != NULL && i < pos - 1; i++)
        p = p->next;

    if (p->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp = p->next;
    p->next = temp->next;
    free(temp);
}

void reverse(void) {
    struct Node *prev = NULL;
    struct Node *cur = head, *next;

    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

void display(void) {
    struct Node *p = head;

    while (p != NULL) {
        printf("%d -> ", p->data);
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
        printf("\n8.Reverse");
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
                pos = 1;
                {
                    struct Node *p = head;
                    while (p != NULL) {
                        pos++;
                        p = p->next;
                    }
                }
                insert(x, pos);
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
                pos = 1;
                {
                    struct Node *p = head;
                    while (p != NULL) {
                        pos++;
                        p = p->next;
                    }
                }
                deleteNode(pos - 1);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteNode(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                reverse();
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
