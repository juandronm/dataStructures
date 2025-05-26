//counting number of trees in a forest
//using graphs
#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 2;

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

graph* createGraph(int v) {
    graph* newGraph = new graph{v};
    newGraph->array = new adjList[v];

    for(int i = 0; i < v; i++) {
        newGraph->array[i].head = NULL;
    }

    return newGraph;
}

void newListNode(graph* g, int from, int dest) {
    adjListNode* newNode = new adjListNode{from};
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;

    newNode = new adjListNode{dest};
    newNode->next = g->array[from].head;
    g->array[from].head = newNode;
}

void DFSUtil(graph* g, int v, bool visited[]) {
    visited[v] = true;

    adjListNode* temp = g->array[v].head;
    while(temp != NULL) {
        int adj = temp->value;
        if(!visited[adj]) {
            DFSUtil(g, adj, visited);
        }
        temp = temp->next;
    }
}

int howManyTrees(graph* g) {
    bool* visited = new bool[g->v];
    for(int i = 0; i < g->v; i++) {
        visited[i] = false;
    }

    int count = 0;

    for(int i = 0; i < g->v; i++) {
        if(!visited[i]) {
            count++;
            DFSUtil(g, i, visited);
        }
    }
    return count;
}

int main() {
    graph* g = createGraph(5);
    newListNode(g, 0, 1);
    newListNode(g, 0, 2);
    newListNode(g, 3, 4);

    cout<<howManyTrees(g);
    return 0;
}
