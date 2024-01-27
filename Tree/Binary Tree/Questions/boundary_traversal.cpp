/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution
{
public:
    void rightTriversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        if (root->right)
            rightTriversal(root->right, ans);
        else
        {
            rightTriversal(root->left, ans);
        }
        ans.push_back(root->data);
    }
    void leafTriversal(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
        leafTriversal(root->left, ans);
        leafTriversal(root->right, ans);
    }
    void leftTriversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;
        ans.push_back(root->data);
        if (root->left)
            leftTriversal(root->left, ans);
        else
        {
            leftTriversal(root->right, ans);
        }
    }
    void f(Node *root, vector<int> &ans)
    {
        ans.push_back(root->data);
        leftTriversal(root->left, ans);
        leafTriversal(root->left, ans);
        leafTriversal(root->right, ans);
        rightTriversal(root->right, ans);
    }
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        if (!root)
            return ans;
        f(root, ans);
        return ans;
    }
};