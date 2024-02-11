// LeetCOde 113

class Solution
{
public:
    void solve(TreeNode *root, int targetSum, vector<vector<int>> &ans, vector<int> &tempV)
    {
        if (!root)
            return;

        tempV.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum)
        {
            ans.push_back(tempV);
        }

        solve(root->left, targetSum - root->val, ans, tempV);
        solve(root->right, targetSum - root->val, ans, tempV);

        tempV.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> tempV;
        if (!root)
            return ans;
        solve(root, targetSum, ans, tempV);
        return ans;
    }
};