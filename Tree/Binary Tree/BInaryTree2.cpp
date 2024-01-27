// Creating Binary tree
#include <iostream>
#include <queue>
#include <map>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    // construction
    TreeNode(int d)
    {
        val = d;
    }
};
TreeNode *createTree()
{
    // creating root
    int d;
    cout << "Enter Value: "
         << " ";
    cin >> d;

    if (d == -1)
    {
        return nullptr;
    }

    TreeNode *newNode = new TreeNode(d);

    cout << "Left  child of --> " << newNode->val << "-->";
    newNode->left = createTree();

    cout << "Right child of --> " << newNode->val << "-->";
    newNode->right = createTree();
}
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << endl;
        }
        else
        {
            cout << front->val << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}
vector<int> zigZagTraversal(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front();
            q.pop();

            // normal insert or reverses insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = front->val;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}
void preOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}
void InOrderTraversal(TreeNode *root)
{
    if (!root)
        return;
    InOrderTraversal(root->left);
    cout << root->val << " ";
    InOrderTraversal(root->right);
}
void createMap(vector<int> &inOrder, map<int, int> &valueToIndexMap)
{
    int j = 0;
    for (auto i : inOrder)
    {
        valueToIndexMap[i] = j++;
    }
}
TreeNode *treeUsingPreOandInOrder(vector<int> &preOrder, int &preOrderIndex, vector<int> &inOrder, map<int, int> &valueToIndexMap, int inOrderStartingIndex, int inOrderEndingIndex)
{
    // base case
    if (preOrderIndex >= preOrder.size() || inOrderStartingIndex > inOrderEndingIndex)
    {
        return NULL;
    }

    int rootVal = preOrder[preOrderIndex++];
    TreeNode *root = new TreeNode(rootVal);

    // create a map too search in O(1)
    int positionInInOrder = valueToIndexMap[rootVal];

    root->left = treeUsingPreOandInOrder(preOrder, preOrderIndex, inOrder, valueToIndexMap, inOrderStartingIndex, positionInInOrder - 1);
    root->right = treeUsingPreOandInOrder(preOrder, preOrderIndex, inOrder, valueToIndexMap, positionInInOrder + 1, inOrderEndingIndex);

    return root;
}
TreeNode *treeUsingPostOandInOrder(vector<int> &postOrder, int &postOrderIndex, vector<int> &inOrder, map<int, int> &valueToIndexMap, int inOrderStartingIndex, int inOrderEndingIndex)
{
    // base case
    if (postOrderIndex < 0 || inOrderStartingIndex > inOrderEndingIndex)
    {
        return NULL;
    }

    int rootVal = postOrder[postOrderIndex--];
    TreeNode *root = new TreeNode(rootVal);

    // create a map too search in O(1)
    int positionInInOrder = valueToIndexMap[rootVal];

    root->right = treeUsingPostOandInOrder(postOrder, postOrderIndex, inOrder, valueToIndexMap, positionInInOrder + 1, inOrderEndingIndex);
    root->left = treeUsingPostOandInOrder(postOrder, postOrderIndex, inOrder, valueToIndexMap, inOrderStartingIndex, positionInInOrder - 1);

    return root;
}
int main()
{
    // TreeNode *root = createTree();

    // cout << endl
    //      << "InOrder Traversal : ";
    // InOrderTraversal(root);
    // cout << endl
    //      << "PreOrder Traversal : ";
    // preOrderTraversal(root);
    // cout << endl
    //      << "PostOrder Traversal : ";
    // postOrderTraversal(root);

    // cout << endl
    //      << "Level Order Traversal : " << endl;
    // levelOrderTraversal(root);

    // vector<int> preOrder = {10, 20, 40, 50, 80, 90, 30, 60, 70};
    // vector<int> inOrder = {40, 20, 80, 50, 90, 10, 60, 30, 70};

    // vector<int> preOrder = {4, 8, 2, 5, 1, 6, 3, 7};
    // vector<int> inOrder = {8, 4, 5, 2, 6, 7, 3, 1};
    // int preOrderIndex = 0;
    // int inOrderStartingIndex = 0;
    // int inOrderEndingIndex = inOrder.size() - 1;

    // map<int, int> valueToIndexMap;
    // createMap(inOrder, valueToIndexMap);

    // TreeNode *root = treeUsingPreOandInOrder(preOrder, preOrderIndex, inOrder, valueToIndexMap, inOrderStartingIndex, inOrderEndingIndex);
    // levelOrderTraversal(root);

    vector<int> inOrder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postOrder = {8, 4, 5, 2, 6, 7, 3, 1};
    int postOrderIndex = postOrder.size() - 1;
    int inOrderStartingIndex = 0;
    int inOrderEndingIndex = inOrder.size() - 1;
    map<int, int> valueToIndexMap;
    createMap(inOrder, valueToIndexMap);

    TreeNode *root = treeUsingPostOandInOrder(postOrder, postOrderIndex, inOrder, valueToIndexMap, inOrderStartingIndex, inOrderEndingIndex);
    cout << endl
         << "InOrder Traversal : ";
    InOrderTraversal(root);
    cout << endl
         << "PreOrder Traversal : ";
    preOrderTraversal(root);
    cout << endl
         << "PostOrder Traversal : ";
    postOrderTraversal(root);

    cout << endl
         << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
}