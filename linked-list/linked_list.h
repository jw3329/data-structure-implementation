#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
  public:
    class Node
    {
      public:
        int val;
        Node *next;
        Node *prev;
        Node();
    };
    LinkedList();
    void printList();
    void insertFront(int val);
    void insertBack(int val);
    int deleteFirstMatchingVal(int val);
    int deletePosition(int position);
    Node *reverse();
    Node *mergeSort();
    ~LinkedList();

  private:
    Node *head, *tail;
};

#endif