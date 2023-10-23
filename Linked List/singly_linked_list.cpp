#include <bits/stdc++.h>
using namespace std;

// New branch --> Linked_List
class Node
{
public:
    int data;
    Node *next;

    // constructors

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int _d)
    {
        this->data = _d;
        this->next = NULL;
    }
};

void *InsertAtHead(Node *(&head), int _val)
{

    // if (head == NULL)
    // {
    //     head = new Node(_val);
    // }
    // else
    // {
    //     Node *newNode = new Node(_val);
    //     newNode->next = head;
    //     head = newNode;
    // }

    // this much is also enough
    Node *newNode = new Node(_val);
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(Node *(head), int _val)
{

    while (head->next != NULL)
    {
        head = head->next;
    }
    Node *newNode = new Node(_val);

    head->next = newNode;
    head = newNode;
}
void InsertAtPosition(Node *(&head), int p, int _val)
{
    Node *newNode = new Node(_val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // insertion at head
    if (p == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // insert at position mid or end
    Node *tempPrev = head;
    for (int i = 1; i < p - 1; i++)
    {
        tempPrev = tempPrev->next;
    }
    Node *tempNext = tempPrev->next;

    newNode->next = tempNext;
    tempPrev->next = newNode;
}
void printLinkedList(Node *(head))
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{

    Node *head = NULL;
    Node *tail = head;
    // InsertAtHead(head, 112);
    // InsertAtHead(head, 113);
    // InsertAtTail(head, 12);
    // InsertAtTail(head, -5);
    // InsertAtTail(head, 45);
    // InsertAtTail(head, 78);
    // InsertAtTail(head, 34);

    // insert at position

    InsertAtPosition(head, 0, 34);
    InsertAtPosition(head, 0, 24);
    InsertAtPosition(head, 0, 14);
    InsertAtPosition(head, 0, 4);
    printLinkedList(head);
    return 0;
}