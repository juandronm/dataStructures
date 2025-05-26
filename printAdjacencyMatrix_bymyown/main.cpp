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

adjListNode* createNode(int n){
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

void addEdge(graph* g, int from, int dest) {
    adjListNode* newNode = createNode(from);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;

    newNode = createNode(dest);
    newNode->next = g->array[from].head;
    g->array[from].head = newNode;
}

void printAdjacencyMatrix(graph* g) {
    if(g == NULL) {
        cout<<"Graph doesnt exists.\n";
        return;
    } else {
        //Step 1, initialize matrix with 0
        int** matrix = new int*[g->v];
        for(int i = 0; i < g->v; i++) {
            matrix[i] = new int[g->v];
            for(int j = 0; j < g->v; j++) {
                matrix[i][j] = 0;
            }
        }

        //fill the matrix based on adjacency list
        for(int i = 0; i < g->v; i++) {
            adjListNode* temp = g->array[i].head;
            while(temp != NULL) {
                matrix[i][temp->value] = 1;
                temp = temp->next;
            }
        }

        cout<<"\nAdjacency matrix:\n";
        for(int i = 0; i < g->v; i++) {
            for(int j = 0; j < g->v; j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
        for(int i = 0; i < g->v; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}
void printAdjList(graph* g) {
    if(g == NULL) {
        cout<<"Graph doesnt exists.\n";
        return;
    } else {
        for(int i = 0; i < g->v; i++) {
            adjListNode* temp = g->array[i].head;
            if(temp == NULL) {
                cout<<"\n"<<i<<" doesn't have adjacency";
                continue;
            }
            cout<<"\nAdjacency List of: "<<i;
            while(temp) {
                cout<<" --> "<<temp->value;
                temp = temp->next;
            }
        }
    }
}

int main() {
    graph* g = createGraph(7);
    addEdge(g, 0, 1);
    addEdge(g, 0, 5);
    addEdge(g, 1, 5);
    addEdge(g, 6, 3);

    printAdjList(g);
    printAdjacencyMatrix(g);
    return 0;
}
