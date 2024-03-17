#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int crl = 0;
        int maxL = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
            {
                crl += 1;
                maxL = max(maxL, crl);
            }
            else
            {
                crl = 0;
            }
        }

        return maxL;
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1};
    Solution s;
    int result = s.findMaxLength(nums);
    cout << result;
}