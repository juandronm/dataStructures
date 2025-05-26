#include <iostream>

using namespace std;

struct MaxHeap {
    int *harr;
    int capacity;
    int heap_size;
};

MaxHeap* createMaxHeap(int capacity) {
    MaxHeap* maxHeap = new MaxHeap{};
    maxHeap -> heap_size = 0;
    maxHeap -> capacity = capacity;
    maxHeap -> harr = (int *)malloc(capacity * sizeof(int));
}

int left(int i) {
    return(2 * i + 1);
}

int right(int i) {
    return(2 * i + 2);
}

int parent(int i) {
    return(i - 1)/2;
}

void insertKey(MaxHeap* maxHeap, int k) {
    if(maxHeap->heap_size == maxHeap->capacity) {
        cout<<"\nTasma: Ekleme basarisiz\n";
        return;
    }
    int i = maxHeap->heap_size++;
    maxHeap->harr[i] = k;

    while(i != 0 && maxHeap->harr[parent(i)] < maxHeap->harr[i]) {
        int temp = maxHeap->harr[i];
        maxHeap->harr[i] = maxHeap->harr[parent(i)];
        maxHeap->harr[parent(i)] = temp;
        i = parent(i);
    }
}

void MaxHeapify(MaxHeap* maxHeap, int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;

    if(l < maxHeap->heap_size && maxHeap->harr[l] > maxHeap->harr[largest]) {
        largest = l;
    }
    if(r < maxHeap->heap_size && maxHeap->harr[r] > maxHeap->harr[largest]) {
        largest = r;
    }

    if(largest != i) {
        int temp = maxHeap->harr[i];
        maxHeap->harr[i] = maxHeap->harr[largest];
        maxHeap->harr[largest] = temp;
        MaxHeapify(maxHeap, largest);
    }
}

int extractMax(MaxHeap* maxHeap) {
    if(maxHeap->heap_size <= 0) {
        return INT_MIN;
    }
    if(maxHeap->heap_size == 1) {
        maxHeap->heap_size--;
        return maxHeap->harr[0];
    }
    //Koku cikarin
    int root = maxHeap->harr[0];
    maxHeap->harr[0] = maxHeap->harr[maxHeap->heap_size - 1];
    maxHeap->heap_size--;
    MaxHeapify(maxHeap, 0);
    return root;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
