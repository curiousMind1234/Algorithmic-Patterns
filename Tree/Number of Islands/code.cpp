void dfs(vector<vector<int>>& grid, int i, int j) {

    if (i < 0 || i >= grid.size() ||
        j < 0 || j >= grid[0].size())
        return;

    if (grid[i][j] == 0)
        return;

    grid[i][j] = 0;

    dfs(grid, i - 1, j); // up
    dfs(grid, i + 1, j); // down
    dfs(grid, i, j - 1); // left
    dfs(grid, i, j + 1); // right
}

int numIslands(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 1) {
                count++;
                dfs(grid, i, j);
            }
        }
    }

    return count;
}


Complexity
For an M × N grid:
Time: O(M × N)
Every cell is visited at most once.
Space: O(M × N) worst case
