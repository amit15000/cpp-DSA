//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {

        vector<int> dist(V, pow(10, 8));
        dist[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        for (int i = 0; i < V; i++)
        {

            while (!pq.empty())
            {

                int n = pq.top().second;
                pq.pop();

                for (auto &vec : edges)
                {
                    if (vec[0] == n)
                    {
                        int s = vec[0];
                        int d = vec[1];
                        int wt = vec[2];
                        int nwt = dist[s] + wt;

                        if (dist[d] > nwt)
                        {
                            dist[d] = nwt;
                            pq.push({nwt, d});
                        }
                    }
                }
            }
        }

        pq.push({0, S});

        while (!pq.empty())
        {

            int n = pq.top().second;
            pq.pop();

            for (auto &vec : edges)
            {
                if (vec[0] == n)
                {
                    int s = vec[0];
                    int d = vec[1];
                    int wt = vec[2];
                    int nwt = dist[s] + wt;

                    if (dist[d] > nwt)
                    {
                        dist.clear();
                        dist.push_back(-1);
                    }
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