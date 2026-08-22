int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(
        m,
        vector<int>(n, 0)
    );

    // If starting cell is blocked
    if (obstacleGrid[0][0] == 1)
        return 0;

    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            // Skip starting cell
            if (i == 0 && j == 0)
                continue;

            // Obstacle → no paths
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            }
            else {

                // From top
                if (i > 0)
                    dp[i][j] += dp[i-1][j];

                // From left
                if (j > 0)
                    dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

Time  = O(m × n)
Space = O(m × n)

Is it an obstacle?
       |
   YES → 0
       |
      NO
       ↓
  top + left

