#include "linked_list.h"
#include <iostream>
using namespace std;

LinkedList::Node::Node()
{
    val = 0;
    next = nullptr;
    prev = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

void LinkedList::printList()
{
    Node *cur = head;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::insertFront(int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LinkedList::insertBack(int val)
{
    Node *newNode = new Node();
    newNode->val = val;
    if(!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int LinkedList::deleteFirstMatchingVal(int val)
{
    if(!head) return INT_MIN;
    Node *cur = head;
    while (cur && cur->val != val) cur = cur->next;
    int ret = cur->val;
    if(cur == head) {
        head = cur->next;
    } else if(cur == tail) {
        tail = tail->prev;
    } else {
        Node *prevNode = cur->prev;
        Node *nextNode = cur->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    delete cur;
    return ret;
}

int LinkedList::deletePosition(position)