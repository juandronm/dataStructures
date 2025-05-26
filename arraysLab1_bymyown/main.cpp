#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void deleteElement(int array[], int element, int& size) {
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(array[i] == element) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        cout<<"Element not found!\n";
        return;
    }

    cout<<"Deleted element: "<<element;
    cout<<"\n";
    for(int i = index; i < size - 1; i++) {
        array[i] = array[i+1];
    }
    size--;
}

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    srand(time(0));

    int size;
    cout<<"How many elements do you want in thw array?: ";
    cin>>size;

    int* elements = new int[size];

    for(int i = 0; i < size; i++) {
        elements[i] = rand() % 300;
    }

    cout<<"Array generated:\n";
    printArray(elements, size);
    cout<<"\n";

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(elements[i] > elements[j]) {
                int temp = elements[i];
                elements[i] = elements[j];
                elements[j] = temp;
            }
        }
    }

    cout<<"Array sorted:\n";
    printArray(elements, size);

    int which;
    cout<<"Which element do you want to delete?: ";
    cin>>which;
    deleteElement(elements, which, size);
    cout<<"After deleted:\n";
    printArray(elements, size);
    return 0;
}
