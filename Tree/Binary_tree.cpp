#include <iostream>
using namespace std;
#include <queue>
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
    // Root Left Right
    if (root == nullptr)
    {
        return;
    }
    // current
    cout << root->data << " ";
    // left child
    preOrderTraversal(root->left);
    // right child
    preOrderTraversal(root->right);
}
void InOrderTraversal(Node *root)
{
    // Left Root Right
    if (root == nullptr)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
void PostOrderTraversal(Node *root)
{
    // Left Right Root
    if (root == nullptr)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    // while (q.size() > 1)
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void morrisTraversalInOrder(Node *root)
{
    if (!root)
        return;
    Node *pre, *current;
    current = root;

    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // find precdecer
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

void morrisTraversalPreOrder(Node *root)
{
    if (!root)
        return;
    Node *pre, *current;
    current = root;

    while (current != NULL)
    {

        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            // find precdecer
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
            {
                pre = pre->right;
            }

            if (pre->right == NULL)
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                current = current->right;
            }
        }
    }
}
int main()
{
    Node *root = createTree();

    // cout << "Pre Order : ";
    // preOrderTraversal(root);
    // cout << endl;
    // cout << "In Order : ";
    // InOrderTraversal(root);
    // cout << endl;
    // cout << "Post Order : ";
    // PostOrderTraversal(root);
    // cout << endl;
    // cout << "Level Order Traversal : " << endl;
    // levelOrderTraversal(root);

    cout << "Morris Traversal InOrder: " << endl;
    morrisTraversalInOrder(root);

    cout << "Morris Traversal PreOrder: " << endl;
    morrisTraversalPreOrder(root);

    cout << endl;
}
