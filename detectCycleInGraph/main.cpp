#include <iostream>

using namespace std;

const int COLS = 2;
const int ROWS = 5;
const int NODES = 4;

int med[ROWS][COLS] = {
    {0, 1},
    {0, 2},
    {1, 2},
    {2, 0},
    {2, 3}
};

struct node {
    int vertex;
    node* next;
};

node* adj[NODES] = {NULL};

void addEdge(int from, int to) {
    node* newNode = new node{to, adj[from]};
    adj[from] = newNode;
}

bool dfs(int v, bool visited[], bool recStack[]) {
    visited[v] = true;
    recStack[v] = true;

    node* temp = adj[v];
    while(temp != NULL) {
        int neighbor = temp->vertex;
        if(!visited[neighbor] && dfs(neighbor, visited, recStack)) {
            return true;
        } else if(recStack[neighbor]) {
            return true;
        }
        temp = temp->next;
    }

    recStack[v] = false;
    return false;
}

bool isThereCycle() {
    bool visited[NODES] = {false};
    bool recStack[NODES] = {false};

    for(int i = 0; i < NODES; i++) {
        if(!visited[i]) {
            if(dfs(i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    for(int i = 0; i < ROWS; i++) {
        int from = med[i][0];
        int to = med[i][1];
        addEdge(from, to);
    }

    if(isThereCycle()) {
        cout<<"Cycle detected.\n";
    }else {
        cout<<"No cycle detected.\n";
    }
    return 0;
}
