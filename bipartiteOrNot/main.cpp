#include <iostream>

using namespace std;

struct queue {
    int num;
    queue* next;
};

struct queue * front = NULL;
struct queue * rear = NULL;

struct adjListNode {
    int value;
    adjListNode * next;
};

struct adjList {
    adjListNode * head;
};

struct graph {
    int v;
    adjList * array;
};

adjListNode* newListNode(int number) {
    adjListNode* willbeadded = new adjListNode{number};
    return willbeadded;
}
graph* createGraph(int v) {
    graph* newGraph = new graph{v};
    newGraph->array = new adjList[v];

    for(int i = 0; i < v; i++) {
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void addNode(graph*& g, int from, int destination) {
    adjListNode* newNode = newListNode(from);
    newNode->next = g->array[destination].head;
    g->array[destination].head = newNode;

    newNode = newListNode(destination);
    newNode->next = g->array[from].head;
    g->array[from].head = newNode;
}

void enqueue(int n) {
    queue* willbeadded = new queue{n};
    if(front == NULL) {
        front = rear = willbeadded;
    } else {
        rear->next = willbeadded;
        rear = willbeadded;
    }
}

queue* dequeue() {
    if(front == NULL) {
        cout<<"Queue empty.\n";
        return NULL;
    } else {
        queue* temp = front;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        return temp;
    }
}

bool queueLength() {
    if(front == NULL) {
        return -1;
    } else {
        int i = 0;
        queue* temp = front;
        while(temp != rear) {
            i++;
            temp = temp->next;
        }
        return i <= 1;
    }
}

bool isBipartite(graph* g, int startingVertex) {
    bool* visited = new bool[g->v];
    for(int i = 0; i < g->v; i++) {
        visited[i] = false;
    }

    enqueue(startingVertex);
    visited[startingVertex] = true;
    while(front != NULL){
        queue* node = dequeue();
        int val = node->num;
        delete node;

        adjListNode* temp = g->array[val].head;
        while(temp != NULL) {
            int adj = temp->value;
            if(!visited[adj]) {
                enqueue(adj);
                visited[adj] = 1 - visited[val];
            } else if(visited[adj] == visited[val]) {
                delete[] visited;
                return false;
            }
            temp = temp->next;
        }
    }
    delete[] visited;
    return true;
}

int main() {
    graph* g = createGraph(4);
    addNode(g, 0, 1);
    addNode(g, 0, 2);
    addNode(g, 1, 2);
    addNode(g, 2, 3);
    cout<<isBipartite(g, 0);
    return 0;
}
