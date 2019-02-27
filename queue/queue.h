#ifndef QUEUE_H
#define QUEUE_H

class Queue {
	private:
		int mfront;
		int mrear;
		int size;
		int capacity;
		int *arr;
	public:
		Queue(int capacity);
		bool isFull();
		bool isEmpty();
		void enqueue(int item);
		int dequeue();
		int front();
		int rear();
};

#endif
