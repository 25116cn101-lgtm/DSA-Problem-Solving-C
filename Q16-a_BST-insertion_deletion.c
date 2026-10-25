#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node *n = malloc(sizeof(struct Node));

    if (n == NULL) exit(1);

    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node *root, int x) {
    if (root == NULL) return newNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

struct Node* search(struct Node *root, int x) {
    if (root == NULL || root->data == x)
        return root;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

struct Node* minimum(struct Node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node *root, int x) {
    struct Node *temp;

    if (root == NULL) return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minimum(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    struct Node *root = NULL;
    int ch, x;

    do {
        printf("\n1.Insert 2.Search 3.Delete 4.Display 0.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                printf("%s\n", search(root, x) ?
                       "Found" : "Not Found");
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 4:
                inorder(root);
                printf("\n");
                break;
        }
    } while (ch != 0);

    return 0;
}
