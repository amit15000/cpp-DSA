#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &n)
    {
        sort(n.begin(), n.end());

        int i = 0, k = n.size() - 1, j = 1;

        vector<vector<int>> res;

        while (i < k - 1 && j < k)
        {
            int s = n[i] + n[j] + n[k];
            cout << "i : " << i << " j :" << j << " k :" << k << " Sum :" << s << endl;

            if (s < 0)
            {
                j++;
                if (j == k)
                {
                    i++;
                    j = i + 1;
                }
            }
            else if (s > 0)
            {
                k--;
                j = i + 1;
            }
            else
            {
                res.push_back({n[i], n[j], n[k]});

                cout << endl
                     << n[i] << " " << n[j] << " " << n[k] << " " << endl;
                j++;
                if (j == k)
                {
                    i++;
                    j = i + 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> n = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    Solution s;
    vector<vector<int>> res = s.threeSum(n);
}