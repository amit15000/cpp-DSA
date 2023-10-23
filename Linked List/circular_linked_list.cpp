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
void DeleteNode(Node *(&head), Node *(&tail), int rmData)
{
    // deletion occurs on basic of he data value.
    // case 1

    if (head == NULL)
    {
        cout << "There are no nodes in the linked list";
        return;
    }

    // CASE 2
    if (head == tail)
    {
        // single node exists
        if (head->data == rmData)
        {
            delete head;
            head = NULL;
            tail = NULL;

            return;
        }
    }

    // CASE 3 element is at head
    if (head->data == rmData)
    {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete temp;
        return;
    }

    Node *temp = head;
    do
    {
        if (temp->data == rmData)
        {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
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

    head->prev = tail;
    tail->next = head;
}
void InsertAtTail(Node *(&head), Node *(&tail), int _val)
{
    Node *newNode = new Node(_val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = head;
    head->prev = tail;
}

void printLinkedListH(Node *(head))
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "There are no nodes in the linked list";
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
void printLinkedListT(Node *(tail))
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "There are no nodes in the linked list";
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != tail);
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

    InsertAtTail(head, tail, 20);
    InsertAtTail(head, tail, 32);
    InsertAtTail(head, tail, 31);
    InsertAtTail(head, tail, 24);
    InsertAtTail(head, tail, 32);
    InsertAtTail(head, tail, 54);

    // cout << tail->data << endl;

    printLinkedListH(head);
    // printLinkedListT(tail);
    DeleteNode(head, tail, 10);
    DeleteNode(head, tail, 54);
    printLinkedListH(head);
    // DeleteNode(7, head, tail);
    // DeleteNode(0, head, tail);
    // // DeleteNode(10, head, tail);
    // // DeleteNode(20, head, tail);
    // DeleteNode(8, head, tail);
    // printLinkedListH(head, tail);
    return 0;
}