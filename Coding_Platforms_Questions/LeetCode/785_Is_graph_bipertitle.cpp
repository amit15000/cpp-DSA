#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
    // BipartitePair structure
    struct BipartitePair
    {
        int vtx;
        int d;

        BipartitePair(int v, int dist) : vtx(v), d(dist) {}
    };

public:
    // Main function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>> &graph)
    {
        // Convert graph to adjacency list
        unordered_map<int, unordered_set<int>> adjList;
        for (int i = 0; i < graph.size(); ++i)
        {
            for (int j = 0; j < graph[i].size(); ++j)
            {
                adjList[i].insert(graph[i][j]);
            }
        }

        return isBipartiteHelper(adjList);
    }

private:
    // Helper function for BFS traversal
    bool isBipartiteHelper(unordered_map<int, unordered_set<int>> &adjList)
    {
        queue<BipartitePair> q;
        unordered_map<int, int> visited;

        for (auto &entry : adjList)
        {
            int src = entry.first;
            if (visited.find(src) != visited.end())
                continue;

            BipartitePair bp(src, 0);
            q.push(bp);

            while (!q.empty())
            {
                BipartitePair r = q.front();
                q.pop();

                if (visited.find(r.vtx) != visited.end() && r.d != visited[r.vtx])
                {
                    return false;
                }

                visited[r.vtx] = r.d;

                for (int nbrs : adjList[r.vtx])
                {
                    if (visited.find(nbrs) == visited.end())
                    {
                        BipartitePair nbp(nbrs, r.d + 1);
                        q.push(nbp);
                    }
                }
            }
        }
        return true;
    }
};