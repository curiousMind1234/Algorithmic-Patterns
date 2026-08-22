bool subsetSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(target + 1)
    );
    dp[0][0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
    
            if (nums[i-1] <= j) {
                dp[i][j] =
                    dp[i-1][j] || //don't take
                    dp[i-1][j - nums[i-1]]; // take
            }
            else {
                dp[i][j] = dp[i-1][j]; // don't take
            } 
        }
    }
    return dp[n][target];
}

Time  = O(N × target)
Space = O(N × target)

Why do you use || instead of max()?"

Say:
"Because I'm not maximizing a value here. I'm checking whether the target sum is possible. If either taking or skipping the current number can produce the sum, the result is true."

           Subset Sum
                ↓
       Can I make target?
                ↓
        ┌───────┴───────┐
      TAKE            DON'T TAKE
       ↓                  ↓
remaining sum        same sum
       ↓                  ↓
dp[i-1][j-num]      dp[i-1][j]
       └───────┬──────────┘
                 ↓
                ||
