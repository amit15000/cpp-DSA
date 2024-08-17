class Solution
{
public:
    long long maxP;
    int r, c;
    vector<vector<long long>> t;

    long long solve(vector<vector<int>> &points, int row, int prevC, int currPoint)
    {
        if (row >= r)
        {
            return 0;
        }

        if (t[row][prevC] != -1)
            return t[row][prevC];

        long long maxPoints = 0;
        for (int col = 0; col < c; col++)
        {
            int cp = currPoint + points[row][col] - abs(prevC - col);
            maxPoints = max(maxPoints, cp + solve(points, row + 1, col, 0));
        }

        t[row][prevC] = maxPoints;
        return maxPoints;
    }

    long long maxPoints(vector<vector<int>> &points)
    {
        r = points.size();
        c = points[0].size();
        maxP = 0;
        t.assign(r, vector<long long>(c, -1));

        for (int col = 0; col < c; col++)
        {
            maxP = max(maxP, points[0][col] + solve(points, 1, col, 0));
        }

        return maxP;
    }
};
