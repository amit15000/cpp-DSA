class Solution
{
public:
    int dp[1001][1001];

    int solve(int n, int screen, int clip)
    {
        if (screen == n)
        {
            return 0;
        }

        if (screen > n)
        {
            return 10001;
        }
        if (dp[screen][clip] != -1)
            return dp[screen][clip];

        // characters can be inserted

        // use clipboard--and keep clipboard same

        int keepClipBoard = 0;

        keepClipBoard = 1 + solve(n, screen + clip, clip);

        // use  clipboard--and update clipboard same

        int updateClipBoard = 0;

        updateClipBoard = 2 + solve(n, screen + clip, screen + clip);

        return dp[screen][clip] = min(keepClipBoard, updateClipBoard);
    }

    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return 1 + solve(n, 1, 1);
    }
};