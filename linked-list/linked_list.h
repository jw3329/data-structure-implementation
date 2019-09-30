#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

class LinkedList
{
  public:
    LinkedList();
    void printList();
    void insertFront(int val);
    void insertBack(int val);
    int deleteFirstMatchingVal(int val);
    int deletePosition(int position);
    LinkedList *reverse();
    LinkedList *mergeSort();
    ~LinkedList();

  private:
    Node *head, *tail;
    LinkedList *merge(LinkedList *first, LinkedList *second);
};

#endif