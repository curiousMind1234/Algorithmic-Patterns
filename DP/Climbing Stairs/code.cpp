int climbStairs(int n) {
    if (n <= 1)
        return 1;

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

Time: O(n)
Space: O(n)



//2nd approach

int climbStairs(int n) {
    if (n <= 1)
        return 1;

    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

Time: O(n)
Space: O(1)
