#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;
};

struct node * temp = NULL;

node* insert(node*& root, int number) {
    if (root == NULL) {
        root = new node{number};
    } else if (number < root->value) {
        root->left = insert(root->left, number);
    } else if(number > root->value) {
        root->right = insert(root->right, number);
    }
    return root;
}

node* findMin(node* root) {
    if(root == NULL) {
        cout<<"Tree is empty.\n";
        return NULL;
    } else {
        temp = root;
        while(temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }
}

node* findMax(node* root) {
    if(root == NULL) {
        cout<<"Tree is empty.\n";
        return NULL;
    } else {
        temp = root;
        while(temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }
}

node* deleteNode(node*& root, int number) {
    if(root == NULL) return root;
    if(number < root->value) {
        root->left = deleteNode(root->left, number);
    } else if(number > root->value) {
        root->right = deleteNode(root->right, number);
    } else {
        if(root->left == NULL){
            temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            delete root;
            return temp;
        } else {
            temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
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

int height(node* root) {
    if(root == NULL) {
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

void mirrorImage(node* root) {
    if(root != NULL) {
        mirrorImage(root->left);
        mirrorImage(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void deleteTree(node* root) {
    if(root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 13);
    root = insert(root, 17);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 14);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 11);
    root = insert(root, 18);

    inorder(root);
    cout<<"\n";
    root = deleteNode(root, 8);
    inorder(root);
    cout<<"\n";
    mirrorImage(root);
    cout<<"Mirror image (inorder traversal): ";
    inorder(root);
    return 0;
}
