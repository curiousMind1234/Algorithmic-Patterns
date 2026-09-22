int subarraySum(const vector<int>& arr, int target)
{
    unordered_map<int, int> mp;
    mp[0] = 1;

    int prefixSum = 0;
    int count = 0;

    for (int num : arr)
    {
        prefixSum += num;

        int required = prefixSum - target;

        if (mp.find(required) != mp.end())
        {
            count += mp[required];
        }

        mp[prefixSum]++;
    }

    return count;
}

Let's use an example that shows why the hashmap is necessary:

arr = [3, -2, 3]
target = 4

Subarray:

[3, -2, 3] = 4

Dry run:

Initial:
mp = {0:1}

3:
prefix = 3
required = 3 - 4 = -1
-1 not found
mp = {0:1, 3:1}

-2:
prefix = 1
required = 1 - 4 = -3
-3 not found
mp = {0:1, 3:1, 1:1}

3:
prefix = 4
required = 4 - 4 = 0
0 exists!
count = 1

The important idea is:

prefix[j] - prefix[i] = target

Therefore:

prefix[i] = prefix[j] - target


Complexity: O(n) average time, O(n) space.
