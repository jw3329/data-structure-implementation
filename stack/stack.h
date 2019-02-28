#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack {
   private:
    T *arr;
    int index;
    int maxSize;

   public:
    Stack(int size);
    bool isEmpty();
    bool push(T item);
    T pop();
};

template <class T>
Stack<T>::Stack(int size) {
    arr = new T[size];
    index = -1;
    maxSize = size;
}
template <class T>
bool Stack<T>::isEmpty() {
    if (index == -1) return true;
    return false;
}
template <class T>
bool Stack<T>::push(T item) {
    if (index == maxSize - 1) return false;
    arr[++index] = item;
    return true;
}
template <class T>
T Stack<T>::pop() {
    if (index == -1) return 0;
    T ret = arr[index];
    arr[index--] = 0;
    return ret;
}

#endif
