#include <ctime>
#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue<int> queue(2000);
    srand(time(NULL));

    for (int i = 0; i < 2000; i++) {
        int num = rand();
        queue.enqueue(num);
        cout << "Enqueued : " << num << endl;
    }

    while (!queue.isEmpty()) {
        cout << queue.dequeue() << endl;
    }

    return 0;
}
