#include <iostream>

using namespace std;

struct node {
    int number;
    node* child;
    node* next;
};

node* yeniNode(int n) {
    node* newNode = new node{n};
    return newNode;
}
node* allNodesOrdered(node* head) {
    node* temp = head;
    while(temp != NULL) {
        if(temp->child) {
            node* hasChild = temp->child;
            node* directlyToEnd = head;
            while(directlyToEnd->next) {
                directlyToEnd = directlyToEnd->next;
            }
            directlyToEnd->next = hasChild;
        }
        temp = temp->next;
    }
    return head;
}

void printList(node* head) {
    node* temp = head;
    while(temp) {
        cout<<temp->number<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main() {
    struct node* head = yeniNode(10);
    head -> next = yeniNode(5);
    head -> next -> next = yeniNode(12);
    head -> next -> next -> next = yeniNode(7);
    head -> next -> next -> next -> next = yeniNode(11);
    head -> child = yeniNode(4);
    head -> child -> next = yeniNode(20);
    head -> child -> next -> next = yeniNode(13);
    head -> child -> next -> child = yeniNode(2);
    head -> child -> next -> next -> child = yeniNode(16);
    head -> child -> next -> next -> child -> child = yeniNode(3);
    head -> next -> next -> next -> child = yeniNode(17);
    head -> next -> next -> next -> child -> next = yeniNode(6);
    head -> next -> next -> next -> child -> child = yeniNode(9);
    head -> next -> next -> next -> child -> child -> next = yeniNode(8);
    head -> next -> next -> next -> child -> child -> child = yeniNode(19);
    head -> next -> next -> next -> child -> child -> child -> next = yeniNode(15);

    node* changed = allNodesOrdered(head);
    printList(changed);
    return 0;
}
