//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {

        vector<bool> vis(V, false);
        vector<int> dist(V, pow(10, 8));
        dist[S] = 0;
        vis[S] = 1;

        for (int i = 0; i < V; i++)
        {

            for (auto &vec : edges)
            {
                if (vis[vec[0]])
                {
                    int n = vec[0];
                    int d = vec[1];
                    int wt = vec[2];

                    vis[d] = 1;

                    int nwt = dist[n] + wt;

                    if (dist[d] > nwt)
                    {
                        dist[d] = nwt;
                    }
                }
            }
        }

        // detect cycle

        for (auto &vec : edges)
        {
            if (vis[vec[0]])
            {
                int n = vec[0];
                int d = vec[1];
                int wt = vec[2];

                vis[d] = 1;

                int nwt = dist[n] + wt;

                if (dist[d] > nwt)
                {
                    dist.clear();
                    dist.push_back(-1);
                    break;
                }
            }
        }

        return dist;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends