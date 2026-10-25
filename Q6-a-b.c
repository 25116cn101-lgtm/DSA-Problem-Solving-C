#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, pow;
    struct Node *next;
};

struct Node *create(int n) {
    struct Node *head = NULL, *tail = NULL, *p;
    int i;

    for (i = 0; i < n; i++) {
        p = malloc(sizeof(struct Node));
        if (p == NULL)
            exit(1);

        printf("Enter coefficient and power: ");
        scanf("%d%d", &p->coeff, &p->pow);

        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    return head;
}

void append(struct Node **head, struct Node **tail,
            int coeff, int pow) {
    struct Node *n = malloc(sizeof(struct Node));

    if (n == NULL)
        exit(1);

    n->coeff = coeff;
    n->pow = pow;
    n->next = NULL;

    if (*head == NULL)
        *head = n;
    else
        (*tail)->next = n;

    *tail = n;
}

struct Node *add(struct Node *a, struct Node *b) {
    struct Node *head = NULL, *tail = NULL;
    int coeff, pow;

    while (a != NULL && b != NULL) {
        if (a->pow == b->pow) {
            coeff = a->coeff + b->coeff;
            pow = a->pow;
            a = a->next;
            b = b->next;
        } else if (a->pow > b->pow) {
            coeff = a->coeff;
            pow = a->pow;
            a = a->next;
        } else {
            coeff = b->coeff;
            pow = b->pow;
            b = b->next;
        }

        if (coeff != 0)
            append(&head, &tail, coeff, pow);
    }

    while (a != NULL) {
        append(&head, &tail, a->coeff, a->pow);
        a = a->next;
    }

    while (b != NULL) {
        append(&head, &tail, b->coeff, b->pow);
        b = b->next;
    }

    return head;
}

void display(struct Node *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }

    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->pow);
        p = p->next;

        if (p != NULL)
            printf(" + ");
    }

    printf("\n");
}

int main(void) {
    int n, m;
    struct Node *a, *b, *sum;

    printf("Enter terms in first polynomial: ");
    scanf("%d", &n);
    a = create(n);

    printf("Enter terms in second polynomial: ");
    scanf("%d", &m);
    b = create(m);

    sum = add(a, b);

    printf("First polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    printf("Sum: ");
    display(sum);

    return 0;
}
