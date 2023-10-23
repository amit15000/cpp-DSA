#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructors

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int _d)
    {
        this->data = _d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void InsertAtHead(Node *(&head), Node *(&tail), int _val)
{
    Node *newNode = new Node(_val);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void InsertAtTail_using_head(Node *(head), int _val)
{

    while (head->next != NULL)
    {
        head = head->next;
    }
    Node *newNode = new Node(_val);

    head->next = newNode;
    newNode->next = head;
    // head = newNode; // this line is useless
}
void InsertAtTail_using_tail(Node *(&head), Node *(&tail), int _val)
{
    Node *newNode = new Node(_val);
    // its first node of the linked list
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void printLinkedListH(Node *(head))
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printLinkedListT(Node *(tail))
{

    while (tail != NULL)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = head;
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 2);
    InsertAtHead(head, tail, 40);
    InsertAtHead(head, tail, 113);

    InsertAtTail_using_tail(head, tail, 20);
    InsertAtTail_using_tail(head, tail, 32);
    InsertAtTail_using_tail(head, tail, 31);
    InsertAtTail_using_tail(head, tail, 24);
    InsertAtTail_using_tail(head, tail, 32);
    InsertAtTail_using_tail(head, tail, 54);

    printLinkedListH(head);
    printLinkedListT(tail);
    // DeleteNode(3, head, tail);
    // printLinkedList(head);
    // DeleteNode(4, head, tail);
    // printLinkedList(head);
    // DeleteNode(4, head, tail);
    // printLinkedList(head);
    // DeleteNode(0, head, tail);
    // printLinkedList(head);
    // DeleteNode(0, head, tail);
    // printLinkedList(head);
    // DeleteNode(0, head, tail);
    // printLinkedList(head);
    // DeleteNode(3, head, tail);

    return 0;
}