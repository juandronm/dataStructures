#include <iostream>

using namespace std;

struct node {
    int data;
    node * left;
    node * right;
};

bool identical(node* root1, node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    if(root1 == NULL || root2 == NULL) {
        return false;
    }

    return (root1->data == root2->data) && identical(root1->left, root2->left)
    && identical(root1->right, root2->right);

}

int main() {
    node* root1 = new node{1};
    root1->left = new node{2};
    root1->right = new node{3};
    root1->left->left = new node{4};

    node* root2 = new node{1};
    root2->left = new node{2};
    root2->right = new node{3};
    root2->left->left = new node{4};

    cout<<identical(root1, root2)<<"\n";

    node* root3 = new node{1};
    root3->left = new node{2};
    root3->right = new node{3};
    root3->left->left = new node{4};

    node* root4 = new node{1};
    root4->left = new node{2};
    root4->right = new node{3};
    root4->right->left = new node{4};

    cout<<identical(root3, root4)<<"\n";
    return 0;
}
