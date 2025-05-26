#include <iostream>

using namespace std;

const int ROW = 5;
const int COL = 6;

char grid[ROW][COL] = {
 {'L', 'L', 'W', 'W', 'W', 'W'},
    {'W', 'L', 'W', 'W', 'W', 'L'},
    {'L', 'W', 'W', 'L', 'L', 'L'},
    {'W', 'W', 'W', 'W', 'W', 'W'},
    {'L', 'W', 'L', 'L', 'W', 'W'}
};

bool visited[ROW][COL];

int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < ROW && y < COL && grid[x][y] == 'L' && !visited[x][y];
}

void DFS(int x, int y) {
    visited[x][y] = true;
    for(int d = 0; d < 8; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(isValid(nx, ny)) {
            DFS(nx, ny);
        }
    }
}

int countIslands() {
    int count = 0;

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            if(grid[i][j] == 'L' && !visited[i][j]) {
                DFS(i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int result = countIslands();
    cout<<"Number of islands: "<<result;
    return 0;
}