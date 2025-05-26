#include <iostream>

using namespace std;

struct stack {
    char data;
    stack * next;
};

struct stack * top;
struct stack * temp;

void push(char num) {
    stack* willbeadded = new stack{num};
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
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool isEmpty() {
    return top == NULL;
}

int prec(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string infixToPostfix(string s) {
    string result;

    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            result += c;
        } else if (c == '(') {
            push('(');
        } else if(c == ')') {
            while(top->data != '(') {
                result += top->data;
                pop();
            }
            pop();
        } else {
            while(!isEmpty() && prec(c) <= prec(top->data)) {
                result += top->data;
                pop();
            }
            push(c);
        }
    }

    while(!isEmpty()) {
        result += top->data;
        pop();
    }
    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(exp);
    return 0;
}
