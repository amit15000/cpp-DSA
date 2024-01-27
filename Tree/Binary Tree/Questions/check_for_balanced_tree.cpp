#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class Solution
{
public:
    // Function to check whether a binary tree is balanced or not.
    int treeHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }

    bool isBalanced(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        int absHeight = abs(leftHeight - rightHeight);
        bool isCurrNodeBalanced = false;
        if (absHeight <= 1)
        {
            isCurrNodeBalanced = true;
        }

        bool isLeftBalanced = isBalanced(root->left);
        bool isRightBalanced = isBalanced(root->right);

        if (isCurrNodeBalanced && isLeftBalanced && isRightBalanced)
        {
            return true;
        }
        return false;
    }
};
