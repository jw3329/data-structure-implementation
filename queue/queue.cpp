#include "queue.h"

#define INT_MIN -99999

Queue::Queue(int capacity) {
	this->capacity = capacity;
	mfront = 0;
	mrear = capacity - 1;
	arr = new int[capacity];
}

bool Queue::isFull() {
	return capacity == size;
}

bool Queue::isEmpty() {
	return size == 0;
}

void Queue::enqueue(int item) {
	if(isFull()) return;
	mrear = (mrear + 1) % capacity;
	arr[mrear] = item;
	size++;
}

int Queue::dequeue() {
	if(isEmpty()) return INT_MIN;
	int item = arr[mfront];
	mfront = (mfront + 1) % capacity;
	size--;
	return item;
}

int Queue::front() {
	return !isEmpty() ? arr[mfront] : INT_MIN;
}

int Queue::rear() {
	return !isEmpty() ? arr[mrear] : INT_MIN;
}
