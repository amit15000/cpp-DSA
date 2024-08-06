class Solution
{
public:
    typedef long long ll;
    int n;

    ll solve(int idx, vector<int> nums, bool flag)
    {

        if (idx == n)
            return 0;

        // skip
        ll skip = solve(idx + 1, nums, flag);

        // take

        ll val = nums[idx];
        if (!flag)
        {
            val = -val;
        }

        ll take = solve(idx + 1, nums, !flag) + val;

        return max(skip, take);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        n = nums.size();
        return solve(0, nums, true);
    }
};