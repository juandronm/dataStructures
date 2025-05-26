#include <iostream>

using namespace std;

struct queue {
    int value;
    queue* next;
};

struct queue* front = NULL;
struct queue* rear = NULL;

void enqueue(int v) {
    queue* willbeadded = new queue{v};
    if(front == NULL) {
        front = rear = willbeadded;
    } else {
        rear->next = willbeadded;
        rear = willbeadded;
    }
}

queue* dequeue() {
    if(front == NULL) {
        cout<<"Queue error.\n";
    } else {
        queue* temp = front;
        front = front->next;
        if(front == NULL) {
            rear = NULL;
        }
        return temp;
    }
}

struct adjListNode {
    int value;
    adjListNode* next;
};

struct adjList {
    adjListNode* head;
};

struct graph {
    int v;
    adjList* array;
};

adjListNode* newListNode(int value) {
    adjListNode* willbeadded = new adjListNode{value};
    return willbeadded;
}

graph* createGraph(int value) {
    graph* gr = new graph{value};
    gr->array = new adjList[value];

    for(int i = 0; i < value; i++) {
        gr->array[i].head = NULL;
    }

    return gr;
}

void addNode(graph* g, int from, int dest) {
    adjListNode* newNode = newListNode(from);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;

    //since it is undirected, we do the same for the dest node
    newNode = newListNode(dest);
    newNode->next = g->array[from].head;
    g->array[from].head = newNode;
}

void printAdjacencyGraphList(graph* g) {
    for(int i = 0; i < g->v; i++) {
        adjListNode* temp = g->array[i].head;
        cout<<"\nAdjacency list of vertex "<<i<<" head";
        while(temp) {
            cout<<" -> "<<temp->value;
            temp = temp->next;
        }
    }
}

void BFS(graph* g, int startVertex) {
    bool* visited = new bool[g->v];
    for(int i = 0; i < g->v; i++) {
        visited[i] = false;
    }

    enqueue(startVertex);
    visited[startVertex] = true;

    while(front != NULL) {
        queue* node = dequeue();
        int current = node->value;
        cout<<current<<" ";
        delete node;

        adjListNode* temp = g->array[current].head;
        while(temp != NULL) {
            int adj = temp->value;
            if(!visited[adj]) {
                enqueue(adj);
                visited[adj] = true;
            }
            temp = temp->next;
        }
    }
    delete[] visited;
}

void DFSUtil(graph* g, int v, bool visited[]) {
    visited[v] = true;
    cout<<v<<" ";

    adjListNode* temp = g->array[v].head;
    while(temp != NULL) {
        int adj = temp->value;
        if(!visited[adj]) {
            DFSUtil(g, adj, visited);
        }
        temp = temp->next;
    }
}

void DFS(graph* g, int startVertex) {
    bool* visited = new bool[g->v];
    for(int i = 0; i < g->v; i++) {
        visited[i] = false;
    }
    DFSUtil(g, startVertex, visited);
    delete[] visited;
}
int main() {
    graph* g = createGraph(5);
    addNode(g, 0,1);
    addNode(g, 0, 4);
    addNode(g, 1, 2);
    addNode(g, 1, 3);
    addNode(g, 1, 4);
    addNode(g, 2, 3);
    addNode(g, 3, 4);

    printAdjacencyGraphList(g);
    cout<<"\nBreadth First Sorting:\n";
    BFS(g, 0);
    cout<<"\nDepth First Sorting:\n";
    DFS(g, 0);
    return 0;
}
