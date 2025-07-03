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

void countSize(Node *head, int *&countPointer)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->nextPointer;
    }

    if (*countPointer < 0)
    {
        *countPointer = count;
    }
    else if (*countPointer > count || *countPointer < count)
    {
        cout << "NO";
    }
    else if (*countPointer == count)
    {
        cout << "YES";
    }
}

int main()
{
    int desiredCount = -10;
    int *countPointer = &desiredCount;
    for (int i = 0; i < 2; i++)
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

        countSize(head, countPointer);
    }

    return 0;
}