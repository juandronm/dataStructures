#include <iostream>

using namespace std;

const int MAXP = 100;

//Adjacency matrix
int graph[10][3] = {
    {1, 4, 5},
    {0, 2, 6},
    {1, 3, 7},
    {2, 4, 8},
    {0, 3, 9},
    {0, 7, 8},
    {1, 8, 9},
    {2, 5, 9},
    {3, 5, 6},
    {4, 6, 7}
};

//Graf tags
char labels[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};

//Basic structure
struct Node {
    int vertex;
    int path[MAXP];
    int len;
};

//Function to write a path (if it exists)
void pathYaz(Node& node) {
    for (int i = 0; i < node.len; i++) {
        cout<< node.path[i];
    }
    cout<<"\n";
}

//Function to find walk
void walk(string& S) {
    Node queue[1000];
    int front = 0, rear = 0;

    //Sort all nodes starting with the start
    for(int i = 0; i < 10; i++) {
        if(labels[i] == S[0]) {
            queue[rear].vertex = i;
            queue[rear].path[0] = i;
            queue[rear].len = 1;
            rear++;
        }
    }

    while(front < rear) {
        Node current = queue[front++];
        if(current.len == S.length()) {
            pathYaz(current);
            return;
        }

        for(int i = 0; i < 3; i++) {
            int neighbor = graph[current.vertex][i];
            if(labels[neighbor] == S[current.len]) {
                Node next = current;
                next.path[next.len++] = neighbor;
                next.vertex = neighbor;
                queue[rear++] = next;
            }
        }
    }
    //If there is no walk
    cout<<-1;
}

int main() {
    string S;
    cout<<"Dizisini girin: ";
    cin>>S;
    walk(S);
    return 0;
}