#include "linked_list.h"
#include <iostream>
using namespace std;

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
    if (!tail)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int handleDelete(Node *cur, Node *head, Node *tail)
{
    if (!head)
        return INT_MIN;
    int ret = cur->val;
    if (cur == head)
    {
        head = head->next;
        head->prev = nullptr;
    }
    else if (cur == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else
    {
        Node *prevNode = cur->prev;
        Node *nextNode = cur->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    delete cur;
    return ret;
}

int LinkedList::deleteFirstMatchingVal(int val)
{
    Node *cur = head;
    while (cur && cur->val != val)
        cur = cur->next;
    return handleDelete(cur, head, tail);
}

int LinkedList::deletePosition(int position)
{
    Node *cur = head;
    for (int i = 0; cur && i < position; i++)
        cur = cur->next;
    return handleDelete(cur, head, tail);
}

LinkedList *LinkedList::reverse()
{
    if (!head)
        return nullptr;
    Node *originHead = head;
    Node *newNode = new Node();
    newNode->val = originHead->val;
    head = head->next;
    if (head)
        head->prev = nullptr;
    LinkedList *nextReversed = reverse();
    if (!nextReversed)
    {
        nextReversed = new LinkedList();
        nextReversed->head = nextReversed->tail = newNode;
    }
    else
    {
        nextReversed->tail->next = newNode;
        newNode->prev = nextReversed->tail;
        nextReversed->tail = newNode;
    }
    if (head)
        head->prev = originHead;
    head = originHead;
    return nextReversed;
}

LinkedList *LinkedList::merge(LinkedList *first, LinkedList *second)
{
    LinkedList *linkedList = new LinkedList();
    Node *firstCur = first->head;
    Node *secondCur = second->head;

    while (firstCur && secondCur)
    {
        if (firstCur->val < secondCur->val)
        {
            linkedList->insertBack(firstCur->val);
            firstCur = firstCur->next;
        }
        else
        {
            linkedList->insertBack(secondCur->val);
            secondCur = secondCur->next;
        }
    }
    while (firstCur)
    {
        linkedList->insertBack(firstCur->val);
        firstCur = firstCur->next;
    }
    while (secondCur)
    {
        linkedList->insertBack(secondCur->val);
        secondCur = secondCur->next;
    }
    delete first;
    delete second;
    return linkedList;
}

LinkedList *LinkedList::mergeSort()
{
    if (!head)
        return nullptr;
    if (head == tail)
    {
        LinkedList *linkedList = new LinkedList();
        linkedList->insertBack(head->val);
        return linkedList;
    }
    int count = 0;
    Node *cur = head;
    while (cur)
    {
        cur = cur->next;
        count++;
    }
    LinkedList *firstLinkedList = new LinkedList();
    LinkedList *secondLinkedList = new LinkedList();
    cur = head;
    for (int i = 0; i < count; i++)
    {
        if (i < (count / 2))
        {
            firstLinkedList->insertBack(cur->val);
        }
        else
        {
            secondLinkedList->insertBack(cur->val);
        }
        cur = cur->next;
    }
    LinkedList *firstSorted = firstLinkedList->mergeSort();
    LinkedList *secondSorted = secondLinkedList->mergeSort();
    return merge(firstSorted, secondSorted);
}

LinkedList::~LinkedList()
{
    Node *cur = head;
    while (cur)
    {
        Node *curNext = cur->next;
        delete cur;
        cur = curNext;
    }
}