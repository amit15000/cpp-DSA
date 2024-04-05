void helper(int start, vector<bool> &vis, vector<int> &res, vector<int> adj[])
{
    vis[start] = true;
    res.push_back(start);
    for (auto adjacent : adj[start])
    {
        if (!vis[adjacent])
        {
            helper(adjacent, vis, res, adj);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    vector<bool> vis(V, false);
    vector<int> res;
    helper(0, vis, res, adj);
    return res;
}