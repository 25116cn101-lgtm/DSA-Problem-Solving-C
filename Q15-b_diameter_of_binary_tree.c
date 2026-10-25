struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int diameterHeight(struct TreeNode *root, int *diameter) {
    int left, right;

    if (root == NULL)
        return 0;

    left = diameterHeight(root->left, diameter);
    right = diameterHeight(root->right, diameter);

    *diameter = max(*diameter, left + right);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter = 0;

    diameterHeight(root, &diameter);

    return diameter;
}
