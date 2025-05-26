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

char peek() {
    if(top != NULL) return top->data;
    return '\0';
}

bool isOperator(char c) {
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isEmpty() {
    return top == NULL;
}

string reverseStr(string str) {
    int n = str.length();
    for(int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
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
            while(!isEmpty() && peek() != '(') {
                result += top->data;
                pop();
            }
            if(!isEmpty()) pop();
        } else {
            while(!isEmpty() && ((prec(c) < prec(peek())) ||
                (prec(c) == prec(peek()) && c != '^'))) {
                result += peek();
                pop();
            }
            push(c);
        }
    }

    while(!isEmpty()) {
        result += peek();
        pop();
    }
    return result;
}

string infixToPrefix(string infix) {
    infix = reverseStr(infix);

    for(int i = 0; i < infix.length(); i++) {
        if(infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string postfix = infixToPostfix(infix);
    string prefix = reverseStr(postfix);

    return prefix;
}

int main() {
    string s = "(a-b/c)*(a/k-l)";
    cout << infixToPrefix(s) << endl;
    return 0;
}
