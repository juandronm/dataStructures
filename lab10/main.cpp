#include <iostream>

using namespace std;

struct node {
    int data;
    node * next;
};

struct Stack {
    struct node* top;
};

struct node * head = NULL;
struct node * temp = NULL;

struct Stack* stackOlustur() {
    Stack* stack = new Stack{NULL};
    return stack;
}

void push(Stack* stack, int n) {
    node* willbeadded = new node{n};
    willbeadded -> next = stack -> top;
    stack -> top = willbeadded;
}

int pop(Stack* stack) {
    if(stack->top == NULL) {
        return -1;
    }
    temp = stack -> top;
    int data = temp -> data;
    stack -> top = stack -> top -> next; //PEEK changes place
    delete(temp);
    return data;
}


int peek(Stack* stack) {
    if(stack -> top == NULL) {
        return -1;
    }
    return stack -> top -> data;
}

int isEmpty(Stack* stack) {
    return(stack-> top == NULL);
}

void yaz(Stack* stack) {
    while(!isEmpty(stack)) {
        cout<<pop(stack)<<" ";
    }
    cout<<"\n";
}

void reverseRecursive(node* top) {
    if(top == NULL) return;
    reverseRecursive(top->next);
    cout<<top->data<<" ";
}

void printReverse(Stack* stack) {
    reverseRecursive(stack -> top);
    cout<<"\n";
}

int factoriel(Stack* stack, int num) {
    for(int i = 1; i <= num; i++) {
        push(stack, i);
    }
    int answer = 1;

    while(!isEmpty(stack)) {
        answer *= pop(stack);
    }
    return answer;
}

void dengeliMi(string op) {
    Stack* ifade = stackOlustur();
    bool dengeli = true;

    for(char ch : op) {
        if(ch == '(') {
            push(ifade, 1);
        } else if (ch == ')') {
            if(isEmpty(ifade)) {
                dengeli = false;
                break;
            }
            pop(ifade);
        }
    }

    if(!isEmpty(ifade)) {
        dengeli = false;
    }

    if(dengeli) {
        cout<<"Ifade dengeli.\n";
    } else {
        cout<<"Ifade dengesiz.\n";
    }
    cout<<"\n";
}

int main() {
    Stack* stack = stackOlustur();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    yaz(stack);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    cout<<"Tersi yaz\n";
    printReverse(stack);

    string op;
    cout<<"Bir ifade girin: ";
    getline(cin, op);

    if(op.empty()) {
        getline(cin,op);
    }
    dengeliMi(op);

    int n;
    Stack* fact = stackOlustur();
    cout<<"Bir sayi giriniz: ";
    cin>>n;
    cout<<n<<". factorial: "<<factoriel(fact, n);
    return 0;
}
