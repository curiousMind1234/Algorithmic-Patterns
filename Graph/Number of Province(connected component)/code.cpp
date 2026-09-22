#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited);
        }
    }
}

int countProvinces(int n, vector<pair<int, int>>& edges)
{
    // Build adjacency list
    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Count connected components
    vector<bool> visited(n, false);
    int provinces = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            provinces++;
            dfs(i, adj, visited);
        }
    }

    return provinces;
}

int main()
{
    int n = 5;

    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4}
    };

    cout << countProvinces(n, edges);

    return 0;
}


Output
2

Because:

0 -- 1 -- 2     → Province 1

3 -- 4          → Province 2
