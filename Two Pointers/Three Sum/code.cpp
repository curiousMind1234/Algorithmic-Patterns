vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate fixed values
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0) {
                results.push_back(
                    {nums[i], nums[j], nums[k]}
                );
                j++;
                k--;

                // Skip duplicate j values
                while (j < k && nums[j] == nums[j - 1]) j++;
                // Skip duplicate k values
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
            else if (sum < 0) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return results;
}

Sorting       → O(N log N)
Two-pointer   → O(N²)

Total Time    → O(N²)
Extra Space   → O(1)
