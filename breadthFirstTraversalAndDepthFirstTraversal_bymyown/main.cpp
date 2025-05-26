#include <iostream>

using namespace std;

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

struct queue {
    int number;
    queue* next;
};

struct queue * front = NULL;
struct queue * rear = NULL;

void enqueue(int digit) {
    queue* willbeadded = new queue{digit};
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

graph* createGraph(int v) {
    graph* newGraph = new graph{v};
    newGraph->array = new adjList[v];

    for(int i = 0; i < v; i++) {
        newGraph->array[i].head = NULL;
    }
    return newGraph;
}

adjListNode* createNewNode(int n) {
    adjListNode* willbeadded = new adjListNode{n};
    return willbeadded;
}

void newNode(graph* g, int from, int dest) {
    adjListNode* newNode =createNewNode(from);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;

    newNode = createNewNode(dest);
    newNode->next = g->array[from].head;
    g->array[from].head = newNode;
}

void printAdjacencyList(graph* g) {
    for(int i = 0; i < g->v; i++) {
        adjListNode* temp = g->array[i].head;
        cout<<"Adjacency list of vertex "<<i<<" head ";
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
        int current = node->number;
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
    graph* g= createGraph(6);
    newNode(g, 0, 1);
    newNode(g, 0, 5);
    newNode(g, 1, 3);
    newNode(g, 1, 4);
    newNode(g, 2, 0);
    newNode(g, 5, 3);

    cout<<"\nBFS:\n";
    BFS(g, 0);
    cout<<"\nDFS:\n";
    DFS(g, 0);

    return 0;
}
