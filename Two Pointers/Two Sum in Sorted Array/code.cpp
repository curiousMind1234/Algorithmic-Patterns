bool checkSumExists(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }

    return false;
}

Time: O(N)
Space: O(1)
