class Solution
{
public:
    int l1, l2;
    int dp[501][501];
    int solve(string &s1, string &s2, int i, int j)
    {
        // base case

        if (i == l1)
        {
            return l2 - j; // Insert remaining characters of s2
        }
        if (j == l2)
        {
            return l1 - i; // Delete remaining characters of s1
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // 3 cases

        if (s1[i] == s2[j])
        {
            dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }
        else
        {
            int ins = 1 + solve(s1, s2, i, j + 1);
            int rep = 1 + solve(s1, s2, i + 1, j + 1);
            int del = 1 + solve(s1, s2, i + 1, j);

            dp[i][j] = min(min(ins, rep), del);
        }

        return dp[i][j];
    }

    int minDistance(string &word1, string &word2)
    {
        l1 = word1.length();
        l2 = word2.length();
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};