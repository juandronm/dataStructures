#include <iostream>

using namespace std;

struct node {
    string adSoyad;
    int sicilNumarasi;
    int maasiUye;
    node* next;
};

struct node * head = NULL;
struct node * temp = NULL;

void addMember(string name, int sicil, int maas) {
    temp = head;
    while(temp) {
        if(temp->sicilNumarasi == sicil) {
            cout<<"User already added.\n";
            return;
        }
        temp = temp->next;
    }

    node* willbeadded = new node{name, sicil, maas};
    if(head == NULL) {
        head = willbeadded;
    } else {
        temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = willbeadded;
    }
}

void call(int sicil) {
    if(head == NULL) {
        cout<<"Empty list.\n";
        return;
    }
    temp = head;
    while(temp && temp->sicilNumarasi != sicil) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Person not found.\n";
        return;
    }
    cout<<"\nMember found:\n";
    cout<<temp->adSoyad<<", "<<temp->sicilNumarasi<<", "<<temp->maasiUye<<"\n";
}

void printList() {
    temp = head;
    while(temp) {
        cout<<"\n* Name: "<<temp->adSoyad<<", sicil no.: "<<temp->sicilNumarasi<<", maas: "<<temp->maasiUye;
        temp = temp->next;
    }
}
int main() {
    addMember("Bunyamin Ciylan", 898754, 987547);
    addMember("Ibrahim Alper Dogru", 158425, 80000525);
    addMember("Adem Tekerek", 488451249, 84520);
    addMember("Aysun Coskun", 9848651, 79845);
    printList();
    call(898754);

    return 0;
}
