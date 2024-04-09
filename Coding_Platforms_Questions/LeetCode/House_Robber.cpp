int rob(vector<int> &nums)
{
    int prev1 = nums[0], prev2 = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int ss = nums[i];
        if (i > 1)
            ss += prev2;
        int fs = prev1;
        int curr = max(ss, fs);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}