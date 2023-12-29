#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int val)
    {
        data = val;
    }
};
Node *createTree()
{
    int val;
    cout << "Enter the value" << endl;
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    Node *newNode = new Node(val);
    // left child
    cout << "Left child of the " << newNode->data << endl;
    newNode->left = createTree();

    // left child
    cout << "Right child of the " << newNode->data << endl;
    newNode->right = createTree();
}
main()
{
    Node *root = createTree();
}