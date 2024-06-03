class Solution
{
public:
    typedef pair<int, int> T;

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        // bfs
        int r = grid.size();
        int c = grid[0].size();

        if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1)
        {
            return -1;
        }

        vector<T> D = {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        queue<T> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty())
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == r - 1 && y == c - 1)
            {
                return grid[x][y];
            }

            for (auto [dx, dy] : D)
            {
                int newX = x + dx;
                int newY = y + dy;

                if (newX >= 0 && newX < r && newY >= 0 && newY < c && grid[newX][newY] == 0)
                {
                    grid[newX][newY] = grid[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return -1;
    }
};