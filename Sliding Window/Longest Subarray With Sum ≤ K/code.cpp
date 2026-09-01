nums = [2, 1, 5, 1, 3, 2]
k = 7
Find the longest contiguous subarray whose sum <= k.

Brute Force — O(N²)
---------------------------
We can fix the starting index i, then expand j and maintain a running sum:

int findLengthofSubarray(vector<int> nums, int k) {
    int n = nums.size();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum <= k) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

Why is this better than recalculating the sum?

We could calculate every subarray's sum from scratch, but that would become O(N³).
Instead:
i = 0
[2]       sum = 2
[2,1]     sum = 3
[2,1,5]   sum = 8
...

We simply do:
sum += nums[j];
So each (i, j) combination is processed once.

Complexity
Outer loop → O(N)
Inner loop → O(N)

Time  → O(N²)
Space → O(1)

Then we optimized this further because all numbers are positive:

Brute force                 Sliding Window
    O(N²)          →             O(N)

Sliding Window:
--------------------------------------
int findLengthofSubarray(vector<int> nums, int k) {
    int left = 0, maxLength = 0, sum = 0;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum > k) {
            sum -= nums[left];
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
}

Let's verify with the example
nums = [2, 1, 5, 1, 3, 2]
k = 7

The window evolves roughly like:

[2]          sum=2   length=1
[2,1]        sum=3   length=2
[2,1,5]      sum=8   ✗
   [1,5]     sum=6   length=2
   [1,5,1]   sum=7   length=3
   [1,5,1,3] sum=10  ✗
      [5,1,3] sum=9 ✗
         [1,3] sum=4
         [1,3,2] sum=6 length=3

Answer:
3

Complexity
Your solution is:
Time: O(N)
Even though there's a while inside the for, left only moves forward and can move at most N times overall.
So:
right → N movements
left  → N movements maximum

Total → O(N)
Space: O(1)

Brute force: enumerate all subarrays using two loops. Maintain a running sum to avoid recalculating it. O(N²).
Optimization: because all numbers are positive, use a sliding window where expanding increases the sum and shrinking decreases it, giving O(N).
