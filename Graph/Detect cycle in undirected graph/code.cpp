bool hasCycleUndirected(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int x : adj[node]) {
        if (x == parent) {
            continue;
        }
        else if (visited[x]) {
            return true;
        }
        else {
            bool result = hasCycleUndirected(x, node, adj, visited);
            if (result) return true;
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    return hasCycleUndirected(0, -1, adj, visited);   // call with parent = -1 for the start node
}
