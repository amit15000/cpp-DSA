#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{

    int solve(int node, unordered_map<int, vector<int>> &adj,
              unordered_map<int, bool> &vis)
    {
        vis[node] = 1;
        int ans = 0;
        for (auto &i : adj[node])
        {
            if (!vis[i])
            {
                ans = max(ans, 1 + solve(i, adj, vis));
            }
        }
        return ans;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;

        for (auto &i : edges)
        {
            int a = i[0];
            int b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        unordered_map<int, vector<int>> store;
        int mini = 1e9;
        int ele = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, bool> vis;
            int val = solve(i, adj, vis);
            store[val].push_back(i);
            // cout<<val<<" ";
            if (val < mini)
            {
                mini = val;
            }
        }
        return store[mini];
    }
};