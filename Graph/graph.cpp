#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph
{
public:
    // graph implementation using adjacency list
    unordered_map<T, list<T>> adj;

    void insertEdge(T u, T v, bool undirected)
    {
        adj[u].push_back(v);
        if (undirected)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << static_cast<char>(j) << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;

    Graph<char> g;

    for (int i = 0; i < m; i++)
    {
        int from;
        int to;
        cout << "From: ";
        cin >> from;
        cout << "To: ";
        cin >> to;
        g.insertEdge(from, to, true); // Assuming undirected graph
    }
    cout << "This is your graph :" << endl;
    g.printGraph();

    return 0;
}
