#include <iostream>

using namespace std;

int N, M;

//Bitisiklik (Adjacency) matrisi olusturma fonksiyonu
void createAdjMatrix(int** Adj, int arr[][2]) {
    //tum degerleri sifirla
    for(int i = 0; i < N + 1; i++) {
        for(int j = 0; j < N + 1; j++) {
            Adj[i][j] = 0;
        }
    }

    //Kenarlari isaretle
    for(int i = 0; i < M; i++) {
        int x = arr[i][0];
        int y = arr[i][1];

        //degeri 1 olarak guncelle
        Adj[x][y] = 1;
        Adj[y][x] = 1;
    }
}

void printAdjMatrix(int** Adj) {
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < N + 1; j++) {
            cout<<Adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    N = 5; //Kose sayisi
    int arr[][2] = {{1, 2}, {2, 3}, {4, 5}, {1, 5}};//kenarlar
    M = sizeof(arr)/sizeof(arr[0]); //kenar sayisi
    int** Adj = new int*[N + 1];
    for(int i = 0; i < N + 1; i++) {
        Adj[i] = new int[N + 1];
    }
    //to find the adjacency matrix
    createAdjMatrix(Adj, arr);
    //to print the matrix
    printAdjMatrix(Adj);

    //to free memory
    for(int i = 0; i < N + 1; i++) {
        delete Adj[i];
    }
    delete Adj;
    return 0;
}
