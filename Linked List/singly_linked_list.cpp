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

int main()
{
    cout << "Enter the number of nodes : ";
    int n;
    cin >> n;

    int j = 10;

    Node *head = new Node(9);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        Node *newNode = new Node(j++);
        temp->next = newNode;
        temp = newNode;
    }
    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}