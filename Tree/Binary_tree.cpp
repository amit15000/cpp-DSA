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
        return nullptr;
    }
    Node *newNode = new Node(val);
    // left child
    cout << "Left child of the " << newNode->data << endl;
    newNode->left = createTree();

    // left child
    cout << "Right child of the " << newNode->data << endl;
    newNode->right = createTree();
}
void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    // left child
    preOrderTraversal(root->left);
    // right child
    preOrderTraversal(root->right);
}

int main()
{
    Node *root = createTree();

    preOrderTraversal(root);
    // InOrderTraversal(root);
}