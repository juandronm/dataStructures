#include <iostream>

using namespace std;

struct stack {
    char character;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(char vl) {
    stack* willbeadded = new stack{vl};
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

bool isEmpty() {
    return top == NULL;
}

int type(char l) {
    if(l == '^') {
        return 3;
    } else if (l == '*' || l == '/') {
        return 2;
    } else if (l == '+' || l == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string s) {
    string result;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') continue;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        } else if(c == '(') {
            push(c);
        } else if (c == ')') {
            while(top->character != '(') {
                result += top->character;
                pop();
            }
            if(!isEmpty())pop();
        } else {
            while(!isEmpty() && type(c) <= type(top->character)) {
                result += top->character;
                pop();
            }
            push(c);
        }
    }
    while(!isEmpty()) {
        result += top->character;
        pop();
    }
    return result;
}

int main() {
    string infix = "(a + b) / c";
    cout<<infixToPostfix(infix);
    return 0;
}
