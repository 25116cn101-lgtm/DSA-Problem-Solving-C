#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int findMax(struct Node *root) {
    int result, leftMax, rightMax;

    if (root == NULL)
        return INT_MIN;

    result = root->data;
    leftMax = findMax(root->left);
    rightMax = findMax(root->right);

    if (leftMax > result)
        result = leftMax;

    if (rightMax > result)
        result = rightMax;

    return result;
}
