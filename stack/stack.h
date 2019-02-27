#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
	private:
		int *stack;
		int index;
	public:
		Stack();
		bool isEmpty();
		bool push(int num);
		int pop();
};

#endif