#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> pset;
        sort(nums.begin(), nums.end());
        vector<int> st;
        for (int mask = 0; mask < (1 << nums.size()); mask++)
        {
            st.clear();
            bool f = true;
            for (int i = 0; i < nums.size(); i++)
            {
                if ((1 << i) & mask)
                {
                    if (i > 0 && nums[i] == nums[i - 1] && !((1 << (i - 1)) & mask))
                    {
                        f = false;
                        break;
                    }
                    st.push_back(nums[i]);
                }
            }
            if (f)
                pset.push_back(st);
        }
        return pset;
    }
};