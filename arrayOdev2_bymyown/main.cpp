#include <iostream>

using namespace std;

void inversed(int array[], int size) {
    int* original = new int[size];
    for(int i = 0; i < size; i++) {
        original[i] = array[i];
    }
    int k = 0;
    for(int i = size - 1; i >= 0; i--) {
        array[k] = original[i];
        k++;
    }
}

void ikiBoyutlu(int array[][3], int size) {
    int** original = new int*[size];
    for(int i = 0; i < size; i++) {
        original[i] = new int[size];
        for(int j = 0; j < size; j++) {
            original[i][j] = array[i][j];
        }
    }


    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            array[i][j] = original[size - 1 - i][size - 1 - j];
        }
    }
}

int main() {
    int size = 5;
    int dizi[] = {1, 5, 8, 3, 27};
    inversed(dizi, size);
    cout<<"After ordering: ";
    for(int i = 0; i < size; i++) {
        cout<<dizi[i]<<" ";
    }

    int newOne[3][3] = {{1, 3, 2}, {1, 4, 5}, {3, 4, 2}};

    ikiBoyutlu(newOne, 3);
    cout<<"New double array:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout<<newOne[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}
