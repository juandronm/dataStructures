#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 4;

int grid[ROWS][COLS] = {
    {1, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 0, 1, 1}
};

bool visited[ROWS][COLS];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < ROWS && y < COLS && grid[x][y] == 1 && !visited[x][y];
}
void DFS(int x, int y) {
    visited[x][y] = true;
    grid[x][y] = 2;

    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(isValid(nx, ny)) {
            DFS(nx, ny);
        }
    }
}

void transforming(int startX, int startY) {
   for(int i = 0; i < ROWS; i++) {
       for(int j = 0; j < COLS; j++) {
           visited[i][j] = false;
       }
   }

   if(grid[startX][startY] == 1) {
       DFS(startX, startY);
   }
}

void printDoubleArray(int ar[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        cout<<"[ ";
        for(int j = 0; j < COLS; j++) {
            cout<<ar[i][j]<<" ";
        }
        cout<<"]\n";
    }
}

int main() {
    cout<<"INITIAL PIXELS:\n";
    printDoubleArray(grid);
    transforming(0, 0);

    cout<<"\nCHANGED PIXELS:\n";
    printDoubleArray(grid);
    return 0;
}
