#include <iostream>

using namespace std;

struct binaryTreeNode {
    int value;
    binaryTreeNode * left;
    binaryTreeNode * right;
};

struct binaryTreeNode * temp = NULL;

binaryTreeNode* add(binaryTreeNode* root, int value) {
    if(!root) {
        root = new binaryTreeNode{value};
    } else {
        if(value < root->value) {
            root->left = add(root->left, value);
        } else if(value > root->value) {
            root->right = add(root->right, value);
        }
    }
    return root;
}

int minimum(binaryTreeNode* root) {
    if(root->left == NULL) {
        return root->value;
    } else {
        return minimum(root->left);
    }
}

int maximum(binaryTreeNode* root){
    if(root->right == NULL) {
        return root->value;
    } else {
        return maximum(root->right);
    }
}

int deep(binaryTreeNode* root) {
    if(root == NULL) {
        return -1;
    } else {
        int depthLeft = deep(root->left);
        int depthRight = deep(root->right);
        if(depthLeft > depthRight) {
            return depthLeft + 1;
        } else {
            return depthRight + 1;
        }
    }
}

int deepOfElement(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return -1;
    }
    if(root->value == wantedValue) {
        return 0;
    }
    else if(wantedValue < root->value) {
        return deepOfElement(root->left, wantedValue) + 1;
    } else if (wantedValue > root->value) {
        return deepOfElement(root->right, wantedValue) + 1;
    }
}

int heightOfElement(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return -1;
    }

    if(root->value == wantedValue) {
        return deep(root);
    }

    if(wantedValue < root->value) {
        return heightOfElement(root->left, wantedValue);
    } else if(wantedValue > root->value) {
        return heightOfElement(root->right, wantedValue);
    }
}

binaryTreeNode* deleteNode(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        cout<<"Value to delete not found.\n";
        return NULL;
    }
    if(root->value == wantedValue) {
        delete root;
        return NULL;
    }

    if(wantedValue < root->value) {
        root->left = deleteNode(root->left, wantedValue);
    } else if(wantedValue > root->value) {
        root->right = deleteNode(root->right, wantedValue);
    } else {
        if(!root->left) {
            temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right) {
            temp = root->left;
            delete root;
            return temp;
        }

        binaryTreeNode* succesor = root->right;
        int vl = minimum(succesor);
        root->value = vl;
        root->right = deleteNode(root->right, vl);
    }
    return root;
}

int numberOfNodes(binaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    } else {
        return numberOfNodes(root->left) + 1 + numberOfNodes(root->right);
    }
}

void collectValues(binaryTreeNode* root, int* arr, int& index) {
    if(root == NULL) return;
    collectValues(root->left, arr, index);
    arr[index++] = root->value;
    collectValues(root->right, arr, index);
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
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void binaryToMaxHeap(binaryTreeNode* root) {
    int size = numberOfNodes(root);
    int* elements = new int[size];
    int index = 0;

    collectValues(root, elements, index);

    buildMaxHeap(elements, size);

    for(int i = 0; i < size; i++) {
        cout<<elements[i]<<" ";
    }
}

int main() {
    binaryTreeNode* root = NULL;
    root = add(root, 5);
    root = add(root, 89);
    root = add(root, 78);
    root = add(root, 7);
    //root = add(root, 3);

    binaryToMaxHeap(root);
    return 0;
}
