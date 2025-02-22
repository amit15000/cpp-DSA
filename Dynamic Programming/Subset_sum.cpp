#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &nums, int i, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }

    if (i == 0)
    {
        return nums[0] == target;
    }

    int not_take = solve(nums, i - 1, target, dp);
    int take = 0;
    if (target >= nums[i])
    {
        take = solve(nums, i - 1, target - nums[i], dp);
    }

    return not_take + take;
}

bool isSubsetSum(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    int res = solve(arr, n - 1, k, dp);
    cout << "Number of subsets with sum " << k << ": " << res << endl;
    return res > 0;
}

int main()
{
    // Test cases
    vector<vector<int>> testCases = {
        {3, 34, 4, 12, 5, 2}, // Test case 1
        {1, 2, 3, 7},         // Test case 2
        {1, 3, 4, 8},         // Test case 3
        {2, 3, 7, 8, 10}      // Test case 4
    };
    vector<int> targets = {9, 6, 6, 11};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test case " << i + 1 << ": ";
        if (isSubsetSum(testCases[i], targets[i]))
        {
            cout << "Subset exists with the target sum.\n";
        }
        else
        {
            cout << "No subset exists with the target sum.\n";
        }
    }

    return 0;
}
