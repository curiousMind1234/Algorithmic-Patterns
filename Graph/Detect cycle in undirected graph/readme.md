For undirected graphs, I track both visited status and the parent node during DFS. When I look at a neighbor, if it's the parent I just came from, I skip it — that's not a cycle, it's the same edge seen from the other side. If the neighbor is visited and is NOT the parent, that means I've reached a node through two different paths — that's the actual cycle signal. I propagate true up through every recursive call the moment a cycle is found."

========================================================================================================

Time complexity: O(V + E)

V = number of vertices (nodes), E = number of edges.
You visit every node once (marked visited, never reprocessed), and for each node you look at all its neighbors — summed across the whole graph, that's every edge examined at most twice (once from each endpoint, since it's undirected). So total work is proportional to nodes plus edges combined.

Space complexity: O(V)

visited array: O(V), one boolean per node.
Recursion call stack: worst case O(V) — if the graph is one long chain (like your earlier example, 1-2-3-4-5...), the recursion goes as deep as there are nodes before unwinding.
These add up but both are O(V), so overall space is O(V).


