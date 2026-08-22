int knapsack(vector<int>& weights,
             vector<int>& values,
             int capacity) {

    int n = weights.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(capacity + 1, 0)
    );

    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= capacity; w++) {

            if (weights[i - 1] <= w) {

                dp[i][w] = max(
                    dp[i - 1][w],
                    values[i - 1] +
                    dp[i - 1][w - weights[i - 1]]
                );

            } else {

                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}


TC = O(n × capacity)
SC = O(n × capacity)

I use 2D DP where dp[i][w] represents the maximum value using the first i items with capacity w. For each item that fits, I choose between taking it and not taking it, and store the maximum. This gives O(N×W) time and O(N×W) space

             Does item fit?
                  |
          ┌───────┴────────┐
         NO                 YES
          ↓                  ↓
    DON'T TAKE         TWO choices
          ↓             /          \
    dp[i-1][w]      TAKE          DON'T TAKE
                       ↓               ↓
                value + remaining   dp[i-1][w]
                       \               /
                         ---- max ----
