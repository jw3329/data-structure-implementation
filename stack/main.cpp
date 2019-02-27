#include <ctime>
#include "stack.h"

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
