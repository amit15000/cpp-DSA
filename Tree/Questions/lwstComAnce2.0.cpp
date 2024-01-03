class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root == p || root == q)
        {
            return root;
        }
        TreeNode *tempRoot = root;
        // check left-side for first pair
        TreeNode *fisrtNode = lowestCommonAncestor(root->left, p, q);
        // check right-side for second pair
        TreeNode *secondNode = lowestCommonAncestor(root->right, p, q);

        if (fisrtNode != NULL && secondNode != NULL)
        {
            // both pairs found-->tempRoot will be lca
            return tempRoot;
        }
        else if (fisrtNode == NULL && secondNode != NULL)
        {
            return secondNode;
        }
        else if (fisrtNode != NULL && secondNode == NULL)
        {
            return fisrtNode;
        }
        else
        {
            // p and q both are in same branch -->so return p or q (means ) ;
            return NULL;
        }
    }
};