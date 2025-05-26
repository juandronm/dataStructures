#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void kLargest(TreeNode* root, int k, int* count, int* result) {
    if(root == NULL || *count >= k) {
        return;
    }

    kLargest(root->right, k, count, result);
    (*count)++;
    if(*count == k) {
        *result = root->val;
        return;
    }
    kLargest(root->left, k, count, result);
}

int kLarg(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    kLargest(root, k, &count, &result);
    return result;
}

void sumNum(TreeNode* root, int current, int* total) {
    if(root == NULL) {
        return;
    }
    current = current * 10 + root->val;
    if(root->left == NULL && root->right == NULL) {
        *total += current;
        return;
    }
    sumNum(root->left, current, total);
    sumNum(root->right, current, total);
}

int sum(TreeNode* root) {
    int totalSum = 0;
    sumNum(root, 0, &totalSum);
    return totalSum;
}
int main(void) {
    TreeNode* root = createNode(5);
    root -> left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(1);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    int k = 3;
    int result = kLarg(root, k);
    printf("%d'nin en buyuk: %d", k, result);
    int resultSum = sum(root);
    printf("\nSum of paths: %d", resultSum);
    return 0;
}
