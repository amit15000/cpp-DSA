
// class Solution
// {
// public:
//     int maxDepth(TreeNode *root)
//     {
//         if (root == NULL)
//         {
//             return 0;
//         }

//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };

// method 2--- counting the number of levels
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int count = 1;

        while (!q.empty())
        {

            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                    count++;
                }
            }
            else
            {
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
        return count;
    }
};