#include "min_heap.h"

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    size = 0;
    arr = new int[capacity];
}

int MinHeap::parent(int i) { return (i - 1) / 2; }

int MinHeap::left(int i) { return 2 * i + 1; }

int MinHeap::right(int i) { return 2 * i + 2; }

int MinHeap::getMin() { return arr[0]; }

int MinHeap::extractMin() {}