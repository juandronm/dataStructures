#include <iostream>

using namespace std;

struct stack {
    string value;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(string n) {
    stack* willbeadded = new stack{n};
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

bool isCharacter(char p) {
    return (p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z') || (p >= '0' && p <= '9');
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
            push(string(1, c));
        } else if(c == ')') {
            while(top->value != "(") {
                final += c;
                pop();
            }
            pop();
        } else {
            while(!isEmpty() && ord(c) <= ord(top->value[0])) {
                final += c;
                pop();
            }
            push(string(1, c));
        }
    }
    while(!isEmpty()) {
        final += top->value;
        pop();
    }
    return final;
}

string postfixToPrefix(string p) {
    string final;
    for(int i = 0; i < p.length(); i++) {
        char s = p[i];
        if(isCharacter(s)) {
            push(string(1, s));
        } else if(isOperand(s)) {
            string op2 = top->value; pop();
            string op1 = top->value; pop();

            string oo = string(1, s) + op1 + op2;
            push(oo);
        }
    }
    final = top->value; pop();
    return final;
}

string infixToPrefix(string inf) {
    string post = infixToPostfix(inf);
    string pre = postfixToPrefix(post);
    return pre;
}

int main() {
    cout<<infixToPrefix("a+b");
    return 0;
}
