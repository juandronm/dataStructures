#include <iostream>

using namespace std;

struct stack {
    float character;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(float c) {
    stack* willbeadded = new stack{c};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

float pop() {
    if(top == NULL) {
        cout<<"Stack is already empty.\n";
    } else {
        float c = top -> character;
        temp = top->next;
        delete top;
        top = temp;
        return c;
    }
}

bool isDigit(char n) {
    return n >= '0' && n <= '9';
}

float evaluationPostfix(string s) {
    int i = 0;
    float num1, num2, value;

    while(s[i] != '\0') {
        if(s[i] == ' ') {
            i++;
            continue;
        }

        if(isDigit(s[i])) {
            push(s[i] - '0');
        } else {
            num2 = pop();
            num1 = pop();

            switch(s[i]) {
                case '+':
                    value = num1 + num2;
                    break;
                case '-':
                    value = num1 - num2;
                    break;
                case '*':
                    value = num1 * num2;
                    break;
                case '/':
                    value = num1 / num2;
                    break;
                default:
                    cout<<"Invalid expression.";
                    exit(1);
            }
            push(value);
        }
        i++;
    }
    return pop();
}

int main() {
    string expression;
    cout<<"Enter any postfix expression: ";
    getline(cin, expression);
    cout<<evaluationPostfix(expression);
    return 0;
}
