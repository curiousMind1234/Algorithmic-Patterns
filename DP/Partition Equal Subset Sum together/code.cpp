bool canPartition(vector<int>& nums) {

    int sum = 0;

    for (int num : nums) {
        sum += num;
    }

    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    int n = nums.size();

    vector<vector<bool>> dp(
        n + 1,
        vector<bool>(target + 1, false)
    );

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= target; j++) {

            if (nums[i-1] <= j) {

                dp[i][j] =
                    dp[i-1][j] ||
                    dp[i-1][j - nums[i-1]];

            } else {

                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

Time  = O(N × target)
Space = O(N × target)


/*
Current number:

nums[i-1]
If it doesn't fit:
if (nums[i-1] > j)
    dp[i][j] = dp[i-1][j];

Only Don't Take is possible.

If it fits:

Two choices:

DON'T TAKE → dp[i-1][j]

TAKE → dp[i-1][j - nums[i-1]]

Therefore:

dp[i][j] =
    dp[i-1][j] ||
    dp[i-1][j - nums[i-1]];

|| because either choice being possible is enough.

🧩 Pattern to Remember
Partition Equal Subset Sum
          ↓
Total sum even?
          ↓
       target = sum/2
          ↓
      Subset Sum
          ↓
   TAKE / DON'T TAKE
          ↓
       boolean DP
       
Complexity
Time  = O(N × target)
Space = O(N × target)

🎯 Interview one-liner

"If the total sum is odd, partitioning is impossible. Otherwise, I need to find whether a subset with sum totalSum/2 exists. I solve this using boolean 0/1 knapsack DP, where each number can either be taken or skipped."

*/
