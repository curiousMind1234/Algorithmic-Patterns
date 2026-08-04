bool hasCycleDirected(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inStack) {
    visited[node] = true;
    inStack[node] = true;

    for (int x : adj[node]) {
        if (visited[x] && !inStack[x]) {
            continue;  // finished branch, not a cycle
        }
        else if (visited[x] && inStack[x]) {
            return true;  // found an active ancestor — real cycle
        }
        else {
            bool result = hasCycleDirected(x, adj, visited, inStack);
            if (result) return true;
        }
    }

    inStack[node] = false;  // done exploring this node, close it
    return false;
}

bool isCyclic(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    vector<bool> inStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDirected(i, adj, visited, inStack)) {
                return true;
            }
        }
    }
    return false;
}
