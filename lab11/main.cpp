#include <iostream>

using namespace std;

struct node {
    int data;
    node * left;
    node * right;
};

struct node * temp = NULL;

void preorder(node* root) {
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(node* root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        cout<<root->data<<" ";
    }
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root -> left);
        cout<<root -> data<<" ";
        inorder(root -> right);
    }
}

void minimum(node* root) {
    if(root == NULL) return;
    temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    cout<<"Minimum value: "<<temp->data;
}

void maximum(node* root) {
    if(root == NULL) return;
    temp = root;
    while(temp -> right != NULL) {
        temp = temp -> right;
    }
    cout<<"Maximum value: "<<temp->data;
}

int main() {
    node* root = new node{10};
    root->left = new node{5};
    root->right = new node{20};
    root->left->left = new node{3};
    root->left->right = new node{7};
    root->right->right = new node{30};

    minimum(root);
    cout<<"\n";
    maximum(root);
    cout<<"\n";

    cout<<"Inorder: ";
    inorder(root);
    cout<<"\n";

    cout<<"Preorder: ";
    preorder(root);
    cout<<"\n";

    cout<<"Postorder: ";
    postorder(root);
    cout<<"\n";

    return 0;
}
