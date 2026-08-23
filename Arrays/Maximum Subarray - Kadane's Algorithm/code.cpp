int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}



Dry-run intuition

The two variables mean:

currentSum → best sum ending at the current index
maxSum     → best sum found anywhere so far

The key line:
currentSum = max(nums[i], currentSum + nums[i]);

means:
Start fresh OR continue the previous subarray — whichever is better.

Complexity
Time  = O(N)
Space = O(1)
