#include "min_heap.h"
#include <climits>
#include <iostream>

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    size = 0;
    arr = new int[capacity];
}

int MinHeap::parent(int i) { return (i - 1) / 2; }

int MinHeap::left(int i) { return 2 * i + 1; }

int MinHeap::right(int i) { return 2 * i + 2; }

int MinHeap::getMin() { return arr[0]; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MinHeap::minHeapify(int index) {
    int l = left(index);
    int r = right(index);
    int smallest = index;
    if (l < size && arr[l] > arr[smallest]) smallest = l;
    if (r < size && arr[r] > arr[smallest]) smallest = r;
    if (smallest != index) {
        swap(&arr[smallest], &arr[index]);
        minHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (size <= 0) return INT_MAX;
    int root = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int newVal) {
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] > arr[i]) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
    // minHeapify(i);
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k) {
    if (size == capacity) {
        std::cout << "Overflow: Could not insertKey" << std::endl;
        return;
    }
    size++;
    int index = size - 1;
    arr[index] = k;

    while (index != 0 && arr[parent(index)] > arr[index]) {
        swap(&arr[index], &arr[parent(index)]);
        index = parent(index);
    }
    // minHeapify(index);
}