// User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 1e9;
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }
    }
};

/// asd

int n = matrix.size();
for (int r = 0; r < n; r++)
{
    for (int c = 0; c < n; c++)
    {
        if (matrix[r][c] == -1)
        {
            matrix[r][c] == 10000;
        }
    }
}

for (int via = 0; via < n; via++)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            matrix[r][c] = min(matrix[r][c], matrix[r][via] + matrix[via][c]);
        }
    }
}

for (int r = 0; r < n; r++)
{
    for (int c = 0; c < n; c++)
    {
        if (matrix[r][c] == 10000)
        {
            matrix[r][c] == -1;
        }
    }
}