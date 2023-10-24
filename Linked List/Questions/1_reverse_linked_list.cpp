#include <bits/stdc++.h>
using namespace std;

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
    head = newNode;
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

    tail = newNode;
}
void DeleteNodeFromHead(Node *(&head))
{
    Node *temp = head;
    head = head->next;

    delete temp;
}
void DeleteNodeFromTail(Node *(&head), Node *(&tail))
{
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}
int len_of_list(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
void DeleteNode(int p, Node *(&head), Node *(&tail))
{
    if (head == NULL)
    {
        cout << "There is no node present in the linked list" << endl;
        return;
    }

    // delete from head

    // case 1  there is only 1 node (head) is present
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // case 2 delete from head
    if (p <= 0)
    {
        DeleteNodeFromHead(head);
        return;
    }

    int len = len_of_list(head);
    // case 3 delete from tail
    if (p >= len)
    {
        DeleteNodeFromTail(head, tail);
        return;
    }

    // Case 4   -- deletion- in - between
    Node *tempP = head;
    int i = 1;
    while (i < p - 1)
    {
        tempP = tempP->next;
        i++;
    }
    Node *tempCurrent = tempP->next;
    // Node *tempNN = tempCurrent->next;  //trying without it
    tempP->next = tempCurrent->next;
    delete tempCurrent;
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
Node *ReverseList(Node *head, Node *(prev))
{
    // base condition
    if (head == NULL)
    {
        return prev;
    }

    Node *temp = head;
    head = head->next;
    temp->next = prev;
    prev = temp;
    ReverseList(head, prev);
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
    InsertAtTail_using_tail(head, tail, 30);
    // InsertAtTail_using_tail(head, tail, 40);
    printLinkedList(head);

    Node *(prev) = NULL;
    head = ReverseList(head, prev);
    printLinkedList(head);

    return 0;
}