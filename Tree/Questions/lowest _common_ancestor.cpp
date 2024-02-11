class Solution
{
public:
    TreeNode *checkCurrentNode(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }
        TreeNode *secondPairL = checkCurrentNode(root->left, p, q);
        if (secondPairL != NULL)
        {
            return secondPairL;
        }
        TreeNode *secondPairR = checkCurrentNode(root->right, p, q);
        if (secondPairR != NULL)
        {
            return secondPairR;
        }
        return NULL;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
        {
            return root;
        }
        if (root == NULL)
        {
            return NULL;
        }
        TreeNode *temp = root;

        TreeNode *leftTree = lowestCommonAncestor(root->left, p, q);

        // case 1
        TreeNode *secondPL = checkCurrentNode(temp, p, q);
        if (leftTree != NULL && secondPL != NULL)
        {
            return temp;
        }
        else if (leftTree != NULL && secondPL == NULL)
        {
            return leftTree;
        }
        else
        {
            return NULL;
        }

        TreeNode *rightTree = lowestCommonAncestor(root->right, p, q);

        TreeNode *secondPR = checkCurrentNode(temp, p, q);
        if (rightTree != NULL && secondPR != NULL)
        {
            return temp;
        }
        else if (rightTree != NULL && secondPR == NULL)
        {
            return rightTree;
        }
        else
        {
            return NULL;
        }
    }
};