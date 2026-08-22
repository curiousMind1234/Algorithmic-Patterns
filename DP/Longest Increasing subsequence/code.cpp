int lengthOfLIS(vector<int>& nums) {

    int n = nums.size();

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (nums[j] < nums[i]) {

                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

Time  = O(N²)
Space = O(N)

1. dp[i] = 1 initially

2. Check ALL previous j

3. If nums[j] < nums[i]:
      dp[i] = max(dp[i], dp[j] + 1)

4. Answer = max of entire dp array
