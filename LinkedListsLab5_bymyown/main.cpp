#include <iostream>

using namespace std;

struct node {
    string ad;
    string dersKodu;
    int kredi;
    int akts;
    string dersHoca;
    node* prev;
    node * next;
};

struct node * head1 = NULL;
struct node * temp = NULL;

struct node * head2 = NULL;

void add(node*& head, string name, string lessonCode, int credits, int akts, string hoca) {
    node* willbeadded = new node{name, lessonCode, credits, akts, hoca};
    if(head == NULL) {
        head = willbeadded;
    } else {
        temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        willbeadded->prev = temp;
        temp->next = willbeadded;
    }
}

void addAfterIndex(node*& head, int ind, string name, string lessonCode, int credits, int akts, string hoca) {
    node* willbeadded = new node{name, lessonCode, credits, akts, hoca};
    if(head == NULL) {
        head = willbeadded;
        return;
    }

    temp = head;
    for(int i = 0; i < ind && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) return;

    willbeadded->prev = temp;
    willbeadded->next = temp->next;
    temp->next = willbeadded;
}

void addAfterClassCode(node*& head, string classDesired, string name, string lessonCode, int credits, int akts, string hoca) {
    node* willbeadded = new node{ name, lessonCode, credits,  akts, hoca};
    if(head == NULL) {
        head = willbeadded;
        return;
    }
    temp = head;
    while(temp && temp->dersKodu != classDesired) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<classDesired<<" not found.\n";
        return;
    }
    willbeadded->prev = temp;
    willbeadded->next = temp->next;
    temp->next = willbeadded;
}

void deleteTeacher(node*& head) {
    if(head == NULL) {
        cout<<"List is empty.\n";
        return;
    }
    temp = head;
    while(temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void search(node*& head, string name) {
    if(head == NULL) {
        cout<<"List empty.\n";
        return;
    }
    temp = head;
    while(temp && temp->ad != name) {
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Class not found.\n";
        return;
    }
    cout<<"\nClass found:\n";
    cout<<temp->ad<<", "<<temp->dersKodu<<", credits: "<<temp->kredi<<", AKTS: "<<temp->akts<<", teacher: "<<temp->dersHoca<<"\n";
}

void printList(node* head) {
    temp = head;
    while(temp) {
        cout<<"* Lesson: "<<temp->ad<<", code: "<<temp->dersKodu<<", credits: "<<temp->kredi<<", AKTS: "<<temp->akts<<", ders hoca: "<<temp->dersHoca<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
}

node* uniteLists(node* list1, node* list2) {
    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }
    temp = list1;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

int main() {
    add(head1, "Bilgisayar Muhendisligi", "BMT202", 9, 15, "Bunyamin Ciylan");
    add(head1, "Veri Yapilari", "BMT215", 9, 14, "Adem Tekerek");
    add(head1, "Lineer Cebir", "BMT102", 6, 7, "Aysun Coskun");
    add(head1, "Fizik", "FIZ205", 8, 17, "Makbule Terlemezoglu Bilmis");
    printList(head1);

    add(head2, "Elektrik", "BMT207", 7, 9, "Fecir Duran");
    add(head2, "Sayisal Tasarim", "BMT205", 8, 10, "Bunyamin Ciylan");
    add(head2, "Veri Bilimi", "BMT213", 8, 9, "Yusuf Sonmez");
    add(head2, "Bilgisayar Programlama", "BMT110", 8, 10, "Saadin Oyucu");
    printList(head2);

    node* bothListsUnited = uniteLists(head1, head2);
    cout<<"\nUnited lists:\n";
    printList(bothListsUnited);
    return 0;
}
