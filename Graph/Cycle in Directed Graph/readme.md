For directed graphs, I can't rely on parent-skipping like in undirected cycle detection, since edges are one-directional. Instead I track two states: visited — has this node ever been touched — and inStack — is this node currently active in my current DFS path. A cycle exists only when I reach a neighbor that's both visited AND still in the recursion stack, meaning I've looped back to an open ancestor. I reset inStack to false right before returning from each call, since that node is now fully explored and closed.


Adjacency list, concretely: vector<vector<int>> adj is a list of lists. adj[i] is itself a vector<int> — the list of all nodes directly connected to node i. Think of it as: index into the outer vector to pick a node, and what you get back is that node's own personal list of neighbors.

Complexity: Time O(V + E), Space O(V) — for visited, inStack, and the recursion stack, same as before.
