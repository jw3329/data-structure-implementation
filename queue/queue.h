#ifndef QUEUE_H
#define QUEUE_H

#include <string>

template <class T>
class Queue {
   private:
    int mfront;
    int mrear;
    int size;
    int capacity;
    T* arr;

   public:
    Queue(int capacity);
    bool isFull();
    bool isEmpty();
    void enqueue(T item);
    T dequeue();
    T front();
    T rear();
};

template <class T>
Queue<T>::Queue(int capacity) {
    this->capacity = capacity;
    mfront = 0;
    mrear = capacity - 1;
    size = 0;
    arr = new T[capacity];
}
template <class T>
bool Queue<T>::isFull() {
    return capacity == size;
}
template <class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
template <class T>
void Queue<T>::enqueue(T item) {
    if (isFull()) return;
    mrear = (mrear + 1) % capacity;
    arr[mrear] = item;
    size++;
}

template <class T>
T Queue<T>::dequeue() {
    if (isEmpty()) return 0;
    T item = arr[mfront];
    mfront = (mfront + 1) % capacity;
    size--;
    return item;
}

template <class T>
T Queue<T>::front() {
    if (isEmpty()) return 0;
    return arr[mfront];
}

template <class T>
T Queue<T>::rear() {
    if (isEmpty()) return 0;
    return arr[mrear];
}

#endif