#include <iostream>

using namespace std;

//representing an adjacency list node
struct adjListNode {
    int value;
    adjListNode* next;
};

//representing an adjacency list
struct adjList {
    adjListNode* head;
};

//representing a graph.
//A graph is an array of adjacency lists.
//Size of the array will be V (number of vertices in graph)
struct graph {
    int v;
    adjList* array;
};

//utility function to create new adjacency list nodes
adjListNode* newAdjListNode(int dest) {
    adjListNode* newNode = new adjListNode{dest};
    return newNode;
}

//a utility function that creates a graph of V vertices
graph* createGraph(int v) {
    graph* graph_ = new graph{v};

    //create an array of adjacency lists. Size will be V
    graph_->array = new adjList[v];

    //initialize each adjacency list as empty by making head as NULL
    for(int i = 0; i < v; i++) {
        graph_->array[i].head = NULL;
    }
    return graph_;
}

void addEdge(graph* g, int src, int dest) {
    adjListNode* newNode = newAdjListNode(dest);
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = g->array[dest].head;
    g->array[dest].head = newNode;
}

void printGraph(graph* g) {
    for(int v = 0; v < g->v; v++) {
        adjListNode* temp = g->array[v].head;
        cout<<"\nAdjacency list of vertex: "<<v<<"\n head ";
        while(temp) {
            cout<<" -> "<<temp->value;
            temp = temp->next;
        }
    }
}

int main() {
    int v = 5;
    graph* g = createGraph(5);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    printGraph(g);
    return 0;
}
