class Solution
{
public:
    vector<vector<int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    vector<vector<vector<int>>> dp; // 3D memoization table

    void BFS(int x, int y, int index, vector<vector<int>> &minDist, vector<vector<int>> &pos)
    {
        vector<vector<int>> t(50, vector<int>(50, -1)); // Shortest distances
        queue<pair<int, int>> que;
        que.push({x, y});
        t[x][y] = 0;

        while (!que.empty())
        {
            auto [currX, currY] = que.front();
            que.pop();

            for (auto &dir : directions)
            {
                int newX = currX + dir[0];
                int newY = currY + dir[1];

                if (newX >= 0 && newX < 50 && newY >= 0 && newY < 50 && t[newX][newY] == -1)
                {
                    t[newX][newY] = t[currX][currY] + 1;
                    que.push({newX, newY});
                }
            }
        }

        for (int i = 0; i < pos.size(); i++)
        {
            int x_ = pos[i][0];
            int y_ = pos[i][1];
            minDist[index][i] = t[x_][y_];
        }
    }

    // Solve function with memoization
    int solve(vector<vector<int>> &minDist, int idx, int mask, int n, bool Alice)
    {
        if (mask == 0)
            return 0;
        if (dp[idx][mask][Alice] != -1)
            return dp[idx][mask][Alice]; // Use memoized result

        int result = (Alice == true) ? -1 : 1e9;

        for (int i = 1; i < n; i++)
        {
            if (mask & (1 << (i - 1)))
            {
                int moves = minDist[idx][i];
                if (Alice)
                {
                    result = max(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice));
                }
                else
                {
                    result = min(result, moves + solve(minDist, i, mask ^ (1 << (i - 1)), n, !Alice));
                }
            }
        }

        return dp[idx][mask][Alice] = result; // Memoize result
    }

    int maxMoves(int kx, int ky, vector<vector<int>> &positions)
    {
        int n = positions.size();
        vector<vector<int>> pos;
        pos.push_back({kx, ky});

        for (auto &vec : positions)
        {
            int x = vec[0];
            int y = vec[1];
            pos.push_back({x, y});
        }

        vector<vector<int>> minDist(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < pos.size(); i++)
        {
            int x = pos[i][0];
            int y = pos[i][1]; // Fixed typo
            BFS(x, y, i, minDist, pos);
        }

        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>((1 << n), vector<int>(2, -1))); // Initialize dp table

        bool Alice = true;
        return solve(minDist, 0, (1 << n) - 1, pos.size(), Alice);
    }
};
