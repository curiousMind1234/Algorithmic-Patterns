int firstNonRepeating(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            if (count == 1)
                return arr[i - 1];

            count = 1;
        }
    }

    // Check the last group
    if (count == 1)
        return arr[n - 1];

    return -1;
}


Complexity: O(N log N) time, and O(1) auxiliary space apart from the sorting implementation's stack
