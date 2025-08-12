#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int data)
    {
        this->val = data;
    }
};
TreeNode *createTree(TreeNode *root)
{
    int val;
    cout << "Value :";
    cin >> val;

    if (val == -1)
        return nullptr;
    else
    {
        TreeNode *newNode = new TreeNode(val);
        cout << "Left Child of " << val << " :";
        newNode->left = createTree(newNode);

        cout << "Right Child of " << val << " :";
        newNode->right = createTree(newNode);
    }
}
void createMap(map<int, int> &nodetoIndexMap, vector<int> &InOrder)
{
    int i = 0;
    for (auto val : InOrder)
    {
        nodetoIndexMap[val] = i++;
    }
}

TreeNode *solve(vector<int> &preOrder, vector<int> &InOrder, int &preOrderIndex, int inOrderStart, int inOrderEnd, map<int, int> &nodetoIndexMap)
{
    // base condition
    if (preOrderIndex >= preOrder.size() || inOrderStart > inOrderEnd)

    {
        return nullptr;
    }

    int element = preOrder[preOrderIndex++];
    TreeNode *root = new TreeNode(element);
    int positionInInOrder = nodetoIndexMap[element];
    root->left = solve(preOrder, InOrder, preOrderIndex, inOrderStart, positionInInOrder - 1, nodetoIndexMap);
    root->right = solve(preOrder, InOrder, preOrderIndex, positionInInOrder + 1, inOrderEnd, nodetoIndexMap);

    return root;
}
void preOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front != NULL)
        {
            cout << front->val << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}

int main()
{
    TreeNode *root = createTree(root);

    // vector<int> preOrder = {10, 20, 40, 50, 60, 70, 30, 80};
    // vector<int> InOrder = {40, 20, 60, 70, 50, 10, 30, 80};
    // map<int, int> nodetoIndexMap;
    // createMap(nodetoIndexMap, InOrder);

    // int preOrderIndex = 0;
    // int inOrderStart = 0;
    // int inOrderEnd = InOrder.size() - 1;
    // TreeNode *root = solve(preOrder, InOrder, preOrderIndex, inOrderStart, inOrderEnd, nodetoIndexMap);

    // preOrderTraversal(root);
    levelOrderTraversal(root);
}