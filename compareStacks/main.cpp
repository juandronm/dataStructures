#include <iostream>

using namespace std;

struct stack {
    int data;
    stack * next;
};

struct stack * temp;
struct stack * temp1;
struct stack * temp2;

void push(int n, stack*& top) {
    stack* willbeadded = new stack{n};
    if(top == NULL) {
        top = willbeadded;
    } else {
        willbeadded->next = top;
        top = willbeadded;
    }
}

void pop(stack*& top) {
    if(top == NULL) {
        cout<<"Stack is already empty.\n";
    } else {
        temp = top->next;
        delete top;
        top = temp;
    }
}

void compareStacks(stack* stack1, stack* stack2) {
    int equal = 1;
    temp1 = stack1;
    temp2 = stack2;
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else {
            equal = 0;
            break;
        }
    }
    if((temp1 == NULL && temp2) || (temp1 && temp2 == NULL)) {
        equal = 0;
    }

    if (equal == 1) {
        cout<<"Stacks are equal.\n";
    } else {
        cout<<"Stacks are not equal.\n";
    }
}

int main() {
    stack* stack1 = NULL;
    push(1, stack1);
    push(2, stack1);
    push(3, stack1);
    push(4, stack1);
    push(5, stack1);

    stack* stack2 = NULL;
    push(1, stack2);
    push(2, stack2);
    push(3, stack2);
    push(4, stack2);
    push(5, stack2);
    compareStacks(stack1, stack2);
    return 0;
}
