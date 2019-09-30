#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class MinHeap {
   private:
    int *arr;
    int capacity;
    int size;

    void minHeapify(int index);

   public:
    MinHeap(int capacity);
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin();
    void decreaseKey(int i, int newVal);
    int getMin();
    void deleteKey(int i);
    void insertKey(int k);
};

#endif