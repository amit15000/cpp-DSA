// using set
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int V, source;
    cin >> V >> source;

    // adjacency list -->  vector<vector<int,int>>v  first int -> adjacent node , second int -> weight of he edge
    vector<vector<int, int>> adj = { 0,
                                     1,
                                     2,
                                     3,
                                     4,
                                     5,
                                     6,
                                     7 }