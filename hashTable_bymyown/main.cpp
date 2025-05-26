#include <iostream>

using namespace std;

#define BUCKET 7

struct node {
    int key;
    node * next;
};

node* HashTable[BUCKET];

int hashFunction(int number) {
    return number % BUCKET;
}

node* createNode(int n) {
    node* newNode = new node{n};
    return newNode;
}

void insertItem(int n) {
    int index = hashFunction(n);
    node* newNode = createNode(n);
    newNode->next = HashTable[index];
    HashTable[index] = newNode;
}

void deleteItem(int number) {
    int index = hashFunction(number);
    node* current = HashTable[index];
    node* previous = NULL;
    while(current != NULL && current->key != number) {
        previous = current;
        current = current->next;
    }
    if(current == NULL) return;
    if(previous == NULL) {
        HashTable[index] = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;
}

void displayHash() {
    for(int i = 0; i < BUCKET; i++) {
        cout<<i;
        node* temp = HashTable[i];
        while(temp) {
            cout<<" --> "<<temp->key;
            temp = temp->next;
        }
        cout<<"\n";
    }
}

int main() {
    int keys[] = {15, 11, 27, 8, 12};
    int n = sizeof(keys)/sizeof(keys[0]);

    for(int i = 0; i < BUCKET; i++) {
        HashTable[i] = NULL;
    }
    for(int i = 0; i < n; i++) {
        insertItem(keys[i]);
    }

    displayHash();
    deleteItem(12);
    cout<<"\nAfter deleting 12:\n";
    displayHash();
    return 0;
}
