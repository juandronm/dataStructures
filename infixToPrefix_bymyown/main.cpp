#include <iostream>

using namespace std;

struct stack {
    string character;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(string c) {
    stack* willbeadded = new stack{c};
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

string reverse(string initial) {
    int n = initial.length();
    for(int i = 0; i < n / 2; i++) {
        if(initial[i] == ' ') {
            continue;
        }
        char temp = initial[i];
        initial[i] = initial[n - i - 1];
        initial[n - i - 1] = temp;
    }

    for(int i = 0; i < n; i++) {
        if(initial[i] == '(') {
            initial[i] = ')';
        } else if (initial[i] == ')') {
            initial[i] = '(';
        } else if (initial[i] == ']') {
            initial[i] = '[';
        } else if (initial[i] == '[') {
            initial[i] = ']';
        } else if (initial[i] == '}') {
            initial[i] = '{';
        } else if (initial[i] == '{') {
            initial[i] = '}';
        }
    }

    return initial;
}

bool isEmpty() {
    return top == NULL;
}

int order(char op) {
    if(op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else {
        return -1;
    }
}

bool isNumerical(char num) {
    return (num >= '0' && num <= '9') || (num >= 'A' && num <= 'Z') || (num >= 'a' && num <= 'z');
}

bool isOperand(char sign) {
    return sign == '^' || sign == '/' || sign == '*' || sign == '+' || sign == '-';
}

string infixToPostfix(string s) {
    string final;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            final += c;
        } else if (c == '(') {
            push(string(1, c));
        } else if (c == ')') {
            while(top->character != "(") {
                final += top->character;
                pop();
            }
            pop();
        } else {
            while(!isEmpty() && order(c) <= order(top->character[0])) {
                final += top->character;
                pop();
            }
            push(string(1, c));
        }
    }
    while(!isEmpty()) {
        final += top->character;
        pop();
    }
    return final;
}

void clearStack() {
    while(top != NULL) {
        pop();
    }
}

string postfixToPrefix(string s) {
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
        if(isNumerical(c)) {
            push(string(1, c));
        } else if (isOperand(c)) {
            string op2 = top->character; pop();
            string op1 = top->character; pop();
            string value = c + op1 + op2;
            push(value);
        }
    }
    string final = top->character;
    pop();
    return final;
}

string infixToPrefix(string infix) {
    //infix = reverse(infix);
    //cout<<"Reversed: "<<infix<<"\n";
    infix = infixToPostfix(infix);
    //cout<<"Postfix: "<<infix<<"\n";
    //infix = reverse(infix);
    //cout<<"Reversed of the postfix: "<<infix<<"\n";
    infix = postfixToPrefix(infix);

    return infix;
}

int main() {
    string expression = "A+B-C*D";
    cout<<"Postfix: "<<infixToPostfix(expression)<<"\n";
    cout<<"Reversed: "<<reverse(expression)<<"\n";
    cout<<"Prefix: "<< infixToPrefix(expression);
    return 0;
}