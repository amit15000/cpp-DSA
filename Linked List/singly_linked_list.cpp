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
    InsertAtHead(head, 112);
    InsertAtHead(head, 113);
    InsertAtTail(head, 12);
    InsertAtTail(head, -5);
    InsertAtTail(head, 45);
    InsertAtTail(head, 78);
    InsertAtTail(head, 34);

    // InsertAtHead(head, 345);
    // InsertAtHead(head, 43);
    // InsertAtHead(head, 7);
    // InsertAtHead(head, 11);
    printLinkedList(head);
    return 0;
}