#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *nextPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->nextPointer = NULL;
    }
};

void insertAtTail(Node *&head, Node *&tail, int integerValue)
{
    Node *newNode = new Node(integerValue);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextPointer = newNode;
        tail = newNode;
    }
}

void sortDescending(Node *&head)
{
    Node *tmp = head;
    for (Node *i = tmp; i->nextPointer != NULL;)
    {
        for (Node *j = i->nextPointer; j != NULL;)
        {
            if (i->integerValue < j->integerValue)
            {
                int swapValue = i->integerValue;
                i->integerValue = j->integerValue;
                j->integerValue = swapValue;
            }
            j = j->nextPointer;
        }
        i = i->nextPointer;
    }
}

void printLinkedList(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->nextPointer;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int inputValue;
    while (true)
    {
        cin >> inputValue;
        if (inputValue == -1)
        {
            break;
        }
        else
        {
            insertAtTail(head, tail, inputValue);
        }
    }

    sortDescending(head);
    printLinkedList(head);

    return 0;
}