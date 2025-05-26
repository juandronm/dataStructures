#include <iostream>

using namespace std;

struct node {
    int number;
    node* left;
    node* right;
};

struct node * temp = NULL;

node* insert(node*& root, int n) {
    if(root == NULL) {
        root = new node{n};
    } else if (n < root->number) {
        root->left = insert(root->left, n);
    } else if (n > root->number) {
        root->right = insert(root->right, n);
    }
    return root;
}

node* findMin(node* root) {
    if(root == NULL) return NULL;
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* deleteValues(node*& root, int n) {
    if(root == NULL) return root;
    if(n < root->number) {
        root->left = deleteValues(root->left, n);
    } else if(n > root->number) {
        root->right = deleteValues(root->right, n);
    } else {
        if(root->right == NULL) {
            temp = root->left;
            delete root;
            return temp;
        } else if(root->left == NULL) {
            temp = root->right;
            delete root;
            return temp;
        } else {
            temp = findMin(root->right);
            root->number = temp->number;
            root->right = deleteValues(root->right, temp->number);
        }
    }
    return root;
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->number<<" ";
        inorder(root->right);
    }
}

void preorder(node* root) {
    if(root != NULL) {
        cout<<root->number<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->number<<" ";
    }
}

int nodeNumber(node* root) {
    if(root == NULL) {
        return 0;
    } else {
        return nodeNumber(root->left) + nodeNumber(root->right) + 1;
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 98);
    root = insert(root, 2);
    root = insert(root, 48);
    root = insert(root, 12);
    root = insert(root, 56);
    root = insert(root, 32);
    root = insert(root, 4);
    root = insert(root, 67);
    root = insert(root, 23);
    root = insert(root, 87);
    root = insert(root, 23);
    root = insert(root, 55);
    root = insert(root, 46);
    inorder(root);
    cout<<"\n";

    root = insert(root, 21);
    root = insert(root, 39);
    root = insert(root, 45);
    root = insert(root, 54);
    root = insert(root, 63);
    inorder(root);
    cout<<"\n";

    root = deleteValues(root, 23);
    root = deleteValues(root, 56);
    root = deleteValues(root, 2);
    root = deleteValues(root, 45);
    inorder(root);
    cout<<"\n";
    cout<<"----------\n";

    cout<<"New Binary Search Tree:\n";
    node* bst = NULL;
    bst = insert(bst, 45);
    bst = insert(bst, 39);
    bst = insert(bst, 56);
    bst = insert(bst, 12);
    bst = insert(bst, 54);
    bst = insert(bst, 78);
    bst = insert(bst, 10);
    bst = insert(bst, 34);
    bst = insert(bst, 67);
    bst = insert(bst, 89);
    bst = insert(bst, 32);
    bst = insert(bst, 81);
    cout<<"Inorder: ";
    inorder(bst);
    cout<<"\nPreorder: ";
    preorder(bst);
    cout<<"\nPostorder: ";
    postorder(bst);
    cout<<"\nNode number: "<<nodeNumber(bst);

    return 0;
}
