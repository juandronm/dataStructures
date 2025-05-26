#include <iostream>

using namespace std;

struct stack {
    char letter;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(char s) {
    stack* willbeadded = new stack{s};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

void pop() {
    if(top == NULL) {
        cout<<"Stack is empty.\n";
    } else {
        temp = top -> next;
        delete top;
        top = temp;
    }
}

bool isCharacter(char p) {
    return (p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z');
}

bool isOperand(char o) {
    return o == '^' || o == '+' || o == '-' || o == '*' || o == '/';
}

bool isEmpty() {
    return top == NULL;
}

int ord(char n) {
    if (n == '^') {
        return 3;
    } else if (n == '*' || n == '/') {
        return 2;
    } else if (n == '+' || n == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string exp) {
    string final;
    for(int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if(c == ' ') continue;
        if(isCharacter(c)) {
            final += c;
        } else if (isOperand(c) || c == '(') {
            push(c);
        } else if(c == ')') {
            while(top->letter != '(') {
                final += c;
                pop();
            }
            pop();
        } else {
            while(!isEmpty() && ord(c) <= ord(top->letter)) {
                final += c;
                pop();
            }
            push(c);
        }
    }
    while(!isEmpty()) {
        final += top->letter;
        pop();
    }
    return final;
}

int main() {
    cout<<infixToPostfix("a+b");
    return 0;
}
