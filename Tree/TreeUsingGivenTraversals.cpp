#include <iostream>
#include <vector>
#include <map>
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
        return root;
    else
    {
        TreeNode *newNode = new TreeNode(val);
        cout << "Left Child of " << val << " :";
        newNode->left = createTree(newNode);

        cout << "Right Child of " << val << " :";
        newNode->right = createTree(newNode);
    }
}
void createMap(map<int, int> &nodetoIndexMap, vector<int> &preOrder)
{
    int i = 0;
    for (auto val : preOrder)
    {
        nodetoIndexMap[i++] = val;
    }
}
int main()
{
    // TreeNode *root = createTree(root);

    vector<int> preOrder = {10, 20, 40, 50, 60, 70, 30, 80};
    vector<int> InOrder = {40, 20, 60, 70, 50, 10, 30, 80};
    map<int, int> nodetoIndexMap;
    createMap(nodetoIndexMap, preOrder);

    preOrderIndex = 0;
    TreeNode *root = sovle(preOrder, InOrder, )
}