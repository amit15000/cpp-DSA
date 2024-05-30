// #include <vector>
// #include <unordered_map>
// #include <queue>
// using namespace std;

// class Solution
// {
//     // BipartitePair structure
//     struct BipartitePair
//     {
//         int vtx;
//         int d;

//         BipartitePair(int v, int dist) : vtx(v), d(dist) {}
//     };

// public:
//     // Main function to check if the graph is bipartite
//     bool isBipartite(vector<vector<int>> &graph)
//     {
//         // Convert graph to adjacency list
//         unordered_map<int, unordered_set<int>> adjList;
//         for (int i = 0; i < graph.size(); ++i)
//         {
//             for (int j = 0; j < graph[i].size(); ++j)
//             {
//                 adjList[i].insert(graph[i][j]);
//             }
//         }

//         return isBipartiteHelper(adjList);
//     }

// private:
//     // Helper function for BFS traversal
//     bool isBipartiteHelper(unordered_map<int, unordered_set<int>> &adjList)
//     {
//         queue<BipartitePair> q;
//         unordered_map<int, int> visited;

//         for (auto &entry : adjList)
//         {
//             int src = entry.first;
//             if (visited.find(src) != visited.end())
//                 continue;

//             BipartitePair bp(src, 0);
//             q.push(bp);

//             while (!q.empty())
//             {
//                 BipartitePair r = q.front();
//                 q.pop();

//                 if (visited.find(r.vtx) != visited.end() && r.d != visited[r.vtx])
//                 {
//                     return false;
//                 }

//                 visited[r.vtx] = r.d;

//                 for (int nbrs : adjList[r.vtx])
//                 {
//                     if (visited.find(nbrs) == visited.end())
//                     {
//                         BipartitePair nbp(nbrs, r.d + 1);
//                         q.push(nbp);
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };

// Method 2
class Solution
{

private:
    bool bfs(int start, int color[], vector<vector<int>> &graph, int n)
    {
        queue<int> q;
        q.push(start);

        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto i : graph[node])
            {
                if (color[i] == -1)
                {
                    color[i] = !color[node];
                    q.push(i);
                }
                else if (color[i] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();

        int color[n];

        for (int i = 0; i < n; i++)
        {
            color[i] = -1;
        }

        // components of graph
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (bfs(i, color, graph, n) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }
};