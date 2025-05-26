#include <iostream>

using namespace std;

struct binaryTreeNode {
    int number;
    binaryTreeNode* left;
    binaryTreeNode* right;
};

struct binaryTreeNode * temp = NULL;

binaryTreeNode* addNode(binaryTreeNode* root, int number) {
    if(root == NULL) {
        root = new binaryTreeNode{number};
    } else {
        if(number < root->number) {
            root->left = addNode(root->left, number);
        } else if (number > root->number) {
            root->right = addNode(root->right, number);
        }
    }
    return root;
}

int minimum(binaryTreeNode* root) {
    if(root->left == NULL) {
        return root->number;
    } else {
        return minimum(root->left);
    }
}

int maximum(binaryTreeNode* root) {
    if(root->right == NULL) {
        return root->number;
    } else {
        return maximum(root->right);
    }
}

int sizeOfTree(binaryTreeNode* root) {
    if(root == NULL) {
        return 0;
    } else {
        return sizeOfTree(root->left) + 1 + sizeOfTree(root->right);
    }
}

binaryTreeNode* deleteNode(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return NULL;
    }
    if(wantedValue == root->number) {
        delete root;
        root = NULL;
        return root;
    }

    if(wantedValue < root->number) {
        root->left = deleteNode(root->left, wantedValue);
    } else if (wantedValue > root->number) {
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
        root->number = vl;
        root->right = deleteNode(root->right, vl);
    }
    return root;
}

void passElements(binaryTreeNode* root, int* array, int& index) {
    if(root == NULL) return;
    passElements(root->left, array, index);
    array[index++] = root->number;
    passElements(root->right, array, index);
}

void heapify(int array[], int size, int num) {
    int largest = num;
    int left = 2*num + 1;
    int right = 2*num + 2;

    if(left < size && array[left] > array[largest]) {
        largest = left;
    }
    if(right < size && array[right] > array[largest]) {
        largest = right;
    }

    if(largest != num) {
        swap(array[num], array[largest]);
        heapify(array, size, largest);
    }
}

void buildMaxHeap(int elements[], int size) {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(elements, size, i);
    }
}
void binaryToHeap(binaryTreeNode* root) {
    int size = sizeOfTree(root);
    int* elements = new int[size];
    int index = 0;

    passElements(root, elements, index);

    buildMaxHeap(elements, size);

    cout<<"\nMax heap:\n";
    for(int i = 0; i < size; i++) {
        cout<<elements[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    binaryTreeNode* root = NULL;
    root = addNode(root, 5);
    root = addNode(root, 8);
    root = addNode(root, 1);
    root = addNode(root, 85);
    root = addNode(root, 2);
    root = addNode(root, 3);
    root = addNode(root, 4);
    root = addNode(root, 963);

    binaryToHeap(root);

    return 0;
}
