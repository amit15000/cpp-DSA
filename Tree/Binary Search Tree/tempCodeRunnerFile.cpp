{
    if (root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }
    if (data < root->val)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}