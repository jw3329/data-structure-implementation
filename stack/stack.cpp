#include "stack.h"

const int max_size = 1000;

Stack::Stack() {
	stack = new int[max_size];
	index = -1;
}

bool Stack::isEmpty() {
	if(index == -1) return true;
	return false;
}

bool Stack::push(int num) {
	if(index == max_size - 1) return false;
	stack[++index] = num;
	cout << "pushed : " << num << endl;
	return true;
}

int Stack::pop() {
	if(index == -1) return 0;
	int ret = stack[index];
	stack[index--] = 0;
	return ret;
}