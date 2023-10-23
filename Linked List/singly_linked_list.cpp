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
Node *InsertAtHead(int _val)
{
    Node *head = new Node(_val);
    return head;
}

int main()
{
    Node *head = InsertAtHead(10);
    cout << head->data << endl;
    return 0;
}