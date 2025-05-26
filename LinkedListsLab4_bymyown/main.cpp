#include <iostream>

using namespace std;

struct node {
    int number;
    node* next;
};

struct node * head = NULL;
struct node * temp = NULL;
struct node * temp2 = NULL;

void addHead(int n) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        head = willbeadded;
        return;
    }
    willbeadded->next = head;
    head = willbeadded;
}

void addFoot(int n) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        head = willbeadded;
        return;
    }
    temp = head;
    while(temp->next) {
        temp = temp ->next;
    }
    temp->next = willbeadded;
}

void addAfter(int n, int after) {
    node* willbeadded = new node{n};
    if(head == NULL) {
        head = willbeadded;
        return;
    }
    temp = head;
    while(temp != NULL && temp ->number != after) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Element not found!\n";
        return;
    }
    willbeadded->next = temp->next;
    temp->next = willbeadded;
}

void deleteFirst() {
    if(head == NULL) {
        cout<<"List already empty.\n";
        return;
    }
    temp = head->next;
    delete head;
    head = temp;
}

void deleteFoot() {
    if(head == NULL) {
        cout<<"List already empty.\n";
        return;
    }
    temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deleteDesired(int desired) {
    if(head == NULL) {
        cout<<"list already empty.\n";
        return;
    }
    if(head->number == desired) {
        temp = head;
        head = head->next;
        cout<<temp->number<<" eliminated.\n";
        delete temp;
        return;
    }

    temp = head;
    while(temp->next != NULL && temp->next->number != desired) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        cout<<"Element not found.\n";
        return;
    }
    temp2 = temp->next->next;
    cout<<"\n"<<temp->next->number<<" eliminated.\n";
    delete temp->next;
    temp->next = temp2;
}

void printList() {
    temp = head;
    while(temp) {
        cout<<temp->number<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void call(int n) {
    if(head == NULL) {
        cout<<"List is empty.\n";
        return;
    }
    temp = head;
    while(temp && temp->number != n) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Element not found.\n";
        return;
    }
    cout<<n<<" was found";
}
int main() {
    addHead(8);
    addHead(9);
    addHead(10);
    printList();
    addFoot(7);
    addFoot(6);
    addFoot(5);
    printList();
    addAfter(89, 10);
    addAfter(81, 8);
    printList();
    deleteFirst();
    printList();
    deleteFoot();
    printList();
    deleteDesired(9);
    printList();
    call(6);
    return 0;
}
