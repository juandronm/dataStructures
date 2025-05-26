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

adjListNode* newNode(int n){
    adjListNode* willbeadded = new adjListNode{n};
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

void addEdge(graph* g, int from, int to) {
    adjListNode* newPart = newNode(from);
    newPart->next = g->array[to].head;
    g->array[to].head = newPart;

    newPart = newNode(to);
    newPart->next = g->array[from].head;
    g->array[from].head = newPart;
}

void printAdjacencyList(graph* g) {
    if(g == NULL) {
        cout<<"Graph is empty!\n";
        return;
    } else {
        for(int i = 0; i < g->v; i++) {
            adjListNode* temp = g->array[i].head;
            if(temp == NULL) {
                cout<<"\n"<<i<<" has no adjacency";
                continue;
            }
            cout<<"\nAdjacency list of "<<i;
            while(temp != NULL) {
                cout<<" --> "<<temp->value;
                temp = temp->next;
            }
        }
    }
}

void printAdjacencyMatrix(graph* g) {
    if(g == NULL) {
        cout<<"Graph is empty!\n";
        return;
    }

    int** adjMatrix = new int*[g->v];
    for(int i = 0; i < g->v; i++) {
        adjMatrix[i] = new int[g->v];
        for(int j = 0; j < g->v; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < g->v; i++) {
        adjListNode* temp = g->array[i].head;
        while(temp != NULL) {
            adjMatrix[i][temp->value] = 1;
            temp = temp->next;
        }
    }

    cout<<"\nAdjacency matrix:\n";
    for(int i = 0; i < g->v; i++) {
        cout<<"[ ";
        for(int j = 0; j < g->v; j++) {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<"]\n";
    }

    for(int i = 0; i <g->v; i++) {
        delete[] adjMatrix[i];
    }

    delete[] adjMatrix;
}
int main() {
    graph* g = createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 1, 0);

    printAdjacencyList(g);
    printAdjacencyMatrix(g);
    return 0;
}
