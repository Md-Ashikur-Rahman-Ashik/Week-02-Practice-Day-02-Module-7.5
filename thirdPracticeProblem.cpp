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

int countMaximum(Node *&head)
{
    int maximumValue = -1000000000;
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->integerValue > maximumValue)
        {
            maximumValue = tmp->integerValue;
        }

        tmp = tmp->nextPointer;
    }

    return maximumValue;
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

    int result = countMaximum(head);
    cout << result << endl;

    return 0;
}