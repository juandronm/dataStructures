#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void append(Node** head_ref, int data) {
    Node* new_node = newNode(data);
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* temp = *head_ref;
    while(temp->next) {
        temp = temp->next;
    }
    temp -> next = new_node;
}

void yaz(Node* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

//To transform to BST
TreeNode* newTreeNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insertBinarySearched(TreeNode* root, int data) {
    if(root == NULL) {
        return newTreeNode(data);
    }
    if(data < root->data) {
        root->left = insertBinarySearched(root->left, data);
    } else {
        root->right = insertBinarySearched(root->right, data);
    }
    return root;
}

void inorder(TreeNode* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//To transform to Max Heap
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    Node* head = NULL;
    int values[] = {5, 3, 8, 1, 6, 9};
    int n = sizeof(values)/sizeof(values[0]);

    for(int i = 0; i < n; i++) {
        append(&head, values[i]);
    }

    printf("Linked list:\n");
    yaz(head);

    //BST
    TreeNode* bstroot = NULL;
    Node* temp = head;
    while(temp) {
        bstroot = insertBinarySearched(bstroot, temp->data);
        temp = temp->next;
    }

    printf("\nBST inorder:\n");
    inorder(bstroot);
    printf("\n");

    //Max Heap
    int heapArr[n];
    temp = head;
    for(int i = 0; i < n && temp; i++) {
        heapArr[i] = temp->data;
        temp = temp -> next;
    }
    buildMaxHeap(heapArr, n);
    printf("Max Heap:\n");
    printHeap(heapArr, n);

    return 0;
}
