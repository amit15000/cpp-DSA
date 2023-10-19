#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &matrix, int row, int col, int res)
{
    if (col > 0 || col > matrix.size())
        return 0;
    if (row == matrix[0].size())
    {
        return 0;
    }

    int maxi = INT_MIN;
    for (int i = -1; i < 2; i++)
    {

        res = solve(matrix, row + 1, col + i, res);
        res += matrix[row][col];

        maxi = max(maxi, res);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int res = INT_MIN;
    for (int i = 0; i < matrix.size(); i++)
    {
        int sum = solve(matrix, 0, 0, matrix[0][i]);
        res = max(res, sum);
    }
    return res;
}
int main()
{

    vector<vector<int>> matrix = {{2, 1, 10, 4},
                                  {3, 100, 2, 1},
                                  {1, 1, 20, 2},
                                  {2, 1, 2, 1}};
    // vector<vector<int>> matrix = {{1, 2, 3}, {9, 8, 7}, {4, 5, 6}};
    //

    int ans = getMaxPathSum(matrix);
    cout << ans;
}