#include <iostream>

using namespace std;

struct stack {
    char value;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(char i) {
    stack* willbeadded = new stack{i};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

void pop() {
    if (top == NULL) {
        cout<<"Stack is already empty.\n";
    } else {
        temp = top->next;
        delete top;
        top = temp;
    }
}

int op(char vl) {
    if(vl == '^') {
        return 3;
    } else if (vl == '*' || vl == '/') {
        return 2;
    } else if (vl == '+' || vl == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool isEmpty() {
    return top == NULL;
}

string infixToPostfix(string s) {
    string result;

    for(int i = 0; i < s.length(); i++) {
        char l = s[i];

        if((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z')) {
            result += l;
        } else if(l == '(') {
            push(l);
        } else if (l == ')') {
            while(top->value != '(') {
                result += top->value;
                pop();
            }
            pop();
        } else {
            while(!isEmpty() && op(l) <= op(top->value)) {
                result += top->value;
                pop();
            }
            push(l);
        }
    }
    while(!isEmpty()) {
        result += top->value;
        pop();
    }
    return result;
}

int main() {
    string sentence = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(sentence);
    return 0;
}
