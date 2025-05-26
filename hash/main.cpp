#include <iostream>

using namespace std;

unsigned int simpleHash(string input) {
    unsigned int hash = 0;
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        hash = hash * 101 + c;
    }
    return hash;
}

int main() {
    string data;
    cout<<"Enter input to hash: ";
    getline(cin, data);

    unsigned int hashed = simpleHash(data);
    cout<<"Simple hash: "<<hashed<<"\n";
    return 0;
}
