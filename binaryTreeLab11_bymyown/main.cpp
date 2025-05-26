#include <iostream>

using namespace std;

struct binaryTreeNode {
    int number;
    binaryTreeNode* left;
    binaryTreeNode* right;
};

binaryTreeNode* addNewNode(binaryTreeNode* root, int value){
    if(root == NULL) {
        root = new binaryTreeNode{value};
    } else {
        if(value < root->number) {
            root->left = addNewNode(root->left, value);
        } else if(value > root->number) {
            root->right = addNewNode(root->right, value);
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

void inorder(binaryTreeNode* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->number<<" ";
        inorder(root->right);
    }
}

void preorder(binaryTreeNode* root) {
    if(root != NULL) {
        cout<<root->number<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(binaryTreeNode* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->number<<" ";
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

int deepOfElement(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return -1;
    } else if(root->number == wantedValue) {
        return 0;
    } else {
        if(wantedValue < root->number) {
            return deepOfElement(root->left, wantedValue) + 1;
        } else if(wantedValue > root->number) {
            return deepOfElement(root->right, wantedValue) + 1;
        }
    }
}

int heightOfElement(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        return -1;
    }

   if(root->number == wantedValue) {
       return deep(root);
   }

    if(wantedValue < root->number) {
        return heightOfElement(root->left, wantedValue);
    } else if(wantedValue > root->number) {
        return heightOfElement(root->right, wantedValue);
    }
}

binaryTreeNode* deleteNode(binaryTreeNode* root, int wantedValue) {
    if(root == NULL) {
        cout<<"Value not found.\n";
        return NULL;
    }

    if(wantedValue < root->number) {
        root->left = deleteNode(root->left, wantedValue);
    } else if(wantedValue > root->number) {
        root->right = deleteNode(root->right, wantedValue);
    } else {
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        if(!root->left) {
            binaryTreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            binaryTreeNode* temp = root->left;
            delete root;
            return temp;
        }

        binaryTreeNode* succesor = root->right;
        int min = minimum(succesor);

        root->number = min;
        root->right = deleteNode(root->right, min);
    }
    return root;
}

int main() {
    binaryTreeNode* root = NULL;
    root = addNewNode(root, 15);
    root = addNewNode(root, 16);
    root = addNewNode(root, 28);
    root = addNewNode(root, 89);
    root = addNewNode(root, 5);

    cout<<"\n* Minimum: "<<minimum(root);
    cout<<"\n* Maximum: "<<maximum(root);

    cout<<"\n* Preorder:\n";
    preorder(root);
    cout<<"\n* Inorder:\n";
    inorder(root);
    cout<<"\n* Postorder:\n";
    postorder(root);
    cout<<"\n* Deepth of element 89: "<<deepOfElement(root, 89);
    cout<<"\n* Height of element 15: "<<heightOfElement(root, 16);
    root = deleteNode(root, 16);
    cout<<"\nInorder after deleting 16:\n";
    inorder(root);

    return 0;
}
