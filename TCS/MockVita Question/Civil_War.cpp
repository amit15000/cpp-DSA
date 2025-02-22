#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int minAbsDifference(vector<int> &power)
{
    int N = power.size();
    int total_sum = accumulate(power.begin(), power.end(), 0);
    int target = total_sum / 2;

    // DP array to check possible subset sums
    vector<bool> dp(target + 1, false);
    dp[0] = true; // Zero sum is always possible (by taking no elements)

    for (int i = 0; i < N; ++i)
    {
        // Traverse backwards to avoid overwriting results from the same iteration
        for (int j = target; j >= abs(power[i]); --j)
        {
            dp[j] = dp[j] || dp[j - abs(power[i])];
        }
    }

    // Find the largest sum closest to target that is possible
    for (int j = target; j >= 0; --j)
    {
        if (dp[j])
        {
            return abs(total_sum - 2 * j); // Minimize the absolute difference
        }
    }

    return total_sum; // Fallback in case no valid partition
}

int main()
{
    vector<int> power = {105, 100, -1, 4, 5, -3};
    cout << "Minimum Absolute Difference: " << minAbsDifference(power) << endl;
    return 0;
}
