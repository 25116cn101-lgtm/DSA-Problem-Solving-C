#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *p = head;

    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        head = n;
        return;
    }

    while (p->next != NULL)
        p = p->next;

    p->next = n;
}

void insertPos(int x, int pos) {
    struct Node *p = head;
    int i;

    if (pos < 1) return;
    if (pos == 1) {
        insertBeg(x);
        return;
    }

    for (i = 1; p != NULL && i < pos - 1; i++)
        p = p->next;

    if (p == NULL) return;

    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = p->next;
    p->next = n;
}

void deleteBeg(void) {
    if (head == NULL) return;

    struct Node *p = head;
    head = head->next;
    free(p);
}

void deleteEnd(void) {
    struct Node *p = head;

    if (p == NULL) return;

    if (p->next == NULL) {
        free(p);
        head = NULL;
        return;
    }

    while (p->next->next != NULL)
        p = p->next;

    free(p->next);
    p->next = NULL;
}

void deletePos(int pos) {
    struct Node *p = head;
    int i;

    if (pos < 1 || head == NULL) return;
    if (pos == 1) {
        deleteBeg();
        return;
    }

    for (i = 1; p->next != NULL && i < pos - 1; i++)
        p = p->next;

    if (p->next == NULL) return;

    struct Node *temp = p->next;
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
        printf("\n1.Insert Beginning  2.Insert End");
        printf("\n3.Insert Position  4.Delete Beginning");
        printf("\n5.Delete End  6.Delete Position");
        printf("\n7.Reverse  8.Display  0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                insertBeg(x);
                break;
            case 2:
                scanf("%d", &x);
                insertEnd(x);
                break;
            case 3:
                scanf("%d%d", &x, &pos);
                insertPos(x, pos);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 7:
                reverse();
                break;
            case 8:
                display();
                break;
        }
    } while (ch != 0);

    return 0;
}
