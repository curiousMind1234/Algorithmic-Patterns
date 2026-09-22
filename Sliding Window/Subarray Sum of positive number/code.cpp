int subarraySumPositive(const vector<int>& arr, int target)
{
    int left = 0;
    int sum = 0;
    int count = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];

        while (sum > target && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
        {
            count++;
        }
    }

    return count;
}

Example:

[1,2,3,4,5], target = 9
Answer = 2

The two subarrays are [2,3,4] and [4,5].

Complexity: O(n) time, O(1) space.
