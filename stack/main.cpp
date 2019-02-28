#include <ctime>
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack<int> s(1000);
    srand(time(NULL));
    for (int i = 0; i < 1001; i++) {
        if (!s.push(rand() % 1000)) {
            cout << "Stack Overflow" << endl;
        }
    }
    while (!s.isEmpty()) {
        cout << s.pop() << endl;
    }
    return 0;
}
