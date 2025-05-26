#include <iostream>

using namespace std;

#define N 3
bool knows(int M[N][N], int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(int M[N][N], int n) {
    int stack[N];
    int top = -1;

    for(int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    while(top > 0) {
        int a = stack[top--];
        int b = stack[top--];

        if(knows(M, a, b)) {
            stack[++top] = b;
        } else {
            stack[++top] = a;
        }
    }

    if(top == -1) return -1;

    int candidate = stack[top];

    for(int i = 0; i < n; i++) {
        if(i == candidate) continue;

        if(knows(M, candidate, i)) return -1;
        if(!knows(M, i, candidate)) return -1;
    }
    return candidate;
}
int main() {
    int M[N][N] = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };
    int celeb = findCelebrity(M, N);
    if(celeb == -1) {
        cout<<"No celebrity found.\n";
    } else {
        cout<<"Celebrity is person "<<celeb<<"\n";
    }
    return 0;
}
