class Solution
{
public:
    vector<int> shortestPath(int V, int m, vector<vector<int>> &edges)
    {
        // Code here
        vector<pair<int, int>> adj[V + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        set<pair<int, int>> st;
        int parent[V + 1];
        vector<int> dist(V + 1);
        for (int i = 1; i <= V; i++)
        {
            dist[i] = 1e9;
            parent[i] = i;
        }

        st.insert({0, 1});
        dist[1] = 0;

        while (!st.empty())
        {
            auto it = *(st.begin());
            int node = it.second;
            int nodeWt = it.first;
            st.erase(it);
            for (auto it : adj[node])
            {
                int edgeWt = it.second;
                int adjNode = it.first;

                if (nodeWt + edgeWt < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = nodeWt + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[V] == 1e9)
        {
            return {-1};
        }

        vector<int> path;
        int node = V;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[V]);
        reverse(path.begin(), path.end());

        return path;
    }
};