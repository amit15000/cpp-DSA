vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{

    int r = image.size();
    int c = image[0].size();
    // bfs
    queue<pair<int, int>> q;
    int clr = image[sr][sc];
    image[sr][sc] = newColor;
    q.push({sr, sc});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        // check 4 adjacents
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {

            int nr = x + dr[i];
            int nc = y + dc[i];

            if ((nr >= 0 && nr < c) && (nc >= 0 && nc < c && image[nr][nc] == clr))
            {
                image[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }
    return image;
}