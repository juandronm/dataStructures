#include <iostream>

using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* newNode(int item) {
    node* temp = new node{item};
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* node, int data) {
    if(node == NULL) {
        return newNode(data);
    }

    if(data < node->data) {
        node -> left = insert(node->left, data);
    } else if (data > node->data) {
        node -> right = insert(node->right, data);
    }

    return node;
}

void preorder(node* root) {
    if(root != NULL) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

node* search(node* root, int key) {
    if(root == NULL || root->data == key) {
        return root;
    }
    if(root->data <= key) {
        return search(root->right, key);
    } else {
        return search(root->left, key);
    }
}

node* findMin(node* node) {
    struct node* current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

node* findMax(node* node) {
    struct node* current = node;
    while(current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

node* deleteNode(node* root, int key) {
    if(root == NULL) {
        return root;
    }
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if(root->left == NULL) {
            struct node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            struct node* temp = root->left;
            delete root;
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);
    root = insert(root, 60);
    root = insert(root, 60);

    cout<<"Preorder:\n";
    preorder(root);

    cout<<"\nInorder:\n";
    inorder(root);

    cout<<"\nPostorder:\n";
    postorder(root);
    cout<<"\n";

    cout<<"20 silinecek\n";
    root = deleteNode(root, 20);
    cout<<"20 degeri solindikten sonra preorder: ";
    preorder(root); cout<<"\n";
    cout<<"20 degeri solindikten sonra inorder: ";
    inorder(root); cout<<"\n";
    cout<<"20 degeri solindikten sonra postorder: ";
    postorder(root); cout<<"\n";

    cout<<"30 silinecek\n";
    root = deleteNode(root, 30);
    cout<<"30 degeri solindikten sonra preorder: ";
    preorder(root); cout<<"\n";
    cout<<"30 degeri solindikten sonra inorder: ";
    inorder(root); cout<<"\n";
    cout<<"30 degeri solindikten sonra postorder: ";
    postorder(root); cout<<"\n";

    int value = 60;
    node* foundNode = search(root, value);
    if(foundNode != NULL){
        cout<<value<<" was found on the BST.\n";
    } else {
        cout<<value<<" was not found on the BST.\n";
    }
    return 0;
}
