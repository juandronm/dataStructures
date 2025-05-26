#include <iostream>

using namespace std;

struct node {
    int value;
    node * left;
    node * right;
};

node* insert(node*& root, int number) {
    if(root == NULL) {
        root = new node{number};
    } else if(number > root->value) {
        root->right = insert(root->right, number);
    } else if (number < root->value) {
        root->left = insert(root->left, number);
    }
    return root;
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    }
}

bool search(node* root, int value) {
    if(root == NULL) return false;
    if(root->value == value) return true;
    if(value < root->value) return search(root->left, value);
    if(value > root->value) return search(root->right, value);
}

int height(node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int totalNodes(node* root) {
    if(root == NULL) {
        return 0;
    } else {
        return totalNodes(root->left) + totalNodes(root->right) + 1;
    }
}

int totalInternalNodes(node* root) {
    if(root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 0;
    } else {
        return totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1;
    }
}

int totalExternalNodes(node* root) {
    if(root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return totalExternalNodes(root->left) + totalExternalNodes(root->right);
    }
}

int smallestElement(node* root) {
    if(root == NULL) {
        cout<<"Tree empty.\n";
        return -1;
    } else if(root -> left == NULL){
        return root->value;
    } else {
        return smallestElement(root->left);
    }
}

int largestElement(node* root) {
    if(root == NULL) {
        cout<<"Tree empty.\n";
        return -1;
    } else if(root ->right == NULL) {
        return root->value;
    } else {
        return largestElement(root->right);
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 45);
    root = insert(root, 39);
    root = insert(root, 56);
    root = insert(root, 12);
    root = insert(root, 34);
    root = insert(root, 78);
    root = insert(root, 32);
    root = insert(root, 10);
    root = insert(root, 89);
    root = insert(root, 54);
    root = insert(root, 67);
    root = insert(root, 81);

    inorder(root);
    cout<<"\n";
    cout<<search(root, 13)<<"\n";
    cout<<search(root, 78)<<"\n";
    cout<<"Height: "<<height(root)<<"\n";
    cout<<"Total nodes: "<<totalNodes(root)<<"\n";
    cout<<"Internal nodes: "<<totalInternalNodes(root)<<"\n";
    cout<<"External nodes: "<<totalExternalNodes(root)<<"\n";
    cout<<"Smallest element: "<<smallestElement(root)<<"\n";
    cout<<"Largest element: "<<largestElement(root)<<"\n";
    return 0;
}
