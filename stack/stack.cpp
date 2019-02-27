#include <iostream>
#include <ctime>
using namespace std;

const int max_size = 1000;


class Stack {
	private:
		int stack[max_size];
		int index;
	public:
		Stack();
		bool isEmpty();
		bool push(int num);
		int pop();
};

Stack::Stack() {
	stack[max_size] = {};
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
	
int main() {
	Stack s;
	srand(time(NULL));
	for(int i=0;i<1001;i++) {
		if(!s.push(rand() % 1000)) {
			cout << "Stack Overflow" << endl;
		}
	}
	while(!s.isEmpty()) {
		cout << s.pop() << endl;
	}
	return 0;
}
