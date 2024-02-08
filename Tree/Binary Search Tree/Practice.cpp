#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(int d)
    {
        this->data = d;
    }
};

Node *insertInBST(Node *root, int key)
{
    if (root == nullptr)
    {
        root = new Node(key);
        return root;
    }

    if (key >= root->data)
    {
        root->right = insertInBST(root->right, key);
    }
    if (key < root->data)
    {
        root->left = insertInBST(root->left, key);
    }
    return root;
}
void createBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
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
int main()
{
    Node *root = nullptr;
    createBST(root);
    levelOrderTraversal(root);
}