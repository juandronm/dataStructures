#include <iostream>

using namespace std;

int lambda(int n) {
    if(n == 1) {
        return 0;
    } else if (n > 1) {
        return lambda(n/2) + 1;
    }
}
int main() {
    cout<<lambda(5);
    return 0;
}
