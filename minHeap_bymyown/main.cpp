#include <iostream>

using namespace std;

struct binaryTreeNode {
    int value;
    binaryTreeNode* left;
    binaryTreeNode* right;
};

struct binaryTreeNode * temp = NULL;

binaryTreeNode* add(binaryTreeNode* root, int value) {
    if(root == NULL) {
        root = new binaryTreeNode{value};
    } else {
        if(value < root->value) {
            root->left = add(root->left, value);
        } else if (value > root->value) {
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

int maximum(binaryTreeNode* root) {
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
        int dLeft = deep(root->left);
        int dRight = deep(root->right);
        if(dLeft > dRight) {
            return dLeft + 1;
        } else {
            return dRight + 1;
        }
    }
}

int numberOfNodes(binaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    } else {
        return numberOfNodes(root->left) + 1 + numberOfNodes(root->right);
    }
}

int heightOfNode(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return -1;
    }
    if(wantedValue == root->value) {
        return deep(root);
    }
    if(wantedValue < root->value) {
        return heightOfNode(root->left, wantedValue);
    } else if(wantedValue > root->value) {
        return heightOfNode(root->right, wantedValue);
    }
}

binaryTreeNode* deleteNode(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        cout<<"Value to delete not found.\n";
        return NULL;
    }
    if(root->value == wantedValue) {
        delete root;
        root = NULL;
        return root;
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

void addElements(binaryTreeNode* root, int* array, int& index) {
    if(root == NULL) return;
    addElements(root->left, array, index);
    array[index++] = root->value;
    addElements(root->right, array, index);
}

void heapify(int array[], int size, int num) {
    int min = num;
    int left = 2*num + 1;
    int right = 2*num + 2;

    if(left < size && array[left] < array[min]) {
        min = left;
    }
    if(right < size && array[right] < array[min]) {
        min = right;
    }

    if(min != num) {
        swap(array[num], array[min]);
        heapify(array, size, min);
    }
}

void buildMinHeap(int array[], int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }
}

void binaryToMinHeap(binaryTreeNode* root) {
    int size = numberOfNodes(root);
    int* elements = new int[size];
    int index = 0;

    addElements(root, elements, index);
    buildMinHeap(elements, size);

    cout<<"Min heap:\n";
    for(int i = 0; i < size; i++) {
        cout<<elements[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    binaryTreeNode* root = NULL;
    root = add(root, 14);
    root = add(root, 82);
    root = add(root, 20);
    root = add(root, 78);
    root = add(root, 27);
    root = add(root, 2);
    root = add(root, 52);

    binaryToMinHeap(root);
    return 0;
}
