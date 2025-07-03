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

int calculateListSize(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->nextPointer;
    }

    return count;
}

void insertAtAnyPosition(Node *&head, int desiredIndex, int desiredValue)
{
    Node *newNode = new Node(desiredValue);
    Node *tmp = head;

    if (desiredIndex != 0)
    {
        for (int i = 0; i < desiredIndex - 1; i++)
        {
            tmp = tmp->nextPointer;
        }
        newNode->nextPointer = tmp->nextPointer;
        tmp->nextPointer = newNode;
    }
    else
    {
        newNode->nextPointer = head;
        head = newNode;
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
    cout << endl;
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

    int desiredQueries;
    cin >> desiredQueries;

    for (int i = 0; i < desiredQueries; i++)
    {
        int desiredIndex, desiredValue;
        cin >> desiredIndex >> desiredValue;

        int listSize = calculateListSize(head);

        if (listSize < desiredIndex)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insertAtAnyPosition(head, desiredIndex, desiredValue);
            printLinkedList(head);
        }
    }

    return 0;
}