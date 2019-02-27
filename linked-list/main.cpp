#include "linked_list.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    LinkedList linkedList;
    srand(time(nullptr));
    for (int i = 0; i < 1000; i++)
    {
        linkedList.insertBack(rand());
    }
    cout << "head to tail values in the linked list : " << endl;
    linkedList.printList();
    cout << endl;
    LinkedList *reversed = linkedList.reverse();
    cout << "head to tail values in the reversed linked list : " << endl;
    reversed->printList();
    cout << endl;
    cout << "head to tail values in the merged linked list : " << endl;
    LinkedList *mergeSorted = reversed->mergeSort();
    mergeSorted->printList();
    delete mergeSorted;
    delete reversed;
    return 0;
}