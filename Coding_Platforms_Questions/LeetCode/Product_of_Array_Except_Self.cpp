#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int j = 0;
        vector<int> result;
        long long int temp = 1;
        int i = 1;
        while (j < nums.size())
        {
            if (j != i)
            {
                cout << "Amit";
                temp *= nums[i];
            }

            if (i == nums.size() - 1)
            {
                result.push_back(temp);
                temp = 1;
                i = 0;
                j++;
            }
        }

        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    v = s.productExceptSelf(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
}