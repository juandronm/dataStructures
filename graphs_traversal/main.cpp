#include <iostream>

using namespace std;

int* vis;

struct Graph {
    int V;
    int E;
    int** Adj;
};

struct Graph* adjMatrix() {
    Graph* G = new Graph{};
    if(!G) {
        cout<<"Memory Error\n";
        return NULL;
    }
    G->V = 7;
    G->E = 7;


}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
