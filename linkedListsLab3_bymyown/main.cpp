#include <iostream>

using namespace std;

struct node {
    int number;
    node* next;
};

struct node * head = NULL;
struct node * temp = NULL;

void addHead(int n) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        head = willbeadded;
    } else {
        willbeadded->next = head;
        head = willbeadded;
    }
}

void addAfter(int n, int after) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        cout<<"List is empty. Added at head";
        head = willbeadded;
        return;
    }

    temp = head;
    while(temp != NULL && temp->number != after) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Element not found!\n";
        return;
    }
    willbeadded->next = temp->next;
    temp->next = willbeadded;
}

void addFoot(int n) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        head = willbeadded;
        return;
    }
    temp = head;
    while(temp -> next != NULL) {
        temp = temp->next;
    }
    temp->next = willbeadded;
}

void printList() {
    temp = head;
    while(temp) {
        cout<<temp->number<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main() {
    addHead(5);
    addHead(6);
    addHead(7);
    printList();
    addFoot(4);
    addFoot(3);
    addFoot(2);
    printList();
    addAfter(890, 6);
    printList();
    return 0;
}
