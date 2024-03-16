#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    void makeRandCZero(vector<vector<int>> &matrix, unordered_set<pair<int, int>> &m)
    {
        for (auto elem : m)
        {
            int row = elem.first;
            int col = elem.second;
            // make row zero
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[row][j] = 0;
            }
            // make column zero
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][col] = 0;
            }
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<pair<int, int>> m;
        int nr = matrix.size();
        int nc = matrix[0].size();
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (matrix[i][j] == 0)
                {
                    m.insert({i, j});
                }
            }
        }
        for (auto i : m)
        {
            cout << i.first << " " << i.second << " " << endl;
        }
        makeRandCZero(matrix, m);
    }
};
int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    Solution s;
    s.setZeroes(matrix);
}