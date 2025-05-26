#include <iostream>

using namespace std;

struct stack {
    string name;
    stack * next;
};

struct stack * top = NULL;
struct stack * temp;

void push(string name) {
    stack* willbeadded = new stack{name};
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

void yaz() {
    temp = top;
    while(temp != NULL) {
        cout<<temp->name<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main() {
    push("Juan");
    push("Pedro");
    push("Andrés");
    push("Joaquín");
    push("Alejandro");
    yaz();
    return 0;
}
