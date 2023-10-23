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
    ~Node()
    {

        printf("===>>>  %d deleted from the list.\n", this->data);
    }
};
void DeleteNodeFromHead(Node *(&head))
{
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void DeleteNodeFromTail(Node *(&head), Node *(&tail))
{
    // Ptail --> previous of the tail
    Node *Ptail = head;
    while (Ptail->next != tail)
    {
        Ptail = Ptail->next;
    }
    Ptail->next = NULL;
    delete tail;
    tail = Ptail;
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
    (tempCurrent->next)->prev = tempP;
    delete tempCurrent;
}

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
    DeleteNode(4, head, tail);
    DeleteNode(7, head, tail);
    DeleteNode(0, head, tail);
    // DeleteNode(10, head, tail);
    // DeleteNode(20, head, tail);
    DeleteNode(8, head, tail);
    printLinkedListH(head);
    return 0;
}