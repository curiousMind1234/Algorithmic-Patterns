Problem Statement
Given an integer array nums and an integer k, find the number of pairs (i, j) such that:
i < j
|nums[i] - nums[j]| < k
Return the total number of valid pairs.
Assume k > 0.

Example
nums = [1, 5, 3, 4, 2]
k = 3

Valid pairs:

(1, 3) → |1 - 3| = 2
(1, 2) → |1 - 2| = 1
(5, 3) → |5 - 3| = 2
(5, 4) → |5 - 4| = 1
(3, 4) → |3 - 4| = 1
(3, 2) → |3 - 2| = 1
(4, 2) → |4 - 2| = 2

Output:
7

--------------------------------------------------------------------------------------------------------------------
  
Solution 1: Brute Force
Approach

Check every possible pair (i, j) where i < j.
---------------------------------------------------------
int findPairs(vector<int> nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(nums[i] - nums[j]) < k) {
                count++;
            }
        }
    }

    return count;
}


Complexity
Time  : O(N²)
Space : O(1)

-------------------------------------------------------------------------------------------------------------
Solution 2: Sorting + Two Pointers
Key Observation

After sorting:
[1, 2, 3, 4, 5]
For a fixed i, as j moves right: nums[j] - nums[i] can only increase. Therefore, once: nums[j] - nums[i] >= k we know that all elements after j are also invalid for this i.
We can therefore stop checking individual pairs.

Approach
Sort the array.
Maintain i and j.
Move j forward while:
nums[j] - nums[i] < k
j becomes the first invalid position.
Number of valid elements for this i:
j - i - 1
Add that to count.
Code

------------------------------------------------
int findPairs(vector<int> nums, int k) {
    if (k <= 0)
        return 0;

    int count = 0;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    int j = 0;

    for (int i = 0; i < n; i++) {

        if (j < i + 1)
            j = i + 1;

        while (j < n && nums[j] - nums[i] < k) {
            j++;
        }

        count += j - i - 1;
    }

    return count;
}

----------------------------------------------------------------------------------------------------------------------------
  
Complexity
Sorting       → O(N log N)
Two pointers  → O(N)
----------------------
Total         → O(N log N)

Space         → O(1) auxiliary

----------------------------------------------------------------------------------------------------------------------------
⭐ Interview takeaway

The important optimization isn't just sorting.
The real insight is: j never moves backward.
So although the while loop is nested inside the for loop, j moves at most N times in total, not N times for every i.
Therefore:
O(N) + O(N) = O(N)
after sorting, giving the overall: O(N log N)
