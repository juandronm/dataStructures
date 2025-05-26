#include <iostream>

using namespace std;

struct stack {
    int number;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(int num) {
    stack* willbeadded = new stack{num};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

int pop() {
    if(top == NULL) {
        cout<<"Stack underflow.\n";
    } else {
        int value = top->number;
        temp = top->next;
        delete top;
        top = temp;
        return value;
    }
}

bool isNum(char n) {
    return n >= '0' && n <= '9';
}

bool isOperand(char op) {
    return op == '^' || op == '/' || op == '*' || op == '+' || op == '-';
}

int prefixEvaluation(string exp) {
    int op1, op2, value;
    for(int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if(c == ' ') {
            continue;
        }
        if(isNum(c)) {
            push(c - '0');
        } else if (isOperand(c)) {
            op1 = pop();
            op2 = pop();
            switch(c) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '^':
                    value = op1 ^ op2;
                    break;
                default:
                    cout<<"Wrong expression!\n";
                    return -1;
            }
            push(value);
        }
    }
    return pop();
}

int main() {
    cout<<prefixEvaluation("+-927")<<"\n";
    return 0;
}
