#include <iostream>

using namespace std;

const int COLS = 3;
const int ROWS = 10;

int med[ROWS][COLS] = {
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

char dots[] = {
    'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'
};

string bestPath = "";
bool found = false;

void dfs(int node, string words, int idx, string path, bool visited[][ROWS]) {
    if(dots[node] != words[idx]) return;

    path += to_string(node);

    if(idx == words.length() - 1) {
        if(!found || path < bestPath) {
            bestPath = path;
            found = true;
        }
        return;
    }

    for(int i = 0; i < COLS; i++) {
        int next = med[node][i];
        if(!visited[idx + 1][next]) {
            visited[idx + 1][next] = true;
            dfs(next, words, idx + 1, path, visited);
            visited[idx + 1][next] = false;
        }
    }
}

string pathToDesiredPoint(string words) {
    found = false;
    bestPath = "";

    for(int i = 0; i < ROWS; i++) {
        if(dots[i] == words[0]) {
            bool visited[100][ROWS] = {false};
            visited[0][i] = true;
            dfs(i, words, 0, "", visited);
        }
    }
    if(found) return bestPath;
    else return "-1";
}

int main() {
    string input;
    cout<<"Enter a letter sequence (A-E):\n";
    getline(cin, input);

    string result = pathToDesiredPoint(input);
    cout<<"Path to desired point: "<<result;
    return 0;
}
