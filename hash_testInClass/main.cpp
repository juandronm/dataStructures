#include<bits/stdc++.h>
#include <iostream>

using namespace std;

#define BUCKET 7 //constant

//structure of the linked list
struct Node {
    int key;
    Node * next;
};

//Hash table: linked lists in form of arrays
Node* hashTable[BUCKET];

//Hash function
int hashFunction(int key) {
    return key % BUCKET;
}

//To create a new node
Node* createNode(int key) {
    Node* newNode = new Node{key};
    return newNode;
}

//Insert an element
void insertItem(int key) {
    int index = hashFunction(key);
    Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

//Delete element
void deleteItem(int key) {
    int index = hashFunction(key);
    Node* curr = hashTable[index];
    Node* prev = NULL;
    while(curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL) return;
    if(prev == NULL) {
        hashTable[index] = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
}

//To print hash table
void displayHash() {
    for(int i = 0; i < BUCKET; i++) {
        cout<<i;
        Node* curr = hashTable[i];
        while(curr != NULL) {
            cout<<" --> "<<curr->key;
            curr = curr->next;
        }
        cout<<"\n";
    }
}

int main() {
    int keys[] = {15, 11, 27, 8, 12};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i = 0; i < BUCKET; i++) {
        hashTable[i] = NULL;
    }
    for(int i = 0; i < n; i++) {
        insertItem(keys[i]);
    }
    deleteItem(12);
    displayHash();

    return 0;
}
