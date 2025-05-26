//Parenthesis checker
#include <iostream>

using namespace std;

struct stack {
    char character;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(char c) {
    stack* willbeadded = new stack{c};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

char pop() {
    if(top == NULL) {
        cout<<"Stack is already empty!!!";
        return '\0';
    } else {
        char c = top->character;
        temp = top -> next;
        delete top;
        top = temp;
        return c;
    }
}

void checker(string s) {
    int tot = 1;
    for(int i = 0; i < s.length(); i++) {
        char val = s[i];
        if(val == '(' || val == '{' || val == '[') {
            push(val);
        } else if(val == ')' || val == '}' || val == ']'){
            if(top == NULL) {
                tot = 0;
            } else {
                char pip = pop();
                if(val == ')' && (pip == '}' || pip == ']')) {
                    tot = 0;
                } else if (val == '}' && (pip == ')' || pip == ']')) {
                    tot = 0;
                } else if (val == ']' && (pip == ')' || pip == '}')) {
                    tot = 0;
                }
            }
        }
    }
    if(top) {
        tot = 0;
    }
    if(tot == 1) {
        cout<<"Valid expression.\n";
    } else {
        cout<<"Invalid expression\n";
    }
}
int main() {
    checker("(A + B)");
    return 0;
}
